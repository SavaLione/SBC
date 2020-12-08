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
 * @brief Обработчик веб запросов
 * @author SavaLione
 * @date 08 Dec 2020
 */
#ifndef WEB_REQUEST_HANDLER_H
#define WEB_REQUEST_HANDLER_H

#include <string>

#include <fcgi_config.h>
#include <fcgiapp.h>

#include "web/method.h"
#include "web/cookie.h"

/*
    Обработка запроса FastCGI
*/
class request_handler
{
public:
    request_handler(FCGX_Request &request) : _request(request) { _init(); };
    ~request_handler();

    /* Получение типа запроса */
    const method get_method();

private:
    /* variables */

    /* Запрос от FastCGI */
    FCGX_Request &_request;

    /* Тип запроса */
    method _method = _unknown_method;

    /* Тип запроса */
    std::string _request_method = FCGX_GetParam("REQUEST_METHOD", _request.envp);

    /* Длинна запроса */
    std::string _content_length = FCGX_GetParam("CONTENT_LENGTH", _request.envp);

    /* Адрес клиента */
    std::string _remote_addr = FCGX_GetParam("REMOTE_ADDR", _request.envp);

    /* Запрашиваемый uri */
    std::string _request_uri = FCGX_GetParam("REQUEST_URI", _request.envp);
    std::string _query_string = FCGX_GetParam("QUERY_STRING", _request.envp);
    std::string _document_uri = FCGX_GetParam("DOCUMENT_URI", _request.envp);
    std::string _document_root = FCGX_GetParam("DOCUMENT_ROOT", _request.envp);
    std::string _http_host = FCGX_GetParam("HTTP_HOST", _request.envp);

    /*
        Переменная хранит в себе необработанную строку с Cookie
        Пример:
        Cookie: username=SavaLione; uuid=aa-bb-cc-dd; some=Soome; 
        Если в запросе от клиента небыло cookie, строка становится равна NULL
    */
    std::string _http_cookie = (FCGX_GetParam("HTTP_COOKIE", _request.envp) != NULL) ? FCGX_GetParam("HTTP_COOKIE", _request.envp) : "NULL";

    /* Cookie установлены? */
    bool _is_cookie_set = false;

    cookie _cookie(_http_cookie);

    /* functions */

    /* Инициализация. Получение всех переменных и прочее. */
    void _init();

    /* Распознать установленны ли Cookie */
    void _recognize_cookie();

    /* Распознать тип запроса */
    void _recognize_method();
};

#endif // WEB_REQUEST_HANDLER_H