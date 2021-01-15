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

#include "web/cookie_repository.h"
#include "web/method.h"
#include "web/cookie.h"
#include "web/page.h"
#include "web/post.h"

#include "core/user_handler.h"
#include "core/uuid.h"

#include "db/db.h"
#include "db/table_users.h"

/*
    Обработка запроса FastCGI
*/
class request_handler
{
public:
    request_handler(FCGX_Request &request) : _request(request) { _init(); };
    ~request_handler();

    /* Получаем тип метода */
    const method get_method() const { return _method; };

    /* Получаем запрашиваемый uri */
    const std::string get_request_uri() const { return _request_uri; };

private:
    /* cookie */
    cookie_repository &_cookie_instance = cookie_repository::Instance();

    /* uuid */
    uuid &_uuid_instance = uuid::Instance();

    /* Подключение к базе данных */
    db &_db_instance = db::instance();

    /* Запрос от FastCGI */
    FCGX_Request &_request;

    /* Тип запроса */
    const std::string _request_method = FCGX_GetParam("REQUEST_METHOD", _request.envp);

    /* Длинна запроса */
    const std::string _content_length = FCGX_GetParam("CONTENT_LENGTH", _request.envp);

    /* Адрес клиента */
    const std::string _remote_addr = FCGX_GetParam("REMOTE_ADDR", _request.envp);

    /* Запрашиваемый uri */
    const std::string _request_uri = FCGX_GetParam("REQUEST_URI", _request.envp);
    const std::string _query_string = FCGX_GetParam("QUERY_STRING", _request.envp);
    const std::string _document_uri = FCGX_GetParam("DOCUMENT_URI", _request.envp);
    const std::string _document_root = FCGX_GetParam("DOCUMENT_ROOT", _request.envp);
    const std::string _http_host = FCGX_GetParam("HTTP_HOST", _request.envp);

    /* Максимальная длина post запроса */
    static const int _post_max_length = 2048;

    /* Переменная с post запросом */
    char _string_post[_post_max_length];

    /* Тип запроса */
    method _method = recognize_method(_request_method);

    /* Нужная нам страница */
    page _page = recognize_page(_request_uri);

    /*
        Переменная хранит в себе необработанную строку с Cookie
        Пример:
        Cookie: username=SavaLione; uuid=aa-bb-cc-dd; some=Soome; 
        Если в запросе от клиента небыло cookie, строка становится равна NULL
    */
    const std::string _http_cookie = (FCGX_GetParam("HTTP_COOKIE", _request.envp) != NULL) ? FCGX_GetParam("HTTP_COOKIE", _request.envp) : "NULL";

    /* Cookie установлены? */
    bool _is_cookie_set = false;

    /* Обработанные Cookie */
    cookie _cookie;

    /* 
        Post запрос
        Необработанный
        будет обработан после _post.set(_string_post);
    */
    post _post;

    /* Пользователь */
    user _user;

    /* Обработка пользователя */
    user_handler _user_handler = user_handler(_user);

    /* functions */

    /* Инициализация. Получение всех переменных и прочее. */
    void _init();

    /* Распознать установленны ли Cookie */
    void _recognize_cookie();

    /* Распознать, есть ли пользователь по cookie uuid */
    void _recognize_user();

    /* Распознать, есть ли post */
    void _recognize_post();

    /* Определяем пост запрос */
    void _processing_post_request();

    /* Показать страницу пользователю */
    void _show_page(std::string const &p);

    /* Показать страницу About */
    void _show_page_about();

    /* Показать страницу Login */
    void _show_page_login();

    /* Показать страницу Not found */
    void _show_page_not_found();

    /* Показать страницу Test */
    void _show_page_test_page();

    /* Показать страницу Registration */
    void _show_page_registration();

    /* Показать страницу Terms */
    void _show_page_terms();

    /* Показать страницу Install */
    void _show_page_install();

    /* Показать страницу Logout */
    void _show_page_logout();

    /* Показать страницу Dashboard */
    void _show_page_dashboard();

    /* Показать страницу Index */
    void _show_page_index();

    /* Вывести отладочную информацию в консоль */
    void _debug();
};

#endif // WEB_REQUEST_HANDLER_H