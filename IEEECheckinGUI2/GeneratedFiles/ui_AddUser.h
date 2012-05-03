/********************************************************************************
** Form generated from reading UI file 'AddUser.ui'
**
** Created: Mon Apr 30 00:50:06 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

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

class Ui_AddUser
{
public:
    QLabel *label;
    QLabel *label_4;
    QLineEdit *NameText;
    QLineEdit *EmailText;
    QPushButton *pushButtonSubmit;
    QLabel *label_2;
    QLineEdit *CardNumberText;
    QLabel *label_3;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *AddUser)
    {
        if (AddUser->objectName().isEmpty())
            AddUser->setObjectName(QString::fromUtf8("AddUser"));
        AddUser->resize(392, 139);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AddUser->setWindowIcon(icon);
        label = new QLabel(AddUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 40, 46, 13));
        label_4 = new QLabel(AddUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 40, 71, 16));
        NameText = new QLineEdit(AddUser);
        NameText->setObjectName(QString::fromUtf8("NameText"));
        NameText->setGeometry(QRect(140, 60, 113, 20));
        EmailText = new QLineEdit(AddUser);
        EmailText->setObjectName(QString::fromUtf8("EmailText"));
        EmailText->setGeometry(QRect(260, 60, 113, 20));
        pushButtonSubmit = new QPushButton(AddUser);
        pushButtonSubmit->setObjectName(QString::fromUtf8("pushButtonSubmit"));
        pushButtonSubmit->setGeometry(QRect(110, 100, 75, 23));
        label_2 = new QLabel(AddUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 40, 71, 16));
        CardNumberText = new QLineEdit(AddUser);
        CardNumberText->setObjectName(QString::fromUtf8("CardNumberText"));
        CardNumberText->setGeometry(QRect(20, 60, 113, 20));
        label_3 = new QLabel(AddUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 91, 16));
        pushButtonCancel = new QPushButton(AddUser);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(200, 100, 75, 23));
        QWidget::setTabOrder(CardNumberText, NameText);
        QWidget::setTabOrder(NameText, EmailText);
        QWidget::setTabOrder(EmailText, pushButtonSubmit);
        QWidget::setTabOrder(pushButtonSubmit, pushButtonCancel);

        retranslateUi(AddUser);

        QMetaObject::connectSlotsByName(AddUser);
    } // setupUi

    void retranslateUi(QWidget *AddUser)
    {
        AddUser->setWindowTitle(QApplication::translate("AddUser", "Add Member", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddUser", "Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddUser", "Card Number:", 0, QApplication::UnicodeUTF8));
        pushButtonSubmit->setText(QApplication::translate("AddUser", "Submit", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddUser", "Email Address:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddUser", "New Member", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("AddUser", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddUser: public Ui_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
