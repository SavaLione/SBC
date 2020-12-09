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
 * @brief User
 * @author SavaLione
 * @date 25 Nov 2020
 */
#ifndef CORE_USER_H
#define CORE_USER_H

#include <string>

#include "time/current_time.h"

enum role
{
    DEFAULT = 0,
    GUEST = 1,
    MANAGER = 2,
    ADMINISTRATOR = 3,
    BANNED = 100
};



class user
{
public:
    user();
    user(bool is_user_set) : _is_user_set(is_user_set) { _init(); };
    ~user();

    const void set_id(std::string const& id);
    const void set_username(std::string const& username);
    const void set_password(std::string const& password);
    const void set_name(std::string const& name);
    const void set_email(std::string const& email);
    const void set_phone(std::string const& phone);
    const void set_role(role r);
    const void set_registration_date(std::string const& registration_date);
    const void set_last_time_online(std::string const& last_time_online);
    const void set_description(std::string const& description);
    const void set_department(std::string const& department);
    const void set_branch(std::string const& branch);
    const void set_is_user_active(std::string const& description);
    const void set_registration_confirmation_code(std::string const& registration_confirmation_code);
    const void set_city(std::string const& city);

    /* get */
    std::string get_name();
    std::string get_username();
    std::string get_email();
    std::string get_phone();
    std::string get_password();
    std::string get_last_time_online();
    std::string get_uuid();

    role get_role();

    /*
        Устанавливаем состояние пользователя
        true - пользователь есть, данные заполнены
        false - пользователя нет, данные не заполнены
    */
    void set_user(bool is_user_set);

    /*
        Получаем состояние пользователя
        true - пользователь есть, данные заполнены
        false - пользователя нет, данные не заполнены
    */
    const bool get_is_user_set() const
    {
        return _is_user_set;
    }

private:
    /* variables */
    std::string _name = "";
    std::string _username = "";
    std::string _email = "";
    std::string _phone = "";
    std::string _password = "";
    std::string _last_time_online = "";
    std::string _uuid = "";

    role _role = DEFAULT;

    bool _is_user_set = false;

    /* private functions */
    const void _set_last_time_online();

    /* Инициализация user */
    void _init();
};

#endif // CORE_USER_H