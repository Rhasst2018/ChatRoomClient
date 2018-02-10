/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QPushButton *send_chat;
    QPushButton *close_chat;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QWidget *widget;
    QToolButton *filetrans;
    QFontComboBox *fontComboBox;
    QComboBox *front_size;
    QToolButton *front_color;
    QToolButton *QQface;
    QToolButton *toolButton_4;
    QTextBrowser *textBrowser_filename;

    void setupUi(QDialog *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(600, 421);
        chat->setMinimumSize(QSize(423, 421));
        chat->setMaximumSize(QSize(600, 421));
        send_chat = new QPushButton(chat);
        send_chat->setObjectName(QStringLiteral("send_chat"));
        send_chat->setGeometry(QRect(310, 390, 93, 28));
        close_chat = new QPushButton(chat);
        close_chat->setObjectName(QStringLiteral("close_chat"));
        close_chat->setGeometry(QRect(200, 390, 93, 28));
        gridLayoutWidget = new QWidget(chat);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 391, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 2, 1);

        gridLayoutWidget_2 = new QWidget(chat);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 295, 391, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(gridLayoutWidget_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        widget = new QWidget(chat);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(410, 20, 181, 191));
        filetrans = new QToolButton(chat);
        filetrans->setObjectName(QStringLiteral("filetrans"));
        filetrans->setGeometry(QRect(290, 270, 61, 21));
        fontComboBox = new QFontComboBox(chat);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(11, 270, 112, 21));
        front_size = new QComboBox(chat);
        front_size->setObjectName(QStringLiteral("front_size"));
        front_size->setGeometry(QRect(130, 270, 87, 21));
        front_color = new QToolButton(chat);
        front_color->setObjectName(QStringLiteral("front_color"));
        front_color->setGeometry(QRect(250, 270, 27, 26));
        QIcon icon;
        icon.addFile(QStringLiteral("face/textcolor.png"), QSize(), QIcon::Active, QIcon::On);
        front_color->setIcon(icon);
        QQface = new QToolButton(chat);
        QQface->setObjectName(QStringLiteral("QQface"));
        QQface->setGeometry(QRect(220, 270, 27, 26));
        QIcon icon1;
        icon1.addFile(QStringLiteral("face/2.gif"), QSize(), QIcon::Normal, QIcon::Off);
        QQface->setIcon(icon1);
        toolButton_4 = new QToolButton(chat);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(360, 270, 53, 21));
        textBrowser_filename = new QTextBrowser(chat);
        textBrowser_filename->setObjectName(QStringLiteral("textBrowser_filename"));
        textBrowser_filename->setGeometry(QRect(420, 230, 171, 181));

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QDialog *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Dialog", 0));
        send_chat->setText(QApplication::translate("chat", "\345\217\221\351\200\201", 0));
        close_chat->setText(QApplication::translate("chat", "\345\205\263\351\227\255", 0));
        filetrans->setText(QApplication::translate("chat", "\346\226\207\344\273\266\344\274\240\350\276\223", 0));
        front_color->setText(QApplication::translate("chat", "...", 0));
        QQface->setText(QApplication::translate("chat", "...", 0));
        toolButton_4->setText(QApplication::translate("chat", "\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
