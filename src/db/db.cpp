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

#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

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

    for (int i = 0; i < 1000; i++)
    {
        soci::session sql("sqlite3", "sbc.db");
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