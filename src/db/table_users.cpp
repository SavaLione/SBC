/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
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
 * @brief Структура таблицы с пользователями
 * @author SavaLione
 * @date 13 Jan 2021
 */
#include "db/table_users.h"

table_users::table_users()
{
}

table_users::~table_users()
{
}

void table_users::clear()
{
    id = 0;
    username = "";
    password = "";
    name = "";
    email = "";
    phone = "";
    role = "";
    registration_date = "";
    last_time_online = "";
    description = "";
    department = "";
    branch = "";
    is_user_active = "";
    registration_confirmation_code = "";
    city = "";
}

void table_users::print()
{
    spdlog::debug("id: {}", id);
    spdlog::debug("username: {}", username);
    spdlog::debug("password: {}", password);
    spdlog::debug("name: {}", name);
    spdlog::debug("email: {}", email);
    spdlog::debug("phone: {}", phone);
    spdlog::debug("role: {}", role);
    spdlog::debug("registration_date: {}", registration_date);
    spdlog::debug("last_time_online: {}", last_time_online);
    spdlog::debug("description: {}", description);
    spdlog::debug("department: {}", department);
    spdlog::debug("branch: {}", branch);
    spdlog::debug("is_user_active: {}", is_user_active);
    spdlog::debug("registration_confirmation_code: {}", registration_confirmation_code);
    spdlog::debug("city: {}", city);
}

table_users &table_users::operator=(table_users const &rhs)
{
    if (this != &rhs)
    {
        id = rhs.id;
        username = rhs.username;
        password = rhs.password;
        name = rhs.name;
        email = rhs.email;
        phone = rhs.phone;
        role = rhs.role;
        registration_date = rhs.registration_date;
        last_time_online = rhs.last_time_online;
        description = rhs.description;
        department = rhs.department;
        branch = rhs.branch;
        is_user_active = rhs.is_user_active;
        registration_confirmation_code = rhs.registration_confirmation_code;
        city = rhs.city;
    }
    return *this;
}