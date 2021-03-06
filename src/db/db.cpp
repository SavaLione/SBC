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
#include "core/sha.h"

#include "io/logger.h"

#include "time/current_time.h"

db::db()
{
    std::string open_db_request = "";

    if (_settings_instance.db() == SQLITE3)
    {
        open_db_request = "";
        open_db_request += "dbname=";
        open_db_request += _settings_instance.db_sqlite_name();
    }

    is_db_connect = _db.connect(_settings_instance.string_db_name(), open_db_request);

    /*
        sqlite3
        Если таблицы users нет, создаём
    */
    _create();
}

db::~db()
{
}

void db::request(std::string const &r)
{
    try
    {
        soci::session sql(*_db.get_pool());

        sql << r;
    }
    catch (const std::exception &e)
    {
        spdlog::error(e.what());
    }
}

void db::_create()
{
    try
    {
        soci::session sql(*_db.get_pool());

        if (sql.get_backend_name() == "sqlite3")
        {
            int table_users_found = 0;
            int table_test_found = 0;
            int table_codes_found = 0;

            sql << "select count(*) from sqlite_master where type='table' and name='users'", soci::into(table_users_found);
            sql << "select count(*) from sqlite_master where type='table' and name='test'", soci::into(table_test_found);
            sql << "select count(*) from sqlite_master where type='table' and name='codes'", soci::into(table_codes_found);

            if (!table_users_found)
            {
                spdlog::info("sqlite table users not exists. creating sqlite table users");

                {
                    soci::ddl_type ddl = sql.create_table("users");

                    ddl.column("id", soci::dt_integer)("not null");
                    ddl.column("username", soci::dt_string)("not null unique");
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

                    ddl.unique("users", "id");
                    ddl.primary_key("users", "id");
                }

                if (_settings_instance.app_level() == application_level::APP_DEBUG)
                {
                    for (int i = 1; i < 3; i++)
                    {
                        current_time ct;

                        sql << "insert into users(username, password, name, email, phone, role, registration_date, last_time_online, description, department, branch, is_user_active, registration_confirmation_code, city) values("
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'" << ct.s_date() << "', "
                            << "'" << ct.s_date() << "', "
                            << "'" << sha_256(std::to_string(i + 1024)) << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "', "
                            << "'testuser_" << i << "'"
                            << ")";
                    }
                }
            }

            if (!table_test_found)
            {
                spdlog::info("sqlite table test not exists. creating sqlite table test");

                {
                    soci::ddl_type ddl = sql.create_table("test");

                    ddl.column("id", soci::dt_integer)("not null");

                    ddl.unique("test", "id");
                    ddl.primary_key("test", "id");
                }

                for (int i = 0; i < 16; i++)
                {
                    sql << "insert into test(id) values(" << i << ")";
                }
            }

            if (!table_codes_found)
            {
                spdlog::info("sqlite table codes not exists. creating sqlite table codes");

                {
                    soci::ddl_type ddl = sql.create_table("codes");

                    ddl.column("id", soci::dt_integer)("not null");

                    ddl.column("code", soci::dt_string);
                    ddl.column("time", soci::dt_string);
                    ddl.column("user", soci::dt_string);
                    ddl.column("status", soci::dt_string);

                    ddl.unique("test", "id");
                    ddl.primary_key("test", "id");
                }

                for (int i = 0; i < 4; i++)
                {
                    current_time ct;
                    sql << "insert into codes(code, time, user, status) values('" << sha_256(std::to_string(i)) << "', '" << ct.s_date() << "', 'test', 'OTHER')";
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        spdlog::error(e.what());
    }
}

#include "db/table_template.h"

void db::_test_table_test_print()
{
    try
    {
        soci::session sql(*_db.get_pool());
        soci::indicator ind;

        table_template tt;

        soci::rowset<table_template> rs = (sql.prepare << "SELECT * FROM test");

        for (auto it = rs.begin(); it != rs.end(); it++)
        {
            table_template &i = *it;
            i.print();
        }
    }
    catch (const std::exception &e)
    {
        spdlog::error(e.what());
    }
}

db_pool &db::get()
{
    return _db;
}