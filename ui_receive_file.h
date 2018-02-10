/********************************************************************************
** Form generated from reading UI file 'receive_file.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVE_FILE_H
#define UI_RECEIVE_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receive_file
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *receive_file)
    {
        if (receive_file->objectName().isEmpty())
            receive_file->setObjectName(QStringLiteral("receive_file"));
        receive_file->resize(366, 241);
        label = new QLabel(receive_file);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 291, 20));
        progressBar = new QProgressBar(receive_file);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(70, 90, 241, 23));
        progressBar->setValue(0);
        pushButton = new QPushButton(receive_file);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 160, 93, 28));
        pushButton_2 = new QPushButton(receive_file);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 160, 93, 28));

        retranslateUi(receive_file);

        QMetaObject::connectSlotsByName(receive_file);
    } // setupUi

    void retranslateUi(QWidget *receive_file)
    {
        receive_file->setWindowTitle(QApplication::translate("receive_file", "Form", 0));
        label->setText(QApplication::translate("receive_file", "<html><head/><body><p>\344\275\240\346\234\211\344\270\200\344\270\252\346\226\207\344\273\266\344\274\240\350\276\223\350\257\267\346\261\202\357\274\214\350\257\267\346\263\250\346\204\217\346\237\245\346\224\266........</p></body></html>", 0));
        pushButton->setText(QApplication::translate("receive_file", "\346\216\245\346\224\266", 0));
        pushButton_2->setText(QApplication::translate("receive_file", "\346\213\222\347\273\235", 0));
    } // retranslateUi

};

namespace Ui {
    class receive_file: public Ui_receive_file {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVE_FILE_H
