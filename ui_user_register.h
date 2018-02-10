/********************************************************************************
** Form generated from reading UI file 'user_register.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_REGISTER_H
#define UI_USER_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_user_register
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *line_user;
    QLineEdit *line_pwd;
    QLineEdit *line_pwdcfm;
    QPushButton *u_register;
    QPushButton *r_cancel;

    void setupUi(QDialog *user_register)
    {
        if (user_register->objectName().isEmpty())
            user_register->setObjectName(QStringLiteral("user_register"));
        user_register->resize(372, 251);
        label = new QLabel(user_register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 20, 201, 18));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(user_register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 60, 64, 18));
        label_3 = new QLabel(user_register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 110, 61, 18));
        label_4 = new QLabel(user_register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 150, 64, 18));
        line_user = new QLineEdit(user_register);
        line_user->setObjectName(QStringLiteral("line_user"));
        line_user->setGeometry(QRect(150, 60, 161, 28));
        line_pwd = new QLineEdit(user_register);
        line_pwd->setObjectName(QStringLiteral("line_pwd"));
        line_pwd->setGeometry(QRect(150, 100, 161, 28));
        line_pwdcfm = new QLineEdit(user_register);
        line_pwdcfm->setObjectName(QStringLiteral("line_pwdcfm"));
        line_pwdcfm->setGeometry(QRect(150, 140, 161, 28));
        u_register = new QPushButton(user_register);
        u_register->setObjectName(QStringLiteral("u_register"));
        u_register->setGeometry(QRect(50, 190, 93, 28));
        r_cancel = new QPushButton(user_register);
        r_cancel->setObjectName(QStringLiteral("r_cancel"));
        r_cancel->setGeometry(QRect(200, 190, 93, 28));
        r_cancel->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        line_user->raise();
        line_pwd->raise();
        line_pwdcfm->raise();
        u_register->raise();

        retranslateUi(user_register);

        QMetaObject::connectSlotsByName(user_register);
    } // setupUi

    void retranslateUi(QDialog *user_register)
    {
        user_register->setWindowTitle(QApplication::translate("user_register", "Dialog", 0));
        label->setText(QApplication::translate("user_register", "USER_REGISTER", 0));
        label_2->setText(QApplication::translate("user_register", "username", 0));
        label_3->setText(QApplication::translate("user_register", "passwd", 0));
        label_4->setText(QApplication::translate("user_register", "confirm", 0));
        u_register->setText(QApplication::translate("user_register", "\346\263\250\345\206\214", 0));
        r_cancel->setText(QApplication::translate("user_register", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class user_register: public Ui_user_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_REGISTER_H
