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
 * @brief Page template
 * @author SavaLione
 * @date 07 Dec 2020
 */
#include "web/pages/page_template.h"

#include "io/logger.h"

page_template::~page_template()
{
}

std::string page_template::_get_name()
{
    return _name;
}

void page_template::_add_content(std::string content)
{
    std::string s = content;
    s += "\r\n";
    FCGX_PutS(s.c_str(), _request.out);
}

void page_template::_html_header()
{
    _add_content(mime_type(_mime));
    _add_content("Set-Cookie: author=SavaLione;");
    _add_content("");
}

void page_template::debug()
{
    spdlog::debug("REQUEST_METHOD: [{}]", _request_method);
    spdlog::debug("CONTENT_LENGTH: [{}]", _content_length);
    spdlog::debug("REMOTE_ADDR: [{}]", _remote_addr);
    spdlog::debug("REQUEST_URI: [{}]", _request_uri);
    spdlog::debug("QUERY_STRING: [{}]", _query_string);
    spdlog::debug("DOCUMENT_URI: [{}]", _document_uri);
    spdlog::debug("DOCUMENT_ROOT: [{}]", _document_root);
    spdlog::debug("HTTP_HOST: [{}]", _http_host);
    spdlog::debug("HTTP_COOKIE: [{}]", _http_cookie);
}

void page_template::_html()
{
    _add_content("<!doctype html>");
    _add_content("<html lang=\"en\">");
}

void page_template::_head()
{
    _add_content("<head>");

    _add_content("<meta charset=\"utf-8\">");
    _add_content("");
    _add_content("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("<meta name=\"description\" content=\"\">");
    _add_content("<meta name=\"author\" content=\"SavaLione\">");
    _add_content("<link rel=\"icon\" href=\"assets/favicon.ico\">");
    _add_content("");
    {
        std::string s = "<title>";
        s += _name;
        s += "</title>";
        _add_content(s);
    }
    _add_content("");
    _add_content("<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");
    _add_content("");
    _add_content("<link href=\"assets/css/form-validation.css\" rel=\"stylesheet\">");
    _add_content("");

    _add_content("</head>");
}

void page_template::_body()
{
}

void page_template::_init()
{
    if (FCGX_GetParam("HTTP_COOKIE", _request.envp) != NULL)
    {
        _http_cookie = FCGX_GetParam("HTTP_COOKIE", _request.envp);
        _is_cookie_set = true;
    }
    else
    {
        _http_cookie = "NULL";
        _is_cookie_set = false;
    }

    _get_method();
}

void page_template::_get_method()
{
    if (_request_method == "OPTIONS")
    {
        _method = _OPTIONS;
        return;
    }

    if (_request_method == "GET")
    {
        _method = _GET;
        return;
    }

    if (_request_method == "HEAD")
    {
        _method = _HEAD;
        return;
    }

    if (_request_method == "POST")
    {
        _method = _POST;
        return;
    }

    if (_request_method == "PUT")
    {
        _method = _PUT;
        return;
    }

    if (_request_method == "DELETE")
    {
        _method = _DELETE;
        return;
    }

    if (_request_method == "TRACE")
    {
        _method = _TRACE;
        return;
    }

    if (_request_method == "CONNECT")
    {
        _method = _CONNECT;
        return;
    }
}

void page_template::show()
{
    _init();

    _html_header();

    _html();
    _head();
    _body();

    _add_content("</html>");
}