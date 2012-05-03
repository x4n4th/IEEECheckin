#include "UpdateDataBase.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void UpdateMembers(MYSQL *connection)
{
    ifstream in("OfflineData.txt");

    string name, email, cardID, points, myQuery;
    MYSQL_RES *result;
    MYSQL_ROW row;

    if(connection == NULL)
    {
        string exception = "Connection to SQL server was NULL";
        throw exception;
    }

    while(!in.eof())
	{
        
        getline(in, name);

        if(name == "")
            break;

        if(name[0] == '#')
        {
            continue;
        }
        else
        {
            getline(in, email);
            getline(in, cardID);
            getline(in, points);

            myQuery =  "SELECT studentID FROM checkin WHERE studentID = '" + cardID + "'";
        
            int query_state = mysql_query(connection, myQuery.c_str());
            if (query_state !=0) 
            {
                //QMessageBox::about(this,"Error",mysql_error(connection));
            }

            result = mysql_store_result(connection);

            if(mysql_num_rows(result))
            {          
                cardID = esc(connection, cardID);
                name = esc(connection, name);
                email = esc(connection, email);
                points = esc(connection, points);

                myQuery =  "UPDATE checkin SET points = points + " + points + " WHERE studentID = '" + cardID + "'";

                //boost::thread workerThread(UpdateStudentRow, connection, myQuery, studentID);
                Query(connection, myQuery);
            }
            else
            {
                cardID = esc(connection, cardID);
                name = esc(connection, name);
                email = esc(connection, email);
                points = esc(connection, points);

                myQuery = "INSERT INTO checkin (emailAddress, studentID, accessID, points, time) VALUES ('" + email + "', '" + cardID + "', '" + name + "', '" + points + "', CURRENT_TIMESTAMP )";

                //boost::thread workerThread(&AddUser::UpdateStudentRow, myQuery);
                Query(connection, myQuery);
            }
        }
    }
    in.close();

    ofstream out("OfflineData.txt");
    
    out << "# Offline mode output file: DO NOT Modify" << endl;

    out.close();
}
void Query(MYSQL *connection, string& myQuery)
{
    int query_state;
    
    MYSQL_RES *result;
    MYSQL_ROW row;

    query_state = mysql_query(connection, myQuery.c_str());
    if (query_state !=0) 
    {
       // QMessageBox::about(this,"MySQLError",mysql_error(connection));
    }
}
string esc(MYSQL *connection, string& toEscape)
{
    char* buf = new char[toEscape.length()];
    mysql_real_escape_string(connection, buf, toEscape.c_str(), toEscape.length());
    return string(buf);
}