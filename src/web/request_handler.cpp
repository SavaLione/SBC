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

#include "time/current_time.h"

request_handler::~request_handler()
{
}

void request_handler::_init()
{
    _recognize_cookie();
    _recognize_post();
    _recognize_user();
    _processing_post_request();

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
    case page_registration:
        _show_page_registration();
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
        _cookie.set(_http_cookie);
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
        spdlog::debug("Pre _post.set()");
        spdlog::debug(_string_post);
        _post.set(_string_post);
        spdlog::debug(_string_post);
        spdlog::debug("Post _post.set()");
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
    login l(_user, _cookie);
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

void request_handler::_show_page_registration()
{
    registration r(_user);
    _show_page(r);
}

void request_handler::_recognize_user()
{
    /* Проверяем, есть ли в запросе cookie uuid */
    if (_cookie.get_uuid().set)
    {
        /* uuid установлен */

        /* Пытаемся получить пользователя по uuid */
        _user._uuid = _cookie.get_uuid().value;
        _user_handler.get();
    }
    else
    {
        /* uuid не установлен */
        /* нет uuid, значит и пользователя в запросе нет */
        _user._user_status = USER_STATUS_NOT_SET;
    }
}

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
    if (_user._user_status == USER_STATUS_SET)
    {
        spdlog::debug("Пользователь установлен");
    }
    else
    {
        spdlog::debug("Пользователь НЕ установлен");
    }
    spdlog::debug("");

    spdlog::debug("post: {}", _string_post);
}

void request_handler::_processing_post_request()
{
    /*
        Определяем тип post запроса
        login
        registration
    */
    if (_method == _POST)
    {
        /* Пользователя нет в системе */
        if (_user._user_status != USER_STATUS_SET)
        {
            spdlog::debug("Пользователя нет в системе");
            spdlog::debug(_post.get_input_username().value);
            spdlog::debug(_post.get_input_password().value);

            /* registration post запрос */
            if (_post.get_input_username().set && _post.get_input_password().set && _post.get_input_terms_of_use().set)
            {
                spdlog::debug("Регистрация пользователя в системе");
                spdlog::debug(_post.get_input_username().value);
                spdlog::debug(_post.get_input_password().value);
                try
                {
                    db_pool *db_p = &_db_instance.get();
                    table_users _users;

                    soci::session sql(*db_p->get_pool());

                    current_time ct;

                    _users.username = _post.get_input_username().value;
                    _users.password = _post.get_input_password().value;
                    _users.name = _post.get_input_first_name().value;
                    _users.name += " ";
                    _users.name += _post.get_input_last_name().value;
                    _users.email = _post.get_input_email().value;
                    _users.phone = _post.get_input_phone().value;
                    _users.role = "DEFAULT";
                    _users.registration_date = ct.s_date();
                    _users.last_time_online = ct.s_date();
                    _users.description = "";
                    _users.department = _post.get_input_department().value;
                    _users.branch = _post.get_input_branch().value;
                    _users.is_user_active = "true";
                    _users.registration_confirmation_code = "true";
                    _users.city = "";

                    sql << "insert into users(username, password, name, email, phone, role, registration_date, last_time_online, description, department, branch, is_user_active, registration_confirmation_code, city) "
                        << "values(:username, :password, :name, :email, :phone, :role, :registration_date, :last_time_online, :description, :department, :branch, :is_user_active, :registration_confirmation_code, :city)",
                        soci::use(_users);
                }
                catch (const std::exception &e)
                {
                    spdlog::error(e.what());
                }
                return;
            }

            /* login post запрос */
            if (_post.get_input_username().set && _post.get_input_password().set)
            {
                try
                {
                    db_pool *db_p = &_db_instance.get();
                    soci::indicator ind;
                    table_users _users;

                    soci::session sql(*db_p->get_pool());

                    sql << "SELECT * FROM users WHERE username='" << _post.get_input_username().value << "' and password='" << _post.get_input_password().value << "' LIMIT 1", soci::into(_users, ind);

                    if (ind == soci::i_null)
                    {
                        spdlog::warn("could not find user: [{}] by password: [{}]", _post.get_input_username().value, _post.get_input_password().value);
                    }
                    else
                    {
                        if ((_users.username.size() > 0) && (_users.password.size() > 0))
                        {
                            spdlog::info("found user: [{}] by password: [{}]", _post.get_input_username().value, _post.get_input_password().value);
                            spdlog::info("found user: [{}] by password: [{}]", _users.username, _users.password);

                            /* Нужно установить cookie */
                            {
                                std::string __uuid = _uuid_instance.get();

                                cookie_pair uuid = {"uuid", __uuid, true};
                                _cookie.set_uuid(uuid);

                                user __u;
                                __u._id = _users.id;
                                __u._username = _users.username;
                                __u._password = _users.password;
                                __u._name = _users.name;
                                __u._email = _users.email;
                                __u._phone = _users.phone;
                                __u._user_role = USER_ROLE_DEFAULT;
                                __u._registration_date = _users.registration_date;
                                __u._last_time_online = _users.last_time_online;
                                __u._description = _users.description;
                                __u._department = _users.department;
                                __u._branch = _users.branch;
                                __u._is_user_active = true;
                                __u._registration_confirmation_code = _users.registration_confirmation_code;
                                __u._city = _users.city;
                                __u._uuid = __uuid;
                                __u._user_status = USER_STATUS_SET;

                                _cookie_instance.add(__u);
                            }

                            return;
                        }
                        else
                        {
                            spdlog::warn("not found user: [{}] by password: [{}]", _post.get_input_username().value, _post.get_input_password().value);
                            spdlog::warn("_users.username, _users.password - empty");
                        }
                    }
                }
                catch (const std::exception &e)
                {
                    spdlog::error(e.what());
                }
            }
        }
    }
}
