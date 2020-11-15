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
#include "db/db_wrapper.h"

#include <time/current_time.h>

db_wrapper::db_wrapper()
{
}

db_wrapper::~db_wrapper()
{
}

const bool db_wrapper::check_username(std::string const &username)
{
    return _dbm.has("users_table", "username", username);
}

const bool db_wrapper::check_mail(std::string const &mail)
{
    return _dbm.has("users_table", "mail", mail);
}

const void db_wrapper::add_data(std::string const &username, std::vector<std::string> const &data)
{
    std::string user_table_name = "user_table_";
    user_table_name += username;
    std::vector<std::string> column_names = {"lat", "lon", "date", "time"};
    //const bool add(std::string const &table_name, std::vector<std::string> const &column_names, std::vector<std::string> const &data);
    _dbm.add(user_table_name, column_names, data);
}

const void db_wrapper::create_user(std::string const &username, std::string const &password, std::string const &mail)
{
    current_time ct;
    std::string s_time = ct.s_year();
    s_time += "-";
    s_time += ct.s_month();
    s_time += "-";
    s_time += ct.s_day();
    s_time += " ";
    s_time += ct.s_hour();
    s_time += ":";
    s_time += ct.s_min();
    s_time += ":";
    s_time += ct.s_sec();

    std::string user_table = "user_table_";
    user_table += username;

    std::vector<std::string> column_names = {"username", "password", "mail", "date_reg", "user_table"};
    std::vector<std::string> user_data = {username, password, mail, s_time, user_table};
    _dbm.add("users_table", column_names, user_data);
}

const bool db_wrapper::check_password(std::string const &username, std::string const &password)
{
    if (_dbm.get_string("users_table", "username", username) == password)
    {
        return true;
    }
    return false;
}

const void db_wrapper::add_data(std::string const &username, std::string const &data)
{
    std::string user_table_name = "user_table_";
    user_table_name += username;
    std::vector<std::string> column_names = {"lat", "lon", "date", "time"};

    std::vector<std::string> data_insert = {data, "test", "test", "test"};

    _dbm.add(user_table_name, column_names, data_insert);
}