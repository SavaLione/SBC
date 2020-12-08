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
 * @brief Список всех страниц
 * @author SavaLione
 * @date 08 Dec 2020
 */
#include "web/page.h"

#include "io/logger.h"

std::string get_page_name(page p)
{
    switch (p)
    {
    case page_about:
        return "/about";
        break;
    case page_index:
        return "/index";
        break;
    case page_login:
        return "/login";
        break;
    case page_nologin:
        return "/nologin";
        break;
    case page_registration:
        return "/registration";
        break;
    default:
        return "/page_not_exist";
        break;
    }
    return "/page_not_exist";
}

page recognize_page(std::string const &unprocessed_page)
{
    spdlog::debug("page: {}", unprocessed_page);
    spdlog::debug("about: {}", unprocessed_page.find(get_page_name(page_about)));
    spdlog::debug("index: {}", unprocessed_page.find(get_page_name(page_index)));
    spdlog::debug("login: {}", unprocessed_page.find(get_page_name(page_login)));

    if (unprocessed_page.find(get_page_name(page_about)) >= 0)
    {
        return page_about;
    }

    if (unprocessed_page.find(get_page_name(page_index)) >= 0)
    {
        return page_index;
    }

    if (unprocessed_page.find(get_page_name(page_login)) >= 0)
    {
        return page_login;
    }

    if (unprocessed_page.find(get_page_name(page_nologin)) >= 0)
    {
        return page_nologin;
    }

    if (unprocessed_page.find(get_page_name(page_registration)) >= 0)
    {
        return page_registration;
    }

    return page_not_exist;
}