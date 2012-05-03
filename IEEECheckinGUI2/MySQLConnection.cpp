#include "MySQLConnection.h"

void MySQLConnection::InitializeConnection(string host, string user, string password, string database, int port)
{
     mysql_init(&mysql);

     connection = Connect(host, user, password, database, port);

     if(connection != NULL)
        CreateStructure();
}
void MySQLConnection::CreateStructure()
{
   string myQuery = "CREATE TABLE IF NOT EXISTS checkin( emailAddress varchar(50), studentID int(20) NOT NULL, accessID varchar(50) NOT NULL, points int(10) NOT NULL, time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, PRIMARY KEY (`email`))";
   //boost::thread workerThread(Query, myQuery);
   Query(myQuery);
}
void MySQLConnection::Query(string& myQuery)
{
    int query_state = mysql_query(connection, myQuery.c_str());
    if (query_state !=0) 
    {
        std::cout << mysql_error(connection) << endl;
    }
}
void MySQLConnection::Disconnect()
{
    mysql_close(connection);
}

MYSQL* MySQLConnection::GetConnection()
{
    return connection;
}

MYSQL MySQLConnection::Getmysql()
{
    return mysql;
}

MYSQL* MySQLConnection::Connect(string& host, string& user, string& password, string& database, int port)
{
    const string constHost = host;
    const string constUser = user; 
    const string constPassword = password;
    const string constDatabase = database;

    return mysql_real_connect(&mysql,constHost.c_str(),constUser.c_str(), constPassword.c_str(),constDatabase.c_str(),port,0,0);
    return NULL;
}