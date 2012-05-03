#include "Threads.h"

void SendQuery(MYSQL *connection, std::string& myQuery)
{
    int query_state;
    
    MYSQL_RES *result;
    MYSQL_ROW row;

    query_state = mysql_query(connection, myQuery.c_str());
    if (query_state !=0) 
    {
        //QMessageBox::about(this,"MySQLError",mysql_error(connection));
    }
}
//Threaded Query
void SendQueryThread(MYSQL *connection, std::string& myQuery)
{
    boost::thread workerThread(SendQuery, connection, myQuery);
}
//Threaded Email
void SendEmailThread(std::string& email)
{
    boost::thread workerThread(SendEmail, email);
}
//Threaded Excel Export Thread
void ExcelExportThread(MYSQL *connection, std::string fileName)
{
    ExcelExport(connection, fileName);
}