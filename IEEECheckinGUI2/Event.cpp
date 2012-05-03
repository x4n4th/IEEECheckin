#include "Event.h"
#include <QMessageBox>
#include <qpalette.h>

Event::Event(QWidget *parent, Qt::WFlags flags) : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    connect(ui.AddUserpushButton, SIGNAL(clicked()), this, SLOT(UserAdd())); 
}

Event::~Event()
{

}
void Event::Exit()
{
    this->close();
}
void Event::Initialize(MYSQL *Connection, string Points, State& ConnectionState, vector<string> *queue)
{
    this->show();
    connection = Connection;
    points = Points;
    state = ConnectionState;
    Queue = queue;
}
void Event::UserAdd()
{
    AddUser *w = new AddUser;
    w->Initialize(connection, points, state, Queue);
}
void Event::SwipeEvent()
{           
    MYSQL_RES *result;
    MYSQL_ROW row;

    if(state.isOnline())
    {
        if(mysql_query(connection, "show engines"))
        {
            mysql_close(connection);
            state.setOfflineMode();
        }
        result = mysql_store_result(connection);
        row = mysql_fetch_row(result);
    }

    string userInput = ui.lineEdit->text().toStdString();
    ui.lineEdit->clear();

    boost::regex re("/?;([0-9]{16})=");
    boost::match_results<string::const_iterator> matches;
    boost::match_flag_type flags = boost::match_default;

        
    if (!boost::regex_search(userInput, matches, re, boost::match_default))  
    {
        //QMessageBox::about(this,"Error","Invalid Swipe");
        QPalette plt;
        plt.setColor(QPalette::WindowText, Qt::red);
        ui.label->setPalette(plt);
    }
    else
    {      
        string studentID = matches[1];
        
        if(state.isOnline())
        {    
            string myQuery;
            int query_state = 0;

            QPalette plt;
            plt.setColor(QPalette::WindowText, Qt::green);
            ui.label->setPalette(plt);

            myQuery =  "SELECT studentID FROM checkin WHERE studentID = '" + studentID + "'";

            query_state = mysql_query(connection, myQuery.c_str());
            if (query_state !=0) 
            {
                QMessageBox::about(this,"MySQL ERROR",mysql_error(connection));
            }

            result = mysql_store_result(connection);
            row = mysql_fetch_row(result);

            if(mysql_num_rows(result))
            {
                myQuery =  "UPDATE checkin SET points = points + " + points + " WHERE studentID = '" + studentID + "'";

                SendQueryThread(connection, myQuery);
                
            }
            else
            {
                AddUser *w = new AddUser;
                w->EventInitialize(connection, points, studentID, state);
            }
        }
        else
        {
            AddUser *w = new AddUser;
            w->EventInitialize(connection, points, studentID, state);
        }
    }
}
void Event::UpdateStudentRow(string& myQuery, string& studentID)
{
    int query_state;
    
    MYSQL_RES *result;
    MYSQL_ROW row;

    query_state = mysql_query(connection, myQuery.c_str());
    if (query_state !=0) 
    {
        std::cout << mysql_error(connection) << endl;
    } 
}

void Event::ColorChangeOnSwipe()
{
    QPalette plt;
    plt.setColor(QPalette::WindowText, Qt::black);
    ui.label->setPalette(plt);
}