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
 * @brief Страница с справкой по установке SBC
 * @author SavaLione
 * @date 15 Dec 2021
 */
#include "web/pages/install.h"

install::~install()
{
}

void install::_head()
{
    _add_content("    <head>");
    _add_content("        <meta charset=\"utf-8\">");
    _add_content("        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("        <meta name=\"description\" content=\"SBC\">");
    _add_content("        <meta name=\"author\" content=\"SBC team\">");
    _add_content("        <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("        <title>About</title>");

    _add_content("        <!-- Bootstrap core CSS -->");
    _add_content("        <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\" />");
    _add_content("        <style>");
    _add_content("            .code-format {");
    _add_content("                margin-bottom: 16px;");
    _add_content("            }");

    _add_content("            .code-format pre {");
    _add_content("                padding: 16px;");
    _add_content("                margin: 1em 0px;");
    _add_content("                overflow: auto;");
    _add_content("                font-size: 85%;");
    _add_content("                line-height: 1.45;");
    _add_content("                background-color: #f6f8fa;");
    _add_content("                border-radius: 6px;");

    _add_content("                word-break: normal;");
    _add_content("            }");

    _add_content("            p code {");
    _add_content("                padding: .2em .4em;");
    _add_content("                margin: 0;");
    _add_content("                font-size: 85%;");
    _add_content("                background-color: var(--color-markdown-code-bg);");
    _add_content("                border-radius: 6px;");
    _add_content("            }");
    _add_content("        </style>");
    _add_content("    </head>");
}

void install::_body()
{
    _add_content("    <body>");
    _add_content("        <div class=\"container pt-4 pb-4\">");
    _add_content("            <div class=\"row\">");
    _add_content("                <div class=\"col-3\">");
    _add_content("                    <button class=\"btn btn-primary shadow w-100 mb-1\" onclick=\"change_tab('server')\">Установка сервера</button>");
    _add_content("                    <button class=\"btn btn-primary shadow w-100 mb-1\" onclick=\"change_tab('mobile')\">Установка мобильного приложения</button>");
    _add_content("                    <button class=\"btn btn-primary shadow w-100 mb-1\" onclick=\"change_tab('team')\">Команда разработки</button>");
    _add_content("                </div>");
    _add_content("                <div class=\"col-9\">");
    _add_content("                    <div id=\"server\" class=\"tab container-fluid\">");
    _add_content("                        <h2>Установка сервера</h2>");
    _add_content("                        <p>Проект разделён на несколько частей:</p>");
    _add_content("                        <ul>");
    _add_content("                            <li>sbc - Сервер</li>");
    _add_content("                            <li>sbc-client - Консольный клиент</li>");
    _add_content("                            <li>sbc-tests - Автоматические тесты</li>");
    _add_content("                            <li>dev - Дополнительные инструменты для разработки проекта sbc</li>");
    _add_content("                        </ul>");
    _add_content("                        <p>Стандартные порты:</p>");
    _add_content("                        <ul>");
    _add_content("                            <li>9000 - FastCGI (web интерфейс)</li>");
    _add_content("                            <li>12340 - Порт sbc сервера</li>");
    _add_content("                        </ul>");
    _add_content("                        <div id=\"server-list\" class=\"accordion\">");
    _add_content("                            <div class=\"card\">");
    _add_content("                                <div id=\"dependencies-header\" class=\"card-header\">");
    _add_content("                                    <h4 class=\"mb-0\">");
    _add_content("                                        <button class=\"btn btn-link\" type=\"button\" data-toggle=\"collapse\" data-target=\"#dependencies\" aria-expanded=\"true\" aria-controls=\"dependencies\">");
    _add_content("                                            Установка зависимостей");
    _add_content("                                        </button>");
    _add_content("                                    </h4>");
    _add_content("                                </div>");
    _add_content("                                <div id=\"dependencies\" class=\"collapse show\" aria-labelledby=\"dependencies-header\" data-parent=\"#server-list\">");
    _add_content("                                    <div class=\"card-body\">");
    _add_content("                                        <h5>Список зависимостей</h5>");
    _add_content("                                        <p><strong>sbc</strong></p>");
    _add_content("                                        <ul>");
    _add_content("                                            <li>C++ (c++11 и выше)</li>");
    _add_content("                                            <li>gcc (тестировалось на версии 9.3.0)</li>");
    _add_content("                                            <li>CMake 3.13.1+ (только на время сборки проекта)</li>");
    _add_content("                                            <li>Boost 1.71.0+</li>");
    _add_content("                                            <li>Threads (поставляется с gcc)</li>");
    _add_content("                                            <li>Protocol Buffers (тестировалось на версии 3.14.0)</li>");
    _add_content("                                            <li>SQLite3 (для поддержки sqlite)</li>");
    _add_content("                                            <li>spdlog (тестировалось на версии 1:1.5.0-1)</li>");
    _add_content("                                            <li>SOCI 4.0+</li>");
    _add_content("                                            <li>OpenSSL (тестировалось на версии 1.1.1f)</li>");
    _add_content("                                            <li>FastCGI (libfcgi) (тестировалось на версии 2.4.0-10build1)</li>");
    _add_content("                                        </ul>");
    _add_content("                                        <p><strong>sbc-client</strong></p>");
    _add_content("                                        <ul>");
    _add_content("                                            <li>C++ (c++11 и выше)</li>");
    _add_content("                                            <li>gcc (тестировалось на версии 9.3.0)</li>");
    _add_content("                                            <li>CMake 3.13.1+ (только на время сборки проекта)</li>");
    _add_content("                                            <li>Boost 1.71.0+</li>");
    _add_content("                                        </ul>");
    _add_content("                                        <p><strong>sbc-tests</strong></p>");
    _add_content("                                        <ul>");
    _add_content("                                            <li>C++ (c++11 и выше)</li>");
    _add_content("                                            <li>gcc (тестировалось на версии 9.3.0)</li>");
    _add_content("                                            <li>CMake 3.13.1+ (только на время сборки проекта)</li>");
    _add_content("                                            <li>Boost 1.71.0+</li>");
    _add_content("                                            <li>Threads (поставляется с gcc)</li>");
    _add_content("                                            <li>Protocol Buffers (тестировалось на версии 3.14.0)</li>");
    _add_content("                                            <li>SQLite3 (для поддержки sqlite)</li>");
    _add_content("                                            <li>spdlog (тестировалось на версии 1:1.5.0-1)</li>");
    _add_content("                                            <li>SOCI 4.0+</li>");
    _add_content("                                            <li>OpenSSL (тестировалось на версии 1.1.1f)</li>");
    _add_content("                                            <li>FastCGI (libfcgi) (тестировалось на версии 2.4.0-10build1)</li>");
    _add_content("                                            <li>Google C++ Testing Framework (gtest) (тестировалось на версии 1.10.0-2)</li>");
    _add_content("                                        </ul>");
    _add_content("                                        <p><strong>dev</strong></p>");
    _add_content("                                        <ul>");
    _add_content("                                            <li>C++ (c++11 и выше)</li>");
    _add_content("                                            <li>gcc (тестировалось на версии 9.3.0)</li>");
    _add_content("                                            <li>CMake 3.13.1+ (только на время сборки проекта)</li>");
    _add_content("                                        </ul>");

    _add_content("                                        <h5>Установка зависимостей (ubuntu)</h5>");
    _add_content("                                        <p><strong>Перед установкой пакетов желательно обновить список пакетов:</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt update</pre></div>");
    _add_content("                                        <p><strong>gcc</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install build-essential</pre></div>");
    _add_content("                                        <p><strong>CMake</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install cmake</pre></div>");
    _add_content("                                        <p><strong>Boost</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install libboost-all-dev</pre></div>");
    _add_content("                                        <p><strong>Protocol Buffers</strong></p>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("sudo apt install autoconf automake libtool curl make g++ unzip");
    _add_content("git clone https://github.com/protocolbuffers/protobuf.git");
    _add_content("cd protobuf");
    _add_content("git submodule update --init --recursive");
    _add_content("./autogen.sh");
    _add_content("./configure");
    _add_content("make -j4");
    _add_content("make check");
    _add_content("sudo make install");
    _add_content("sudo ldconfig");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("-j4 после команды make означает, что компилируем проект 4 процессорными ядрами");
    _add_content("4 можно заменить на любое число. Также можно вовсе убрать -j4");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <p><strong>SQLite3 (для поддержки sqlite)</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install sqlite3 libsqlite3-dev</pre></div>");
    _add_content("                                        <p><strong>spdlog</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install libspdlog-dev</pre></div>");
    _add_content("                                        <p><strong>SOCI</strong></p>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("git clone https://github.com/SOCI/soci.git");
    _add_content("cd soci && mkdir build");
    _add_content("cd build");
    _add_content("cmake .. -DSOCI_CXX11=ON -DWITH_BOOST=ON");
    _add_content("make -j4");
    _add_content("sudo make install");

    _add_content("sudo cp /usr/local/lib64/libsoci_core.a /usr/local/lib/libsoci_core.a");
    _add_content("sudo cp /usr/local/lib64/libsoci_empty.a /usr/local/lib/libsoci_empty.a");
    _add_content("sudo cp /usr/local/lib64/libsoci_sqlite3.a /usr/local/lib/libsoci_sqlite3.a");
    _add_content("sudo ln -s /usr/local/lib64/libsoci_core.so  /usr/local/lib/libsoci_core.so");
    _add_content("sudo ln -s /usr/local/lib64/libsoci_empty.so /usr/local/lib/libsoci_empty.so");
    _add_content("sudo ln -s /usr/local/lib64/libsoci_sqlite3.so /usr/local/lib/libsoci_sqlite3.so");

    _add_content("sudo ln -s /usr/local/lib64/libsoci_core.so.4.0 /usr/local/lib/libsoci_core.so.4.0");
    _add_content("sudo ln -s /usr/local/lib64/libsoci_empty.so.4.0 /usr/local/lib/libsoci_empty.so.4.0");
    _add_content("sudo ln -s /usr/local/lib64/libsoci_sqlite3.so.4.0 /usr/local/lib/libsoci_sqlite3.so.4.0");

    _add_content("sudo ldconfig");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("-j4 после команды make означает, что компилируем проект 4 процессорными ядрами");
    _add_content("4 можно заменить на любое число. Также можно вовсе убрать -j4");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <p><strong>OpenSSL</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install libssl-dev</pre></div>");
    _add_content("                                        <p><strong>Google C++ Testing Framework (gtest)</strong></p>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("sudo apt install libgtest-dev");
    _add_content("cd /usr/src/gtest");
    _add_content("sudo cmake CMakeLists.txt");
    _add_content("sudo make -j4");

    _add_content("sudo cp *.a /usr/lib");
    _add_content("sudo ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a");
    _add_content("sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("-j4 после команды make означает, что компилируем проект 4 процессорными ядрами");
    _add_content("4 можно заменить на любое число. Также можно вовсе убрать -j4");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <p><strong>FastCGI (libfcgi)</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo pat install libfcgi-dev</pre></div>");
    _add_content("                                    </div>");
    _add_content("                                </div>");
    _add_content("                            </div>");
    _add_content("                            <div class=\"card\">");
    _add_content("                                <div id=\"sbc-header\" class=\"card-header\">");
    _add_content("                                    <h4 class=\"mb-0\">");
    _add_content("                                        <button class=\"btn btn-link collapsed\" type=\"button\" data-toggle=\"collapse\" data-target=\"#sbc\" aria-expanded=\"false\" aria-controls=\"sbc\">");
    _add_content("                                            Установка проекта sbc (*nix)");
    _add_content("                                        </button>");
    _add_content("                                    </h4>");
    _add_content("                                </div>");
    _add_content("                                <div id=\"sbc\" class=\"collapse\" aria-labelledby=\"sbc-header\" data-parent=\"#server-list\">");
    _add_content("                                    <div class=\"card-body\">");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("git clone https://github.com/SavaLione/SBC.git");
    _add_content("cd SBC");
    _add_content("mkdir build");
    _add_content("cd build");
    _add_content("cmake ..");
    _add_content("make -j4");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("-j4 после команды make означает, что компилируем проект 4 процессорными ядрами");
    _add_content("4 можно заменить на любое число. Также можно вовсе убрать -j4");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                        <p>Для сборки автоматических тестов <code>sbc</code> нужно указать дополнительный флаг <code>-DSBC_PROJECT_TESTS=on</code></p>");
    _add_content("                                        <p>Для сборки автоматических тестов <code>sbc-client</code> нужно указать дополнительный флаг <code>-DSBC_CLIENT_TESTS=on</code></p>");
    _add_content("                                        <p>Для сборки автоматических тестов <code>dev</code> нужно указать дополнительный флаг <code>-DSBC_DEV_TESTS=on</code></p>");
    _add_content("                                        <p>Для сборки <code>dev</code> нужно указать дополнительный флаг <code>-DSBC_PROJECT_DEV=on</code></p>");
    _add_content("                                        <p>Пример:</p>");
    _add_content("                                        <div class=\"code-format\"><pre>cmake .. -DSBC_PROJECT_TESTS=on -DSBC_CLIENT_TESTS=on</pre></div>");
    _add_content("                                    </div>");
    _add_content("                                </div>");
    _add_content("                            </div>");
    _add_content("                            <div class=\"card\">");
    _add_content("                                <div id=\"web-header\" class=\"card-header\">");
    _add_content("                                    <h4 class=\"mb-0\">");
    _add_content("                                        <button class=\"btn btn-link collapsed\" type=\"button\" data-toggle=\"collapse\" data-target=\"#web\" aria-expanded=\"false\" aria-controls=\"web\">");
    _add_content("                                            Установка web интерфейса");
    _add_content("                                        </button>");
    _add_content("                                    </h4>");
    _add_content("                                </div>");
    _add_content("                                <div id=\"web\" class=\"collapse\" aria-labelledby=\"web-header\" data-parent=\"#server-list\">");
    _add_content("                                    <div class=\"card-body\">");
    _add_content("                                        <h5>Установка зависимостей (ubuntu)</h5>");
    _add_content("                                        <p><strong>nginx (если предполагается использование nginx web сервера)</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install nginx</pre></div>");
    _add_content("                                        <p><strong>apache (если предполагается использование apache web сервера)</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install apache2</pre></div>");
    _add_content("                                        <p><strong>FastCGI (libfcgi)</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo pat install libfcgi-dev</pre></div>");

    _add_content("                                        <h5>Установка web интерфейса проекта sbc</h5>");
    _add_content("                                        <p>Необходимо разместить дополнительные материалы (assets) по пути /assets (путь от домена)</p>");
    _add_content("                                        <p>Веб серверу нужно указать путь к FastCGI порту</p>");
    _add_content("                                        <p><strong>Пример конфигурации nginx</strong></p>");
    _add_content("                                        <div class=\"code-format\">");
    _add_content("                                            <pre>");
    _add_content("server {");
    _add_content("        listen 80 default_server;");
    _add_content("        listen [::]:80 default_server;");

    _add_content("        root /home/savalione/www/assets;");

    _add_content("        index index.html index.htm index.nginx-debian.html;");

    _add_content("        server_name _;");

    _add_content("        location /assets {");
    _add_content("                try_files $uri $uri/ =404;");
    _add_content("        }");

    _add_content("        location / {");
    _add_content("                fastcgi_pass 127.0.0.1:9000;");

    _add_content("                include fastcgi_params;");
    _add_content("        }");
    _add_content("}");
    _add_content("                                            </pre>");
    _add_content("                                        </div>");
    _add_content("                                    </div>");
    _add_content("                                </div>");
    _add_content("                            </div>");
    _add_content("                            <div class=\"card\">");
    _add_content("                                <div id=\"docs-header\" class=\"card-header\">");
    _add_content("                                    <h4 class=\"mb-0\">");
    _add_content("                                        <button class=\"btn btn-link collapsed\" type=\"button\" data-toggle=\"collapse\" data-target=\"#docs\" aria-expanded=\"false\" aria-controls=\"docs\">");
    _add_content("                                            Сборка документации к проекту (не обязательно)");
    _add_content("                                        </button>");
    _add_content("                                    </h4>");
    _add_content("                                </div>");
    _add_content("                                <div id=\"docs\" class=\"collapse\" aria-labelledby=\"docs-header\" data-parent=\"#server-list\">");
    _add_content("                                    <div class=\"card-body\">");
    _add_content("                                        <h5>Установка зависимостей</h5>");
    _add_content("                                        <p><strong>Doxygen</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install doxygen</pre></div>");
    _add_content("                                        <p><strong>Graphviz (не обязательно)</strong></p>");
    _add_content("                                        <div class=\"code-format\"><pre>sudo apt install graphviz</pre></div>");

    _add_content("                                        <h5>Сборка документации</h5>");
    _add_content("                                        <div class=\"code-format\"><pre>doxygen</pre></div>");
    _add_content("                                    </div>");
    _add_content("                                </div>");
    _add_content("                            </div>");
    _add_content("                        </div>");
    _add_content("                    </div>");
    _add_content("                    <div id=\"mobile\" class=\"tab container-fluid\">");
    _add_content("                        <h2>Установка мобильного приложения</h2>");
    _add_content("                        <h5>Для того, чтобы установить мобильное приложение, необходимо:</h5>");
    _add_content("                        <ul>");
    _add_content("                            <li>Для пользователей Android зайти на <a href=\"https://install.appcenter.ms/users/illyasviel/apps/code-scaner.android/distribution_groups/testers\">страницу</a>;</li>");
    _add_content("                            <li>Найти последнюю доступную сборку приложения;</li>");
    _add_content("                            <li>Нажать на кнопку \"Download\" и дождаться окончания загрузки файла;</li>");
    _add_content("                            <li>Установить загруженный файл;</li>");
    _add_content("                            <li>Если установщик запрещает устанавливать приложения из неизвестных источников, то нужно отключить защиту в настройках устройства;</li>");
    _add_content("                            <li>Начать пользоваться.</li>");
    _add_content("                        </ul>");
    _add_content("                    </div>");
    _add_content("                    <div id=\"team\" class=\"tab container-fluid\">");
    _add_content("                        <h2>Команда разработки</h2>");
    _add_content("                        <p><a href=\"https://vk.com/savalione\">Потоцкий Савелий</a> - серверная часть, веб интерфейс</p>");
    _add_content("                        <p><a href=\"https://vk.com/abs0lute.zer0\">Лахманец Илья</a> - мобильное приложение</p>");
    _add_content("                        <p><a href=\"https://vk.com/yulia_medvedeva\">Медведева Юлия</a> - анализ решений, присутствующих сейчас на рынке</p>");
    _add_content("                        <p><a href=\"https://vk.com/damak0rne\">Корецкий Даниил</a> - project manager, тестировщик</p>");
    _add_content("                        <a class=\"btn btn-secondary\" href=\"https://github.com/SavaLione/SBC\">Ссылка на ресурсы</a>");
    _add_content("                    </div>");
    _add_content("                </div>");
    _add_content("            </div>");
    _add_content("        </div>");

    _add_content("        <script src=\"https://code.jquery.com/jquery-3.5.1.min.js\" integrity=\"sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=\" crossorigin=\"anonymous\"></script>");
    _add_content("        <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js\" integrity=\"sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV\" crossorigin=\"anonymous\"></script>");
    _add_content("        <script>");
    _add_content("                        var id_current_tab = null;");

    _add_content("                        $(function () {");
    _add_content("                            var tabs = $('.tab');");
    _add_content("                            tabs.each(function () {");
    _add_content("                                $(this).addClass('d-none');");
    _add_content("                            });");

    _add_content("                            change_tab(tabs.eq(0).attr('id'));");
    _add_content("                        });");

    _add_content("                        function change_tab(id_tab) {");
    _add_content("                            if (id_current_tab !== null) {");
    _add_content("                                $('#' + id_current_tab).removeClass('d-block');");
    _add_content("                                $('#' + id_current_tab).addClass('d-none');");
    _add_content("                            }");

    _add_content("                            $('#' + id_tab).removeClass('d-none');");
    _add_content("                            $('#' + id_tab).addClass('d-block');");

    _add_content("                            id_current_tab = id_tab;");
    _add_content("                        }");
    _add_content("        </script>");
    _add_content("    </body>");
}