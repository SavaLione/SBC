/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
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
 * @brief Пул для работы с базой данных
 * @author SavaLione
 * @date 12 Jan 2021
 */
#ifndef DB_DB_POOL_H
#define DB_DB_POOL_H

#include <soci/soci.h>
#include <soci/connection-pool.h>

#include <string>

class db_pool
{
public:
    db_pool() : _pool(nullptr), _pool_size(0){};
    ~db_pool(close(););

    soci::connection_pool *get_pool();

    /*
        Подключение к базе данных
        connect_string - строка с параметрами для подключения
    */
    bool connect(std::string const &connect_string, std::size_t n = 8);

    /*
        Подключение к базе данных
        backend_name - название базы данных
        connect_string - строка с параметрами для подключения
    */
    bool connect(std::string const &backend_name, std::string const &connect_string, std::size_t n = 8);

    /* Закрытие соединений в пуле */
    void close();

private:
    /* Пул */
    soci::connection_pool *_pool;

    /* Размер пула */
    std::size_t _pool_size;
};

#endif // DB_DB_POOL_H