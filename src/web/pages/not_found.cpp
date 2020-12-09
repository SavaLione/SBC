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
 * @brief Страница не найдена
 * @author SavaLione
 * @date 09 Dec 2020
 */
#include "web/pages/not_found.h"

not_found::~not_found()
{
}

void not_found::_head()
{
    _add_content("  <head>");

    _add_content("    <meta charset=\"utf-8\">");
    _add_content("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("    <meta name=\"description\" content=\"SBC\">");
    _add_content("    <meta name=\"author\" content=\"SBC team\">");
    _add_content("    <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("    <title>Страница не найдена</title>");

    _add_content("    <!-- Bootstrap core CSS -->");
    _add_content("    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");

    _add_content("    <!--  Page not found css -->");
    _add_content("    <link href=\"/assets/css/not_found.css\" rel=\"stylesheet\">");

    _add_content("  </head>");
}

void not_found::_body()
{
    _add_content("  <div class=\"d-flex justify-content-center align-items-center\" id=\"main\">");
    _add_content("      <h1 class=\"mr-3 pr-3 align-top border-right inline-block align-content-center\"><a href=\"/index\">404</a></h1>");
    _add_content("      <div class=\"inline-block align-middle\">");
    _add_content("      	<h2 class=\"font-weight-normal lead\" id=\"desc\">Запрошенная вами страница не найдена.</h2>");
    _add_content("      </div>");
    _add_content("  </div>");
}