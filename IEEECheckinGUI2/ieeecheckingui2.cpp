#include "ieeecheckingui2.h"
#include <QMessageBox>

IEEECheckinGUI2::IEEECheckinGUI2(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this); 
    connect(ui.pushButtonConnect, SIGNAL(clicked()), this, SLOT(Connect())); 
    connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(Dispose())); 
    ui.lineEditPassword->setEchoMode(QLineEdit::Password);
}

IEEECheckinGUI2::~IEEECheckinGUI2()
{

}
void IEEECheckinGUI2::Initialize(IEEECheckin* W)
{
    this->show();
    w = W;
}

void IEEECheckinGUI2::Connect()
{
    MySQLConnection *MySQLInstance = new MySQLConnection;

    MySQLInstance->InitializeConnection(ui.lineEditHost->text().toStdString(),ui.lineEditUserName->text().toStdString(),ui.lineEditPassword->text().toStdString(),ui.lineEditDataBase->text().toStdString(), 3306);
   
    MYSQL* connection = MySQLInstance->GetConnection();

    if(connection == NULL)
    {
        QMessageBox::about(this,"Error","Could Not Connect To Server Please Check Login Information");
            
        mysql_close(connection);
    }
    else
    {
        QMessageBox::about(this,"Thank you","Connected To Server!");
        w->InitializeConnection(connection);
        this->close();
    }
}

void IEEECheckinGUI2::Dispose()
{
    this->close();
}