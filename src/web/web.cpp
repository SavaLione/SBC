/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2020, Savely Pototsky (SavaLione)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * @file
 * @brief Web fcgi
 * @author SavaLione
 * @date 17 Nov 2020
 */
#include "web/web.h"

#include "web/request_handler.h"

#include "core/settings.h"

#include "io/logger.h"

#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>

#include <fcgi_config.h>
#include <fcgiapp.h>

/* Дескриптор открытого сокета */
static int _socket_id;

int _connection_count = 0;

static void *_fcgi_page(void *a)
{
    int rc;
    FCGX_Request request;
    char *server_name;

    if (FCGX_InitRequest(&request, _socket_id, 0) != 0)
    {
        /* Ошибка при инициализации структуры запроса */
        spdlog::debug("Can not init request");
        return NULL;
    }

    while (true)
    {
        static pthread_mutex_t accept_mutex = PTHREAD_MUTEX_INITIALIZER;

        /* Попробовать получить новый запрос */
        pthread_mutex_lock(&accept_mutex);
        rc = FCGX_Accept_r(&request);
        pthread_mutex_unlock(&accept_mutex);

        if (rc < 0)
        {
            /* Ошибка при получении запроса */
            spdlog::debug("Can not accept new request");
            break;
        }
        /* Request is accepted */

        // /* Пробуем получить данные */
        // char str_post[2048];
        // // int FCGX_GetStr(char * str, int n, FCGX_Stream *stream);
        // while (FCGX_GetStr(str_post, sizeof(str_post), request.in) > 0)
        // {
        //     spdlog::debug("POST: {}", str_post);
        // }

        /* Обрабатываем запрос */
        request_handler rh(request);

        /* Закрыть текущее соединение */
        FCGX_Finish_r(&request);

        /* Завершающие действия - запись статистики, логгирование ошибок и т.п. */
    }
    return NULL;
}

web::web()
{
    settings &settings_instance = settings::Instance();

    pthread_t id[settings_instance.fcgi_thread_count()];

    /* Инициализация библиотеки */
    FCGX_Init();

    /* Открывыаем новый сокет */
    _socket_id = FCGX_OpenSocket(settings_instance.fcgi_socket_path().c_str(), 20);

    if (_socket_id < 0)
    {
        /* Ошибка при открытии сокета */
        spdlog::error("Error opening socket");
    }
    else
    {
        /* Сокет открыт */
    }

    /* Создаём рабочие потоки */
    for (int i = 0; i < settings_instance.fcgi_thread_count(); i++)
    {
        pthread_create(&id[i], NULL, _fcgi_page, NULL);
    }

    /* Ждем завершения рабочих потоков */
    for (int i = 0; i < settings_instance.fcgi_thread_count(); i++)
    {
        pthread_join(id[i], NULL);
    }
}

web::~web()
{
}
