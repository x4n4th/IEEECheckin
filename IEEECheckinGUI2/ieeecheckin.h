#ifndef IEEECHECKIN_H
#define IEEECHECKIN_H

#include <QtGui/QMainWindow>
#include <WinSock2.h>
#include <mysql.h>
#include <vector>

#include "ui_IEEECheckin.h"
#include "MySQLConnection.h"
#include "State.h"
#include "UpdateDataBase.h"
#include "ConsumerQueue.h"

class IEEECheckin : public QMainWindow
{
    Q_OBJECT

public:
    IEEECheckin(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~IEEECheckin();
    void InitializeConnection(MYSQL *connection);
    public slots:
        void startMySQL();
        void stopMySQL();
        void Report();
        void UserAdd();
        void startEvent();
        void ClearList();
        void ExportToExcel();
        void Offline();
        void createEvent();
private:
    Ui::IEEECheckin ui;
    MYSQL *connection;
    State state;
    vector<string> *Queue;
};

#endif
