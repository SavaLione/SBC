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
 * @brief Страница регистрации
 * @author SavaLione
 * @date 14 Jan 2021
 */
#include "web/pages/registration.h"

registration::~registration()
{
}

void registration::_head()
{
    _add_content("<head>");

    _add_content("  <meta charset=\"utf-8\">");
    _add_content("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("  <meta name=\"description\" content=\"\">");
    _add_content("  <meta name=\"author\" content=\"\">");
    _add_content("  <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("  <title>Registration</title>");

    _add_content("  <!-- Bootstrap core CSS -->");
    _add_content("  <!-- <link href=\"../dist/css/bootstrap.min.css\" rel=\"stylesheet\"> -->");
    _add_content("  <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");

    _add_content("  <!-- Custom styles for this template -->");
    _add_content("  <link href=\"/assets/css/registration.css\" rel=\"stylesheet\">");

    _add_content("</head>");
}

void registration::_body()
{
    if (_user._user_status == USER_STATUS_SET)
    {
        /* Пользователь уже есть в системе */
        _add_content("  <body class=\"text-center\">");

        _add_content("<div class=\"form-signin\">");
        _add_content("      <img class=\"mb-4\" src=\"/assets/console.svg\" alt=\"\" width=\"72\" height=\"72\">");
        _add_content("      <h1 class=\"h3 mb-3 font-weight-normal\">Вы уже зарегистрированы в системе</h1>");
        _add_content("      <a href=\"/index\" class=\"btn btn-lg btn-primary btn-block\" role=\"button\">Перейти на главную страницу</a>");
        _add_content("      <p class=\"mt-5 mb-3 text-muted\">&copy; 2020 SBC team</p>");
        _add_content("</div>");

        _add_content("  </body>");
    }
    else
    {
        /* Пользователя нет в системе */
        _add_content("<body class=\"bg-light\">");
        _add_content("  <form method=\"post\" class=\"form-signin\">");

        _add_content("    <div class=\"container\">");
        _add_content("      <div class=\"py-5 text-center\">");
        _add_content("        <img class=\"d-block mx-auto mb-4\" src=\"/assets/console.svg\" alt=\"\" width=\"72\" height=\"72\">");
        _add_content("        <h2>Registration form</h2>");
        _add_content("        <p class=\"lead\">Registration form for SBC service.</p>");
        _add_content("      </div>");

        _add_content("      <div class=\"row\">");

        _add_content("        <div class=\"col-md-12 order-md-1\">");
        _add_content("          <h4 class=\"mb-3\">User data</h4>");
        _add_content("          <form class=\"needs-validation\" novalidate>");
        _add_content("            <div class=\"row\">");
        _add_content("              <div class=\"col-md-4 mb-3\">");
        _add_content("                <label for=\"lastName\">Last name</label>");
        _add_content("                <input type=\"text\" class=\"form-control\" id=\"input_last_name\" placeholder=\"\" value=\"\" required>");
        _add_content("                <div class=\"invalid-feedback\">");
        _add_content("                  Valid last name is required.");
        _add_content("                </div>");
        _add_content("              </div>");
        _add_content("              <div class=\"col-md-4 mb-3\">");
        _add_content("                <label for=\"firstName\">First name</label>");
        _add_content("                <input type=\"text\" class=\"form-control\" id=\"input_first_name\" placeholder=\"\" value=\"\" required>");
        _add_content("                <div class=\"invalid-feedback\">");
        _add_content("                  Valid first name is required.");
        _add_content("                </div>");
        _add_content("              </div>");
        _add_content("              <div class=\"col-md-4 mb-3\">");
        _add_content("                <label for=\"middleName\">Middle name</label>");
        _add_content("                <input type=\"text\" class=\"form-control\" id=\"input_middle_name\" placeholder=\"\" value=\"\" required>");
        _add_content("                <div class=\"invalid-feedback\">");
        _add_content("                  Valid middle name is required.");
        _add_content("                </div>");
        _add_content("              </div>");
        _add_content("            </div>");

        _add_content("            <div class=\"mb-3\">");
        _add_content("              <label for=\"username\">Username</label>");
        _add_content("              <div class=\"input-group\">");
        _add_content("                <div class=\"input-group-prepend\">");
        _add_content("                  <span class=\"input-group-text\">@</span>");
        _add_content("                </div>");
        _add_content("                <input type=\"text\" class=\"form-control\" id=\"input_username\" placeholder=\"Username\" required>");
        _add_content("                <div class=\"invalid-feedback\" style=\"width: 100%;\">");
        _add_content("                  Your username is required.");
        _add_content("                </div>");
        _add_content("              </div>");
        _add_content("            </div>");

        _add_content("            <div class=\"mb-3\">");
        _add_content("              <label for=\"email\">Email <span class=\"text-muted\"></span></label>");
        _add_content("              <input type=\"email\" class=\"form-control\" id=\"input_email\" placeholder=\"you@example.com\" required>");
        _add_content("              <div class=\"invalid-feedback\">");
        _add_content("                Please enter a valid email address for shipping updates.");
        _add_content("              </div>");
        _add_content("            </div>");

        _add_content("            <hr class=\"mb-4\">");

        _add_content("            <div class=\"mb-3\">");
        _add_content("              <label for=\"address\">Address <span class=\"text-muted\">(Optional)</span></label>");
        _add_content("              <input type=\"text\" class=\"form-control\" id=\"input_address\" placeholder=\"1234 Main St\">");
        _add_content("              <div class=\"invalid-feedback\">");
        _add_content("                Your address.");
        _add_content("              </div>");
        _add_content("            </div>");

        _add_content("            <div class=\"mb-3\">");
        _add_content("              <label for=\"address2\">phone <span class=\"text-muted\">(Optional)</span></label>");
        _add_content("              <input type=\"text\" class=\"form-control\" id=\"input_phone\" placeholder=\"Phone number\">");
        _add_content("            </div>");

        _add_content("            <div class=\"row\">");
        _add_content("              <div class=\"col-md-5 mb-3\">");
        _add_content("                <label for=\"country\">Branch of the company <span class=\"text-muted\">(Optional)</span></label>");
        _add_content("                <select class=\"custom-select d-block w-100\" id=\"input_branch\">");
        _add_content("                  <option value=\"\">Not set</option>");
        _add_content("                  <option>Yekaterinburg</option>");
        _add_content("                  <option>Moscow</option>");
        _add_content("                  <option>St. Petersburg</option>");
        _add_content("                  <option>Not on the list</option>");
        _add_content("                </select>");
        _add_content("                <div class=\"invalid-feedback\">");
        _add_content("                  Please select a valid branch of the company.");
        _add_content("                </div>");
        _add_content("              </div>");
        _add_content("              <div class=\"col-md-4 mb-3\">");
        _add_content("                <label for=\"state\">The Department</label>");
        _add_content("                <select class=\"custom-select d-block w-100\" id=\"input_department\">");
        _add_content("                  <option value=\"\">Not set</option>");
        _add_content("                  <option value=\"\">Delivery</option>");
        _add_content("                  <option>Unpacking</option>");
        _add_content("                  <option>Packaging</option>");
        _add_content("                  <option>Sales</option>");
        _add_content("                </select>");
        _add_content("                <div class=\"invalid-feedback\">");
        _add_content("                  Please provide a valid department.");
        _add_content("                </div>");
        _add_content("              </div>");
        _add_content("            </div>");
        _add_content("            <hr class=\"mb-4\">");
        _add_content("            <div class=\"custom-control custom-checkbox\">");
        _add_content("              <input type=\"checkbox\" class=\"custom-control-input\" id=\"input_terms_of_use\" required>");
        _add_content("              <label class=\"custom-control-label\" for=\"input_terms_of_use\">I agree to the terms of use</label>");
        _add_content("            </div>");
        _add_content("            <hr class=\"mb-4\">");

        _add_content("            <button class=\"btn btn-primary btn-lg btn-block\" type=\"submit\">Continue to checkout</button>");
        _add_content("          </form>");
        _add_content("        </div>");
        _add_content("      </div>");

        _add_content("      <footer class=\"my-5 pt-5 text-muted text-center text-small\">");
        _add_content("        <p class=\"mb-1\">&copy; 2021 SBC team</p>");
        _add_content("        <ul class=\"list-inline\">");
        _add_content("          <li class=\"list-inline-item\"><a href=\"/about\">Privacy</a></li>");
        _add_content("          <li class=\"list-inline-item\"><a href=\"/terms\">Terms</a></li>");
        _add_content("          <li class=\"list-inline-item\"><a href=\"/about\">Support</a></li>");
        _add_content("        </ul>");
        _add_content("      </footer>");
        _add_content("    </div>");

        _add_content("    <!-- Bootstrap core JavaScript");
        _add_content("    ================================================== -->");
        _add_content("    <!-- Placed at the end of the document so the pages load faster -->");
        _add_content("    <script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\" crossorigin=\"anonymous\"></script>");
        _add_content("    <script>");
        _add_content("      window.jQuery || document.write('<script src=\"../assets/js/vendor/jquery-slim.min.js\"><\\/script>')");
        _add_content("    </script>");
        _add_content("    <!-- <script src=\"../assets/js/vendor/popper.min.js\"></script> -->");
        _add_content("    <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/2.5.4/umd/popper.min.js\" integrity=\"sha512-7yA/d79yIhHPvcrSiB8S/7TyX0OxlccU8F/kuB8mHYjLlF1MInPbEohpoqfz0AILoq5hoD7lELZAYYHbyeEjag==\" crossorigin=\"anonymous\"></script>");
        _add_content("    <!-- <script src=\"../dist/js/bootstrap.min.js\"></script> -->");
        _add_content("    <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js\" integrity=\"sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV\" crossorigin=\"anonymous\"></script>");
        _add_content("    <!-- <script src=\"../assets/js/vendor/holder.min.js\"></script> -->");
        _add_content("    <script src=\"https://cdnjs.cloudflare.com/ajax/libs/holder/2.9.7/holder.min.js\" integrity=\"sha512-O6R6IBONpEcZVYJAmSC+20vdsM07uFuGjFf0n/Zthm8sOFW+lAq/OK1WOL8vk93GBDxtMIy6ocbj6lduyeLuqQ==\" crossorigin=\"anonymous\"></script>");
        _add_content("    <script>");
        _add_content("      // Example starter JavaScript for disabling form submissions if there are invalid fields");
        _add_content("      (function() {");
        _add_content("        'use strict';");

        _add_content("        window.addEventListener('load', function() {");
        _add_content("          // Fetch all the forms we want to apply custom Bootstrap validation styles to");
        _add_content("          var forms = document.getElementsByClassName('needs-validation');");

        _add_content("          // Loop over them and prevent submission");
        _add_content("          var validation = Array.prototype.filter.call(forms, function(form) {");
        _add_content("            form.addEventListener('submit', function(event) {");
        _add_content("              if (form.checkValidity() === false) {");
        _add_content("                event.preventDefault();");
        _add_content("                event.stopPropagation();");
        _add_content("              }");
        _add_content("              form.classList.add('was-validated');");
        _add_content("            }, false);");
        _add_content("          });");
        _add_content("        }, false);");
        _add_content("      })();");
        _add_content("    </script>");
        _add_content("  </form>");
        _add_content("</body>");
    }
}