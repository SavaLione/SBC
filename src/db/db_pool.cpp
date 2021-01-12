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
#include "db/db_pool.h"

#include "io/logger.h"

db_pool::~db_pool()
{
    close();
}

soci::connection_pool *db_pool::get_pool()
{
    return _pool;
}

bool db_pool::connect(std::string const &connect_string, std::size_t n)
{
    if (_pool != nullptr)
    {
        close();
    }
    int is_connected = 0;

    if (!(_pool = new soci::connection_pool((_pool_size = n))))
    {
        return false;
    }

    try
    {
        soci::indicator ind;
        for (std::size_t i = 0; i < _pool_size; i++)
        {
            soci::session &sql = _pool->at(i);

            /* На каждой сессии открываем соединение с бд */
            sql.open(connect_string);

            /* Проверяем, открыли ли соединение */
            sql << "SELECT 1;", soci::into(is_connected, ind);

            if (!is_connected)
            {
                break;
            }
            else if (i + 1 < _pool_size)
            {
                is_connected = 0;
            }
        }
    }
    catch (const std::exception &e)
    {
        spdlog::error(e.what());
    }

    if (!is_connected)
    {
        close();
    }

    return (_pool != nullptr);
}

bool db_pool::connect(std::string const &backend_name, std::string const &connect_string, std::size_t)
{
    if (_pool != nullptr)
    {
        close();
    }
    int is_connected = 0;

    if (!(_pool = new soci::connection_pool((_pool_size = n))))
    {
        return false;
    }

    try
    {
        soci::indicator ind;
        for (std::size_t i = 0; i < _pool_size; i++)
        {
            soci::session &sql = _pool->at(i);

            /* На каждой сессии открываем соединение с бд */
            sql.open(backend_name, connect_string);

            /* Проверяем, открыли ли соединение */
            sql << "SELECT 1;", soci::into(is_connected, ind);

            if (!is_connected)
            {
                break;
            }
            else if (i + 1 < _pool_size)
            {
                is_connected = 0;
            }
        }
    }
    catch (const std::exception &e)
    {
        spdlog::error(e.what());
    }

    if (!is_connected)
    {
        close();
    }

    return (_pool != nullptr);
}

void db_pool::close()
{
    if (_pool != nullptr)
    {
        try
        {
            for (std::size_t i = 0; i < _pool_size; i++)
            {
                soci::session &sql = _pool->at(i);
                sql.close();
            }
            delete _pool;
            _pool = nullptr;
        }
        catch (const std::exception &e)
        {
            spdlog::error(e.what());
        }
        _pool_size = 0;
    }
}