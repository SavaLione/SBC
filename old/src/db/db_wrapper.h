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
 * @brief db wrapper
 * @author SavaLione
 * @date 06 Sep 2020
 */
#ifndef DB_DB_WRAPPER_H
#define DB_DB_WRAPPER_H

#include "db/db_mysql.h"

#include <string>

/*
    Table users_table
    |id|username|password|mail|date_reg|user_table|

    Table user_count_operations
    |id|username|day|count|

    Table user_table_${username}
    |id|lat|lon|date|time|
*/

/*
    Usage:
    db_wrapper &instance = db_wrapper::Instance();
    instance.request();
*/

class db_wrapper
{
public:
    static db_wrapper& Instance()
    {
        static db_wrapper dbw;
        return dbw;
    }
    ~db_wrapper();

    /*
        true - user found
        false - user not found
    */
    const bool check_username(std::string const &username);

    /*
        true - password ok
        false - password not ok
    */
    const bool check_password(std::string const &username, std::string const &password);

    /*
        true - mail found
        false - mail not found
    */
    const bool check_mail(std::string const &mail);

    /*
        add data to db:
        lat, lon, date, time
    */
    const void add_data(std::string const &username, std::vector<std::string> const &data);

    const void add_data(std::string const &username, std::string const &data);

    const void create_user(std::string const &username, std::string const &password, std::string const &mail);

private:
    db_wrapper();
    db_wrapper(db_wrapper const&) = delete;
    db_wrapper& operator= (db_wrapper const&) = delete;

    db_mysql _dbm;
};

#endif // DB_DB_WRAPPER_H