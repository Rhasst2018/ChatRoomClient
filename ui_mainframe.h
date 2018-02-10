/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainframe
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTreeView *treeView;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QWidget *Mainframe)
    {
        if (Mainframe->objectName().isEmpty())
            Mainframe->setObjectName(QStringLiteral("Mainframe"));
        Mainframe->resize(214, 476);
        Mainframe->setMinimumSize(QSize(214, 476));
        Mainframe->setMaximumSize(QSize(214, 476));
        Mainframe->setLayoutDirection(Qt::LeftToRight);
        gridLayoutWidget = new QWidget(Mainframe);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 100, 211, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        treeView = new QTreeView(tab);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(0, 0, 211, 301));
        treeView->setMinimumSize(QSize(34, 34));
        QIcon icon;
        icon.addFile(QStringLiteral("resorces/menu_feedback.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, icon, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(Mainframe);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 70, 211, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_2 = new QToolButton(horizontalLayoutWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(Mainframe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 71, 31));
        toolButton = new QToolButton(Mainframe);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(80, 20, 121, 41));

        retranslateUi(Mainframe);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Mainframe);
    } // setupUi

    void retranslateUi(QWidget *Mainframe)
    {
        Mainframe->setWindowTitle(QApplication::translate("Mainframe", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Mainframe", "Friends", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Mainframe", "Group", 0));
        toolButton_2->setText(QApplication::translate("Mainframe", "search", 0));
        label->setText(QApplication::translate("Mainframe", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">I'M:</span></p></body></html>", 0));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mainframe: public Ui_Mainframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
