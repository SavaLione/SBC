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
 * @brief SBC server
 * @author SavaLione
 * @date 15 Nov 2020
 */

#include <thread>

#include "core/settings.h"
#include "core/uuid.h"
#include "core/user.h"

#include "io/logger.h"

#include "net/server.h"

#include "db/db_sqlite.h"
#include "db/db.h"

#include "web/web.h"
#include "web/mime.h"
#include "web/cookie_repository.h"

#include "time/execution_time.h"

void web_server()
{
    spdlog::info("Start web FastCGI server.");
    web *web_f = new web();

    delete web_f;
}

void sbc_server()
{
    settings &settings_instance = settings::Instance();

    spdlog::info("Start SBC server.");

    try
    {
        boost::asio::io_context io_context;
        server s(io_context, settings_instance.port());
        io_context.run();
    }
    catch (const std::exception &e)
    {
        spdlog::error("SBC server exception: {}", e.what());
    }
}

void sbc_console()
{
    spdlog::info("Start SBC console.");

    for (std::string line; std::cout << " >" && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == "exit")
            {
                exit(0);
            }
        }
    }
}

void sbc_test()
{
    spdlog::info("Start SBC test.");

    /* cookie */
    cookie_repository &cookie_instance = cookie_repository::Instance();

    cookie_instance.debug();

    {
        user savalione;
        savalione._username = "SavaLione";
        savalione._name = "Sava Lione";
        savalione._uuid = "aa-bb-cc-dd";

        cookie_instance.add(savalione);
    }

    /* testuser */
    user testuser;
    testuser._username = "testname";
    testuser._name = "Test User";
    testuser._uuid = "cc-cc-cc-cc";

    cookie_instance.add(testuser);
    /* testuser */

    cookie_instance.debug();

    {
        user some;
        some._username = "some";
        some._name = "Some User Name";
        some._uuid = "dd-dd-dd-dd";

        cookie_instance.add(some);
    }

    cookie_instance.debug();

    //cookie_instance.remove(testuser);

    cookie_instance.debug();
}

void sbc_test_cookie()
{
    spdlog::info("Start SBC cookie test.");
}

void sbc_test_db()
{
    spdlog::info("Start SBC db test.");

    execution_time et;

    spdlog::debug("START");
    et.start();
    db_test_open();
    spdlog::debug("STOP");
    spdlog::debug("Time: {}", et.s_duration);
    spdlog::debug("-----------------");
}

int main(int argc, char *argv[])
{
    /* Logger initialization */
    logger_init();

    /* Settings initialization */
    settings &settings_instance = settings::Instance();

    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    /* cookie_repository */
    cookie_repository &cookie_repository_instance = cookie_repository::Instance();

    /* Запуск web сервера */
    std::thread thread_web_server(web_server);

    /* Запуск sbc сервера */
    std::thread thread_sbc_server(sbc_server);

    /* Запуск консоли */
    std::thread thread_sbc_console(sbc_console);

    /* Тестирование некоторых функций */
    std::thread thread_sbc_test(sbc_test);
    std::thread thread_sbc_test_cookie(sbc_test_cookie);
    std::thread thread_sbc_test_db(sbc_test_db);

    if (thread_web_server.joinable())
    {
        thread_web_server.join();
        spdlog::info("Stop web FastCGI server.");
    }

    if (thread_sbc_server.joinable())
    {
        thread_sbc_server.join();
        spdlog::info("Stop SBC server.");
    }

    if (thread_sbc_console.joinable())
    {
        thread_sbc_console.join();
        spdlog::info("Stop SBC console.");
    }

    if (thread_sbc_test.joinable())
    {
        thread_sbc_test.join();
        spdlog::info("Stop SBC test.");
    }

    if (thread_sbc_test_cookie.joinable())
    {
        thread_sbc_test_cookie.join();
        spdlog::info("Stop SBC cookie test.");
    }

    if (thread_sbc_test_db.joinable())
    {
        thread_sbc_test_db.join();
        spdlog::info("Stop SBC db test.");
    }

    return 0;
}
