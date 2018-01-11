#include "history_record.h"
#include"QMessageBox"
#include "ui_history_record.h"

history_record::history_record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history_record)
{
    ui->setupUi(this);
    this->setWindowTitle("HISTORY_RECORD");
}

history_record::~history_record()
{
    delete ui;
}


void history_record::load_historyrecord(QString myname, QString sendname)
{
    QString my_name=myname;
    QString send_name=sendname;
    QDir *mulu=new QDir();
    QString str_mulu="E:/ServerStore/"+myname+"_"+send_name;
    bool exist=mulu->exists(str_mulu);

    if(exist)//////目录存在课进行读取，
    {
        QString fileName = str_mulu+"/a.txt";
        QString str_line;
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);
            qDebug()<<"wenjian dakai shi bai zai history zhong jinxing xianshide shihou!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }
        QTextStream in(&file);
        str_line=in.readAll();//读取一行//如果读取多行

        ui->textBrowser->append(str_line);

        file.flush();
        file.close();
    }
    else
        qDebug()<<"has a fail in the dir ,there no it";
}

void history_record::on_pushButton_clicked()
{
    this->close();
}
