#ifndef FINDBACK_PASSWORD_H
#define FINDBACK_PASSWORD_H

#include <QMainWindow>
#include <client_socket.h>

namespace Ui {
class findback_password;
}

class findback_password : public QMainWindow
{
    Q_OBJECT

public:
    explicit findback_password(QWidget *parent = 0);
    ~findback_password();

private slots:
    void on_confirm_Button_clicked();

    void on_cancel_Button_clicked();

    void changeisOK(int isOK);
private:
    Ui::findback_password *ui;
    client_socket *mytcpsct;
};

#endif // FINDBACK_PASSWORD_H
