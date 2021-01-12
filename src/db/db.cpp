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
 * @brief Работа с базой данных
 * @author SavaLione
 * @date 13 Dec 2020
 */
#include "db/db.h"

#include "core/settings.h"

// db::db()
// {
//     if (_db_type == SQLITE3)
//     {
//         _initialization_sqlite();
//     }
// }

void db::_init()
{
    /* Settings initialization */
    settings &_settings_instance = settings::Instance();

    _db_type = _settings_instance.db();

    _connection_pool_size = _settings_instance.pool_size();
}

db::~db()
{
}

void db::_initialization_sqlite()
{
    for (int i = 0; i < _connection_pool_size; i++)
    {
        soci::session &sql = _pool.at(i);

        std::string db_param = "dbname=";
        db_param += _settings_instance.db_sqlite_name();

        sql.open("sqlite3", db_param);
    }
}

void db::request(std::string const &r)
{
    soci::session sql(_pool);

    sql << r;
}

void db::create()
{
    soci::session sql(_pool);

    soci::ddl_type ddl = sql.create_table("users");
    ddl.column("id", soci::dt_integer)("not null")("primary key")("autoincrement");
    ddl.column("username", soci::dt_string);
    ddl.column("password", soci::dt_string);
    ddl.column("name", soci::dt_string);
    ddl.column("email", soci::dt_string);
    ddl.column("phone", soci::dt_string);
    ddl.column("role", soci::dt_string);
    ddl.column("registration_date", soci::dt_string);
    ddl.column("last_time_online", soci::dt_string);
    ddl.column("description", soci::dt_string);
    ddl.column("department", soci::dt_string);
    ddl.column("branch", soci::dt_string);
    ddl.column("is_user_active", soci::dt_string);
    ddl.column("registration_confirmation_code", soci::dt_string);
    ddl.column("city", soci::dt_string);
}