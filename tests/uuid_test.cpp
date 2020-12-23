/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2020, Darlakon
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
 * @brief Тест uuid
 * @author Darlakon
 * @date 23 Dec 2020
 */
#include "uuid_test.h"

#include "core/uuid.h"

uuid_test::uuid_test()
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();
}

uuid_test::~uuid_test()
{
}

TEST_F(uuid_test, test_not_equal_1)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_2)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_3)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_4)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_5)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_6)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_7)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, test_not_equal_8)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    ASSERT_NE(uuid_instance.get(), uuid_instance.get());
}

TEST_F(uuid_test, string_test_not_equal_1)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_2)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_3)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_4)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_5)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_6)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_7)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}

TEST_F(uuid_test, string_test_not_equal_8)
{
    /* uuid */
    uuid &uuid_instance = uuid::Instance();

    std::string result_first = uuid_instance.get();
    std::string result_second = uuid_instance.get();

    ASSERT_NE(result_first, result_second);
}