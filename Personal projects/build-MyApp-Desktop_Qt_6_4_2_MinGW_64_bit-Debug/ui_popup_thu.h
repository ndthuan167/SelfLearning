/********************************************************************************
** Form generated from reading UI file 'popup_thu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_THU_H
#define UI_POPUP_THU_H

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

class Ui_popup_Thu
{
public:
    QFrame *frametest;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label;
    QPushButton *pushButton_SetThu;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_date_selected_2;
    QPlainTextEdit *plainTextEdit_7;
    QLabel *label_18;
    QPushButton *pushButton_Selectday_Thu;
    QLabel *label_date_selected_Thu;
    QFrame *PopupselectDay_Thu;
    QLabel *label_21;
    QPushButton *pushButton_SelectedDay_Thu;
    QPushButton *pushButton_back_day_Thu;
    QPushButton *pushButton_next_day_Thu;
    QLabel *label_date_select_Thu;

    void setupUi(QDialog *popup_Thu)
    {
        if (popup_Thu->objectName().isEmpty())
            popup_Thu->setObjectName("popup_Thu");
        popup_Thu->resize(425, 203);
        frametest = new QFrame(popup_Thu);
        frametest->setObjectName("frametest");
        frametest->setGeometry(QRect(0, 0, 201, 181));
        frametest->setStyleSheet(QString::fromUtf8("#frametest{\n"
"	background-color: #EDE4E0;\n"
"	border-radius: 15;\n"
"	border: 2px solid white;\n"
"}"));
        frametest->setFrameShape(QFrame::StyledPanel);
        frametest->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frametest);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(45, 48, 141, 28));
        QFont font;
        font.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font.setPointSize(10);
        font.setBold(true);
        comboBox->setFont(font);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 10px;\n"
"    min-width: 6em;\n"
"	padding-left: 10;\n"
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
        comboBox->setEditable(false);
        comboBox->setMaxVisibleItems(10);
        plainTextEdit_2 = new QPlainTextEdit(frametest);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(45, 118, 141, 28));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font1.setBold(true);
        plainTextEdit_2->setFont(font1);
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5"));
        label_11 = new QLabel(frametest);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 48, 25, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-goal-40.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(frametest);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 83, 25, 25));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-money-40.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(frametest);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 118, 25, 25));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-note-40.png")));
        label_13->setScaledContents(true);
        label = new QLabel(frametest);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 83, 35, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        pushButton_SetThu = new QPushButton(frametest);
        pushButton_SetThu->setObjectName("pushButton_SetThu");
        pushButton_SetThu->setGeometry(QRect(60, 151, 71, 25));
        pushButton_SetThu->setFont(font);
        pushButton_SetThu->setStyleSheet(QString::fromUtf8("#pushButton_SetThu\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_SetThu::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_SetThu::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Image/icons8-next-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SetThu->setIcon(icon);
        pushButton_SetThu->setIconSize(QSize(20, 20));
        plainTextEdit_3 = new QPlainTextEdit(frametest);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(45, 83, 101, 28));
        plainTextEdit_3->setFont(font);
        plainTextEdit_3->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 8"));
        label_date_selected_2 = new QLabel(frametest);
        label_date_selected_2->setObjectName("label_date_selected_2");
        label_date_selected_2->setGeometry(QRect(60, 13, 91, 25));
        label_date_selected_2->setFont(font);
        label_date_selected_2->setStyleSheet(QString::fromUtf8("#label_date_selected{\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"	border: 1px solid white;\n"
"	color: black\n"
"}"));
        label_date_selected_2->setAlignment(Qt::AlignCenter);
        plainTextEdit_7 = new QPlainTextEdit(frametest);
        plainTextEdit_7->setObjectName("plainTextEdit_7");
        plainTextEdit_7->setGeometry(QRect(45, 13, 141, 28));
        plainTextEdit_7->setFont(font1);
        plainTextEdit_7->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5"));
        label_18 = new QLabel(frametest);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(8, 13, 31, 31));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-calendar-48.png")));
        label_18->setScaledContents(true);
        pushButton_Selectday_Thu = new QPushButton(frametest);
        pushButton_Selectday_Thu->setObjectName("pushButton_Selectday_Thu");
        pushButton_Selectday_Thu->setGeometry(QRect(160, 15, 21, 24));
        pushButton_Selectday_Thu->setStyleSheet(QString::fromUtf8("#pushButton_Selectday_Thu\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_Selectday_Thu::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_Selectday_Thu::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Image/icons8-calendar-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Selectday_Thu->setIcon(icon1);
        pushButton_Selectday_Thu->setIconSize(QSize(20, 20));
        label_date_selected_Thu = new QLabel(frametest);
        label_date_selected_Thu->setObjectName("label_date_selected_Thu");
        label_date_selected_Thu->setGeometry(QRect(60, 15, 91, 25));
        label_date_selected_Thu->setFont(font);
        label_date_selected_Thu->setStyleSheet(QString::fromUtf8("#label_date_selected_Thu{\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"	border: 1px solid white;\n"
"	color: black\n"
"}"));
        label_date_selected_Thu->setAlignment(Qt::AlignCenter);
        PopupselectDay_Thu = new QFrame(popup_Thu);
        PopupselectDay_Thu->setObjectName("PopupselectDay_Thu");
        PopupselectDay_Thu->setGeometry(QRect(210, 30, 191, 71));
        PopupselectDay_Thu->setStyleSheet(QString::fromUtf8("#PopupselectDay_Thu{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 2px solid white;\n"
"}"));
        PopupselectDay_Thu->setFrameShape(QFrame::StyledPanel);
        PopupselectDay_Thu->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(PopupselectDay_Thu);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 37, 31, 31));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-calendar-48.png")));
        label_21->setScaledContents(true);
        pushButton_SelectedDay_Thu = new QPushButton(PopupselectDay_Thu);
        pushButton_SelectedDay_Thu->setObjectName("pushButton_SelectedDay_Thu");
        pushButton_SelectedDay_Thu->setGeometry(QRect(70, 40, 71, 25));
        pushButton_SelectedDay_Thu->setFont(font);
        pushButton_SelectedDay_Thu->setStyleSheet(QString::fromUtf8("#pushButton_SelectedDay_Thu\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_SelectedDay_Thu::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_SelectedDay_Thu::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        pushButton_SelectedDay_Thu->setIcon(icon);
        pushButton_SelectedDay_Thu->setIconSize(QSize(20, 20));
        pushButton_back_day_Thu = new QPushButton(PopupselectDay_Thu);
        pushButton_back_day_Thu->setObjectName("pushButton_back_day_Thu");
        pushButton_back_day_Thu->setGeometry(QRect(0, 10, 30, 30));
        pushButton_back_day_Thu->setStyleSheet(QString::fromUtf8("#pushButton_back_day_Thu\n"
"{\n"
"	background-color: white ;\n"
"	border-radius: 15;\n"
"}\n"
"#pushButton_back_day_Thu:pressed\n"
"{\n"
"	background-color: white;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_back_day_Thu:hover\n"
"{\n"
"	background-color: #CCFFFF;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back_day_Thu->setIcon(icon2);
        pushButton_back_day_Thu->setIconSize(QSize(30, 30));
        pushButton_next_day_Thu = new QPushButton(PopupselectDay_Thu);
        pushButton_next_day_Thu->setObjectName("pushButton_next_day_Thu");
        pushButton_next_day_Thu->setGeometry(QRect(160, 10, 30, 30));
        pushButton_next_day_Thu->setStyleSheet(QString::fromUtf8("#pushButton_next_day_Thu\n"
"{\n"
"	background-color :white ;\n"
"	border-radius: 15;\n"
"}\n"
"#pushButton_next_day_Thu:pressed\n"
"{\n"
"	background-color: white;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_next_day_Thu:hover\n"
"{\n"
"	background-color: #CCFFFF;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/Image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next_day_Thu->setIcon(icon3);
        pushButton_next_day_Thu->setIconSize(QSize(30, 30));
        label_date_select_Thu = new QLabel(PopupselectDay_Thu);
        label_date_select_Thu->setObjectName("label_date_select_Thu");
        label_date_select_Thu->setGeometry(QRect(30, 10, 131, 25));
        label_date_select_Thu->setFont(font);
        label_date_select_Thu->setStyleSheet(QString::fromUtf8("#label_date_select_Thu{\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"	border: 1px solid gray;\n"
"	color: black\n"
"}"));
        label_date_select_Thu->setAlignment(Qt::AlignCenter);

        retranslateUi(popup_Thu);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(popup_Thu);
    } // setupUi

    void retranslateUi(QDialog *popup_Thu)
    {
        popup_Thu->setWindowTitle(QCoreApplication::translate("popup_Thu", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("popup_Thu", "L\306\260\306\241ng th\303\241ng", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("popup_Thu", "Kh\303\241c", nullptr));

        plainTextEdit_2->setPlainText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label->setText(QCoreApplication::translate("popup_Thu", "VN\304\220", nullptr));
        pushButton_SetThu->setText(QCoreApplication::translate("popup_Thu", "Enter", nullptr));
        plainTextEdit_3->setPlainText(QString());
        label_date_selected_2->setText(QCoreApplication::translate("popup_Thu", "09/12/2023", nullptr));
        plainTextEdit_7->setPlainText(QString());
        label_18->setText(QString());
        pushButton_Selectday_Thu->setText(QString());
        label_date_selected_Thu->setText(QCoreApplication::translate("popup_Thu", "09/12/2023", nullptr));
        label_21->setText(QString());
        pushButton_SelectedDay_Thu->setText(QCoreApplication::translate("popup_Thu", "Enter", nullptr));
        pushButton_back_day_Thu->setText(QString());
        pushButton_next_day_Thu->setText(QString());
        label_date_select_Thu->setText(QCoreApplication::translate("popup_Thu", "09/12/2023", nullptr));
    } // retranslateUi

};

namespace Ui {
    class popup_Thu: public Ui_popup_Thu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_THU_H
