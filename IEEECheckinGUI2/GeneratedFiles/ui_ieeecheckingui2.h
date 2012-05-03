/********************************************************************************
** Form generated from reading UI file 'ieeecheckingui2.ui'
**
** Created: Mon Apr 30 01:17:12 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IEEECHECKINGUI2_H
#define UI_IEEECHECKINGUI2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IEEECheckinGUI2Class
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditPassword;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditHost;
    QLabel *label_2;
    QLineEdit *lineEditDataBase;
    QLineEdit *lineEditUserName;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonCancel;

    void setupUi(QMainWindow *IEEECheckinGUI2Class)
    {
        if (IEEECheckinGUI2Class->objectName().isEmpty())
            IEEECheckinGUI2Class->setObjectName(QString::fromUtf8("IEEECheckinGUI2Class"));
        IEEECheckinGUI2Class->resize(399, 96);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        IEEECheckinGUI2Class->setWindowIcon(icon);
        centralWidget = new QWidget(IEEECheckinGUI2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEditPassword = new QLineEdit(centralWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(280, 40, 113, 20));
        lineEditPassword->setInputMethodHints(Qt::ImhHiddenText);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 40, 51, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 51, 16));
        lineEditHost = new QLineEdit(centralWidget);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));
        lineEditHost->setGeometry(QRect(80, 10, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 10, 61, 16));
        lineEditDataBase = new QLineEdit(centralWidget);
        lineEditDataBase->setObjectName(QString::fromUtf8("lineEditDataBase"));
        lineEditDataBase->setGeometry(QRect(80, 40, 113, 20));
        lineEditDataBase->setLayoutDirection(Qt::LeftToRight);
        lineEditUserName = new QLineEdit(centralWidget);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(280, 10, 113, 20));
        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(120, 70, 75, 23));
        pushButtonCancel = new QPushButton(centralWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(200, 70, 75, 23));
        IEEECheckinGUI2Class->setCentralWidget(centralWidget);
        QWidget::setTabOrder(lineEditHost, lineEditDataBase);
        QWidget::setTabOrder(lineEditDataBase, lineEditUserName);
        QWidget::setTabOrder(lineEditUserName, lineEditPassword);
        QWidget::setTabOrder(lineEditPassword, pushButtonConnect);
        QWidget::setTabOrder(pushButtonConnect, pushButtonCancel);

        retranslateUi(IEEECheckinGUI2Class);

        QMetaObject::connectSlotsByName(IEEECheckinGUI2Class);
    } // setupUi

    void retranslateUi(QMainWindow *IEEECheckinGUI2Class)
    {
        IEEECheckinGUI2Class->setWindowTitle(QApplication::translate("IEEECheckinGUI2Class", "Connect to Server", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IEEECheckinGUI2Class", "Host:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IEEECheckinGUI2Class", "Password:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("IEEECheckinGUI2Class", "DataBase:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IEEECheckinGUI2Class", "User Name:", 0, QApplication::UnicodeUTF8));
        lineEditDataBase->setText(QApplication::translate("IEEECheckinGUI2Class", "checkin", 0, QApplication::UnicodeUTF8));
        pushButtonConnect->setText(QApplication::translate("IEEECheckinGUI2Class", "Connect", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("IEEECheckinGUI2Class", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IEEECheckinGUI2Class: public Ui_IEEECheckinGUI2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IEEECHECKINGUI2_H
