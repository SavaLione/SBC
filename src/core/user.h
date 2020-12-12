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

/*
    Роль пользователя в системе 
*/
enum user_role
{
    USER_ROLE_NOT_SET = -1,
    USER_ROLE_DEFAULT = 0,
    USER_ROLE_GUEST = 1,
    USER_ROLE_MANAGER = 2,
    USER_ROLE_ADMINISTRATOR = 3,
    USER_ROLE_BANNED = 100
};

/*
    Статус пользователя(класса)
    USER_NOT_SET - пользователь не установлен
    USER_NOT_FOUND - пользователь не найден
    USER_SET - пользователь установлен
*/
enum user_status
{
    USER_NOT_SET = -1,
    USER_NOT_FOUND = 0,
    USER_SET = 1,
};

struct user
{
    /* id пользователя */
    int _id = -1;

    /* Логин */
    std::string const &_username;

    /* Пароль */
    std::string _password;

    /* ФИО */
    std::string _name;

    /* Адрес электронной почты */
    std::string _email;

    /* Номер телефона */
    std::string _phone;

    /* Роль в системе */
    user_role _user_role = USER_ROLE_NOT_SET;

    /* Дата регистрации */
    std::string _registration_date;

    /* Последний раз в сети */
    std::string _last_time_online;

    /* Описание пользователя */
    std::string _description;

    /* Отдел */
    std::string _department;

    /* Филиал */
    std::string _branch;

    /* Активен пользователь? Есть доступ к системе? */
    bool _is_user_active = false;

    /* Код подтверждения регистрации */
    std::string _registration_confirmation_code;

    /* Город */
    std::string _city;

    /* Уникальный идентификатор */
    std::string _uuid;

    /* Статус пользователя(структуры) */
    user_status _user_status = USER_NOT_SET;
};

class user_handler
{
private:
    /* data */
public:
    user_handler(/* args */);
    ~user_handler();
};

user_handler::user_handler(/* args */)
{
}

user_handler::~user_handler()
{
}


class user
{
public:
    user(std::string const &username) = _username(username) { _init(); };
    ~user();

    const user_status get_user_status() const
    {
        return _user_status;
    }

private:
    /* Инициализация user */
    void _init();
};

#endif // CORE_USER_H