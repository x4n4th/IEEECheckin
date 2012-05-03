/********************************************************************************
** Form generated from reading UI file 'Event.ui'
**
** Created: Mon Apr 30 00:50:06 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_H
#define UI_EVENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Event
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *AddUserpushButton;

    void setupUi(QWidget *Event)
    {
        if (Event->objectName().isEmpty())
            Event->setObjectName(QString::fromUtf8("Event"));
        Event->resize(464, 285);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Event->setWindowIcon(icon);
        label = new QLabel(Event);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 161, 61));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"MS Shell Dlg 2\";"));
        lineEdit = new QLineEdit(Event);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 110, 181, 21));
        AddUserpushButton = new QPushButton(Event);
        AddUserpushButton->setObjectName(QString::fromUtf8("AddUserpushButton"));
        AddUserpushButton->setGeometry(QRect(190, 170, 75, 23));

        retranslateUi(Event);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), Event, SLOT(SwipeEvent()));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), Event, SLOT(ColorChangeOnSwipe()));

        QMetaObject::connectSlotsByName(Event);
    } // setupUi

    void retranslateUi(QWidget *Event)
    {
        Event->setWindowTitle(QApplication::translate("Event", "IEEE Event", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Event", "Swipe id+ Card", 0, QApplication::UnicodeUTF8));
        AddUserpushButton->setText(QApplication::translate("Event", "SignUp", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Event: public Ui_Event {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_H
