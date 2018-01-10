#include "chat.h"
#include "ui_chat.h"
#include <QPalette>
#include <QDir>
#include <QBuffer>
#include <QTimer>
#include "chat_face.h"
#include "QMessageBox"

chat::chat(QWidget *parent,QString myname,QString name_tosend,int ispositive) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    this->myname=myname;
    this->name_tosend=name_tosend;
    this->ispositive=ispositive;
    this->iscansend=0;

    ui->front_size->insertItem(0,tr("8"));
    ui->front_size->insertItem(1,tr("9"));
    ui->front_size->insertItem(2,tr("10"));
    ui->front_size->insertItem(3,tr("11"));
    ui->front_size->insertItem(4,tr("12"));
    ui->front_size->insertItem(5,tr("13"));
    ui->front_size->insertItem(6,tr("14"));
    ui->front_size->insertItem(7,tr("15"));
    ui->front_size->insertItem(8,tr("16"));
    ui->front_size->insertItem(9,tr("17"));
    ui->front_size->insertItem(10,tr("18"));
    ui->front_size->insertItem(11,tr("19"));
    ui->front_size->insertItem(12,tr("20"));

    connect(ui->send_chat,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->close_chat,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));//////再筐子定义的时候链接到信号；
    //connect(ui->filetrans,SIGNAL(clicked()),this,SLOT(on_filetrans_clicked()));
}

chat::~chat()
{
    delete ui;
}

void chat::on_pushButton_2_clicked()
{
    this->close();
}

void chat::on_pushButton_clicked()
{
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
 //   QString msg=ui->textEdit->toPlainText();//获取要发送的信息，只能获取文本
    QString msg=ui->textEdit->toHtml();//////这样获取的是整个html页面的格式，是不是邮电浪费？？？？？！！！！！格式太多！！！！

    qDebug()<<"i get the msg to send is the picture "<<msg;

    QString name=get_myname();
    QString sendname=get_sendname();

    ui->textBrowser->setTextColor(Qt::green);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",11));/////设置发送的字体
    ui->textBrowser->append("[ " +myname+" ] "+ time);
    ui->textBrowser->append(msg);

    ui->textEdit->clear();
    ui->textEdit->setFocus();////发送完数据清空缓存，等待下次发送；
    if(ispositive)
        emit(send_msg(name,sendname,msg));//数据设置好了以后发送信号给主窗口的套接字；
    else
        emit(respond_msg(sendname,name,msg));

}

void chat::show_newmsg(QString name, QString sendname, QString msg)/////发送者的姓名，我的姓名，msg
{
    qDebug()<<"show_newmsg------------------70";
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->setTextColor(Qt::red);//
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",11));/////设置发送的字体
    ui->textBrowser->append("[ " +name+" ] "+ time);//////
    ui->textBrowser->append(msg);
    ui->textEdit->setFocus();
}

void chat::on_close_chat_clicked()
{

    if(ispositive==1)
    {
        qDebug()<<"send close_chat(name_tosend,1)";
        emit close_chat(name_tosend,1);/////主动发起的窗口对应是sendlist的处理，被动接收的窗口是receivelist的处理
    }
    else
    {
        qDebug()<<"send close_chat(name_tosend,0)";
        emit close_chat(name_tosend,0);/////
    }
    qDebug()<<"you press the close of the chat,the communication with "+name_tosend+"will be end ";
    QString file_record=ui->textBrowser->toHtml();///////保存到本地的文件
    QString record_intext=ui->textBrowser->toPlainText();
    if(record_intext.size()==0)
    {
        qDebug()<<"file length is  0 ,you need not to save it!!";
        return;
    }
    QString my_name=get_myname();
    QString send_name=get_sendname();

    QDir *mulu=new QDir();
    QString str_mulu="E:/ServerStore/"+myname+"_"+send_name;
    bool exist=mulu->exists(str_mulu);
    if(exist)
    {
        qDebug()<<"dir has been exist ,you can not creat it again";
        QString filename=str_mulu+"/a.txt";
        QFile file(filename);
        if(!file.open(QFile::WriteOnly|QFile::Text))/////如果文件不存在并且指定IO_WriteOnly或IO_ReadWrite时，文件被创建。
            qDebug()<<"this has a fail in the file write";
        else
        {
            QTextStream in(&file);
            in<<file_record;
        }
        file.flush();
        file.close();
        qDebug()<<"file has been save it!!!!!!!!!!!";
    }
    else
    {
        bool create_ok=mulu->mkdir(str_mulu);
        if(create_ok)
         {
            qDebug()<<"dir creart is success now";
            QString filename=str_mulu+"/a.txt";
            QFile file(filename);
            if(!file.open(QIODevice::Append|QIODevice::Text))/////如果文件不存在并且指定IO_WriteOnly或IO_ReadWrite时，文件被创建。
                qDebug()<<"this has a fail in the file write";
            else
            {
                QTextStream in(&file);
                in<<file_record;
            }
            file.flush();
            file.close();
            qDebug()<<"file has been save it!!!!!!!!!!!";
        }
        else
            qDebug()<<"creat fail";
    }
}

void chat::on_QQface_clicked()
{
    qDebug()<<"in the on_QQface_clicked";
    chat_face *mychat_face=new chat_face();
    qDebug()<<"on_QQface_clicked() is press";

    mychat_face->show();
    connect(mychat_face,SIGNAL(load_face(QString)),this,SLOT(loadface(QString)));
    qDebug()<<"on_QQface_clicked after";
}

void chat::loadface(QString clickedname)
{
    qDebug()<<"in the loadface------127";
    QString beclick_name=clickedname;
    int num_name=beclick_name.size();

    QStringList array;
    QString second_name;

    if(num_name==5)
        ui->textEdit->append("<img src='./imqface/1.gif'>");
    else
    {
        array=beclick_name.split("_");////字符串分割，将对应的图片资源加载到聊天窗口
        second_name=array.at(1);
        qDebug()<<"second_name is now -------162"<<second_name;
        ui->textEdit->append("<img src=':/new/picture/imqface/"+second_name+".gif'>");
    }
}

void chat::on_front_color_clicked()
{
    mycolor=QColorDialog::getColor(mycolor,this);
    if(mycolor.isValid())
    {
        ui->textEdit->setTextColor(mycolor);
        ui->textEdit->setFocus();
    }
}

void chat::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setCurrentFont(f);
    ui->textEdit->setFocus();
}

void chat::on_front_size_currentIndexChanged(const QString &arg1)
{
    ui->textEdit->setFontPointSize(arg1.toDouble());
    ui->textEdit->setFocus();
}

void chat::on_toolButton_4_clicked()////关于聊天记录的保存
{
    QString my_name=get_myname();
    QString send_name=get_sendname();
            history_record *record_dialog=new history_record();
            record_dialog->show();
            connect(this,SIGNAL(load_historyrecord(QString,QString)),record_dialog,SLOT(load_historyrecord(QString,QString)));
            emit load_historyrecord(my_name,send_name);

}

void chat::on_filetrans_clicked()/////实现文件传输问题
{
    this->resize(600,421);
    this->setMinimumSize(600,421);
    this->setMaximumSize(600,421);
    qDebug()<<"为啥打不开";

    vboxlayout=new QVBoxLayout(ui->widget);
    horizontal=new QHBoxLayout(ui->widget);
    process=new QProgressBar(ui->widget);
    process->setValue(0);
    horizontal->addWidget(process);
    process->show();
    vboxlayout->addLayout(horizontal);

    push_set=new QHBoxLayout(ui->widget);
    button1=new QPushButton(ui->widget);
    button1->resize(100,30);
    button1->setText(tr("打开"));
    connect(button1,SIGNAL(clicked()),this,SLOT(file_open_tosend()));
    button1->show();

    button2=new QPushButton(ui->widget);
    button2->setText(tr("发送"));//////解决中文乱码问题，在主函数main添加 QTextCodec::setCodecForTr(QTextCodec::codecForLocale());即可
    button2->resize(100,30);
    push_set->addWidget(button1);
    push_set->addWidget(button2);
    connect(button2,SIGNAL(clicked()),this,SLOT(sendfile()));
    button2->show();
    vboxlayout->addLayout(push_set);
}

void chat::close_filetrans(QString msg_from, QString myname)

{
    this->setMinimumSize(423,421);
    this->setMaximumSize(423,421);
    process->close();
    button1->close();
    button2->close();
    this->resize(423,421);
    QMessageBox::information(this,"Refused","The other party refused to receive the message");
}

void chat::file_open_tosend()//////定义用来打开文件浏览器，随后进行文件传输
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        thefilename=fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
        ui->textBrowser_filename->append(tr("要传送的文件为：%1 ").arg(thefilename));
        //ui->textBrowser_filename->append(thefilename);
        qDebug()<<"fille name is the things doing in the flower"<<fileName;
    }

    localFile=new QFile(fileName);
    if(!localFile->open(QIODevice::ReadOnly))
    {
        qDebug()<<"file open fail ,over it now!!-----352";
        return;
    }

    totalBytes=localFile->size();
    bytesToWrite=totalBytes;
    bytesWritten=0;
}

void chat::assure_receive(QString msg_from, QString sendname, QHostAddress re_addr, quint16 re_port)
{
    rece_addr=re_addr;
    rece_port=re_port;
    qDebug()<<"re_addr is"<<re_addr<<"re_port is"<<re_port;
    iscansend=1;
    if(iscansend==1)
    {
        senddata();
    }
}

void chat::sendfile()
{
    QString myname=get_myname();
    QString sendname=get_sendname();
    port=setport();
    emit get_sendip_port(myname,sendname,port,thefilename,totalBytes);

    udpserver=new QUdpSocket();
    udpserver->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    QMetaObject::Connection con = connect(udpserver,SIGNAL(readyRead()),this,SLOT(accept_connect()),Qt::DirectConnection);
    qDebug() << con;

    //数据初始化
    timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutResent()));

    connect(udpserver,SIGNAL(bytesWritten(qint64)),this,SLOT(update_serverprocess(qint64)));

    groupnum=60000;
    windowsize=10;
    linelen=0;
    linesended=0;
    notreceived=0;
    base=0;
    nextseqnum=base+windowsize-1;
    loadSize=8;
    NUMBER=totalBytes/(loadSize*128)+1;
    qDebug()<<"zong gong you "<<NUMBER;
    AckRec.clear();
}

checksum *chat::readdata()
{
    if(!localFile->atEnd())
    {
        QByteArray line=localFile->read(loadSize*128-5);
        checksum *cheksum=new checksum;
        cheksum->Ack=0;
        cheksum->Number=linelen;
        cheksum->Size=line.size()+5;
        cheksum->Data.resize(line.size());
        cheksum->Data=line;

        bytesWritten += line.size();
        bytesToWrite -= line.size();
        notreceived++;
        if(++linelen == groupnum) linelen=0;

        return cheksum;
     }
    return NULL;
}

void chat::senddata()
{
   int i;
   for(i=0;i<groupnum;i++)
   {
       if(i<windowsize)
       {
           checksum *mychecksum = readdata();
           if(mychecksum==NULL) break;
           QPair<bool,checksum*> *pair=new QPair<bool,checksum*>(false,mychecksum);
           sendchecksum(*mychecksum);
           AckRec.push_back(pair);
       }
       else
       {
           QPair<bool,checksum*> *pair=new QPair<bool,checksum*>(false,NULL);
           AckRec.push_back(pair);
       }
       isACK[i]=0;
   }
    //QTimer::singleShot(1000,this,SLOT(timeoutResent()));
}

void chat::sendchecksum(checksum &sendchecksum)
{
    QByteArray send;
    send.resize(sizeof(checksum));

    QBuffer buffer(&send);
    buffer.open(QIODevice::WriteOnly);

    QDataStream out(&buffer);
    out<<sendchecksum;
    buffer.close();
    if(send.size()<(loadSize*128))
    {
        timer->stop();
        localFile->close();
        udpserver->close();
        //QMessageBox::information(this,"Finish","transform completed!");
    }
    qDebug()<<"yi fa song"<<bytesWritten<<"   "<<send.size()<<"bian hao"<<sendchecksum.Number;
    udpserver->writeDatagram(send.data(),send.size(),rece_addr,rece_port);

}

void chat::accept_connect()
{
    qDebug()<<"We are receive ACK now!";
    while(udpserver->hasPendingDatagrams())
    {
        QByteArray datagram;
        QBuffer buffer(&datagram);
        buffer.open(QIODevice::ReadOnly);
        datagram.resize(udpserver->pendingDatagramSize());
        udpserver->readDatagram(datagram.data(),datagram.size(),&rece_addr,&rece_port);

        checksum chksum;
        QDataStream in(&buffer);
        in>>chksum;
        buffer.close();
        /*if(chksum.Number+10>NUMBER)
        {
            timer->stop();
            localFile->close();
            udpserver->close();
            QMessageBox::information(this,"Finish","transform completed!");
            break;
        }*/
        qDebug()<<"shou dao le "<<chksum.Number<<"yao fa song"<<chksum.Size<<"base "<<base;
        if(chksum.Ack==1)
        {

            ////先处理base和下次希望收到的数据编码之间的数据，说明这之间的数据已经全部收到
            if(base<chksum.Size+groupnum)
            {
                while(base!=chksum.Size)
                {
                    checksum *newchksum=readdata();
                    if(newchksum==NULL)
                    {
                        checksum *finchksum=new checksum;
                        finchksum->Ack=0;
                        finchksum->Number=2;
                        finchksum->Size=0;
                        finchksum->Data="trans finish";
                        sendchecksum(*finchksum);
                        delete finchksum;
                        timer->stop();
                        break;
                    }
                    sendchecksum(*newchksum);
                    timer->stop();
                    timer->start(1000);
                    AckRec[base]->first=false;
                    isACK[base]=0;
                    ///窗口向前滑动
                    if(++base==groupnum)base=0;
                    if(++nextseqnum==groupnum)nextseqnum=0;
                    AckRec[nextseqnum]->first=false;
                    AckRec[nextseqnum]->second=newchksum;
                    isACK[nextseqnum]=0;
                }
            }

            ///三次冗余ACK重传
            if(++isACK[chksum.Size]==3)
            {
                sendchecksum(*(AckRec[chksum.Size]->second));
                if(AckRec[chksum.Size]->second==NULL)
                    qDebug()<<"1";
                isACK[chksum.Size]=0;
            }

            AckRec[chksum.Number]->first=true;
            delete AckRec[chksum.Number]->second;
            AckRec[chksum.Number]->second=NULL;

            ////再处理下次希望收到的数据编号与nextsqenum之间的数据
            while(AckRec[base]->first)
            {
                notreceived--;
                checksum *newchksum=readdata();
                if(newchksum==NULL)
                {
                    checksum *finchksum=new checksum;
                    finchksum->Ack=0;
                    finchksum->Number=2;
                    finchksum->Size=0;
                    finchksum->Data="trans finish";
                    sendchecksum(*finchksum);
                    delete finchksum;
                    timer->stop();
                    break;
                }
                sendchecksum(*newchksum);
                timer->stop();
                timer->start(1000);
                AckRec[base]->first=false;
                isACK[base]=0;
                ///窗口向前滑动
                if(++base==groupnum)base=0;
                if(++nextseqnum==groupnum)nextseqnum=0;
                AckRec[nextseqnum]->first=false;
                AckRec[nextseqnum]->second=newchksum;
                isACK[nextseqnum]=0;
            }
        }
    }
}

void chat::timeoutResent()
{
    /*if(udpserver->bytesAvailable()!=0){
        udpserver->close();
        udpserver=new QUdpSocket();
        udpserver->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
        QMetaObject::Connection con = connect(udpserver,SIGNAL(readyRead()),this,SLOT(accept_connect()),Qt::DirectConnection);
        qDebug() << con;
    }*/
    sendchecksum(*(AckRec.at(base)->second));
    if(AckRec[base]->second==NULL)
        qDebug()<<"1";
    if(localFile->atEnd())
        timer->stop();
}

void chat::update_serverprocess(qint64 numbytes)
{
    process->setMaximum(totalBytes);
    process->setValue(bytesWritten);
    qDebug()<<"wen jian da xiao "<<totalBytes;
    if(bytesWritten==totalBytes)
    {
        localFile->close();
        udpserver->close();
        qDebug()<<"file trans over now";
        QMessageBox::information(this,"Finish","transform completed!");
        this->setMinimumSize(423,421);
        this->setMaximumSize(423,421);
        process->close();
        button1->close();
        button2->close();
        this->resize(423,421);
    }
}

void chat::display_error(QAbstractSocket::SocketError)/////表明这个时候出现了错误；应该进行相关的处理
{
    qDebug()<<socket->errorString();
    socket->close();
}

quint16  chat::setport()
{
    QTime time=QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    return (qrand()%(32700-1024+1)+1024);
}

