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
#ifndef DB_TABLE_USERS_H
#define DB_TABLE_USERS_H

#include "db/table_template.h"

class table_users : public table_template
{
public:
    std::string username = "";
    std::string password = "";
    std::string name = "";
    std::string email = "";
    std::string phone = "";
    std::string role = "";
    std::string registration_date = "";
    std::string last_time_online = "";
    std::string description = "";
    std::string department = "";
    std::string branch = "";
    std::string is_user_active = "";
    std::string registration_confirmation_code = "";
    std::string city = "";

    table_users();
    ~table_users();

    void clear();
    void print();

    table_users &operator=(table_users const &rhs);

private:
    /* data */
};

namespace soci
{
    template <>
    struct type_conversion<table_users>
    {
        typedef values base_type;

        static void from_base(values const &v, indicator ind, table_users &p)
        {
            if (ind == i_null)
            {
                return;
            }

            try
            {
                p.id = v.get<int>("id", 0);
                p.username = v.get<std::string>("username", {});
                p.password = v.get<std::string>("password", {});
                p.name = v.get<std::string>("name", {});
                p.email = v.get<std::string>("email", {});
                p.phone = v.get<std::string>("phone", {});
                p.role = v.get<std::string>("role", {});
                p.registration_date = v.get<std::string>("registration_date", {});
                p.last_time_online = v.get<std::string>("last_time_online", {});
                p.description = v.get<std::string>("description", {});
                p.department = v.get<std::string>("department", {});
                p.branch = v.get<std::string>("branch", {});
                p.is_user_active = v.get<std::string>("is_user_active", {});
                p.registration_confirmation_code = v.get<std::string>("registration_confirmation_code", {});
                p.city = v.get<std::string>("city", {});
            }
            catch (std::exception const &e)
            {
                spdlog::error(e.what());
            }
        }

        static void to_base(table_users const &p, values &v, indicator &ind)
        {
            try
            {
                v.set("id", p.id);
                v.set("username", p.username);
                v.set("password", p.password);
                v.set("name", p.name);
                v.set("email", p.email);
                v.set("phone", p.phone);
                v.set("role", p.role);
                v.set("registration_date", p.registration_date);
                v.set("last_time_online", p.last_time_online);
                v.set("description", p.description);
                v.set("department", p.department);
                v.set("branch", p.branch);
                v.set("is_user_active", p.is_user_active);
                v.set("registration_confirmation_code", p.registration_confirmation_code);
                v.set("city", p.city);

                ind = i_ok;
                return;
            }
            catch (std::exception const &e)
            {
                spdlog::error(e.what());
            }
            ind = i_null;
        }
    };

} // namespace soci

#endif // DB_TABLE_USERS_H