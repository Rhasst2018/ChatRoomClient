/********************************************************************************
** Form generated from reading UI file 'history_record.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_RECORD_H
#define UI_HISTORY_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history_record
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *history_record)
    {
        if (history_record->objectName().isEmpty())
            history_record->setObjectName(QStringLiteral("history_record"));
        history_record->resize(457, 371);
        textBrowser = new QTextBrowser(history_record);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 20, 451, 291));
        pushButton = new QPushButton(history_record);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 320, 93, 28));

        retranslateUi(history_record);

        QMetaObject::connectSlotsByName(history_record);
    } // setupUi

    void retranslateUi(QWidget *history_record)
    {
        history_record->setWindowTitle(QApplication::translate("history_record", "Form", 0));
        pushButton->setText(QApplication::translate("history_record", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class history_record: public Ui_history_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_RECORD_H
