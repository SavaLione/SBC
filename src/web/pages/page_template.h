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
#ifndef WEB_PAGE_PAGE_TEMPLATE_H
#define WEB_PAGE_PAGE_TEMPLATE_H

#include <string>

#include <fcgi_config.h>
#include <fcgiapp.h>

#include "core/user.h"

#include "web/mime.h"
#include "web/cookie.h"

class page_template
{
public:
    page_template(std::string name, mime m, bool required_authorization)
        : _name(name), _mime(m), _required_authorization(required_authorization){};
    ~page_template();

    void show();

    operator std::string() const
    {
        return _content;
    }

    const &std::string get();

protected:
    std::string _get_name();
    void _add_content(std::string content);
    virtual void _init();

    /* Системный заголовок. Тип контента, Cookies и прочее. */
    virtual void _html_header();

    virtual void _html();
    virtual void _head();
    virtual void _body();

    std::string _content = "";

private:
    std::string _name = "page_template";

    mime _mime = text_html;

    user _user;

    /* Чтобы просматривать эту страницу, нужна авторизация? */
    bool _required_authorization = true;
};

#endif // WEB_PAGE_PAGE_TEMPLATE_H