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
 * @brief Working with mysql database
 * @author SavaLione
 * @date 16 Nov 2020
 */
#include "db/db_mysql.h"

#include "core/settings.h"

using namespace std;

db_mysql::~db_mysql()
{
    delete stmt;
    delete con;
}

db_mysql::db_mysql()
{
    settings &instance = settings::Instance();

    cout << "Connect to db" << endl;
    try
    {
        sql::Driver *driver;
        driver = get_driver_instance();
        con = driver->connect(instance.db_host(), instance.db_username(), instance.db_password());
        con->setSchema(instance.db_name());
        stmt = con->createStatement();
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void db_mysql::runc()
{
    cout << "Running: SELECT * FROM test_table;" << endl;

    try
    {
        sql::ResultSet *res;
        res = stmt->executeQuery("SELECT * FROM test_table;");
        while (res->next())
        {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("user") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            cout << res->getString(1) << " " << res->getString(2) << " " << res->getString(3) << endl;
        }
        delete res;
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    //return EXIT_SUCCESS;
}

/*
    SELECT column_name FROM table_name WHERE column_name = 'data';
*/
const bool db_mysql::has(std::string const &table_name, std::string const &column_name, std::string const &data)
{
    try
    {
        sql::ResultSet *res;
        std::string sql = "SELECT ";
        sql += column_name;
        sql += " FROM ";
        sql += table_name;
        sql += " WHERE ";
        sql += column_name;
        sql += " = '";
        sql += data;
        sql += "';";

        res = stmt->executeQuery(sql);
        while (res->next())
        {
            return true;
        }
        delete res;
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return false;
}

/*
    table_name - table name
    column_names - column names
        user password date mail
    data - data to insert
        sava savapas savadate savamail lione lionepas lionedate lionemail
        It means:
        sava  savapas  savadate  savamail
        lione lionepas lionedate lionemail
        Full:

        user  password date      mail
        ----  -------- --------  --------
        sava  savapas  savadate  savamail
        lione lionepas lionedate lionemail

*/
const bool db_mysql::add(std::string const &table_name, std::vector<std::string> const &column_names, std::vector<std::string> const &data)
{
    try
    {
        sql::ResultSet *res;
        std::string sql = "INSERT ";
        sql += table_name;
        sql += "(";
        for (int i = 0; i < column_names.size(); i++)
        {
            sql += column_names[i];
            if (i != (column_names.size() - 1))
            {
                sql += ",";
            }
        }
        sql += ") VALUES ";

        for (int i = 0; i < data.size() / column_names.size(); i++)
        {
            sql += "(";
            for (int k = i * column_names.size(); k < i * column_names.size() + column_names.size(); k++)
            {
                sql += data[k];
                if (k != i * column_names.size() + column_names.size() - 1)
                {
                    sql += ",";
                }
            }
            sql += ")";
            if (i != (data.size() / column_names.size() - 1))
            {
                sql += ",";
            }
        }
        sql += ";";

        res = stmt->executeQuery(sql);

        delete res;
    }
    catch (sql::SQLException &e)
    {
        if (!e.getErrorCode())
        {
            return true;
        }
        else
        {
            cout << "# ERR: SQLException in " << __FILE__;
            cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            return false;
        }
    }
    return false;
}

const std::string db_mysql::get_string(std::string const &table_name, std::string const &column_name, std::string const &where)
{
    try
    {
        sql::ResultSet *res;
        std::string sql = "SELECT ";
        sql += column_name;
        sql += " FROM ";
        sql += table_name;
        sql += " WHERE ";
        sql += column_name;
        sql += " = '";
        sql += where;
        sql += "';";

        res = stmt->executeQuery(sql);
        while (res->next())
        {
            std::cout << res->getString(1) << std::endl;
            return res->getString(1);
        }
        delete res;
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return "";
}