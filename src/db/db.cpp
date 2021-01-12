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

#include "io/logger.h"

#include <string>
#include <map>
#include <sstream>
#include <iostream>

struct userss
{
    int id = -1;
    std::string username;
    std::string password;
    std::string email;
};

void v_print_userss(userss const &u)
{
    spdlog::debug("id: {} username: {} password: {} email: {}", u.id, u.username, u.password, u.email);
}

void db_test_open()
{
    /* try catch */
    // soci::session sql("sqlite3", "sbc.db");

    // userss u;

    // std::string query = "CREATE TABLE \"users\" (";
    // query += "\"id\"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,";
    // query += "\"username\"	TEXT NOT NULL UNIQUE,";
    // query += "\"password\"	TEXT NOT NULL,";
    // query += "\"email\"	TEXT";
    // query += ");";

    // sql << query;

    // static const std::string s_select = "SELECT * FROM users WHERE username = \'some\';";
    static const std::string s_select = "SELECT * FROM users;";

    soci::session sql("sqlite3", "sbc.db");

    for (int i = 0; i < 1000; i++)
    {
        soci::row r;
        userss u;
        sql << s_select, soci::into(r);

        std::ostringstream doc;
        doc << "<row>" << std::endl;

        for (std::size_t i = 0; i != r.size(); ++i)
        {
            const soci::column_properties &props = r.get_properties(i);

            doc << '<' << props.get_name() << '>';

            switch (props.get_data_type())
            {
            case soci::dt_string:
                doc << r.get<std::string>(i);
                break;
            case soci::dt_double:
                doc << r.get<double>(i);
                break;
            case soci::dt_integer:
                doc << r.get<int>(i);
                break;
            case soci::dt_long_long:
                doc << r.get<long long>(i);
                break;
            case soci::dt_unsigned_long_long:
                doc << r.get<unsigned long long>(i);
                break;
            case soci::dt_date:
                std::tm when = r.get<std::tm>(i);
                doc << asctime(&when);
                break;
            }

            doc << "</" << props.get_name() << '>' << std::endl;
        }
        doc << "</row>";
    }
}

db::db()
{
    if (_db_type == SQLITE3)
    {
        _initialization_sqlite();
    }
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
    if (_db_type == SQLITE3)
    {
        _create_sqlite();
    }
}

void db::_create_sqlite()
{
    std::string sql_request = "";

    sql_request += "CREATE TABLE IF NOT EXISTS \"users\" (";
    sql_request += "	\"id\"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,";
    sql_request += "	\"username\"	TEXT NOT NULL UNIQUE,";
    sql_request += "	\"password\"	TEXT NOT NULL,";
    sql_request += "	\"name\" TEXT,";
    sql_request += "	\"email\"	TEXT,";
    sql_request += "	\"phone\"	TEXT,";
    sql_request += "	\"role\"	TEXT,";
    sql_request += "	\"registration_date\"	TEXT,";
    sql_request += "	\"last_time_online\"	TEXT,";
    sql_request += "	\"description\"	TEXT,";
    sql_request += "	\"department\"	TEXT,";
    sql_request += "	\"branch\"	TEXT,";
    sql_request += "	\"is_user_active\"	TEXT,";
    sql_request += "	\"registration_confirmation_code\"	TEXT,";
    sql_request += "	\"city\"	TEXT";
    sql_request += ");";

    request(sql_request);
}