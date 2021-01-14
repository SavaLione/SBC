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
 * @brief Обработка post запроса
 * @author SavaLione
 * @date 09 Dec 2020
 */
#ifndef WEB_POST_H
#define WEB_POST_H

#include <string>

#include "web/url.h"

/*
    Пара post
    key - ключ
    value - значение
    set - установлена ли пара?
*/
struct post_pair
{
    const std::string key;
    std::string value;
    bool set = false;
};

class post
{
public:
    post();
    post(std::string const &unprocessed_post) : _unprocessed_post(unprocessed_post) { _init(); };
    ~post();

    /* Получаем пару post username */
    const post_pair get_username() const
    {
        return _username;
    }

    /* Получаем пару post email */
    const post_pair get_email() const
    {
        return _email;
    }

    /* Получаем пару post password */
    const post_pair get_password() const
    {
        return _password;
    }

    /* Получаем пару post input_last_name */
    const post_pair get_input_last_name() const
    {
        return _input_last_name;
    }

    const post_pair get_input_first_name() const
    {
        return _input_first_name;
    }

    const post_pair get_input_middle_name() const
    {
        return _input_middle_name;
    }

    const post_pair get_input_username() const
    {
        return _input_username;
    }

    const post_pair get_input_password() const
    {
        return _input_password;
    }

    const post_pair get_input_email() const
    {
        return _input_email;
    }

    const post_pair get_input_address() const
    {
        return _input_address;
    }

    const post_pair get_input_phone() const
    {
        return _input_phone;
    }

    const post_pair get_input_terms_of_use() const
    {
        return _input_terms_of_use;
    }

    const post_pair get_input_branch() const
    {
        return _input_branch;
    }

    const post_pair get_input_department() const
    {
        return _input_department;
    }

    /* 
        Устанавливаем необработанный post запрос
        Необходимо при инициализации класса вида:
        post p;
    */
    void set(std::string const &unprocessed_post);

private:
    /* 
        Необработанный post запрос
        Строка вида:
        email=sava%40savalione.com&password=asd&checkbox=remember-me
    */
    std::string _unprocessed_post;

    /*
        Обработанный post запрос
        Строка вида:
        email=sava@savalione.com&password=asd&checkbox=remember-me
    */
    std::string _decoded_uncompressed_post;

    /* Разделитель post данных */
    char _separator = '&';

    /* Инициализация объекта. Получение post из строки. */
    void _init();

    /* Адрес электронной почты пользователя */
    post_pair _email = {"email", ""};

    /* Пароль пользователя */
    post_pair _password = {"password", ""};

    post_pair _username = {"username", ""};

    post_pair _input_last_name = {"input_last_name", ""};
    post_pair _input_first_name = {"input_first_name", ""};
    post_pair _input_middle_name = {"input_middle_name", ""};
    post_pair _input_username = {"input_username", ""};
    post_pair _input_password = {"input_password", ""};
    post_pair _input_email = {"input_email", ""};
    post_pair _input_address = {"input_address", ""};
    post_pair _input_phone = {"input_phone", ""};
    post_pair _input_terms_of_use = {"input_terms_of_use", ""};

    post_pair _input_branch = {"input_branch", ""};
    post_pair _input_department = {"input_department", ""};

    void _get(post_pair &pp);
};

#endif // WEB_POST_H