#ifndef ADDUSER_H
#define ADDUSER_H

#include <QtGui/QMainWindow>
#include <WinSock2.h>
#include <mysql.h>
#include <boost/regex.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <QMessageBox>

#include "ui_AddUser.h"
#include "MySQLConnection.h"
#include "ieeecheckin.h"
#include "State.h"
#include "email.h"
#include "Threads.h"

class AddUser : public QMainWindow
{
    Q_OBJECT

public:
    AddUser(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~AddUser();
    void Initialize(MYSQL *connection, string points, State state, vector<string> *queue);
    void EventInitialize(MYSQL *connection, string points, string& studentID, State& state);
    void UpdateStudentRow(string& myQuery);
    string esc(MYSQL *connection, string& toEscape);
    public slots:
        void Insert();
        void Exit();

private:
    Ui::AddUser ui;
    MYSQL *connection;
    string name, email , cardID, myQuery, points;
    State OnlineState;
    vector<string> *Queue;
};

#endif
