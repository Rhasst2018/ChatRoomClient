/********************************************************************************
** Form generated from reading UI file 'findback_password.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDBACK_PASSWORD_H
#define UI_FINDBACK_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findback_password
{
public:
    QWidget *centralwidget;
    QPushButton *confirm_Button;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username_Edit;
    QLineEdit *password_edit;
    QLabel *label_3;
    QLineEdit *confirm_password;
    QPushButton *cancel_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *findback_password)
    {
        if (findback_password->objectName().isEmpty())
            findback_password->setObjectName(QStringLiteral("findback_password"));
        findback_password->resize(343, 284);
        centralwidget = new QWidget(findback_password);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        confirm_Button = new QPushButton(centralwidget);
        confirm_Button->setObjectName(QStringLiteral("confirm_Button"));
        confirm_Button->setGeometry(QRect(50, 180, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 72, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 72, 15));
        username_Edit = new QLineEdit(centralwidget);
        username_Edit->setObjectName(QStringLiteral("username_Edit"));
        username_Edit->setGeometry(QRect(140, 40, 113, 21));
        password_edit = new QLineEdit(centralwidget);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setGeometry(QRect(140, 80, 113, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 72, 15));
        confirm_password = new QLineEdit(centralwidget);
        confirm_password->setObjectName(QStringLiteral("confirm_password"));
        confirm_password->setGeometry(QRect(140, 120, 113, 21));
        cancel_Button = new QPushButton(centralwidget);
        cancel_Button->setObjectName(QStringLiteral("cancel_Button"));
        cancel_Button->setGeometry(QRect(180, 180, 93, 28));
        findback_password->setCentralWidget(centralwidget);
        menubar = new QMenuBar(findback_password);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 343, 26));
        findback_password->setMenuBar(menubar);
        statusbar = new QStatusBar(findback_password);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        findback_password->setStatusBar(statusbar);

        retranslateUi(findback_password);

        QMetaObject::connectSlotsByName(findback_password);
    } // setupUi

    void retranslateUi(QMainWindow *findback_password)
    {
        findback_password->setWindowTitle(QApplication::translate("findback_password", "MainWindow", 0));
        confirm_Button->setText(QApplication::translate("findback_password", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
        label->setText(QApplication::translate("findback_password", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("findback_password", "\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("findback_password", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        cancel_Button->setText(QApplication::translate("findback_password", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class findback_password: public Ui_findback_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDBACK_PASSWORD_H
