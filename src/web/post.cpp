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
 * @brief Обработка post запроса
 * @author SavaLione
 * @date 09 Dec 2020
 */
#include "web/post.h"

post::~post()
{
}

post::post()
{
}

void post::set(std::string const &unprocessed_post)
{
    _unprocessed_post = unprocessed_post;
    _init();
}

void post::_init()
{
    _decoded_uncompressed_post = url_decode(_unprocessed_post);

    _get(_input_username);
    _get(_input_password);
    _get(_input_email);
    _get(_input_last_name);
    _get(_input_first_name);
    _get(_input_middle_name);
    _get(_input_address);
    _get(_input_phone);
    _get(_input_terms_of_use);
    _get(_input_branch);
    _get(_input_department);
}

void post::_get(post_pair &pp)
{
    int pos = _decoded_uncompressed_post.find(pp.key);
    if (pos >= 0)
    {
        for (int i = pos + pp.key.size() + 1; i < _decoded_uncompressed_post.size(); i++)
        {
            if (_decoded_uncompressed_post[i] != _separator)
            {
                pp.value += _decoded_uncompressed_post[i];
            }
            else
            {
                break;
            }
        }
        pp.set = true;
    }
    else
    {
        pp.set = false;
    }
}

const post_pair post::get_input_username() { return _input_username; }
const post_pair post::get_input_password() { return _input_password; }
const post_pair post::get_input_email() { return _input_email; }
const post_pair post::get_input_last_name() { return _input_last_name; }
const post_pair post::get_input_first_name() { return _input_first_name; }
const post_pair post::get_input_middle_name() { return _input_middle_name; }
const post_pair post::get_input_address() { return _input_address; }
const post_pair post::get_input_phone() { return _input_phone; }
const post_pair post::get_input_terms_of_use() { return _input_terms_of_use; }
const post_pair post::get_input_branch() { return _input_branch; }
const post_pair post::get_input_department() { return _input_department; }