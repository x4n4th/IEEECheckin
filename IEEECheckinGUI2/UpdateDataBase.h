//DataBase Update Handeler
#pragma once

#include <WinSock2.h>
#include <mysql.h>
#include <string>

using namespace std;

void UpdateMembers(MYSQL *connection);
void Query(MYSQL *connection, string& myQuery);
string esc(MYSQL *connection, string& toEscape);