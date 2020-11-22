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
#ifndef WEB_PAGE_H
#define WEB_PAGE_H

#include <string>

#include <fcgi_config.h>
#include <fcgiapp.h>

class page
{
public:
    page(FCGX_Request &request) : _request(request){_init()};
    ~page();

private:
    FCGX_Request &_request;

    void _init();

    std::string _request_method = FCGX_GetParam("REQUEST_METHOD", _request.envp);
    std::string _content_length = FCGX_GetParam("CONTENT_LENGTH", _request.envp);
    std::string _remote_addr = FCGX_GetParam("REMOTE_ADDR", _request.envp);
    std::string _request_uri = FCGX_GetParam("REQUEST_URI", _request.envp);
    std::string _query_string = FCGX_GetParam("QUERY_STRING", _request.envp);
    std::string _document_uri = FCGX_GetParam("DOCUMENT_URI", _request.envp);
    std::string _document_root = FCGX_GetParam("DOCUMENT_ROOT", _request.envp);
    std::string _http_host = FCGX_GetParam("HTTP_HOST", _request.envp);
    std::string _http_cookie;

    void _header();
};

#endif // WEB_PAGE_H
