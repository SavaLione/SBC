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
    ~user();

    /* set */
    const void set_name(std::string name);
    const void set_username(std::string username);
    const void set_email(std::string email);
    const void set_phone(std::string phone);
    const void set_password(std::string password);

    const void set_role(role r);

    /* get */
    std::string get_name();
    std::string get_username();
    std::string get_email();
    std::string get_phone();
    std::string get_password();
    std::string get_last_time_online();
    std::string get_uuid();

    role get_role();

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

    /* private functions */
    const void _set_last_time_online();
};

#endif // CORE_USER_H