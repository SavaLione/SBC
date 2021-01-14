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
 * @brief About
 * @author SavaLione
 * @date 07 Dec 2020
 */
#include "web/pages/about.h"

about::~about()
{
}

void about::_body()
{
    _add_content("    <body>");
    _add_content("        <div class=\"container pt-4 pb-4\">");
    _add_content("            <div class=\"row\">");
    _add_content("                <div class=\"col-3\">");
    _add_content("                    <button class=\"btn btn-primary shadow w-100 mb-1\" onclick=\"change_tab('description')\">Описание проекта</button>");
    _add_content("                    <button class=\"btn btn-primary shadow w-100 mb-1\" onclick=\"change_tab('components')\">Компоненты проекта</button>");
    _add_content("                    <button class=\"btn btn-primary shadow w-100 mb-1\" onclick=\"change_tab('team')\">Команда разработки</button>");
    _add_content("                </div>");
    _add_content("                <div class=\"col-9\">");
    _add_content("                    <div id=\"description\" class=\"tab container-fluid\">");
    _add_content("                        <h2>Описание проекта</h2>");
    _add_content("                        <p>Проект создан, чтобы упростить процесс логистики, в основном ориентирован для мелких компаний, которые не могут, по финансовым причинам, позволить себе интеграцию таких гигантов, как 1С.</p>");
    _add_content("                        <p>Проект является полностью самостоятельным решением и не предоставляет возможности внедрения в другие системы.</p>");
    _add_content("                    </div>");
    _add_content("                    <div id=\"components\" class=\"tab container-fluid\">");
    _add_content("                        <h2>Компоненты проекта</h2>");
    _add_content("                        <div>");
    _add_content("                            <h3>Серверная часть</h3>");
    _add_content("                            <h4>Описание</h4>");
    _add_content("                            <p>Основное приложение, выполняющее сложные операции по поиску и изменению состояний товаров, предоставляющее интерфейсы по регистрации и аутентификации пользователей.</p>");
    _add_content("                            <h4>Возможности</h4>");
    _add_content("                            <ul>");
    _add_content("                                <li>взаимодействие с несколькими видами БД</li>");
    _add_content("                                <li>сериализация данных в protobuf</li>");
    _add_content("                                <li>механизм регистрации и аутентификации</li>");
    _add_content("                            </ul>");
    _add_content("                            <h4>Стек технологий</h4>");
    _add_content("                            <ul>");
    _add_content("                                <li>C++ - язык программирования</li>");
    _add_content("                                <li>Boost Asio - библиотека для работы с сетью</li>");
    _add_content("                                <li>SOCI - библиотека доступа к базам данным</li>");
    _add_content("                                <li>Protobuf - библиотека сериализации данных в protobuf</li>");
    _add_content("                                <li>OpenSSL - криптографическая библиотека для шифрования данных</li>");
    _add_content("                            </ul>");
    _add_content("                        </div>");
    _add_content("                        <div>");
    _add_content("                            <h3>Веб интерфейс</h3>");
    _add_content("                            <h4>Описание</h4>");
    _add_content("                            <p>Веб страница администратора, на которой можно посмотреть данные о всех товарах и при необходимости изменять их.</p>");
    _add_content("                            <h4>Возможности</h4>");
    _add_content("                            <ul>");
    _add_content("                                <li>просмотр всей информации об товарах</li>");
    _add_content("                                <li>регистрация и аутентификация</li>");
    _add_content("                            </ul>");
    _add_content("                            <h4>Стек технологий</h4>");
    _add_content("                            <ul>");
    _add_content("                                <li>Bootstrap - библиотека для быстрой и адаптивной разметки веб страниц</li>");
    _add_content("                                <li>jQuery - javascript фреймворк, который упрощает написание сценариев веб страницы</li>");
    _add_content("                            </ul>");
    _add_content("                        </div>");
    _add_content("                        <div>");
    _add_content("                            <h3>Мобильное приложение</h3>");
    _add_content("                            <h4>Описание</h4>");
    _add_content("                            <p>Простейшее приложение для Android и IOS, которое позволяет отслеживать все контрольные точки, которые проходит товар.</p>");
    _add_content("                            <h4>Возможности</h4>");
    _add_content("                            <ul>");
    _add_content("                                <li>сканер 1D/2D-кодов</li>");
    _add_content("                                <li>помимо сканера есть возможность ввести код вручную</li>");
    _add_content("                                <li>сериализация данных в protobuf</li>");
    _add_content("                                <li>настройка подключения к серверу</li>");
    _add_content("                            </ul>");
    _add_content("                            <h4>Стек технологий</h4>");
    _add_content("                            <ul>");
    _add_content("                                <li>C# - язык программирования</li>");
    _add_content("                                <li>Xamarin, .NET - платформа для разработки мобильных приложений</li>");
    _add_content("                                <li>Zxing.Mobile - библиотека для сканирования 1D/2D-кодов</li>");
    _add_content("                                <li>protobuf-net - библиотека сериализации данных в protobuf для .NET платформы</li>");
    _add_content("                                <li>CrossSettings - библиотека для хранения настроек приложения в памяти устройства</li>");
    _add_content("                            </ul>");
    _add_content("                        </div>");
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

void about::_head()
{
    _add_content("    <head>");
    _add_content("        <meta charset=\"utf-8\">");
    _add_content("        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("        <meta name=\"description\" content=\"SBC\">");
    _add_content("        <meta name=\"author\" content=\"SBC team\">");
    _add_content("        <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("        <title>About</title>");

    _add_content("        <!-- Bootstrap core CSS -->");
    _add_content("        <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");
    _add_content("    </head>");
}