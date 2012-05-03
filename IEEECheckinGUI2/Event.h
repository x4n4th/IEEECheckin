#ifndef EVENT_H
#define EVENT_H

#include <QtGui/QMainWindow>
#include <WinSock2.h>
#include <mysql.h>
#include <vector>

#include "ui_ieeecheckingui2.h"
#include "ieeecheckin.h"
#include "MySQLConnection.h"
#include "ui_Event.h"
#include "AddUser.h"
#include "State.h"
#include "Threads.h"


class Event : public QMainWindow
{
    Q_OBJECT

public:
    Event(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~Event();
    void Initialize(MYSQL *connection, string Points, State& ConnectionState, vector<string> *queue);
    void UpdateStudentRow(string& myQuery, string& studentID);
    public slots:
        void Exit();
        void UserAdd();
        void SwipeEvent();
        void ColorChangeOnSwipe();

private:
    Ui::Event ui;
    Event* w;
    MYSQL *connection;
    string points;
    State state;
    vector<string> *Queue;
};

#endif // EVENT_H
