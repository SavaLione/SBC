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

#include <vector>

cookie::~cookie()
{
}

cookie_pair cookie::get_uuid()
{
    return _uuid;
}

void cookie::_init()
{
    _get(_uuid);
}

void cookie::_get(cookie_pair &c)
{
    /*
        Тут возможно нетепичное поведение, когда pos будет равна FFFFFFFF,
        хотя подстроки нет.
        Можно использовать != std::string::npos , но тогда мы будем проверять два
        раза на нахождение. Возможно есть алгоритм лучше. Надо будет исправить при
        следующей работе с cookie.

        upd:
        После проверки, при отсутствии значения, pos был равен -1
    */
    int pos = _unprocessed_cookies.find(c.key);
    if (pos >= 0)
    {
        for (int i = pos + c.key.size() + 1; i < _unprocessed_cookies.size(); i++)
        {
            if (_unprocessed_cookies[i] != _separator)
            {
                c.value += _unprocessed_cookies[i];
            }
            else
            {
                break;
            }
        }
        c.set = true;
    }
    else
    {
        c.set = false;
    }
}

void cookie::set_uuid(cookie_pair const &uuid)
{
    _uuid.value = uuid.value;
    _uuid.set = true;
}

void cookie::set(std::string const &unprocessed_cookies)
{
    _unprocessed_cookies = unprocessed_cookies;
    _init();
}

std::string cookie::get()
{
    std::vector<std::string> params;
    std::string result = "";

    if (_author.set)
    {
        std::string res = "";
        res += "Set-Cookie: ";
        res += _author.key;
        res += "=";
        res += _author.value;
        res += "; ";
        params.push_back(res);
    }

    if (_uuid.set)
    {
        std::string res = "";
        res += _uuid.key;
        res += "=";
        res += _uuid.value;
        res += "; ";
        params.push_back(res);
    }

    for (int i = 0; i < params.size(); i++)
    {
        result += params[i];

        if (i != (params.size() - 1))
        {
            result += "\n";
        }
    }

    return result;
}