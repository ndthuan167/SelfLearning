/********************************************************************************
** Form generated from reading UI file 'popupchi.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPCHI_H
#define UI_POPUPCHI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PopupChi
{
public:
    QFrame *PopupChi_2;
    QComboBox *comboBox_2;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_2;
    QPushButton *pushButton_SetChi;
    QPlainTextEdit *plainTextEdit_5;
    QLabel *label_17;
    QPlainTextEdit *plainTextEdit_6;
    QPushButton *pushButton_Selectday;
    QLabel *label_date_selected;
    QFrame *PopupselectDay;
    QLabel *label_20;
    QPushButton *pushButton_SelectedDay;
    QPushButton *pushButton_back_day;
    QPushButton *pushButton_next_day;
    QLabel *label_date_select;

    void setupUi(QDialog *PopupChi)
    {
        if (PopupChi->objectName().isEmpty())
            PopupChi->setObjectName("PopupChi");
        PopupChi->resize(452, 185);
        PopupChi_2 = new QFrame(PopupChi);
        PopupChi_2->setObjectName("PopupChi_2");
        PopupChi_2->setGeometry(QRect(0, 0, 201, 181));
        PopupChi_2->setStyleSheet(QString::fromUtf8("#PopupChi_2{\n"
"	background-color: #EDE4E0;\n"
"	border-radius: 15;\n"
"	border: 2px solid white;\n"
"}"));
        PopupChi_2->setFrameShape(QFrame::StyledPanel);
        PopupChi_2->setFrameShadow(QFrame::Raised);
        comboBox_2 = new QComboBox(PopupChi_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(45, 45, 140, 28));
        QFont font;
        font.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font.setPointSize(10);
        font.setBold(true);
        comboBox_2->setFont(font);
        comboBox_2->setLayoutDirection(Qt::LeftToRight);
        comboBox_2->setAutoFillBackground(false);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 10px;\n"
"    min-width: 6em;\n"
"	padding-left: 25;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"    border-bottom-left-radius: 0px;\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border-bottom-right-radius: 10px;\n"
"    border-bottom-left-radius: 10px;\n"
"    background: transparent;\n"
"    border: 1px solid gray;\n"
"    padding: 4px 4px 4px 4px\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	image: url(\":/Icon/Image/icons8-down-25.png\");\n"
"	width:20;\n"
"	padding-left: 5\n"
"}\n"
""));
        comboBox_2->setEditable(false);
        comboBox_2->setMaxVisibleItems(10);
        plainTextEdit_4 = new QPlainTextEdit(PopupChi_2);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(45, 115, 141, 28));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font1.setBold(true);
        plainTextEdit_4->setFont(font1);
        plainTextEdit_4->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5"));
        label_14 = new QLabel(PopupChi_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 45, 25, 25));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-goal-40.png")));
        label_14->setScaledContents(true);
        label_15 = new QLabel(PopupChi_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 80, 25, 25));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-money-40.png")));
        label_15->setScaledContents(true);
        label_16 = new QLabel(PopupChi_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 115, 25, 25));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-note-40.png")));
        label_16->setScaledContents(true);
        label_2 = new QLabel(PopupChi_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 85, 35, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font2.setPointSize(12);
        font2.setBold(true);
        label_2->setFont(font2);
        pushButton_SetChi = new QPushButton(PopupChi_2);
        pushButton_SetChi->setObjectName("pushButton_SetChi");
        pushButton_SetChi->setGeometry(QRect(70, 150, 71, 25));
        pushButton_SetChi->setFont(font);
        pushButton_SetChi->setStyleSheet(QString::fromUtf8("#pushButton_SetChi\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_SetChi::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_SetChi::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Image/icons8-next-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SetChi->setIcon(icon);
        pushButton_SetChi->setIconSize(QSize(20, 20));
        plainTextEdit_5 = new QPlainTextEdit(PopupChi_2);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(45, 80, 91, 28));
        plainTextEdit_5->setFont(font);
        plainTextEdit_5->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 15"));
        label_17 = new QLabel(PopupChi_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(8, 8, 31, 31));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-calendar-48.png")));
        label_17->setScaledContents(true);
        plainTextEdit_6 = new QPlainTextEdit(PopupChi_2);
        plainTextEdit_6->setObjectName("plainTextEdit_6");
        plainTextEdit_6->setGeometry(QRect(45, 10, 141, 28));
        plainTextEdit_6->setFont(font1);
        plainTextEdit_6->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5"));
        pushButton_Selectday = new QPushButton(PopupChi_2);
        pushButton_Selectday->setObjectName("pushButton_Selectday");
        pushButton_Selectday->setGeometry(QRect(160, 12, 21, 24));
        pushButton_Selectday->setStyleSheet(QString::fromUtf8("#pushButton_Selectday\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_Selectday::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_Selectday::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Image/icons8-calendar-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Selectday->setIcon(icon1);
        pushButton_Selectday->setIconSize(QSize(20, 20));
        label_date_selected = new QLabel(PopupChi_2);
        label_date_selected->setObjectName("label_date_selected");
        label_date_selected->setGeometry(QRect(60, 12, 91, 25));
        label_date_selected->setFont(font);
        label_date_selected->setStyleSheet(QString::fromUtf8("#label_date_selected{\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"	border: 1px solid white;\n"
"	color: black\n"
"}"));
        label_date_selected->setAlignment(Qt::AlignCenter);
        PopupselectDay = new QFrame(PopupChi);
        PopupselectDay->setObjectName("PopupselectDay");
        PopupselectDay->setGeometry(QRect(250, 40, 191, 71));
        PopupselectDay->setStyleSheet(QString::fromUtf8("#PopupselectDay{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 2px solid white;\n"
"}"));
        PopupselectDay->setFrameShape(QFrame::StyledPanel);
        PopupselectDay->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(PopupselectDay);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 37, 31, 31));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-calendar-48.png")));
        label_20->setScaledContents(true);
        pushButton_SelectedDay = new QPushButton(PopupselectDay);
        pushButton_SelectedDay->setObjectName("pushButton_SelectedDay");
        pushButton_SelectedDay->setGeometry(QRect(70, 40, 71, 25));
        pushButton_SelectedDay->setFont(font);
        pushButton_SelectedDay->setStyleSheet(QString::fromUtf8("#pushButton_SelectedDay\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_SelectedDay::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_SelectedDay::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        pushButton_SelectedDay->setIcon(icon);
        pushButton_SelectedDay->setIconSize(QSize(20, 20));
        pushButton_back_day = new QPushButton(PopupselectDay);
        pushButton_back_day->setObjectName("pushButton_back_day");
        pushButton_back_day->setGeometry(QRect(0, 10, 30, 30));
        pushButton_back_day->setStyleSheet(QString::fromUtf8("#pushButton_back_day\n"
"{\n"
"	background-color: white ;\n"
"	border-radius: 15;\n"
"}\n"
"#pushButton_back_day:pressed\n"
"{\n"
"	background-color: white;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_back_day:hover\n"
"{\n"
"	background-color: #CCFFFF;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back_day->setIcon(icon2);
        pushButton_back_day->setIconSize(QSize(30, 30));
        pushButton_next_day = new QPushButton(PopupselectDay);
        pushButton_next_day->setObjectName("pushButton_next_day");
        pushButton_next_day->setGeometry(QRect(160, 10, 30, 30));
        pushButton_next_day->setStyleSheet(QString::fromUtf8("#pushButton_next_day\n"
"{\n"
"	background-color :white ;\n"
"	border-radius: 15;\n"
"}\n"
"#pushButton_next_day:pressed\n"
"{\n"
"	background-color: white;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_next_day:hover\n"
"{\n"
"	background-color: #CCFFFF;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/Image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next_day->setIcon(icon3);
        pushButton_next_day->setIconSize(QSize(30, 30));
        label_date_select = new QLabel(PopupselectDay);
        label_date_select->setObjectName("label_date_select");
        label_date_select->setGeometry(QRect(30, 10, 131, 25));
        label_date_select->setFont(font);
        label_date_select->setStyleSheet(QString::fromUtf8("#label_date_select{\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"	border: 1px solid gray;\n"
"	color: black\n"
"}"));
        label_date_select->setAlignment(Qt::AlignCenter);

        retranslateUi(PopupChi);

        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PopupChi);
    } // setupUi

    void retranslateUi(QDialog *PopupChi)
    {
        PopupChi->setWindowTitle(QCoreApplication::translate("PopupChi", "Dialog", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("PopupChi", "Ti\341\273\201n tr\341\273\215", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("PopupChi", "Sinh ho\341\272\241t", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("PopupChi", "\304\220i ch\306\241i", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("PopupChi", "\304\202n u\341\273\221ng", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("PopupChi", "Kh\303\241c", nullptr));

        plainTextEdit_4->setPlainText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_2->setText(QCoreApplication::translate("PopupChi", "VN\304\220", nullptr));
        pushButton_SetChi->setText(QCoreApplication::translate("PopupChi", "Enter", nullptr));
        plainTextEdit_5->setPlainText(QString());
        label_17->setText(QString());
        plainTextEdit_6->setPlainText(QString());
        pushButton_Selectday->setText(QString());
        label_date_selected->setText(QString());
        label_20->setText(QString());
        pushButton_SelectedDay->setText(QCoreApplication::translate("PopupChi", "Enter", nullptr));
        pushButton_back_day->setText(QString());
        pushButton_next_day->setText(QString());
        label_date_select->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PopupChi: public Ui_PopupChi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPCHI_H
