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
 * @brief Тип синхронизации базы данных SQLite
 * @author SavaLione
 * @date 12 Dec 2020
 */
#ifndef DB_SQLITE_SQLITE_SYNCHRONOUS_H
#define DB_SQLITE_SQLITE_SYNCHRONOUS_H

#include <string>

/*
    PRAGMA schema.synchronous;
    PRAGMA schema.synchronous = 0 | OFF | 1 | NORMAL | 2 | FULL | 3 | EXTRA;

    Query or change the setting of the "synchronous" flag.
    The first (query) form will return the synchronous setting as an integer.
    The second form changes the synchronous setting.
    The meanings of the various synchronous settings are as follows:

    EXTRA (3)
        EXTRA synchronous is like FULL with the addition that the directory containing a rollback journal
        is synced after that journal is unlinked to commit a transaction in DELETE mode.
        EXTRA provides additional durability if the commit is followed closely by a power loss.
    FULL (2)
        When synchronous is FULL (2), the SQLite database engine will use the xSync method of the VFS
        to ensure that all content is safely written to the disk surface prior to continuing.
        This ensures that an operating system crash or power failure will not corrupt the database.
        FULL synchronous is very safe, but it is also slower. FULL is the most commonly used synchronous
        setting when not in WAL mode.
    NORMAL (1)
        When synchronous is NORMAL (1), the SQLite database engine will still sync at the most
        critical moments, but less often than in FULL mode.
        There is a very small (though non-zero) chance that a power failure at just the wrong time
        could corrupt the database in journal_mode=DELETE on an older filesystem.
        WAL mode is safe from corruption with synchronous=NORMAL, and probably DELETE mode is
        safe too on modern filesystems. WAL mode is always consistent with synchronous=NORMAL,
        but WAL mode does lose durability.
        A transaction committed in WAL mode with synchronous=NORMAL might roll back following a power
        loss or system crash.
        Transactions are durable across application crashes regardless of the synchronous setting or
        journal mode.
        The synchronous=NORMAL setting is a good choice for most applications running in WAL mode.
    OFF (0)
        With synchronous OFF (0), SQLite continues without syncing as soon as it has handed data
        off to the operating system.
        If the application running SQLite crashes, the data will be safe, but the database might
        become corrupted if the operating system crashes or the computer loses power before that data
        has been written to the disk surface. On the other hand, commits can be orders of magnitude
        faster with synchronous OFF.
    
    In WAL mode when synchronous is NORMAL (1), the WAL file is synchronized before each checkpoint
    and the database file is synchronized after each completed checkpoint and the WAL file header is
    synchronized when a WAL file begins to be reused after a checkpoint, but no sync operations occur
    during most transactions.
    With synchronous=FULL in WAL mode, an additional sync operation of the WAL file happens
    after each transaction commit.
    The extra WAL sync following each transaction help ensure that transactions are durable across a power loss.
    Transactions are consistent with or without the extra syncs provided by synchronous=FULL.
    If durability is not a concern, then synchronous=NORMAL is normally all one needs in WAL mode.

    The TEMP schema always has synchronous=OFF since the content of of TEMP is ephemeral and is not expected
    to survive a power outage. Attempts to change the synchronous setting for TEMP are silently ignored.
*/
enum sqlite_synchronous
{
    SQLITE_SYNCHRONOUS_EXTRA = 3,
    SQLITE_SYNCHRONOUS_FULL = 2,
    SQLITE_SYNCHRONOUS_NORMAL = 1,
    SQLITE_SYNCHRONOUS_OFF = 0
};

/* Получить строковое представление типа синхронизации sqlite */
const std::string string_sqlite_synchronous(sqlite_synchronous const &synchronous);

/* Получить строку с параметром для sqlite */
const std::string get_sqlite_synchronous(sqlite_synchronous const &synchronous);

#endif // DB_SQLITE_SQLITE_SYNCHRONOUS_H