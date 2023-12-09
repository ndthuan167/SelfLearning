/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondwindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *secondwindow)
    {
        if (secondwindow->objectName().isEmpty())
            secondwindow->setObjectName("secondwindow");
        secondwindow->resize(800, 600);
        centralwidget = new QWidget(secondwindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(500, 190, 75, 24));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(310, 310, 22, 22));
        secondwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(secondwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        secondwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(secondwindow);
        statusbar->setObjectName("statusbar");
        secondwindow->setStatusBar(statusbar);

        retranslateUi(secondwindow);

        QMetaObject::connectSlotsByName(secondwindow);
    } // setupUi

    void retranslateUi(QMainWindow *secondwindow)
    {
        secondwindow->setWindowTitle(QCoreApplication::translate("secondwindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("secondwindow", "PushButton", nullptr));
        toolButton->setText(QCoreApplication::translate("secondwindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondwindow: public Ui_secondwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
