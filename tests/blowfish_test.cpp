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
 * @brief Тест blowfish
 * @author Darlakon
 * @date 21 Dec 2020
 */
#include "blowfish_test.h"

#include "core/blowfish.h"

blowfish_test::blowfish_test()
{
}

blowfish_test::~blowfish_test()
{
}

TEST_F(blowfish_test, string_test_encrypt_1)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Hello";
    std::string blowfish_result = "7E06EF51A06513BE2A0DDF346FE4F3682DACABC62CC23D31";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_encrypt_2)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Some";
    std::string blowfish_result = "9DEDF65D0D37FF2226B9AD938B72D34812982518130AE858";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_encrypt_3)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Some new";
    std::string blowfish_result = "320491D0BF5343B8EAE90D60400CB007B7384B3A20B1DB42";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_encrypt_4)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    std::string blowfish_result = "8264D1A649DFA1D8B9FE3A7478A5826CA8A8BD8CFEBFF9D6DBACCFB84626CF89ED310FE46E69F09F131A3F4E2BFEA36E070588A4A9D28DC38ECFF45C10A1AEB9E25ABC0BE16A4E2A6F570DF327E9B71B8E80C3D313C78225D963B7C918E829340D04616DE566F6807E93078C615A46539AD24CA8DDB572F1C4C6FED6F373FE67754BC8F73E21B0DE0DB328F5EA0E2AA937F01B7456855D35BC4B66451E3C641D0B1199E5287B250673A9284D3CC75C185258C222E98C3F893A857576AAE17BCDC153DECC2B4CA76AF75E3925EB5FC4D4416AC2E20FC9D100F5E547A25697180160A264C9A44FFD4DB4819CF99692E5599F9AB6AEDD0A5D4FF15A104AAFD9815C16D26014A73EE67900C72097E16F504908B7EAFC5460A1CA9E8EDF5E5F5AE774FD27E5F1BFF11C8B87B6C6B7E376AEBEB2E5C23983BF583C9E8FF69BD087E8B3436A0103A556FF3794652269852266908197EB65D43BD43E965B8BD9F039895A14A894263D823855C61CF338A0F792C0B9418968E5CD08F079116C8938901730045B3F2E1DF8BB0ED5E7827F1713848BD92B33A26DD2D32196EF80B291CA02C3FD383EB2A85547B00AD59DB066A8A2B7BB5EE53E899CC36761FD76159BB91FC234D905558994276FD3A317FDDDED900A";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_decrypt_1)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "7E06EF51A06513BE2A0DDF346FE4F3682DACABC62CC23D31";
    std::string original = "Hello";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}

TEST_F(blowfish_test, string_test_decrypt_2)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "9DEDF65D0D37FF2226B9AD938B72D34812982518130AE858";
    std::string original = "Some";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}

TEST_F(blowfish_test, string_test_decrypt_3)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "320491D0BF5343B8EAE90D60400CB007B7384B3A20B1DB42";
    std::string original = "Some new";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}

TEST_F(blowfish_test, string_test_decrypt_4)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "8264D1A649DFA1D8B9FE3A7478A5826CA8A8BD8CFEBFF9D6DBACCFB84626CF89ED310FE46E69F09F131A3F4E2BFEA36E070588A4A9D28DC38ECFF45C10A1AEB9E25ABC0BE16A4E2A6F570DF327E9B71B8E80C3D313C78225D963B7C918E829340D04616DE566F6807E93078C615A46539AD24CA8DDB572F1C4C6FED6F373FE67754BC8F73E21B0DE0DB328F5EA0E2AA937F01B7456855D35BC4B66451E3C641D0B1199E5287B250673A9284D3CC75C185258C222E98C3F893A857576AAE17BCDC153DECC2B4CA76AF75E3925EB5FC4D4416AC2E20FC9D100F5E547A25697180160A264C9A44FFD4DB4819CF99692E5599F9AB6AEDD0A5D4FF15A104AAFD9815C16D26014A73EE67900C72097E16F504908B7EAFC5460A1CA9E8EDF5E5F5AE774FD27E5F1BFF11C8B87B6C6B7E376AEBEB2E5C23983BF583C9E8FF69BD087E8B3436A0103A556FF3794652269852266908197EB65D43BD43E965B8BD9F039895A14A894263D823855C61CF338A0F792C0B9418968E5CD08F079116C8938901730045B3F2E1DF8BB0ED5E7827F1713848BD92B33A26DD2D32196EF80B291CA02C3FD383EB2A85547B00AD59DB066A8A2B7BB5EE53E899CC36761FD76159BB91FC234D905558994276FD3A317FDDDED900A";
    std::string original = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}