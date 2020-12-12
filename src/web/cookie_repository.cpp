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
 * @brief Cookie repository
 * @author SavaLione
 * @date 08 Dec 2020
 */
#include "web/cookie_repository.h"

#include "io/logger.h"

cookie_repository::cookie_repository()
{
    spdlog::info("Cookie initialization");
}

cookie_repository::~cookie_repository()
{
}

const void cookie_repository::add(user const &u)
{
    _users.push_back(u);
}

const void cookie_repository::remove(user const &u)
{
    bool uuid_set = false;
    bool username_set = false;

    /* Проверяем, указан ли uuid */
    if (!u._uuid.empty())
    {
        /* uuid указан */
        uuid_set = true;
    }

    /* Проверяем, указан ли username */
    if (!u._username.empty())
    {
        /* username указан */
        username_set = true;
    }

    /* Проверяем, указан ли uuid и username */
    if (!uuid_set && !username_set)
    {
        /* uuid и username не установлены */
        return;
    }

    for (int i = 0; i < _users.size(); i++)
    {
        if (uuid_set)
        {
            if (_users[i]._uuid == u._uuid)
            {
                _users.erase(_users.begin() + i);
                break;
            }
        }

        if (username_set)
        {
            if (_users[i]._username == u._username)
            {
                _users.erase(_users.begin() + i);
                break;
            }
        }
    }
}

void cookie_repository::debug()
{
    spdlog::debug("cookie_repository users: {}", _users.size());
    for (int i = 0; i < _users.size(); i++)
    {
        spdlog::debug("--- {} ---", i);
        spdlog::debug("username: {}", _users[i]._username);
        spdlog::debug("name: {}", _users[i]._name);
        spdlog::debug("uuid: {}", _users[i]._uuid);
    }
}

void cookie_repository::get(user &u)
{
    bool uuid_set = false;
    bool username_set = false;

    /* Проверяем, указан ли uuid */
    if (!u._uuid.empty())
    {
        /* uuid указан */
        uuid_set = true;
    }

    /* Проверяем, указан ли username */
    if (!u._username.empty())
    {
        /* username указан */
        username_set = true;
    }

    /* Проверяем, указан ли uuid и username */
    if (!uuid_set && !username_set)
    {
        /* uuid и username не установлены */
        return;
    }
    else
    {
        for (int i = 0; i < _users.size(); i++)
        {
            if (uuid_set)
            {
                if (_users[i]._uuid == u._uuid)
                {
                    u = _users[i];

                    u._user_status = USER_STATUS_SET;

                    return;
                }
            }

            if (username_set)
            {
                if (_users[i]._username == u._username)
                {
                    u = _users[i];

                    u._user_status = USER_STATUS_SET;

                    return;
                }
            }
        }
    }
}