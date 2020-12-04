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
 * @brief Cookie
 * @author SavaLione
 * @date 24 Nov 2020
 */

#include "web/cookie.h"

#include "io/logger.h"

cookie::cookie()
{
    spdlog::info("Cookie initialization");
}

cookie::~cookie()
{
}

const void cookie::add_user(user &u)
{
    _users.push_back(u);
}

const void cookie::remove_user(std::string uuid)
{
    for (int i = 0; i < _users.size(); i++)
    {
        if (_users[i].get_uuid() == uuid)
        {
            _users.erase(_users.begin() + i);
            break;
        }
    }
}

bool cookie::have_user(std::string uuid)
{
    for (int i = 0; i < _users.size(); i++)
    {
        if (_users[i].get_uuid() == uuid)
        {
            return true;
        }
    }
    return false;
}

user cookie::get_user(std::string uuid)
{
    for (int i = 0; i < _users.size(); i++)
    {
        if (_users[i].get_uuid() == uuid)
        {
            return _users[i];
        }
    }
    user u;
    return u;
}

void cookie::debug()
{
    spdlog::debug("cookie users: {}", _users.size());
    for (int i = 0; i < _users.size(); i++)
    {
        spdlog::debug("---cookie--[{}]", i);
        spdlog::debug("name: {}", _users[i].get_name());
        spdlog::debug("username: {}", _users[i].get_username());
        spdlog::debug("uuid: {}", _users[i].get_uuid());
    }
    
}