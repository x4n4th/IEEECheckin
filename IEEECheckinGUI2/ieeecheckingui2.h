#ifndef IEEECHECKINGUI2_H
#define IEEECHECKINGUI2_H

#include <QtGui/QMainWindow>
#include <WinSock2.h>
#include <mysql.h>

#include "ui_ieeecheckingui2.h"
#include "ieeecheckin.h"
#include "MySQLConnection.h"

class IEEECheckinGUI2 : public QMainWindow
{
    Q_OBJECT

public:
    IEEECheckinGUI2(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~IEEECheckinGUI2();
    void Initialize(IEEECheckin*);
    public slots:
            void Connect();
            void Dispose();
private:
    Ui::IEEECheckinGUI2Class ui;
    IEEECheckin* w;
};

#endif // IEEECHECKINGUI2_H
