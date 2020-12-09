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
#include "web/request_handler.h"

#include "web/page.h"

#include "io/logger.h"

request_handler::~request_handler()
{
}

void request_handler::_init()
{
    _recognize_cookie();
    _recognize_user();

    switch (_page)
    {
    case page_about:
        _show_page_about();
        break;
    case page_login:
        _show_page_login();
        break;
    case page_test_page:
        _show_page_test_page();
        break;
    default:
        _show_page_not_found();
        break;
    }
}

void request_handler::_recognize_cookie()
{
    if (_http_cookie == "NULL")
    {
        _is_cookie_set = false;
    }
    else
    {
        _is_cookie_set = true;
    }
}

void request_handler::_show_page(std::string const &p)
{
    FCGX_PutS(p.c_str(), _request.out);
}

void request_handler::_show_page_about()
{
    about a(_user);
    _show_page(a);
}

void request_handler::_show_page_login()
{
    login l(_user);
    _show_page(l);
}

void request_handler::_show_page_not_found()
{
    not_found nf(_user);
    _show_page(nf);
}

void request_handler::_show_page_test_page()
{
    _debug();
}

void request_handler::_recognize_user()
{
    /* cookie_repository */
    cookie_repository &cookie_repository_instance = cookie_repository::Instance();

    /* Проверяем, есть ли в запросе cookie uuid */
    if (_cookie.is_uuid_set())
    {
        /* Выполняем проверку, есть ли uuid в базе */
        if (cookie_repository_instance.have_user(_cookie.get_uuid().value))
        {
            /* Есть */
            _user = cookie_repository_instance.get_user(_cookie.get_uuid().value);
            _user.set_user(true);
        }
        else
        {
            /* Нет */
            _user.set_user(false);
        }
    }
    else
    {
        /* uuid не установлен */
        /* нет uuid, значит и пользователя в запросе нет */
        _user.set_user(false);
    }
}

void request_handler::_debug()
{
    spdlog::("");
    spdlog::("REQUEST_METHOD: {}", _request_method);
    spdlog::("CONTENT_LENGTH: {}", _content_length);
    spdlog::("REMOTE_ADDR: {}", _remote_addr);
    spdlog::("REQUEST_URI: {}", _request_uri);
    spdlog::("QUERY_STRING: {}", _query_string);
    spdlog::("DOCUMENT_URI: {}", _document_uri);
    spdlog::("DOCUMENT_ROOT: {}", _document_root);
    spdlog::("HTTP_HOST: {}", _http_host);
    spdlog::("COOKIE: {}", _http_cookie);
    spdlog::("");
    if(_user.get_is_user_set())
    {
        spdlog::("Пользователь установлен");
    }
    else
    {
        spdlog::("Пользователь НЕ установлен");
    }
    spdlog::("");
}