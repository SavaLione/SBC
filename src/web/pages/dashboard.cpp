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
 * @brief Панель управления sbc
 * @author SavaLione
 * @date 15 Dec 2021
 */
#include "web/pages/dashboard.h"

#include "db/db.h"
#include "db/table_users.h"
#include "db/table_codes.h"

#include "io/logger.h"

dashboard::~dashboard()
{
}

void dashboard::_head()
{
    _add_content("<head>");
    _add_content("  <meta charset=\"utf-8\">");
    _add_content("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("  <meta name=\"description\" content=\"\">");
    _add_content("  <meta name=\"author\" content=\"\">");
    _add_content("  <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("  <title>SBC dashboard</title>");

    _add_content("  <!-- Bootstrap core CSS -->");
    _add_content("  <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");

    _add_content("  <!-- Custom styles for this template -->");
    _add_content("  <link href=\"/assets/css/dashboard.css\" rel=\"stylesheet\">");
    _add_content("</head>");
}

void dashboard::_body()
{
    if (_user._user_status == USER_STATUS_SET)
    {
        _add_content("<body>");
        _add_content("  <nav class=\"navbar navbar-dark sticky-top bg-dark flex-md-nowrap p-0\">");
        _add_content("    <a class=\"navbar-brand col-sm-3 col-md-2 mr-0\" href=\"#\">Scanning bar codes</a>");
        _add_content("    <!-- <input class=\"form-control form-control-dark w-100\" type=\"text\" placeholder=\"Search\" aria-label=\"Search\"> -->");
        _add_content("    <ul class=\"navbar-nav px-3\">");
        _add_content("      <li class=\"nav-item text-nowrap\">");
        _add_content("        <a class=\"nav-link\" href=\"/logout\">Sign out</a>");
        _add_content("      </li>");
        _add_content("    </ul>");
        _add_content("  </nav>");

        _add_content("  <div class=\"container-fluid\">");
        _add_content("    <div class=\"row\">");
        _add_content("      <nav class=\"col-md-2 d-none d-md-block bg-light sidebar\">");
        _add_content("        <div class=\"sidebar-sticky\">");
        _add_content("          <ul class=\"nav flex-column\">");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link active\" href=\"/index\">");
        _add_content("                <span data-feather=\"home\"></span> Home <span class=\"sr-only\">(current)</span>");
        _add_content("              </a>");
        _add_content("            </li>");
        _add_content("            <!-- <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"file\"></span> Orders </a>");
        _add_content("            </li> -->");
        _add_content("            <!-- <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"shopping-cart\"></span> Products </a>");
        _add_content("            </li> -->");
        _add_content("            <!-- <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"users\"></span> Customers </a>");
        _add_content("            </li> -->");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"/install\">");
        _add_content("                <span data-feather=\"bar-chart-2\"></span> Install </a>");
        _add_content("            </li>");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"/documentation\">");
        _add_content("                <span data-feather=\"file\"></span> Documentation </a>");
        _add_content("            </li>");
        _add_content("            <!-- <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"layers\"></span> Integrations </a>");
        _add_content("            </li> -->");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"/settings\">");
        _add_content("                <span data-feather=\"layers\"></span> Settings </a>");
        _add_content("            </li>");
        _add_content("          </ul>");

        _add_content("          <!-- <h6 class=\"sidebar-heading d-flex justify-content-between align-items-center px-3 mt-4 mb-1 text-muted\">");
        _add_content("            <span>Saved reports</span>");
        _add_content("            <a class=\"d-flex align-items-center text-muted\" href=\"#\">");
        _add_content("              <span data-feather=\"plus-circle\"></span>");
        _add_content("            </a>");
        _add_content("          </h6>");
        _add_content("          <ul class=\"nav flex-column mb-2\">");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"file-text\"></span>");
        _add_content("                Current month");
        _add_content("              </a>");
        _add_content("            </li>");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"file-text\"></span>");
        _add_content("                Last quarter");
        _add_content("              </a>");
        _add_content("            </li>");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"file-text\"></span>");
        _add_content("                Social engagement");
        _add_content("              </a>");
        _add_content("            </li>");
        _add_content("            <li class=\"nav-item\">");
        _add_content("              <a class=\"nav-link\" href=\"#\">");
        _add_content("                <span data-feather=\"file-text\"></span>");
        _add_content("                Year-end sale");
        _add_content("              </a>");
        _add_content("            </li> -->");
        _add_content("          </ul>");
        _add_content("        </div>");
        _add_content("      </nav>");

        _add_content("      <main role=\"main\" class=\"col-md-9 ml-sm-auto col-lg-10 pt-3 px-4\">");
        _add_content("        <div class=\"d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pb-2 mb-3 border-bottom\">");
        _add_content("          <h1 class=\"h2\">Dashboard</h1>");
        _add_content("          <div class=\"btn-toolbar mb-2 mb-md-0\">");
        _add_content("            <!-- <div class=\"btn-group mr-2\">");
        _add_content("              <button class=\"btn btn-sm btn-outline-secondary\">Share</button>");
        _add_content("              <button class=\"btn btn-sm btn-outline-secondary\">Export</button>");
        _add_content("            </div>");
        _add_content("            <button class=\"btn btn-sm btn-outline-secondary dropdown-toggle\">");
        _add_content("              <span data-feather=\"calendar\"></span>");
        _add_content("              This week");
        _add_content("            </button> -->");
        _add_content("          </div>");
        _add_content("        </div>");

        _add_content("        <!-- <canvas class=\"my-4\" id=\"myChart\" width=\"900\" height=\"380\"></canvas> -->");

        _add_content("        <h2>Users</h2>");
        _add_content("        <div class=\"table-responsive\">");
        _add_content("          <table class=\"table table-striped table-sm\">");
        _add_content("            <thead>");
        _add_content("              <tr>");
        _add_content("                <th>id</th>");
        _add_content("                <th>username</th>");
        _add_content("                <th>name</th>");
        _add_content("                <th>email</th>");
        _add_content("                <th>registration_date</th>");
        _add_content("                <th>last_time_online</th>");
        _add_content("                <th>description</th>");
        _add_content("                <th>department</th>");
        _add_content("                <th>branch</th>");
        _add_content("              </tr>");
        _add_content("            </thead>");
        _add_content("            <tbody>");

        /* Выводим список пользователей */
        {
            try
            {
                db &_db_instance = db::instance();
                db_pool *db_p = &_db_instance.get();

                soci::session sql(*db_p->get_pool());

                soci::rowset<table_users> rs = (sql.prepare << "SELECT * FROM users");

                for (auto it = rs.begin(); it != rs.end(); it++)
                {
                    table_users &t_u = *it;

                    _add_content("              <tr>");

                    /* id */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.id;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* username */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.username;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* name */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.name;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* email */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.email;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* registration_date */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.registration_date;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* last_time_online */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.last_time_online;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* description */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.description;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* department */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.department;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* branch */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_u.branch;
                        s += "</td>";
                        _add_content(s);
                    }

                    _add_content("              </tr>");
                }
            }
            catch (const std::exception &e)
            {
                spdlog::error(e.what());
            }
        }
        // _add_content("              <tr>");
        // _add_content("                <td>1</td>");
        // _add_content("                <td>some</td>");
        // _add_content("                <td>Some name</td>");
        // _add_content("                <td>some@s.s</td>");
        // _add_content("                <td>2021-01-15</td>");
        // _add_content("                <td>2021-01-15</td>");
        // _add_content("                <td>Some description</td>");
        // _add_content("                <td>Some department</td>");
        // _add_content("                <td>Some branch</td>");
        // _add_content("              </tr>");
        // _add_content("              <tr>");
        // _add_content("                <td>2</td>");
        // _add_content("                <td>test</td>");
        // _add_content("                <td>Test name</td>");
        // _add_content("                <td>test@s.s</td>");
        // _add_content("                <td>2021-01-12</td>");
        // _add_content("                <td>2021-01-12</td>");
        // _add_content("                <td>Test description</td>");
        // _add_content("                <td>Test department</td>");
        // _add_content("                <td>Test branch</td>");
        // _add_content("              </tr>");
        _add_content("            </tbody>");
        _add_content("          </table>");
        _add_content("        </div>");

        _add_content("        <h2>Codes</h2>");
        _add_content("        <div class=\"table-responsive\">");
        _add_content("          <table class=\"table table-striped table-sm\">");
        _add_content("            <thead>");
        _add_content("              <tr>");
        _add_content("                <th>id</th>");
        _add_content("                <th>code</th>");
        _add_content("                <th>time</th>");
        _add_content("                <th>user</th>");
        _add_content("              </tr>");
        _add_content("            </thead>");
        _add_content("            <tbody>");

        /* Выводим список кодов */
        {
            try
            {
                db &_db_instance = db::instance();
                db_pool *db_p = &_db_instance.get();

                soci::session sql(*db_p->get_pool());

                soci::rowset<table_codes> rs = (sql.prepare << "SELECT * FROM codes");

                for (auto it = rs.begin(); it != rs.end(); it++)
                {
                    table_codes &t_c = *it;

                    _add_content("              <tr>");

                    /* id */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_c.id;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* code */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_c.code;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* time */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_c.time;
                        s += "</td>";
                        _add_content(s);
                    }

                    /* user */
                    {
                        std::string s = "";
                        s += "<td>";
                        s += t_c.user;
                        s += "</td>";
                        _add_content(s);
                    }

                    _add_content("              </tr>");
                }
            }
            catch (const std::exception &e)
            {
                spdlog::error(e.what());
            }
        }
        // _add_content("              <tr>");
        // _add_content("                <td>1</td>");
        // _add_content("                <td>aa-bb-cc-dd</td>");
        // _add_content("                <td>2021-01-14</td>");
        // _add_content("                <td>some</td>");
        // _add_content("              </tr>");
        // _add_content("              <tr>");
        // _add_content("                <td>2</td>");
        // _add_content("                <td>ee-ff-gg-hh</td>");
        // _add_content("                <td>2021-01-15</td>");
        // _add_content("                <td>test</td>");
        // _add_content("              </tr>");
        _add_content("            </tbody>");
        _add_content("          </table>");
        _add_content("        </div>");

        _add_content("      </main>");
        _add_content("    </div>");
        _add_content("  </div>");

        _add_content("  <!-- Bootstrap core JavaScript");
        _add_content("    ================================================== -->");
        _add_content("  <!-- Placed at the end of the document so the pages load faster -->");
        _add_content("  <script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\" crossorigin=\"anonymous\"></script>");
        _add_content("  <script>");
        _add_content("    window.jQuery || document.write(");
        _add_content("      '<script src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.5.1/jquery.slim.min.js\" integrity=\"sha512-/DXTXr6nQodMUiq+IUJYCt2PPOUjrHJ9wFrqpJ3XkgPNOZVfMok7cRw6CSxyCQxXn6ozlESsSh1/sMCTF1rL/g==\" crossorigin=\"anonymous\"><\\/script>')");
        _add_content("  </script>");
        _add_content("  <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/2.6.0/umd/popper.min.js\" integrity=\"sha512-BmM0/BQlqh02wuK5Gz9yrbe7VyIVwOzD1o40yi1IsTjriX/NGF37NyXHfmFzIlMmoSIBXgqDiG1VNU6kB5dBbA==\" crossorigin=\"anonymous\"></script>");
        _add_content("  <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js\" integrity=\"sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV\" crossorigin=\"anonymous\"></script>");

        _add_content("  <!-- Icons -->");
        _add_content("  <script src=\"https://unpkg.com/feather-icons/dist/feather.min.js\"></script>");
        _add_content("  <script>");
        _add_content("    feather.replace()");
        _add_content("  </script>");

        _add_content("  <!-- Graphs -->");
        _add_content("  <!-- <script src=\"https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.7.1/Chart.min.js\"></script>");
        _add_content("  <script>");
        _add_content("    var ctx = document.getElementById(\"myChart\");");
        _add_content("    var myChart = new Chart(ctx, {");
        _add_content("      type: 'line',");
        _add_content("      data: {");
        _add_content("        labels: [\"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\", \"Saturday\"],");
        _add_content("        datasets: [{");
        _add_content("          data: [15339, 21345, 18483, 24003, 23489, 24092, 12034],");
        _add_content("          lineTension: 0,");
        _add_content("          backgroundColor: 'transparent',");
        _add_content("          borderColor: '#007bff',");
        _add_content("          borderWidth: 4,");
        _add_content("          pointBackgroundColor: '#007bff'");
        _add_content("        }]");
        _add_content("      },");
        _add_content("      options: {");
        _add_content("        scales: {");
        _add_content("          yAxes: [{");
        _add_content("            ticks: {");
        _add_content("              beginAtZero: false");
        _add_content("            }");
        _add_content("          }]");
        _add_content("        },");
        _add_content("        legend: {");
        _add_content("          display: false,");
        _add_content("        }");
        _add_content("      }");
        _add_content("    });");
        _add_content("  </script> -->");
        _add_content("</body>");
    }
    else
    {
        _add_content("  <div class=\"d-flex justify-content-center align-items-center\" id=\"main\">");
        _add_content("      <h1 class=\"mr-3 pr-3 align-top border-right inline-block align-content-center\"><a href=\"/index\">Home</a></h1>");
        _add_content("      <div class=\"inline-block align-middle\">");
        _add_content("      	<h2 class=\"font-weight-normal lead\" id=\"desc\">You are not authorized to access this page.</h2>");
        _add_content("      </div>");
        _add_content("  </div>");
    }
}