#ifndef RECEIVE_FILE_H
#define RECEIVE_FILE_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QFile>
//#include <QQueue>
//#include <QPair>
#include <client_socket.h>
#include <chat.h>

namespace Ui {
    class receive_file;
}

class receive_file : public QWidget
{
    Q_OBJECT

public:
    explicit receive_file(QWidget *parent = 0,QString msg=0,QString my=0,quint16 portt=0,client_socket *socket=0);
    inline QString get_msgfrom(){return msg_from;}
    inline QString get_myname(){return myname;}
    inline quint16 get_port(){return send_port;}
    void setfilename(QString filename,qint64 filesize);
    void setaddress(QHostAddress addr);
    ~receive_file();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

public slots:
    void start_tranfor();
    void update_clientprocess();////genxin kehuduande wenjian jieshoude jindu
    void display_error(QAbstractSocket::SocketError);
    void timeUpDate();
    void update_process(qint64 numbytes);
signals:
    void assure_receive(QString msg_from,QString my_name,QHostAddress addr,quint16 port);
    void refuse_file(QString msg_from,QString myname);
    void receive_success(QString msgfrom,QString my);

private:

    Ui::receive_file *ui;
    client_socket *mysocket;

    QFile file;
    QUdpSocket *udpsocket;
    QString msg_from;
    QString myname;
    quint16 send_port;
    QHostAddress send_addr;
    quint16 trans_port;
   //////////////////////////////////////以下为进行文件传输的时候要求的东西////////////////////////////////////////

    qint64 totalBytes;  //存放总大小信息
    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QString fileName;   //存放文件名
    QFile *localFile;   //本地文件
    int linelen;
    int groupnum;
    int windowsize;
    int re_base;
    int nextsqenum;
    QByteArray inBlock;   //数据缓冲区
    QQueue <QPair<bool,checksum*>*> ackrec;
    void sendACk(checksum &ack);
};

#endif // RECEIVE_FILE_H
