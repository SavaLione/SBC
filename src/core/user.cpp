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
#include "core/user.h"
#include "core/uuid.h"

user::user()
{
    _init();
}

user::~user()
{
}

/* set */
const void user::set_name(std::string name)
{
    _name = name;
}

const void user::set_username(std::string username)
{
    _username = username;
}

const void user::set_email(std::string email)
{
    _email = email;
}

const void user::set_phone(std::string phone)
{
    _phone = phone;
}

const void user::set_password(std::string password)
{
    _password = password;
}

const void user::set_role(role r)
{
    _role = r;
}

/* get */
std::string user::get_name()
{
    return _name;
}

std::string user::get_username()
{
    return _username;
}

std::string user::get_email()
{
    return _email;
}

std::string user::get_phone()
{
    return _phone;
}

std::string user::get_password()
{
    return _password;
}

std::string user::get_last_time_online()
{
    return _last_time_online;
}

role user::get_role()
{
    return _role;
}

std::string user::get_uuid()
{
    return _uuid;
}

/* private functions */
const void user::_set_last_time_online()
{
    current_time curr_t;
    _last_time_online = curr_t.s_date();
}

void user::_init()
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();
    _uuid = uuid_instance.get();

    _set_last_time_online();
}

void user::set_user(bool is_user_set)
{
    _is_user_set = is_user_set;
}

bool user::get_is_user_set()
{
    return _is_user_set;
}