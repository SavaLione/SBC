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
 * @brief Обработка структуры пользователя. Получение данных и прочее
 * @author SavaLione
 * @date 12 Dec 2020
 */
#include "core/user_handler.h"

#include "io/logger.h"

#include "web/cookie_repository.h"

user_handler::~user_handler()
{
}

const void user_handler::get()
{
    _init();
}

void user_handler::_init()
{
    /* Доступ к cookie repository */
    cookie_repository &cookie_instance = cookie_repository::Instance();

    /* Проверяем, указан ли uuid */
    if (!_user._uuid.empty())
    {
        /* uuid указан */
        _is_uuid_set = true;
    }

    /* Проверяем, указан ли username */
    if (!_user._username.empty())
    {
        /* username указан */
        _is_username_set = true;
    }

    /* Проверяем, указан ли uuid и username */
    if (!_is_uuid_set && !_is_username_set)
    {
        /* uuid и username не установлены */
        /* Мы не можем получить пользователя без uuid или username */
        _user._user_status == USER_STATUS_NOT_SET;
        return;
    }

    /* Если установлен uuid, пытаемся найти пользователя в cookie_repository */
    if (_is_uuid_set)
    {
        cookie_instance.get_by_uuid(_user);

        if (_user._user_status == USER_STATUS_SET)
        {
            /* Пользователь найден в cookie repository */
            return;
        }
    }

    /* Если установлен username, пытаемся найти пользователя в cookie_repository */
    if (_is_username_set)
    {
        cookie_instance.get_by_uuid(_user);

        if (_user._user_status == USER_STATUS_SET)
        {
            /* Пользователь найден в cookie repository */
            return;
        }
    }

    /* Если попали сюда, значит пользователя нет в cookie repository */
    /* Надо найти его в базе данных */

}