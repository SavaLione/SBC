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
 * @brief Тест некоторых функций
 * @author SavaLione
 * @date 13 Dec 2020
 */
#include "test/sbc_db_test.h"

#include <thread>

void start_db()
{
    db_n &db_instance = db_n::instance();
}

void test_single_thread()
{
    db_n &db_instance = db_n::instance();

    for (size_t i = 0; i < I_COUNT_OPERATIONS; i++)
    {
        db_instance.execute(S_SELECT_QUERY);
    }
    
}

int main()
{
    execution_time et;
    start_db();

    et.start();
    test_single_thread();
    spdlog::info("Time: {}", et.s_duration());

    return 0;
}

db_n::db_n()
{
    spdlog::info("Start db");
    try
    {
        for (int i = 0; i != _pool_size; ++i)
        {
            soci::session &sql = _pool.at(i);

            sql.open("sqlite3", "test.db");
        }
    }
    catch (const std::exception &e)
    {
        spdlog::error(e.what());
    }
}

db_n::~db_n()
{
}

const void db_n::execute(std::string const &query)
{
    soci::session sql(_pool);

    sql << query;
}