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
 * @brief Working with sqlite database
 * @author SavaLione
 * @date 16 Nov 2020
 */
#include "db/db_sqlite.h"

std::vector<std::string> _vec_response;

int callback_save_to_vec(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::string s = azColName[i];
        s += ":";
        s += argv[i];
        _vec_response.push_back(s);
    }

    return 0;
}

std::vector<std::string> db_sqlite::open(std::string db_name)
{
    _db_name = db_name;
    return _open();
}

std::vector<std::string> db_sqlite::_open()
{
    int status = -1;
    return _open(status);
}

std::vector<std::string> db_sqlite::_open(int &status)
{
    sqlite3_open(_db_name.c_str(), &_db);

    const char PRAGMA[] =
        "PRAGMA synchronous = OFF;"
        "PRAGMA encoding = \"UTF-8\";"
        "PRAGMA journal_mode = DELETE;";

    std::string sql = PRAGMA;

    std::vector<std::string> ret = vec_answer(sql, status);
    if (status)
    {
        _db_open = false;
    }
    else
    {
        _db_open = true;
    }

    return ret;
}

bool db_sqlite::db_open()
{
    return _db_open;
}

db_sqlite::db_sqlite()
{
}

db_sqlite::~db_sqlite()
{
    _close();
}

void db_sqlite::close()
{
    _close();
}

std::vector<std::string> db_sqlite::vec_answer(std::string request)
{
    int rc = -1;
    return vec_answer(request, rc);
}

std::vector<std::string> db_sqlite::vec_answer(std::string request, int &rc)
{
    std::vector<std::string> vec_return;

    std::string s = "";

    rc = sqlite3_exec(_db, request.c_str(), callback_save_to_vec, &s, NULL);

    if (rc)
    {
        _vec_response.push_back(sqlite3_errmsg(_db));
    }

    vec_return = _vec_response;
    _vec_response.clear();

    return vec_return;
}

void db_sqlite::request(std::string request)
{
    sqlite3_exec(_db, request.c_str(), NULL, NULL, NULL);
}

void db_sqlite::request(std::string request, int &status)
{
    status = sqlite3_exec(_db, request.c_str(), NULL, NULL, NULL);
}

void db_sqlite::_close()
{
    if (_db_open)
    {
        sqlite3_reset(_stmt);
        sqlite3_finalize(_stmt);
        sqlite3_close(_db);
        _db_open = false;
    }
}
