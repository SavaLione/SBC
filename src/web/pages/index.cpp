/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
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
 * @brief Главная страница сайта
 * @author SavaLione
 * @date 15 Dec 2021
 */
#include "web/pages/index.h"

index::~index()
{
}

void index::_head()
{
    _add_content("<head>");
    _add_content("  <meta charset=\"utf-8\">");
    _add_content("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("  <meta name=\"description\" content=\"\">");
    _add_content("  <meta name=\"author\" content=\"\">");
    _add_content("  <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("  <title>SBC project home page</title>");

    _add_content("  <!-- Bootstrap core CSS -->");
    _add_content("  <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");

    _add_content("  <!-- Custom styles -->");
    _add_content("  <link href=\"/assets/css/index.css\" rel=\"stylesheet\">");
    _add_content("</head>");
}

void index::_body()
{
    _add_content("<body class=\"text-center\">");
    _add_content("  <div class=\"cover-container d-flex h-100 p-3 mx-auto flex-column\">");
    _add_content("    <header class=\"masthead mb-auto\">");
    _add_content("      <div class=\"inner\">");
    _add_content("        <h3 class=\"masthead-brand\">Scanning bar codes</h3>");
    _add_content("        <nav class=\"nav nav-masthead justify-content-center\">");
    _add_content("          <a class=\"nav-link active\" href=\"/index\">Home</a>");
    _add_content("          <a class=\"nav-link\" href=\"/about\">About</a>");
    _add_content("          <a class=\"nav-link\" href=\"/install\">Install</a>");
    _add_content("          <a class=\"nav-link\" href=\"/terms\">Terms</a>");
    
    if (_user._user_status == USER_STATUS_SET)
    {
        _add_content("          <!-- if authorized -->");
        _add_content("          <a class=\"nav-link\" href=\"/dashboard\">Dashboard</a>");
        _add_content("          <a class=\"nav-link\" href=\"/exit\">Exit</a>");
        _add_content("          <!-- /if authorized -->");
    }

    _add_content("        </nav>");
    _add_content("      </div>");
    _add_content("    </header>");

    _add_content("    <main role=\"main\" class=\"inner cover\">");
    _add_content("      <h1 class=\"cover-heading\">SBC project.</h1>");
    _add_content("      <p class=\"lead\">The project was created to simplify the logistics process, mainly targeted at small companies that cannot, for financial reasons, afford the integration of such giants as 1C. The project is a completely independent solution and does not provide an opportunity for implementation into other systems.</p>");
    _add_content("      <p class=\"lead\">");
    _add_content("        <a href=\"/about\" class=\"btn btn-lg btn-secondary\">Learn more</a>");
    _add_content("      </p>");
    _add_content("    </main>");

    _add_content("    <footer class=\"mastfoot mt-auto\">");
    _add_content("      <div class=\"inner\">");
    _add_content("        <p>Copyright &copy; 2021 <a href=\"https://github.com/savalione/sbc/\">SBC</a>.</p>");
    _add_content("      </div>");
    _add_content("    </footer>");
    _add_content("  </div>");

    _add_content("  <!-- Bootstrap core JavaScript");
    _add_content("    ================================================== -->");
    _add_content("  <!-- Placed at the end of the document so the pages load faster -->");
    _add_content("  <script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\" crossorigin=\"anonymous\"></script>");
    _add_content("  <script>");
    _add_content("    window.jQuery || document.write('<script src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.5.1/jquery.slim.min.js\" integrity=\"sha512-/DXTXr6nQodMUiq+IUJYCt2PPOUjrHJ9wFrqpJ3XkgPNOZVfMok7cRw6CSxyCQxXn6ozlESsSh1/sMCTF1rL/g==\" crossorigin=\"anonymous\"><\\/script>')");
    _add_content("  </script>");
    _add_content("  <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/2.6.0/umd/popper.min.js\" integrity=\"sha512-BmM0/BQlqh02wuK5Gz9yrbe7VyIVwOzD1o40yi1IsTjriX/NGF37NyXHfmFzIlMmoSIBXgqDiG1VNU6kB5dBbA==\" crossorigin=\"anonymous\"></script>");
    _add_content("  <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js\" integrity=\"sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV\" crossorigin=\"anonymous\"></script>");
    _add_content("</body>");
}