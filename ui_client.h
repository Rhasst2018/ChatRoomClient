/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *line_user;
    QLineEdit *line_pwd;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QPushButton *findback_pass;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(337, 275);
        Client->setMinimumSize(QSize(337, 275));
        Client->setMaximumSize(QSize(337, 275));
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 210, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 100, 51, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 41, 18));
        line_user = new QLineEdit(centralWidget);
        line_user->setObjectName(QStringLiteral("line_user"));
        line_user->setGeometry(QRect(90, 100, 151, 28));
        line_pwd = new QLineEdit(centralWidget);
        line_pwd->setObjectName(QStringLiteral("line_pwd"));
        line_pwd->setGeometry(QRect(90, 140, 151, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 100, 51, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 210, 93, 28));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 180, 78, 21));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(200, 180, 91, 16));
        findback_pass = new QPushButton(centralWidget);
        findback_pass->setObjectName(QStringLiteral("findback_pass"));
        findback_pass->setGeometry(QRect(240, 140, 93, 28));
        Client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 337, 26));
        Client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Client->setStatusBar(statusBar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        pushButton->setText(QApplication::translate("Client", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("Client", "<html><head/><body><p>\347\224\250\346\210\267\345\220\215</p></body></html>", 0));
        label_2->setText(QApplication::translate("Client", "<html><head/><body><p>\345\257\206\347\240\201</p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("Client", "\346\263\250\345\206\214", 0));
        pushButton_3->setText(QApplication::translate("Client", "\345\217\226\346\266\210", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Client", "\345\234\250\347\272\277", 0)
         << QApplication::translate("Client", "\351\232\220\350\272\253", 0)
         << QApplication::translate("Client", "\347\224\250\346\210\267\345\277\231", 0)
        );
        checkBox->setText(QApplication::translate("Client", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        findback_pass->setText(QApplication::translate("Client", "\346\211\276\345\233\236\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
