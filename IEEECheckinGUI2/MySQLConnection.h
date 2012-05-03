// MySQLConnection.h - Handles SQL connection
// Written by Dan Lafey

#pragma once

#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <QMessageBox>
#include <boost\thread.hpp>

#pragma comment (lib,"libmysql.lib")
#pragma comment (lib,"mysqlclient.lib")

using namespace std;

class MySQLConnection
{
public:
    void InitializeConnection(string, string, string, string, int);

    void CreateStructure();

    void Query(string& myQuery);

    void Disconnect();

	MYSQL* GetConnection();

    MYSQL Getmysql();
private:
    MYSQL* Connect(string& host, string& user, string& password, string& database, int port);

	MYSQL *connection;
    MYSQL mysql;
};