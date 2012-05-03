#pragma once

#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <boost\thread.hpp>

#include "email.h"
#include "ExcelExport.h"

void SendQuery(MYSQL *connection, std::string& myQuery);
void SendQueryThread(MYSQL *connection, std::string& myQuery);
void SendEmailThread(std::string& email);
void ExcelExportThread(MYSQL *connection, std::string fileName);