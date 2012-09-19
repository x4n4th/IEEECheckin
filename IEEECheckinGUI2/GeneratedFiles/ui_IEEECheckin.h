/********************************************************************************
** Form generated from reading UI file 'IEEECheckin.ui'
**
** Created: Tue Sep 18 21:13:00 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IEEECHECKIN_H
#define UI_IEEECHECKIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IEEECheckin
{
public:
    QAction *actionConncet;
    QAction *actionDisconnect;
    QAction *actionToExcel;
    QAction *actionConnect;
    QAction *actionStart_Event;
    QAction *actionAdd_User;
    QAction *actionOffline_Mode;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QPushButton *ExportButton;
    QPushButton *ClearButton;
    QPushButton *AddMemberButton;
    QLineEdit *pointsField;
    QLabel *label;
    QProgressBar *ExportprogressBar;
    QLineEdit *EventName;
    QLineEdit *LocationField;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *createEventButton;
    QLabel *label_4;
    QLineEdit *EventNumber;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuEvent;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IEEECheckin)
    {
        if (IEEECheckin->objectName().isEmpty())
            IEEECheckin->setObjectName(QString::fromUtf8("IEEECheckin"));
        IEEECheckin->resize(641, 510);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        IEEECheckin->setWindowIcon(icon);
        actionConncet = new QAction(IEEECheckin);
        actionConncet->setObjectName(QString::fromUtf8("actionConncet"));
        actionDisconnect = new QAction(IEEECheckin);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionToExcel = new QAction(IEEECheckin);
        actionToExcel->setObjectName(QString::fromUtf8("actionToExcel"));
        actionConnect = new QAction(IEEECheckin);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionStart_Event = new QAction(IEEECheckin);
        actionStart_Event->setObjectName(QString::fromUtf8("actionStart_Event"));
        actionAdd_User = new QAction(IEEECheckin);
        actionAdd_User->setObjectName(QString::fromUtf8("actionAdd_User"));
        actionOffline_Mode = new QAction(IEEECheckin);
        actionOffline_Mode->setObjectName(QString::fromUtf8("actionOffline_Mode"));
        centralWidget = new QWidget(IEEECheckin);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 210, 621, 201));
        textEdit->setReadOnly(true);
        ExportButton = new QPushButton(centralWidget);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setEnabled(false);
        ExportButton->setGeometry(QRect(10, 180, 121, 21));
        ClearButton = new QPushButton(centralWidget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setEnabled(false);
        ClearButton->setGeometry(QRect(140, 180, 75, 21));
        AddMemberButton = new QPushButton(centralWidget);
        AddMemberButton->setObjectName(QString::fromUtf8("AddMemberButton"));
        AddMemberButton->setEnabled(false);
        AddMemberButton->setGeometry(QRect(550, 180, 75, 23));
        pointsField = new QLineEdit(centralWidget);
        pointsField->setObjectName(QString::fromUtf8("pointsField"));
        pointsField->setGeometry(QRect(450, 80, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 80, 91, 16));
        ExportprogressBar = new QProgressBar(centralWidget);
        ExportprogressBar->setObjectName(QString::fromUtf8("ExportprogressBar"));
        ExportprogressBar->setEnabled(false);
        ExportprogressBar->setGeometry(QRect(10, 430, 621, 23));
        ExportprogressBar->setValue(0);
        EventName = new QLineEdit(centralWidget);
        EventName->setObjectName(QString::fromUtf8("EventName"));
        EventName->setGeometry(QRect(450, 20, 113, 20));
        LocationField = new QLineEdit(centralWidget);
        LocationField->setObjectName(QString::fromUtf8("LocationField"));
        LocationField->setGeometry(QRect(450, 50, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 20, 91, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 50, 91, 16));
        createEventButton = new QPushButton(centralWidget);
        createEventButton->setObjectName(QString::fromUtf8("createEventButton"));
        createEventButton->setEnabled(false);
        createEventButton->setGeometry(QRect(450, 130, 121, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 20, 91, 16));
        EventNumber = new QLineEdit(centralWidget);
        EventNumber->setObjectName(QString::fromUtf8("EventNumber"));
        EventNumber->setGeometry(QRect(150, 20, 113, 20));
        IEEECheckin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IEEECheckin);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuEvent = new QMenu(menuBar);
        menuEvent->setObjectName(QString::fromUtf8("menuEvent"));
        IEEECheckin->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IEEECheckin);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        IEEECheckin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IEEECheckin);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IEEECheckin->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menuBar->addAction(menuEvent->menuAction());
        menuFile->addAction(actionConnect);
        menuFile->addAction(actionDisconnect);
        menuFile->addAction(actionOffline_Mode);
        menuExport->addAction(actionToExcel);
        menuEvent->addAction(actionStart_Event);

        retranslateUi(IEEECheckin);
        QObject::connect(actionConnect, SIGNAL(triggered()), IEEECheckin, SLOT(startMySQL()));
        QObject::connect(actionDisconnect, SIGNAL(triggered()), IEEECheckin, SLOT(stopMySQL()));
        QObject::connect(actionAdd_User, SIGNAL(triggered()), IEEECheckin, SLOT(UserAdd()));
        QObject::connect(actionStart_Event, SIGNAL(triggered()), IEEECheckin, SLOT(startEvent()));
        QObject::connect(actionToExcel, SIGNAL(triggered()), IEEECheckin, SLOT(ExportToExcel()));
        QObject::connect(actionOffline_Mode, SIGNAL(triggered()), IEEECheckin, SLOT(Offline()));
        QObject::connect(createEventButton, SIGNAL(clicked()), IEEECheckin, SLOT(createEvent()));

        QMetaObject::connectSlotsByName(IEEECheckin);
    } // setupUi

    void retranslateUi(QMainWindow *IEEECheckin)
    {
        IEEECheckin->setWindowTitle(QApplication::translate("IEEECheckin", "IEEECheckin", 0, QApplication::UnicodeUTF8));
        actionConncet->setText(QApplication::translate("IEEECheckin", "Connect", 0, QApplication::UnicodeUTF8));
        actionDisconnect->setText(QApplication::translate("IEEECheckin", "Disconnect", 0, QApplication::UnicodeUTF8));
        actionToExcel->setText(QApplication::translate("IEEECheckin", "ToExcel", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("IEEECheckin", "Connect", 0, QApplication::UnicodeUTF8));
        actionStart_Event->setText(QApplication::translate("IEEECheckin", "Start Event", 0, QApplication::UnicodeUTF8));
        actionAdd_User->setText(QApplication::translate("IEEECheckin", "Add User", 0, QApplication::UnicodeUTF8));
        actionOffline_Mode->setText(QApplication::translate("IEEECheckin", "Offline Mode", 0, QApplication::UnicodeUTF8));
        ExportButton->setText(QApplication::translate("IEEECheckin", "Export List of Members", 0, QApplication::UnicodeUTF8));
        ClearButton->setText(QApplication::translate("IEEECheckin", "Clear List", 0, QApplication::UnicodeUTF8));
        AddMemberButton->setText(QApplication::translate("IEEECheckin", "Add Member", 0, QApplication::UnicodeUTF8));
        pointsField->setText(QApplication::translate("IEEECheckin", "1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IEEECheckin", "Points For Event", 0, QApplication::UnicodeUTF8));
        EventName->setText(QApplication::translate("IEEECheckin", "Default", 0, QApplication::UnicodeUTF8));
        LocationField->setText(QApplication::translate("IEEECheckin", "EE East", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IEEECheckin", "Name Of Event", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IEEECheckin", "Location Of Event", 0, QApplication::UnicodeUTF8));
        createEventButton->setText(QApplication::translate("IEEECheckin", "Create Event", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("IEEECheckin", "Event Number", 0, QApplication::UnicodeUTF8));
        EventNumber->setText(QApplication::translate("IEEECheckin", "0", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("IEEECheckin", "File", 0, QApplication::UnicodeUTF8));
        menuExport->setTitle(QApplication::translate("IEEECheckin", "Export", 0, QApplication::UnicodeUTF8));
        menuEvent->setTitle(QApplication::translate("IEEECheckin", "Event", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IEEECheckin: public Ui_IEEECheckin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IEEECHECKIN_H
