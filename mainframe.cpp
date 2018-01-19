#include "mainframe.h"
#include "ui_mainframe.h"
#include <QByteArray>
#include <QMessageBox>
#include <QMap>

int Mainframe::should_close=1;

Mainframe::Mainframe(QWidget *parent,client_socket *socket) :
    QWidget(parent),
    ui(new Ui::Mainframe)
{
    ui->setupUi(this);
    this->from_client1=socket;

    my_friendlist=new QStringList();
    loginlist=new QStringList();

    imq_menu=new QMenu(this);
    QAction *shut_down=new QAction("quit",this);
    QAction *open_mainframe=new QAction("IMQ",this);
    QAction *imq_msg=new QAction("msg",this);

    imq_menu->addAction(imq_msg);
    imq_menu->addSeparator();

    imq_menu->addAction(open_mainframe);
    imq_menu->addSeparator();

    imq_menu->addAction(shut_down);

    imq_icon=new QSystemTrayIcon(this);
    imq_icon->setToolTip("IMQ_SCH");
    QIcon icon(QPixmap(":new/picture/resorces/1.bmp"));
    imq_icon->setIcon(icon);
    imq_icon->setContextMenu(imq_menu);
    imq_icon->show();
    connect(imq_icon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_systemTrayiconclicked(QSystemTrayIcon::ActivationReason)));
    connect(shut_down,SIGNAL(triggered()),this,SLOT(quit()));
    connect(open_mainframe,SIGNAL(triggered()),this,SLOT(show_normal()));

    connect(from_client1,SIGNAL(set_friendslist(QStringList)),this,SLOT(set_friendslist(QStringList)));///////链接信号设置
    connect(ui->treeView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(show_chat()));/////设置选中的行，进行对应的函数处理；
    connect(from_client1,SIGNAL(showmessage(QString,QString,QString)),this,SLOT(message_comming(QString,QString,QString)));

    connect(this,SIGNAL(info_mylogin()),from_client1,SLOT(info_myfriend_login()));
    connect(this,SIGNAL(info_myofflne()),from_client1,SLOT(info_myfriend_offline()));

    connect(from_client1,SIGNAL(update_fridenglist_login(QString)),this,SLOT(update_fridenglist_login(QString)));
    connect(from_client1,SIGNAL(update_fridenglist_offline(QString)),this,SLOT(update_fridenglist_offline(QString)));

    connect(this,SIGNAL(get_sendipandport(QString,QString,quint16,QHostAddress,QString,qint64)),from_client1,SLOT(get_sendip(QString,QString,quint16,QHostAddress,QString,qint64)));/////修改后，客户端主动发起文件传输的
    //作为服务器，将自己的server端口发送给接收文件的用户，建立建立后进行文传输

    connect(from_client1,SIGNAL(should_connect(QString,QString,quint16,QHostAddress,QString,qint64)),this,SLOT(show_receivefile(QString,QString,quint16,QHostAddress,QString,qint64)));
}

void Mainframe::show_receivefile(QString msg_from, QString myname, quint16 port,QHostAddress addr,QString filename,qint64 filesize)
{
    qDebug()<<addr;
    //QString filepath=QFileDialog::getSaveFileName(0,QString(),filename);
    receive_file *newreceive = new receive_file(0,msg_from,myname,port,from_client1);////接收文件的窗体打开
    newreceive->setfilename(filename,filesize);
    newreceive->setaddress(addr);
    connect(newreceive,SIGNAL(assure_receive(QString,QString,QHostAddress,quint16)),from_client1,SLOT(assure_receive(QString,QString,QHostAddress,quint16)));
    connect(newreceive,SIGNAL(refuse_file(QString,QString)),from_client1,SLOT(refuse_file(QString,QString)));
    connect(newreceive,SIGNAL(receive_success(QString,QString)),from_client1,SLOT(receive_success(QString,QString)));///wenjian jieshou cenggong houchufa
    newreceive->show();
}

quint16 Mainframe::setport()
{
    QTime time=QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    return (qrand()%(32700-1024+1)+1024);
}

Mainframe::~Mainframe()
{
    delete ui;
}


void Mainframe::quit()
{
    should_close=0;/////用来控制imq再控制台下退出，单击时都是最小化到托盘下，其实就是隐藏起来；
    emit(info_myofflne());
    this->close();
}
void Mainframe::show_normal()
{
    this->show();
}

void Mainframe::closeEvent(QCloseEvent *event)
{

    if(should_close==1&&imq_icon->isVisible())
    {
        this->hide();
        event->ignore();
    }
    else
        event->accept();
    emit(info_myofflne());
}


bool Mainframe::Is_inloginlist(QString loginname)/////判断用户是否是已经登录了；
{
    int size_loginlist=loginlist->size();
    int j=0;
    for(int i=0;i<size_loginlist;i++)
        if(loginname==loginlist->at(i))
            return true;
        else
            j++;
    if(j==size_loginlist)
        return false;
}

void Mainframe::update_fridenglist_login(QString loginname)
{
    if(loginname!="")
    {
        qDebug()<<"should update friendlist------ new coming is "<<loginname;
        loginlist->append(loginname);

        int num_list=my_friendlist->size();
        QString image;
        //QIcon icon(QPixmap(":new/picture/resorces/1.bmp"));
        for(int i=0;i<num_list;i++)
        {
            QString name=static_cast<QString>(my_friendlist->at(i));
            QStandardItem *item=new QStandardItem(static_cast<QString>(my_friendlist->at(i)));
            if(name==loginname||Is_inloginlist(name))
            {
                qDebug()<<"zoudao zheyibu lema ";
                image=":new/picture/resorces/1.bmp";
            }
            else
                image=":new/picture/resorces_outline/1.bmp";
            //QIcon icon(QPixmap(image));
            item->setIcon(QIcon(QPixmap(image)));
            model->setItem(i,item);
            ui->treeView->setModel(model);

        }
    }
}

void Mainframe::update_fridenglist_offline(QString offname)
{
    if(offname!="")
    {
        qDebug()<<"should update friendlist------ new lifing is "<<offname;
        int login_list=loginlist->size();
        for(int i=0;i<login_list;i++)
            if(static_cast<QString>(my_friendlist->at(i))==offname)
                loginlist->removeAt(i);

        int num_list=my_friendlist->size();
        QString image;
     //   qDebug()<<numlist;
        for(int i=0;i<num_list;i++)
        {
            QString name=static_cast<QString>(my_friendlist->at(i));
            QStandardItem *item=new QStandardItem(static_cast<QString>(my_friendlist->at(i)));
            if(Is_inloginlist(name))
                image=":new/picture/resorces/1.bmp";
            else
                 image=":new/picture/resorces_outline/1.bmp";
            QIcon icon(image);
            item->setIcon(icon);
            model->setItem(i,item);
            ui->treeView->setModel(model);
        }
    }
}

void Mainframe::set_friendslist(QStringList friendlist)
{
    int num_list=friendlist.size();
    model=new QStandardItemModel();
    QString image;////yong lai shezhi tupian
    for(int i=0;i<num_list;i++)
    {
        QStandardItem *item=new QStandardItem(static_cast<QString>(friendlist.at(i)));
        my_friendlist->append(friendlist.at(i));
        model->setItem(i,item);
        ui->treeView->setModel(model);
    }
    emit(info_mylogin());////告知我的登录信息，以便于好友列表的更新
}

/////发送消息
void Mainframe::show_chat()//////用来进行显示双击后选中的内容
{
    QModelIndex ss=ui->treeView->currentIndex();
   // qDebug()<<ss.data().toString();
    QString name_tosend=ss.data().toString();//////要发送的人的名字；
    QString myname=windowTitle();//////可以获取我自己的用户名；

    ui->toolButton->setText(windowTitle());
    qDebug()<<"in the chat show now ----show_chat()--------------48"<<myname;

    chat *sendchat=new chat(0,myname,name_tosend,1);
    sendchat->setWindowTitle(name_tosend);
    sendlist.insert(name_tosend,sendchat);///////发送方的发送列表中新加入要发送的人员
    sendchat->show();
    sendchat->setMaximumSize(600,421);
    connect(sendchat,SIGNAL(send_msg(QString,QString,QString)),from_client1,SLOT(send_msg(QString,QString,QString)));
    connect(sendchat,SIGNAL(close_chat(QString,int)),this,SLOT(delete_communication(QString,int)));
    connect(this,SIGNAL(show_msginchat(QString,QString,QString)),sendchat,SLOT(show_newmsg(QString,QString,QString)));////绑定的信号；
    connect(sendchat,SIGNAL(get_sendip_port(QString,QString,quint16,QString,qint64)),this,SLOT(get_sendip_port(QString,QString,quint16,QString,qint64)));////修改后的
    connect(from_client1,SIGNAL(close_filetrans(QString,QString)),sendchat,SLOT(close_filetrans(QString,QString)));
    connect(from_client1,SIGNAL(assure_filetrans(QString,QString,QHostAddress,quint16)),sendchat,SLOT(assure_receive(QString,QString,QHostAddress,quint16)));
}

void Mainframe::get_sendip_port(QString myname, QString sendname,quint16 portt,QString filename,qint64 filesize)
{
    QHostAddress addr=from_client1->localAddress();
    qDebug()<<"my addr is "<<addr<<"my port is"<<portt;
    emit get_sendipandport(myname,sendname,portt,addr,filename,filesize);
}

////接收消息
void Mainframe::message_comming(QString sendname, QString myname, QString msg)
{
    qDebug("in the mainframe and fun message_comming---------59");
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString name=sendname;

    QHash<QString,chat *>::const_iterator i;//////为什么会出现异常；
    static int times1=1;
    static int times2=1;
    static int pp=1;
    int num=0;
    chat *mychat;
    for(i=sendlist.begin();i!=sendlist.end();i++)
    {
        if(i.key()==sendname)
        {
            if(times1==1)
           {
                qDebug()<<"this is i have send to positive";
                mychat=i.value();
                goto pppp;
            }
            else
            {
                qDebug()<<"nexttime ----------------98";
                times1=0;
                goto pppp;
            }
        }
    }
    for(i=receivelist.begin();i!=receivelist.end();i++)
    {
        if(i.key()==sendname)
        {
            if(times2==1)
           {
                mychat=i.value();
                goto pppp;
            }
            else
            {
                times2=0;
                goto pppp;
            }
        }
        else
            num++;
    }
    if(num==receivelist.size())
    {
        mychat=new chat(0,myname,name,0);
        receivelist.insert(sendname,mychat);
        mychat->setWindowTitle(name);
        mychat->show();
        connect(mychat,SIGNAL(send_msg(QString,QString,QString)),from_client1,SLOT(send_msg(QString,QString,QString)));
        connect(mychat,SIGNAL(respond_msg(QString,QString,QString)),from_client1,SLOT(respond_msg(QString,QString,QString)));
        connect(mychat,SIGNAL(close_chat(QString,int)),this,SLOT(delete_communication(QString,int)));
        connect(this,SIGNAL(show_msginchat(QString,QString,QString)),mychat,SLOT(show_newmsg(QString,QString,QString)));////绑定的信号；
    }

pppp:
    qDebug("in this message_comming-------------82");
    emit(show_msginchat(sendname,myname,msg));
    qDebug()<<"times xinhao---------140";

}

  /////sendname 是发送者的姓名，myname是接收者也就是我自己的名字标示/////////////////
void Mainframe::delete_communication(QString person, int positive)
{
    qDebug()<<"delete_communicaion is doing------230";
    QHash<QString,chat *>::const_iterator i;
      if(positive==1)
      {
                  sendlist.remove(person);
                  qDebug()<<"remove the person i have chat with it-------237";
      }
      else
      {
          for(i=receivelist.begin();i!=receivelist.end();i++)
              qDebug()<<i.key();
          qDebug()<<person;
          receivelist.remove(person);
      }
}


void Mainframe::on_systemTrayiconclicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        this->hide();
        break;
    case QSystemTrayIcon::DoubleClick:
        this->setWindowState(Qt::WindowActive);
        this->show();
        break;
    default:
        break;
    }
}

