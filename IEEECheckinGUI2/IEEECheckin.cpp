#include <QProgressBar>
#include <qfiledialog.h>
#include <boost\date_time.hpp>
#include <boost\timer.hpp>
#include <boost\thread.hpp>

#include "ieeecheckin.h"
#include "ieeecheckingui2.h"
#include "AddUser.h"
#include "Event.h"
#include "ExcelExport.h"

IEEECheckin::IEEECheckin(QWidget *parent, Qt::WFlags flags): QMainWindow(parent, flags)
{
    ui.setupUi(this);
    connect(ui.ExportButton, SIGNAL(clicked()), this, SLOT(Report()));
    connect(ui.AddMemberButton, SIGNAL(clicked()), this, SLOT(UserAdd())); 
    connect(ui.ClearButton, SIGNAL(clicked()), this, SLOT(ClearList())); 
    connection = NULL;
}
IEEECheckin::~IEEECheckin()
{

}
void IEEECheckin::startMySQL()
{
    IEEECheckinGUI2 *w = new IEEECheckinGUI2;
    w->Initialize(this);

    if(connection != NULL)
    {
       ConsumerQueue *consumer = new ConsumerQueue(connection);
      // boost::thread thread(&ConsumerQueue::Consume, consumer);
    }
}
void IEEECheckin::stopMySQL()
{
    mysql_close(connection);

    ui.AddMemberButton->setEnabled(false);
    ui.ClearButton->setEnabled(false);
    ui.ExportButton->setEnabled(false);
}
void IEEECheckin::UserAdd()
{
    AddUser *w = new AddUser;
    string points = ui.pointsField->text().toStdString();
    w->Initialize(connection, points, state, Queue);
}
void IEEECheckin::startEvent()
{
    Event *w = new Event;

    string points = ui.pointsField->text().toStdString();
    state.setLocation(ui.LocationField->text().toStdString()); 
    state.setName(ui.EventName->text().toStdString());
    state.setPoints(ui.pointsField->text().toInt());


    w->Initialize(connection, points, state, Queue);
}

void IEEECheckin::InitializeConnection(MYSQL *Connection)
{
    connection = Connection;

    if(connection == 0)
    {
        state.setOfflineMode();
    }
    else
    {
        state.setOnlineMode();
    }

    if(state.isOnline())
    {
        try
        {
            UpdateMembers(connection);
        }
        catch(string exception)
        {
            ui.textEdit->append(exception.c_str());
        }
    }

    ui.AddMemberButton->setEnabled(true);
    ui.ClearButton->setEnabled(true);
    ui.ExportButton->setEnabled(true);

    //this->show();
    try
    {
        Report();
    }
    catch(QString exception)
    {
        ui.textEdit->append(exception);
    }
}

void IEEECheckin::ClearList()
{
    ui.textEdit->clear();
}

//Reports current members to text edit field
void IEEECheckin::Report()
{
    int query_state;
    MYSQL_RES *result;
    MYSQL_ROW row;

    if(state.isOnline())
    {
        if(mysql_query(connection, "show engines"))
        {
            mysql_close(connection);
            state.setOfflineMode();
            Offline();
        }
        else
        {         
            result = mysql_store_result(connection);
            row = mysql_fetch_row(result);
        }
    }


    if(connection == NULL && state.isOnline())
    {
        QString exception = "Connection to SQL server was NULL";
        throw exception;
    }

    if(state.isOnline())
    {
        ui.textEdit->append("Exporting a list of current members");

        string myQuery;

        myQuery =  "SELECT emailAddress, cardID, studentName, points FROM members";
        
        query_state = mysql_query(connection, myQuery.c_str());
        if (query_state !=0) 
        {
            ui.textEdit->append(mysql_error(connection));
        }

        result = mysql_store_result(connection);
        row = mysql_fetch_row(result);

        ui.ExportprogressBar->setEnabled(true);
        ui.ExportprogressBar->setMaximum(result->row_count);

        ulonglong r = 0;

        while((row = mysql_fetch_row(result))) 
        {
            QString Row;

            for(size_t i = 0; i < mysql_field_count(connection); i++)
            {
                Row += row[i];
                Row += " ";
            }
            r++;
            ui.ExportprogressBar->setValue(r);

            ui.textEdit->append(Row);

            //boost::this_thread::interruptible_wait(100);
        }
        ui.ExportprogressBar->setValue(0);
        ui.ExportprogressBar->setEnabled(true);
    }
    else
    {
        ui.textEdit->append("Feature Not Supported For Offline Mode");
    }
}

//Slots To report to excel
void IEEECheckin::ExportToExcel()
{
    MYSQL_RES *result;
    MYSQL_ROW row;

    if(state.isOnline())
    {
        if(mysql_query(connection, "show engines"))
        {
            mysql_close(connection);
            state.setOfflineMode();
            Offline();
        }
        else
        {         
            result = mysql_store_result(connection);
            row = mysql_fetch_row(result);
        }
    }

    if(state.isOnline())
    {
        QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save to Excel"), "",
            tr("Address Book (*.csv);;All Files (*)"));

        ExcelExportThread(connection, fileName.toStdString());
    }
}

void IEEECheckin::Offline()
{
    state.setOfflineMode();
    ui.AddMemberButton->setEnabled(true);
    ui.ClearButton->setEnabled(true);
    ui.ExportButton->setEnabled(false);
}

void IEEECheckin::createEvent(){
    /*string myQuery = "INSERT INTO Events (name, location, points) VALUES ('" + ui.EventName + "', '" +   + "', '" + name + "', '" + points + ")";

        
    query_state = mysql_query(connection, myQuery.c_str());
    if (query_state !=0) 
    {
        ui.textEdit->append(mysql_error(connection));
    }

    result = mysql_store_result(connection);
    row = mysql_fetch_row(result);*/
}