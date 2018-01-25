#include "receive_file.h"
#include "ui_receive_file.h"
#include <QDir>
#include<QTime>
#include<QTimer>
#include <QHostAddress>
#include <QMessageBox>
receive_file::receive_file(QWidget *parent,QString msg,QString my,quint16 portt,client_socket *socket) :
    QWidget(parent),
    ui(new Ui::receive_file)
{
    ui->setupUi(this);
    ui->label->setText(QString("filename %1 from %2").arg(fileName).arg(msg));
    mysocket=socket;
    msg_from=msg;
    myname=my;
    send_port=portt;

    //totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    linelen=0;
    groupnum=60000;
    windowsize=10;
    re_base=0;
    nextsqenum=re_base+windowsize-1;
    ackrec.clear();
    for(int i=0;i<groupnum;i++)
    {
        QPair<bool,checksum*> *pair=new QPair<bool,checksum*>(false,NULL);
        ackrec.push_back(pair);
    }
}

receive_file::~receive_file()
{
    delete ui;
}

void receive_file::setaddress(QHostAddress addr)
{
    send_addr=addr;
    return;
}

void receive_file::start_tranfor()
{
    qDebug()<<"tell us the connect is success!!!";
}

void receive_file::setfilename(QString filename, qint64 filesize)
{
    totalBytes=filesize;
    fileName=filename;
}

void receive_file::update_clientprocess()
{
    qDebug()<<"wenjian de fasong zai zhege shihou yijingkaishile --------4111111111111111";
    //int i=0;
    while(udpsocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(datagram.data(),datagram.size(),&send_addr,&send_port);
        QBuffer buffer(&datagram);
        buffer.open(QIODevice::ReadOnly);

        checksum *mychksum =new checksum;
        mychksum->Data.resize(mychksum->Size-4);
        QDataStream in(&buffer);
        in >> *mychksum;
        buffer.close();
        qDebug()<<"shou daole ma"<<mychksum->Data.size()<<" ACK  "<<mychksum->Ack<<" bian hao"<<mychksum->Number;
        if(mychksum->Ack==0)
        {
            qDebug()<<"ni yun xing le ma";
            checksum *ack=new checksum;
            ack->Ack=1;
            ack->Size=re_base;
            qDebug()<<"xia ci xiwang shoudao"<<ack->Size;
            ack->Number=mychksum->Number;
            if(re_base<nextsqenum)
            {
                if(re_base<=mychksum->Number && mychksum->Number<=nextsqenum)
                {
                    sendACk(*ack);
                    ackrec[mychksum->Number]->first=true;
                    ackrec[mychksum->Number]->second=mychksum;
                    while(ackrec[re_base]->first)
                    {
                        qDebug()<<"ni xiejin qu le ma";
                        localFile->write(ackrec[re_base]->second->Data);
                        bytesReceived += ackrec[re_base]->second->Data.size();
                        ackrec[re_base]->first=false;
                        delete ackrec[re_base]->second;
                        ackrec[re_base]->second=NULL;
                        if(++re_base==groupnum) re_base=0;
                        if(++nextsqenum==groupnum) nextsqenum=0;
                    }
                }
                else
                {
                    int index=mychksum->Number<re_base? mychksum->Number+groupnum:mychksum->Number;
                    if(index >= re_base-windowsize+groupnum && index<=re_base+groupnum)
                    {
                        sendACk(*ack);
                    }
                }
            }
            else
            {
                if(mychksum->Number<re_base && mychksum->Number>=re_base - windowsize )
                {
                    sendACk(*ack);
                }
                else if(mychksum->Number>=re_base || mychksum->Number<=nextsqenum)
                {
                    sendACk(*ack);
                    ackrec[mychksum->Number]->first=true;
                    ackrec[mychksum->Number]->second=mychksum;
                    while(ackrec[re_base]->first)
                    {
                        localFile->write(ackrec[re_base]->second->Data);
                        bytesReceived += ackrec[re_base]->second->Data.size();
                        ackrec[re_base]->first=false;
                        delete ackrec[re_base]->second;
                        ackrec[re_base]->second=NULL;
                        if(++re_base==groupnum) re_base=0;
                        if(++nextsqenum==groupnum) nextsqenum=0;
                    }
                }
            }
            delete ack;
        }
       ui->progressBar->setMaximum(totalBytes);
       qDebug()<<"wen jian da xiao "<<totalBytes;
       ui->progressBar->setValue(bytesReceived);
     qDebug()<<"shou dao ="<<bytesReceived;

     if(bytesReceived==totalBytes)
     {
         localFile->close();
         udpsocket->close();

         QMessageBox::information(this,"Finish","transform completed!");
         qDebug()<<"file trans over now";
         this->close();
         break;
     }

    }
}

void receive_file::sendACk(checksum &ack)
{
    QByteArray send;
    send.resize(sizeof(checksum));

    QBuffer buffer(&send);
    buffer.open(QIODevice::WriteOnly);

    QDataStream out(&buffer);
    out<<ack;
    buffer.close();

    udpsocket->writeDatagram(send.data(),send.size(),send_addr,send_port);
}

void receive_file::display_error(QAbstractSocket::SocketError)
{

}

void receive_file::on_pushButton_2_clicked()///表示拒绝接收文件
{
    qDebug()<<"refuse been push "<<"msgfrom "<<get_msgfrom()<<"myname"<<get_myname()<<"port is "<<get_port();
    QString msgfrom=get_msgfrom();
    QString my=get_myname();
    emit refuse_file(msgfrom,my);/////发送拒绝消息
    this->close();
}

void receive_file::on_pushButton_clicked()
{
    QString msgfrom=get_msgfrom();
    QString my=get_myname();

    QHostAddress myaddr=mysocket->localAddress();
    trans_port=5555;

    udpsocket=new QUdpSocket();
    udpsocket->bind(trans_port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    connect(udpsocket,SIGNAL(readyRead()),this,SLOT(update_clientprocess()),Qt::DirectConnection);
    //connect(this,SIGNAL(bytesReceived(qint64)),this,SLOT(update_process(qint64)));
    connect(udpsocket,SIGNAL(bytesReceived(qint64)),this,SLOT(update_process(qint64)));

    QString name = QFileDialog::getSaveFileName(0,"receivefile",fileName);
    if(!name.isEmpty())
    {
        qDebug()<<"fille name is the things doing in the flower"<<fileName;
    }

    localFile=new QFile(name);
    if(!localFile->open(QIODevice::WriteOnly|QIODevice::Unbuffered))
    {
        qDebug()<<"file open fail ,over it now!!-----352";
        return;
    }

    emit assure_receive(msgfrom,my,myaddr,trans_port);
    //QTimer *timer=new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(timeUpDate()));
    //timer->start(10000);
}

void receive_file::update_process(qint64 numbytes)
{
    ui->progressBar->setMaximum(totalBytes);
    qDebug()<<"wen jian da xiao "<<totalBytes;
    ui->progressBar->setValue(bytesReceived);
    /*if(bytesReceived==totalBytes)
    {
        localFile->close();
        udpsocket->close();

        QMessageBox::information(this,"Finish","transform completed!");
        qDebug()<<"file trans over now";
    }*/
    //QTimer::singleShot(1000,this,SLOT(update_process()));
}

void receive_file::timeUpDate()
{
    if(udpsocket->bytesAvailable()!=0)
    {
        qDebug()<<"RESTART";
        udpsocket->close ();
        udpsocket=new QUdpSocket(this);
        udpsocket->bind(trans_port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

        connect(udpsocket,SIGNAL(readyRead()),this,SLOT(update_clientprocess()),Qt::DirectConnection);
    }
}

