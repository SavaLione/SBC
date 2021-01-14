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
 * @brief Settings
 * @author SavaLione
 * @date 16 Nov 2020
 */
#include "core/settings.h"

#include "io/logger.h"

settings::settings()
{
    spdlog::info("Settings initialization");
}

settings::~settings()
{
}

log_level settings::l_level()
{
    return _l_level;
}

std::string settings::ip()
{
    return _ip;
}

int settings::port()
{
    return _port;
}

std::string settings::fcgi_socket_path()
{
    std::string ret = _fcgi_socket_address;
    ret += ":";
    ret += _fcgi_socket_port;
    return ret;
}

int settings::fcgi_thread_count()
{
    return _fcgi_thread_count;
}

database settings::db()
{
    return _db;
}

std::string settings::db_host()
{
    return _db_host;
}

std::string settings::db_name()
{
    return _db_name;
}

std::string settings::db_username()
{
    return _db_username;
}

std::string settings::db_password()
{
    return _db_password;
}

std::string settings::db_sqlite_name()
{
    return _db_sqlite_name;
}

const std::string settings::db_sqlite_pragma()
{
    return get_sqlite_synchronous(_db_sqlite_synchronous) + get_sqlite_encoding(_db_sqlite_encoding) + get_sqlite_journal_mode(_db_sqlite_journal_mode);
}

const int settings::db_soci_pool_size()
{
    return _db_soci_pool_size;
}

hash settings::password_hash()
{
    return _password_hash;
}

const int settings::pool_size()
{
    return _pool_size;
}

std::string settings::string_db_name()
{
    switch (_db)
    {
    case ORACLE:
        return "oracle";
        break;
    case POSTGRESQL:
        return "postgresql";
        break;
    case MYSQL:
        return "mysql";
        break;
    case MARIADB:
        return "mysql";
        break;
    case SQLITE3:
        return "sqlite3";
        break;
    /* В документации soci такого нет */
    case FIREBIRD:
        return "firebird";
        break;
    /* В документации soci такого нет */
    case ODBC:
        return "odbc";
        break;
    /* В документации soci такого нет */
    case DB2:
        return "db2";
        break;
    default:
        /* Стандартная база данных sqlite3 */
        return "sqlite3";
        break;
    }

    /* Стандартная база данных sqlite3 */
    return "sqlite3";
}

application_level settings::app_level()
{
    return _app_level;
}