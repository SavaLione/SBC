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
#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

#include <string>

#include "db/sqlite/sqlite_encoding.h"
#include "db/sqlite/sqlite_journal_mode.h"
#include "db/sqlite/sqlite_synchronous.h"

enum database
{
    SQLITE = 1,
    MYSQL = 2,
    MARIADB = 3,
    POSTGRESQL = 4
};

enum log_level
{
    TRACE = 1,
    DEBUG = 2,
    INFO = 3,
    WARN = 4,
    ERROR = 5,
    CRITICAL = 6
};

class settings
{
public:
    static settings &Instance()
    {
        static settings s;
        return s;
    }

    ~settings();

    log_level l_level();

    std::string ip();
    int port();

    std::string fcgi_socket_path();
    int fcgi_thread_count();

    database db();
    std::string db_host();
    std::string db_name();
    std::string db_username();
    std::string db_password();

    /* Получить название базы данных sqlite */
    std::string db_sqlite_name();

    /* Получить переменные SQLite */
    const std::string db_sqlite_pragma();

private:
    settings();
    settings(settings const &) = delete;
    settings &operator=(settings const &) = delete;

    // log_level _L_level = INFO;
    /* На время разработки SBC */
    log_level _l_level = DEBUG;

    /* ip sbc сервера */
    std::string _ip = "0.0.0.0";

    /* Порт sbc сервера */
    int _port = 12340;
    
    /* ip FastCGI сервера */
    std::string _fcgi_socket_address = "127.0.0.1";

    /* Порт FastCGI сервера */
    std::string _fcgi_socket_port = "9000";

    /* Количество FastCGI потоков */
    int _fcgi_thread_count = 8;

    /* Тип базы данных */
    database _db = SQLITE;

    /* Адрес базы данных (если база данных не встраиваемая) */
    std::string _db_host = "tcp://127.0.0.1:3306";

    /* Имя пользователя базы данных (если база данных не встраиваемая) */
    std::string _db_username = "username";

    /* Пароль пользователя базы данных (если база данных не встраиваемая) */
    std::string _db_password = "password";

    /* Имя базы данных (если база данных не встраиваемая) */
    std::string _db_name = "db_name";

    /* Название встраиваемой базы данных SQLite */
    std::string _db_sqlite_name = "db_sbc.db";

    /* Тип синхронизации базы данных SQLite */
    sqlite_synchronous _db_sqlite_synchronous = SQLITE_SYNCHRONOUS_OFF;

    /* Кодировка базы данных SQLite */
    sqlite_encoding _db_sqlite_encoding = SQLITE_ENCODING_UTF_8;

    /* Тип журнала базы данных SQLite */
    sqlite_journal_mode _db_sqlite_journal_mode = SQLITE_JOURNAL_MODE_DELETE;

};

#endif // CORE_SETTINGS_H