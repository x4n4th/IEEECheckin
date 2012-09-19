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
   string myQuery;

   myQuery = "CREATE TABLE IF NOT EXISTS `Events` ("
             "`number` int(5) NOT NULL DEFAULT '0',"
             "`name` varchar(256) DEFAULT 'Default',"
             "`location` varchar(256) DEFAULT 'Default',"
             "`points` int(16) DEFAULT '0',"
             "`date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,"
             "PRIMARY KEY (`number`)"
             ") ENGINE=InnoDB DEFAULT CHARSET=latin1;";

   Query(myQuery);

   myQuery = "CREATE TABLE IF NOT EXISTS `checkin` ("
             "`num` int(9) NOT NULL AUTO_INCREMENT,"
             "`cardID` int(20) NOT NULL,"
             "`time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,"
             "`eventNumber` int(6) NOT NULL DEFAULT '0',"
             "PRIMARY KEY (`num`)"
             ") ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;";

   Query(myQuery);

   myQuery = "CREATE TABLE IF NOT EXISTS `members` ("
             "`cardID` bigint(20) NOT NULL,"
             "`studentName` varchar(60) DEFAULT NULL,"
             "`emailAddress` varchar(60) DEFAULT NULL,"
             "`points` int(16) DEFAULT NULL,"
             "PRIMARY KEY (`cardID`)"
             ") ENGINE=InnoDB DEFAULT CHARSET=latin1;";

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