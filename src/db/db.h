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
#ifndef DB_DB_H
#define DB_DB_H

#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

#include "core/settings.h"

class db
{
public:
    static db &instance()
    {
        static db d;
        return d;
    }

    ~db();

    /* Простой запрос, без ответа */
    void request(std::string const &r);

    /* Создаём таблицу/базу */
    void create();

private:
    db();
    db(db const &) = delete;
    db &operator=(db const &) = delete;

    /* Settings initialization */
    settings &_settings_instance = settings::Instance();

    database _db_type = _settings_instance.db();

    // const int _connection_pool_size = _settings_instance.pool_size();
    // const int _connection_pool_size = 16;
    const std::size_t _connection_pool_size = 16;

    // soci::connection_pool _pool = soci::connection_pool(_connection_pool_size);
    soci::connection_pool _pool(_connection_pool_size);

    /* Инициализация базы данных SQLite3 */
    void _initialization_sqlite();
};

#endif // DB_DB_H