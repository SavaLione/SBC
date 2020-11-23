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

#include "io/logger.h"

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

    _debug();

    _site_page = _get_site_page();
}

void page::_debug()
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
    case _login:
        _page_login();
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
    if (_document_uri == "/sbc")
    {
        return _index;
    }

    if (_document_uri == "/sbc/login")
    {
        return _login;
    }

    return _unknown;
}

void page::_page_unknown()
{
    FCGX_PutS("<head>\r\n", _request.out);
    FCGX_PutS("<meta http-equiv=\"refresh\" content=\"0; URL=/sbc\" />\r\n", _request.out);
    FCGX_PutS("</head>\r\n", _request.out);
}

void page::_page_index()
{
    FCGX_PutS("Hello!\r\n", _request.out);
    FCGX_PutS("It's index page!\r\n", _request.out);
}

void page::_page_login()
{
    FCGX_PutS("<!doctype html>\r\n", _request.out);
    FCGX_PutS("<html lang=\"en\">\r\n", _request.out);
    FCGX_PutS("  <head>\r\n", _request.out);
    FCGX_PutS("    <meta charset=\"utf-8\">\r\n", _request.out);
    FCGX_PutS("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\r\n", _request.out);
    FCGX_PutS("    <meta name=\"description\" content=\"\">\r\n", _request.out);
    FCGX_PutS("    <meta name=\"author\" content=\"\">\r\n", _request.out);
    FCGX_PutS("    <link rel=\"icon\" href=\"/assets/favicon.ico\">\r\n", _request.out);

    FCGX_PutS("    <title>Signin</title>\r\n", _request.out);

    FCGX_PutS("    <!-- Bootstrap core CSS -->\r\n", _request.out);
    FCGX_PutS("    <!-- <link href=\"../dist/css/bootstrap.min.css\" rel=\"stylesheet\"> -->\r\n", _request.out);
    FCGX_PutS("    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">\r\n", _request.out);

    FCGX_PutS("    <!-- Custom styles for this template -->\r\n", _request.out);
    FCGX_PutS("    <link href=\"/assets/css/signin.css\" rel=\"stylesheet\">\r\n", _request.out);
    FCGX_PutS("  </head>\r\n", _request.out);

    FCGX_PutS("  <body class=\"text-center\">\r\n", _request.out);
    FCGX_PutS("    <form class=\"form-signin\">\r\n", _request.out);
    FCGX_PutS("      <img class=\"mb-4\" src=\"/assets/console.svg\" alt=\"\" width=\"72\" height=\"72\">\r\n", _request.out);
    FCGX_PutS("      <h1 class=\"h3 mb-3 font-weight-normal\">Please sign in</h1>\r\n", _request.out);
    FCGX_PutS("      <label for=\"inputEmail\" class=\"sr-only\">Email address</label>\r\n", _request.out);
    FCGX_PutS("      <input type=\"email\" id=\"inputEmail\" class=\"form-control\" placeholder=\"Email address\" required autofocus>\r\n", _request.out);
    FCGX_PutS("      <label for=\"inputPassword\" class=\"sr-only\">Password</label>\r\n", _request.out);
    FCGX_PutS("      <input type=\"password\" id=\"inputPassword\" class=\"form-control\" placeholder=\"Password\" required>\r\n", _request.out);
    FCGX_PutS("      <div class=\"checkbox mb-3\">\r\n", _request.out);
    FCGX_PutS("        <label>\r\n", _request.out);
    FCGX_PutS("          <input type=\"checkbox\" value=\"remember-me\"> Remember me\r\n", _request.out);
    FCGX_PutS("        </label>\r\n", _request.out);
    FCGX_PutS("      </div>\r\n", _request.out);
    FCGX_PutS("      <button class=\"btn btn-lg btn-primary btn-block\" type=\"submit\">Sign in</button>\r\n", _request.out);
    FCGX_PutS("      <p class=\"mt-5 mb-3 text-muted\">&copy; 2020 SavaLione</p>\r\n", _request.out);
    FCGX_PutS("    </form>\r\n", _request.out);
    FCGX_PutS("  </body>\r\n", _request.out);
    FCGX_PutS("</html>\r\n", _request.out);
}