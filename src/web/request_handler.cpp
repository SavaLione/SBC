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
    _recognize_post();

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

void request_handler::_recognize_post()
{
    /* Работаем только с post запросами */
    if (_method == _POST)
    {
        /* Тут можно получить несколько строк, но получаем толлько одну */
        while (FCGX_GetStr(_string_post, sizeof(_string_post), _request.in) > 0)
        {
        }
        _post = post(_string_post);
    }
}

void request_handler::_show_page(std::string const &p)
{
    _debug();
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
}

void request_handler::_recognize_user()
{
    /* cookie_repository */
    cookie_repository &cookie_repository_instance = cookie_repository::Instance();

    /* Проверяем, есть ли в запросе cookie uuid */
    if (_cookie.get_uuid().set)
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

#include <iostream>

void request_handler::_debug()
{
    spdlog::debug("");
    spdlog::debug("REQUEST_METHOD: {}", _request_method);
    spdlog::debug("CONTENT_LENGTH: {}", _content_length);
    spdlog::debug("REMOTE_ADDR: {}", _remote_addr);
    spdlog::debug("REQUEST_URI: {}", _request_uri);
    spdlog::debug("QUERY_STRING: {}", _query_string);
    spdlog::debug("DOCUMENT_URI: {}", _document_uri);
    spdlog::debug("DOCUMENT_ROOT: {}", _document_root);
    spdlog::debug("HTTP_HOST: {}", _http_host);
    spdlog::debug("COOKIE: {}", _http_cookie);
    spdlog::debug("");
    spdlog::debug("_method: {}", string_method(_method));
    spdlog::debug("");
    if (_user.get_is_user_set())
    {
        spdlog::debug("Пользователь установлен");
    }
    else
    {
        spdlog::debug("Пользователь НЕ установлен");
    }
    spdlog::debug("");

    std::string s_post = "";
    for (int i = 0; i < sizeof(_string_post); i++)
    {
        s_post += _string_post[i];
    }
    
    spdlog::debug("post: {}", _string_post);
    spdlog::debug("post: {}", s_post);
    std::cout << "cout post: " << _string_post << std::endl;
    std::cout << "cout post: " << s_post << std::endl;
}