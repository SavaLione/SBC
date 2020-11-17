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

#include "core/settings.h"

#include "io/logger.h"

db_sqlite::db_sqlite()
{
    settings &settings_instance = settings::Instance();

    _name = settings_instance.db_sqlite_name();

    sqlite3_open(_name.c_str(), &_db);

    const char PRAGMA[] =
        "PRAGMA synchronous = OFF;"
        "PRAGMA encoding = \"UTF-8\";"
        "PRAGMA journal_mode = DELETE;";

    std::string sql = PRAGMA;

    std::string s;
    int rc = sqlite3_exec(_db, sql.c_str(), NULL, &s, NULL);

    if (rc)
    {
        spdlog::error("Error opening SQLite database: {}", sqlite3_errmsg(_db));
        _open = false;
    }
    else
    {
        _open = true;
    }
}

db_sqlite::~db_sqlite()
{
    sqlite3_reset(_stmt);
    sqlite3_finalize(_stmt);
    sqlite3_close(_db);
    _open = false;
}

int callback(void *ret, int size, char **column_text, char **column_name)
{
    if (size == 0)
    {
        return -1;
    }
    auto &container = *static_cast<std::vector<std::string> *>(ret);
    for (int i = 0; i < size; i++)
    {
        if (!column_text[i])
        {
            container.push_back("NULL");
        }
        else
        {
            container.push_back(column_text[i]);
        }
    }
    return 0;
}

bool db_sqlite::answer(std::string const &request, std::vector<std::string> &return_data)
{
    std::vector<std::string> container;

    int rc = sqlite3_exec(_db, request.c_str(), callback, &container, NULL);

    if (rc)
    {
        spdlog::warn("Warn while executing sql query: {}\n {}", request, sqlite3_errmsg(_db));
        return false;
    }

    return_data = container;

    return true;
}