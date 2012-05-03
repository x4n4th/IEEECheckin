#include "ExcelExport.h"
#include <iostream>
#include <fstream>

using namespace std;

void ExcelExport(MYSQL *connection, string filename)
{
    if(connection != NULL)
    {
        int query_state;
        MYSQL_RES *result;
        MYSQL_ROW row;

        ofstream out(filename);

        string myQuery;

        myQuery =  "SELECT emailAddress, studentID, accessID, points, time FROM checkin";
        
        query_state = mysql_query(connection, myQuery.c_str());
        if (query_state !=0) 
        {
            std::cout << mysql_error(connection) << endl;
        }

        result = mysql_store_result(connection);
        row = mysql_fetch_row(result);

        out << "Email Address,CardID,Name,points,Last Sign in" << endl;

        while((row = mysql_fetch_row(result))) 
        {
            for(size_t i = 0; i < mysql_field_count(connection); i++)
            {
                if(i < mysql_field_count(connection) - 1)
                    out << row[i] << ",";
                else
                    out << row[i] << " " << endl;

            }
        }
    }
}