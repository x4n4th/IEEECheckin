#pragma once

#include <iostream>
#include <my_global.h>
#include <mysql.h>
#include <string>

//Exports MySql Data to Excel
void ExcelExport(MYSQL *connection, std::string filename);
