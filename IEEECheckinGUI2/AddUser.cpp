#include "AddUser.h"
#include <fstream>
#include <QMessageBox>

AddUser::AddUser(QWidget *parent, Qt::WFlags flags) : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    connect(ui.pushButtonSubmit, SIGNAL(clicked()), this, SLOT(Insert()));
    connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(Exit()));
}

AddUser::~AddUser()
{

}
void AddUser::Exit()
{
    this->close();
}
void AddUser::Initialize(MYSQL *Connection, string Points, State state, vector<string> *queue)
{
    this->show();
    connection = Connection;
    points = Points;
    OnlineState = state;
    Queue = queue;
}
void AddUser::EventInitialize(MYSQL *Connection, string Points, string& studentID, State& state)
{
    this->show();
    connection = Connection;
    cardID = studentID;
    OnlineState = state;
    points = Points;
    ui.CardNumberText->setText(studentID.c_str());
    ui.CardNumberText->setReadOnly(true);

}
void AddUser::Insert()
{
    int query_state;
    
    MYSQL_RES *result;
    MYSQL_ROW row;
    bool cardIDpass = false;
    bool emailpass = false;

    name = ui.NameText->text().toStdString();
    email = ui.EmailText->text().toStdString();

    if(cardID == "")
    {
        cardID = ui.CardNumberText->text().toStdString();
    }

    if(cardID == "")
    {
        cardIDpass = true;
    }
    else
    {
        boost::regex re("^([0-9]{16})$");
        boost::match_results<string::const_iterator> matches;
        boost::match_flag_type flags = boost::match_default;

        
        if (boost::regex_search(cardID, matches, re, boost::match_default))  
        {
            cardIDpass = true;
        }
    }

    boost::regex re("[a-zA-z0-9._]*+[@]+[a-zA-Z0-9-]*+[.]+[a-zA-Z0-9]*");
    boost::match_results<string::const_iterator> matches;
    boost::match_flag_type flags = boost::match_default;

        
    if (boost::regex_search(email, matches, re, boost::match_default))  
    {
        emailpass = true;
    }

    if(name == "" || !emailpass || !cardIDpass)
    {
         QMessageBox::about(this,"Error","Please Enter All Information!");
    }
    else
    {
        if(OnlineState.isOnline())
        {
            myQuery =  "SELECT studentID FROM checkin WHERE studentID = '" + cardID + "'";

            query_state = mysql_query(connection, myQuery.c_str());
            if (query_state !=0) 
            {
                QMessageBox::about(this,"Error",mysql_error(connection));
            }

            result = mysql_store_result(connection);
            row = mysql_fetch_row(result);

            if(mysql_num_rows(result))
            {          
                QMessageBox::about(this,"Error","Student Found in Database");
            }
            else
            {
                cardID = esc(connection, cardID);
                name = esc(connection, name);
                email = esc(connection, email);

                myQuery = "INSERT INTO checkin (emailAddress, studentID, accessID, points, time) VALUES ('" + email + "', '" + cardID + "', '" + name + "', '" + points + "', CURRENT_TIMESTAMP )";

                SendEmailThread(email);

                SendQueryThread(connection, myQuery);

                //Queue->push_back(myQuery);

                this->close();
            }
        }
        else
        {
            name = ui.NameText->text().toStdString();
            email = ui.EmailText->text().toStdString();

            if(cardID == "")
            {
                cardID = ui.CardNumberText->text().toStdString();
            }

            ofstream out;
            out.open("OfflineData.txt", ios::out | ios::app);

            out << name << endl;
            out << email << endl;
            out << cardID << endl;
            out << points << endl;

            out.close();

            this->close();
        }
    }
}
void AddUser::UpdateStudentRow(string& myQuery)
{
    int query_state;
    
    MYSQL_RES *result;
    MYSQL_ROW row;

    query_state = mysql_query(connection, myQuery.c_str());
    if (query_state !=0) 
    {
        QMessageBox::about(this,"MySQLError",mysql_error(connection));
    }
}
string AddUser::esc(MYSQL *connection, string& toEscape)
{
    char* buf = new char[toEscape.length()];
    mysql_real_escape_string(connection, buf, toEscape.c_str(), toEscape.length());
    return string(buf);
}