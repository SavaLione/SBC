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
 * @brief Web page
 * @author SavaLione
 * @date 22 Nov 2020
 */
#include "web/page.h"

#include "web/mime.h"

page::~page()
{
}

void page::_init()
{
    if (FCGX_GetParam("HTTP_COOKIE", _request.envp) != NULL)
    {
        _http_cookie = FCGX_GetParam("HTTP_COOKIE", _request.envp);
        _cookie = true;
    }
    else
    {
        _http_cookie = "NULL";
        _cookie = false;
    }

    _site_page = _get_site_page();
}

void page::show()
{
    _web_header();

    switch (_site_page)
    {
    case _unknown:
        _page_unknown();
        break;
    case _index:
        _page_index();
        break;
    default:
        _page_unknown();
        break;
    }
}

void page::_web_header()
{
    FCGX_PutS(mime_type(text_html), _request.out);
}

site_pages const page::_get_site_page()
{
    if (_request_uri == "/")
    {
        return _index;
    }

    return _unknown;
}

void page::_page_unknown()
{
    FCGX_PutS("<head>\r\n", _request.out);
    FCGX_PutS("<meta http-equiv=\"refresh\" content=\"0; URL=/\" />\r\n", _request.out);
    FCGX_PutS("</head>\r\n", _request.out);
}

void page::_page_index()
{
    FCGX_PutS("Hello!\r\n", _request.out);
    FCGX_PutS("It's index page!\r\n", _request.out);
}