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
 * @brief Страница авторизации
 * @author SavaLione
 * @date 08 Dec 2020
 */
#include "web/pages/login.h"

login::~login()
{
}

void login::_head()
{
    _add_content("  <head>");

    _add_content("    <meta charset=\"utf-8\">");
    _add_content("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("    <meta name=\"description\" content=\"\">");
    _add_content("    <meta name=\"author\" content=\"\">");
    _add_content("    <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("    <title>Signin</title>");

    _add_content("    <!-- Bootstrap core CSS -->");
    _add_content("    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");

    _add_content("    <!-- Custom styles -->");
    _add_content("    <link href=\"/assets/css/signin.css\" rel=\"stylesheet\">");

    _add_content("  </head>");
}

void login::_body()
{
    _add_content("  <body class=\"text-center\">");

    _add_content("    <form method=POST class=\"form-signin\">");
    _add_content("      <img class=\"mb-4\" src=\"/assets/console.svg\" alt=\"\" width=\"72\" height=\"72\">");
    _add_content("      <h1 class=\"h3 mb-3 font-weight-normal\">Please sign in</h1>");
    _add_content("      <label for=\"inputEmail\" class=\"sr-only\">Email address</label>");
    _add_content("      <input type=\"email\" id=\"inputEmail\" class=\"form-control\" placeholder=\"Email address\" required autofocus>");
    _add_content("      <label for=\"inputPassword\" class=\"sr-only\">Password</label>");
    _add_content("      <input type=\"password\" id=\"inputPassword\" class=\"form-control\" placeholder=\"Password\" required>");
    _add_content("      <div class=\"checkbox mb-3\">");
    _add_content("        <label>");
    _add_content("          <input type=\"checkbox\" value=\"remember-me\"> Remember me");
    _add_content("        </label>");
    _add_content("      </div>");
    _add_content("      <button class=\"btn btn-lg btn-primary btn-block\" type=\"submit\">Sign in</button>");
    _add_content("      <p class=\"mt-5 mb-3 text-muted\">&copy; 2020 SBC team</p>");
    _add_content("    </form>");
    
    _add_content("  </body>");
}