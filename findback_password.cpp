#include "findback_password.h"
#include "QMessageBox"
#include "ui_findback_password.h"

findback_password::findback_password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::findback_password)
{
    ui->setupUi(this);
}

findback_password::~findback_password()
{
    delete ui;
}

void findback_password::on_confirm_Button_clicked()
{

    QString name=ui->username_Edit->text();
    QString password=ui->password_edit->text();
    QString confirm_password=ui->confirm_password->text();
    if(name.size()==0||password.size()==0)
   {
        QMessageBox::information(this,"NO uername","please input username or passwd");
        return;
    }
    else if(password!=confirm_password)
    {
         QMessageBox::information(this,"Noooo","confirm is not right");
         return;
    }
    else
    {
        mytcpsct=new client_socket();
        mytcpsct->connectToHost("222.20.105.76",1234);

        QByteArray buffer;
        QDataStream out(&buffer,QIODevice::WriteOnly);
        out<<qint16(11);
        out<<name<<password;
        mytcpsct->write(buffer);
        connect(mytcpsct,SIGNAL(changeOK(int)),this,SLOT(changeisOK(int)));
    }
}

void findback_password::changeisOK(int isOK)
{
    if(isOK==1)
        QMessageBox::information(this,"OK","change password successfully!");
    else
        QMessageBox::information(this,"ERROR","change password failed!");
}

void findback_password::on_cancel_Button_clicked()
{
     delete mytcpsct;
     this->close();
}
