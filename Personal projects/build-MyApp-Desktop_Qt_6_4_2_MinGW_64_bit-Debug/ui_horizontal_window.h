/********************************************************************************
** Form generated from reading UI file 'horizontal_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HORIZONTAL_WINDOW_H
#define UI_HORIZONTAL_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyApp
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *frame_usual_app;
    QFrame *frame_coding_app;
    QVBoxLayout *verticalLayout_3;
    QPushButton *VSCodeButton;
    QPushButton *GithubButton;
    QFrame *frame_Enter_app;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ZaloButton;
    QPushButton *YoutubeButton;
    QPushButton *FacebookButton;
    QPushButton *GoogleButton;
    QFrame *frame_info;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *frame_password_2;
    QPushButton *pushButton_menu;
    QPushButton *pushButton_login;
    QFrame *frame_password;
    QPushButton *pushButton_Plus_pass;
    QPushButton *pushButton_password;
    QFrame *frame_day_time;
    QLabel *label_time;
    QLabel *label_thu;
    QLabel *label_sun;
    QLabel *label_night;
    QLabel *label_day;
    QFrame *frame_Image;
    QFrame *frame_2;
    QLabel *label_image;
    QLabel *label_image_2;
    QFrame *frame_thuchi;
    QFrame *frame_thu;
    QPushButton *pushButton_Plus_thu;
    QLabel *label_total_thu;
    QFrame *frametest;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label;
    QPushButton *pushButton_SetThu;
    QPlainTextEdit *plainTextEdit_3;
    QFrame *frame_chi;
    QPushButton *pushButton_Plus_chi;
    QLabel *label_6;
    QLabel *label_total_chi;
    QFrame *PopupChi;
    QComboBox *comboBox_2;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_2;
    QPushButton *pushButton_SetChi;
    QPlainTextEdit *plainTextEdit_5;
    QLabel *label_total;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_Excel;
    QPushButton *pushButton_hide;
    QFrame *frame_plan_note;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_plan;
    QLabel *label_8;
    QFrame *frame_note;
    QLabel *label_7;
    QPushButton *pushButton_back;
    QPushButton *pushButton_next;

    void setupUi(QMainWindow *MyApp)
    {
        if (MyApp->objectName().isEmpty())
            MyApp->setObjectName("MyApp");
        MyApp->resize(1500, 850);
        centralwidget = new QWidget(MyApp);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#frame\n"
"{\n"
"	background-color: #164863;\n"
"	border-radius: 25;\n"
"	border: 0\n"
"}\n"
"#frame_usual_app\n"
"{\n"
"	background-color: #4FC1E9;\n"
"	border-radius: 20\n"
"}\n"
"\n"
"#frame_Enter_app {\n"
"    border: 0px solid gray;\n"
"    border-radius: 20px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"#frame_coding_app\n"
"{    \n"
"	border: 0px solid gray;\n"
"    border-radius: 20px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"#ZaloButton\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 20px;\n"
"}\n"
"#ZaloButton::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#ZaloButton::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}\n"
"\n"
"#YoutubeButton\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 20px;\n"
"}\n"
"#YoutubeButton::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#YoutubeButton::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
""
                        "	border-style: inset;\n"
"}\n"
"\n"
"#FacebookButton\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 20px;\n"
"}\n"
"#FacebookButton::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#FacebookButton::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}\n"
"\n"
"#VSCodeButton\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 20px;\n"
"}\n"
"#VSCodeButton::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#VSCodeButton::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}\n"
"\n"
"#GithubButton\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 20px;\n"
"}\n"
"#GithubButton::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#GithubButton::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}\n"
"\n"
"#GoogleButton\n"
"{\n"
"	border: 0px solid "
                        "white;\n"
"	background-color: white;\n"
"	border-radius: 20px;\n"
"}\n"
"#GoogleButton::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#GoogleButton::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}\n"
"\n"
"#frame_day_time{\n"
"	background-color: #F6F6F6;\n"
"	border-image: url(:/Icon/Image/backgroundcalendar.jpg) 0 0 0 0 stretch stretch;\n"
"	border-radius: 15;\n"
"	border: 3px solid #EEEEEE;\n"
"}\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(5, 5, 1300, 750));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_usual_app = new QFrame(frame);
        frame_usual_app->setObjectName("frame_usual_app");
        frame_usual_app->setGeometry(QRect(10, 10, 131, 730));
        frame_usual_app->setFrameShape(QFrame::StyledPanel);
        frame_usual_app->setFrameShadow(QFrame::Raised);
        frame_coding_app = new QFrame(frame_usual_app);
        frame_coding_app->setObjectName("frame_coding_app");
        frame_coding_app->setGeometry(QRect(9, 430, 111, 141));
        frame_coding_app->setFrameShape(QFrame::StyledPanel);
        frame_coding_app->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_coding_app);
        verticalLayout_3->setObjectName("verticalLayout_3");
        VSCodeButton = new QPushButton(frame_coding_app);
        VSCodeButton->setObjectName("VSCodeButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IconApplication/Image/vscode.png"), QSize(), QIcon::Normal, QIcon::Off);
        VSCodeButton->setIcon(icon);
        VSCodeButton->setIconSize(QSize(50, 50));

        verticalLayout_3->addWidget(VSCodeButton);

        GithubButton = new QPushButton(frame_coding_app);
        GithubButton->setObjectName("GithubButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IconApplication/Image/github.png"), QSize(), QIcon::Normal, QIcon::Off);
        GithubButton->setIcon(icon1);
        GithubButton->setIconSize(QSize(50, 50));

        verticalLayout_3->addWidget(GithubButton);

        frame_Enter_app = new QFrame(frame_usual_app);
        frame_Enter_app->setObjectName("frame_Enter_app");
        frame_Enter_app->setGeometry(QRect(10, 160, 111, 261));
        frame_Enter_app->setFrameShape(QFrame::StyledPanel);
        frame_Enter_app->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_Enter_app);
        verticalLayout_2->setObjectName("verticalLayout_2");
        ZaloButton = new QPushButton(frame_Enter_app);
        ZaloButton->setObjectName("ZaloButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IconApplication/Image/zalo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ZaloButton->setIcon(icon2);
        ZaloButton->setIconSize(QSize(50, 50));

        verticalLayout_2->addWidget(ZaloButton);

        YoutubeButton = new QPushButton(frame_Enter_app);
        YoutubeButton->setObjectName("YoutubeButton");
        YoutubeButton->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/IconApplication/Image/youtube.png"), QSize(), QIcon::Normal, QIcon::Off);
        YoutubeButton->setIcon(icon3);
        YoutubeButton->setIconSize(QSize(50, 47));

        verticalLayout_2->addWidget(YoutubeButton);

        FacebookButton = new QPushButton(frame_Enter_app);
        FacebookButton->setObjectName("FacebookButton");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Text Semibold")});
        font.setPointSize(11);
        font.setBold(true);
        FacebookButton->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/IconApplication/Image/facebook.png"), QSize(), QIcon::Normal, QIcon::Off);
        FacebookButton->setIcon(icon4);
        FacebookButton->setIconSize(QSize(48, 48));

        verticalLayout_2->addWidget(FacebookButton);

        GoogleButton = new QPushButton(frame_Enter_app);
        GoogleButton->setObjectName("GoogleButton");
        GoogleButton->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/IconApplication/Image/icons8-google-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        GoogleButton->setIcon(icon5);
        GoogleButton->setIconSize(QSize(48, 48));

        verticalLayout_2->addWidget(GoogleButton);

        frame_info = new QFrame(frame_usual_app);
        frame_info->setObjectName("frame_info");
        frame_info->setGeometry(QRect(10, 630, 111, 45));
        frame_info->setStyleSheet(QString::fromUtf8("#frame_info{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_info);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(15, 7, 31, 31));
        label_9->setStyleSheet(QString::fromUtf8("#label_9\n"
"{\n"
"	border-image: url(:/Icon/Image/Icon.jpg) 0 0 0 0 stretch stretch;\n"
"	border-radius: 15px;\n"
"	border: 1pxsolid white;\n"
"}"));
        label_10 = new QLabel(frame_info);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 3, 51, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("SamsungOne 700")});
        font1.setPointSize(10);
        font1.setBold(true);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);
        frame_password_2 = new QFrame(frame_usual_app);
        frame_password_2->setObjectName("frame_password_2");
        frame_password_2->setGeometry(QRect(10, 680, 111, 41));
        frame_password_2->setStyleSheet(QString::fromUtf8("#frame_password_2{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_password_2->setFrameShape(QFrame::StyledPanel);
        frame_password_2->setFrameShadow(QFrame::Raised);
        pushButton_menu = new QPushButton(frame_password_2);
        pushButton_menu->setObjectName("pushButton_menu");
        pushButton_menu->setGeometry(QRect(15, 5, 30, 30));
        pushButton_menu->setStyleSheet(QString::fromUtf8("#pushButton_menu\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 15px;\n"
"}\n"
"#pushButton_menu::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_menu::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icon/Image/icons8-menu-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_menu->setIcon(icon6);
        pushButton_menu->setIconSize(QSize(30, 30));
        pushButton_login = new QPushButton(frame_password_2);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(70, 5, 30, 30));
        pushButton_login->setStyleSheet(QString::fromUtf8("#pushButton_login\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_login::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_login::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icon/Image/icons8-login-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_login->setIcon(icon7);
        pushButton_login->setIconSize(QSize(35, 35));
        frame_password = new QFrame(frame_usual_app);
        frame_password->setObjectName("frame_password");
        frame_password->setGeometry(QRect(10, 580, 111, 45));
        frame_password->setStyleSheet(QString::fromUtf8("#frame_password{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_password->setFrameShape(QFrame::StyledPanel);
        frame_password->setFrameShadow(QFrame::Raised);
        pushButton_Plus_pass = new QPushButton(frame_password);
        pushButton_Plus_pass->setObjectName("pushButton_Plus_pass");
        pushButton_Plus_pass->setGeometry(QRect(70, 8, 28, 28));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("SamsungOne 400")});
        font2.setPointSize(22);
        font2.setBold(false);
        pushButton_Plus_pass->setFont(font2);
        pushButton_Plus_pass->setStyleSheet(QString::fromUtf8("#pushButton_Plus_pass\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: #5CB8E4;\n"
"	border-radius: 14px;\n"
"	color: white\n"
"}\n"
"#pushButton_Plus_pass::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_Plus_pass::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        pushButton_Plus_pass->setIconSize(QSize(40, 40));
        pushButton_password = new QPushButton(frame_password);
        pushButton_password->setObjectName("pushButton_password");
        pushButton_password->setGeometry(QRect(15, 7, 30, 30));
        pushButton_password->setStyleSheet(QString::fromUtf8("#pushButton_password\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 15px;\n"
"}\n"
"#pushButton_password::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_password::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icon/Image/icons8-password-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_password->setIcon(icon8);
        pushButton_password->setIconSize(QSize(30, 30));
        frame_day_time = new QFrame(frame_usual_app);
        frame_day_time->setObjectName("frame_day_time");
        frame_day_time->setGeometry(QRect(10, 10, 111, 141));
        frame_day_time->setFrameShape(QFrame::StyledPanel);
        frame_day_time->setFrameShadow(QFrame::Raised);
        label_time = new QLabel(frame_day_time);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(15, 95, 87, 35));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("SamsungOne 400")});
        font3.setPointSize(25);
        font3.setBold(false);
        label_time->setFont(font3);
        label_time->setStyleSheet(QString::fromUtf8("color: #3085C3"));
        label_time->setAlignment(Qt::AlignCenter);
        label_thu = new QLabel(frame_day_time);
        label_thu->setObjectName("label_thu");
        label_thu->setGeometry(QRect(15, 5, 85, 28));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("SamsungOne 700")});
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        label_thu->setFont(font4);
        label_thu->setStyleSheet(QString::fromUtf8("color: #3085C3"));
        label_thu->setAlignment(Qt::AlignCenter);
        label_sun = new QLabel(frame_day_time);
        label_sun->setObjectName("label_sun");
        label_sun->setGeometry(QRect(75, 35, 21, 21));
        label_sun->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        label_sun->setScaledContents(true);
        label_night = new QLabel(frame_day_time);
        label_night->setObjectName("label_night");
        label_night->setGeometry(QRect(75, 75, 21, 21));
        label_night->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        label_night->setScaledContents(true);
        label_day = new QLabel(frame_day_time);
        label_day->setObjectName("label_day");
        label_day->setGeometry(QRect(25, 37, 60, 55));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("SamsungOne 700")});
        font5.setPointSize(32);
        font5.setBold(true);
        label_day->setFont(font5);
        label_day->setLayoutDirection(Qt::LeftToRight);
        label_day->setAutoFillBackground(false);
        label_day->setStyleSheet(QString::fromUtf8("color: #3085C3;\n"
"/*#F6F078*/\n"
"background-color:  #CBBCF6;\n"
"border-radius: 25px"));
        label_day->setAlignment(Qt::AlignCenter);
        frame_Image = new QFrame(frame);
        frame_Image->setObjectName("frame_Image");
        frame_Image->setGeometry(QRect(150, 10, 551, 351));
        frame_Image->setStyleSheet(QString::fromUtf8("#frame_Image{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_Image->setFrameShape(QFrame::StyledPanel);
        frame_Image->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame_Image);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 5, 531, 341));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #5CB8E4;\n"
"border-radius: 20px"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_image = new QLabel(frame_2);
        label_image->setObjectName("label_image");
        label_image->setEnabled(true);
        label_image->setGeometry(QRect(120, 5, 521, 331));
        label_image->setStyleSheet(QString::fromUtf8("#label_image\n"
"{\n"
"	border-image: url(:/ImagePersonal/Image/ImagePersonal/1.jpg) 0 0 0 0 stretch stretch;\n"
"	border-radius: 15px;\n"
"	border: 1pxsolid white;\n"
"}"));
        label_image_2 = new QLabel(frame_2);
        label_image_2->setObjectName("label_image_2");
        label_image_2->setGeometry(QRect(5, 5, 521, 331));
        label_image_2->setStyleSheet(QString::fromUtf8("#label_image_2\n"
"{\n"
"	border-image: url(:/ImagePersonal/Image/ImagePersonal/11.jpg) 0 0 0 0 stretch stretch;\n"
"	border-radius: 15px;\n"
"	border: 1pxsolid white;\n"
"}"));
        label_image_2->raise();
        label_image->raise();
        frame_thuchi = new QFrame(frame);
        frame_thuchi->setObjectName("frame_thuchi");
        frame_thuchi->setGeometry(QRect(710, 10, 581, 731));
        frame_thuchi->setStyleSheet(QString::fromUtf8("#frame_thuchi{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_thuchi->setFrameShape(QFrame::StyledPanel);
        frame_thuchi->setFrameShadow(QFrame::Raised);
        frame_thu = new QFrame(frame_thuchi);
        frame_thu->setObjectName("frame_thu");
        frame_thu->setGeometry(QRect(7, 50, 561, 311));
        frame_thu->setStyleSheet(QString::fromUtf8("#frame_thu{\n"
"	background-color: #8ECDDD;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_thu->setFrameShape(QFrame::StyledPanel);
        frame_thu->setFrameShadow(QFrame::Raised);
        pushButton_Plus_thu = new QPushButton(frame_thu);
        pushButton_Plus_thu->setObjectName("pushButton_Plus_thu");
        pushButton_Plus_thu->setGeometry(QRect(5, 275, 31, 31));
        pushButton_Plus_thu->setFont(font2);
        pushButton_Plus_thu->setStyleSheet(QString::fromUtf8("#pushButton_Plus_thu\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: #5CB8E4;\n"
"	border-radius: 15px;\n"
"	color: white\n"
"}\n"
"#pushButton_Plus_thu::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_Plus_thu::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        pushButton_Plus_thu->setIconSize(QSize(40, 40));
        label_total_thu = new QLabel(frame_thu);
        label_total_thu->setObjectName("label_total_thu");
        label_total_thu->setGeometry(QRect(40, 280, 151, 25));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font6.setPointSize(10);
        font6.setBold(true);
        label_total_thu->setFont(font6);
        label_total_thu->setStyleSheet(QString::fromUtf8("#label_total_thu{\n"
"	background-color: #3085C3;\n"
"	border-radius: 10;\n"
"	border: 1px solid white;\n"
"	color: white\n"
"}"));
        label_total_thu->setAlignment(Qt::AlignCenter);
        frametest = new QFrame(frame_thu);
        frametest->setObjectName("frametest");
        frametest->setGeometry(QRect(30, 120, 190, 150));
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
        comboBox->setGeometry(QRect(45, 10, 132, 28));
        comboBox->setFont(font6);
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
        plainTextEdit_2->setGeometry(QRect(45, 80, 131, 28));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font7.setBold(true);
        plainTextEdit_2->setFont(font7);
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5"));
        label_11 = new QLabel(frametest);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 10, 25, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-goal-40.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(frametest);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 45, 25, 25));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-money-40.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(frametest);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 80, 25, 25));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-note-40.png")));
        label_13->setScaledContents(true);
        label = new QLabel(frametest);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 50, 35, 20));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Samsung Sharp Sans")});
        font8.setPointSize(12);
        font8.setBold(true);
        label->setFont(font8);
        pushButton_SetThu = new QPushButton(frametest);
        pushButton_SetThu->setObjectName("pushButton_SetThu");
        pushButton_SetThu->setGeometry(QRect(60, 115, 71, 25));
        pushButton_SetThu->setFont(font6);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Icon/Image/icons8-next-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SetThu->setIcon(icon9);
        pushButton_SetThu->setIconSize(QSize(20, 20));
        plainTextEdit_3 = new QPlainTextEdit(frametest);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(45, 45, 91, 28));
        plainTextEdit_3->setFont(font6);
        plainTextEdit_3->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 8"));
        frame_chi = new QFrame(frame_thuchi);
        frame_chi->setObjectName("frame_chi");
        frame_chi->setGeometry(QRect(10, 370, 561, 351));
        frame_chi->setStyleSheet(QString::fromUtf8("#frame_chi{\n"
"	background-color: #FFE3BB;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_chi->setFrameShape(QFrame::StyledPanel);
        frame_chi->setFrameShadow(QFrame::Raised);
        pushButton_Plus_chi = new QPushButton(frame_chi);
        pushButton_Plus_chi->setObjectName("pushButton_Plus_chi");
        pushButton_Plus_chi->setGeometry(QRect(5, 310, 31, 31));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("SamsungOne 400")});
        font9.setPointSize(22);
        pushButton_Plus_chi->setFont(font9);
        pushButton_Plus_chi->setStyleSheet(QString::fromUtf8("#pushButton_Plus_chi\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: #F5A962;\n"
"	border-radius: 15px;\n"
"	color: white\n"
"}\n"
"#pushButton_Plus_chi::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_Plus_chi::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        pushButton_Plus_chi->setIconSize(QSize(40, 40));
        label_6 = new QLabel(frame_chi);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(530, 5, 28, 28));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-money-48.png")));
        label_6->setScaledContents(true);
        label_total_chi = new QLabel(frame_chi);
        label_total_chi->setObjectName("label_total_chi");
        label_total_chi->setGeometry(QRect(40, 315, 151, 25));
        label_total_chi->setFont(font6);
        label_total_chi->setStyleSheet(QString::fromUtf8("#label_total_chi{\n"
"	background-color: #F5A962;\n"
"	border-radius: 10;\n"
"	border: 1px solid white;\n"
"	color: white\n"
"}"));
        label_total_chi->setAlignment(Qt::AlignCenter);
        PopupChi = new QFrame(frame_chi);
        PopupChi->setObjectName("PopupChi");
        PopupChi->setGeometry(QRect(30, 150, 190, 150));
        PopupChi->setStyleSheet(QString::fromUtf8("#PopupChi{\n"
"	background-color: #EDE4E0;\n"
"	border-radius: 15;\n"
"	border: 2px solid white;\n"
"}"));
        PopupChi->setFrameShape(QFrame::StyledPanel);
        PopupChi->setFrameShadow(QFrame::Raised);
        comboBox_2 = new QComboBox(PopupChi);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(45, 10, 132, 28));
        comboBox_2->setFont(font6);
        comboBox_2->setLayoutDirection(Qt::LeftToRight);
        comboBox_2->setAutoFillBackground(false);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        comboBox_2->setEditable(false);
        comboBox_2->setMaxVisibleItems(10);
        plainTextEdit_4 = new QPlainTextEdit(PopupChi);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(45, 80, 131, 28));
        plainTextEdit_4->setFont(font7);
        plainTextEdit_4->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5"));
        label_14 = new QLabel(PopupChi);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 10, 25, 25));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-goal-40.png")));
        label_14->setScaledContents(true);
        label_15 = new QLabel(PopupChi);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 45, 25, 25));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-money-40.png")));
        label_15->setScaledContents(true);
        label_16 = new QLabel(PopupChi);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 80, 25, 25));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-note-40.png")));
        label_16->setScaledContents(true);
        label_2 = new QLabel(PopupChi);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 50, 35, 20));
        label_2->setFont(font8);
        pushButton_SetChi = new QPushButton(PopupChi);
        pushButton_SetChi->setObjectName("pushButton_SetChi");
        pushButton_SetChi->setGeometry(QRect(60, 115, 71, 25));
        pushButton_SetChi->setFont(font6);
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
        pushButton_SetChi->setIcon(icon9);
        pushButton_SetChi->setIconSize(QSize(20, 20));
        plainTextEdit_5 = new QPlainTextEdit(PopupChi);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(45, 45, 91, 28));
        plainTextEdit_5->setFont(font6);
        plainTextEdit_5->setStyleSheet(QString::fromUtf8("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 8"));
        label_total = new QLabel(frame_thuchi);
        label_total->setObjectName("label_total");
        label_total->setGeometry(QRect(130, 10, 371, 31));
        label_total->setFont(font8);
        label_total->setStyleSheet(QString::fromUtf8("#label_total{\n"
"	background-color: #EEEEEE;\n"
"	border-radius: 10;\n"
"	border: 1px solid white;\n"
"	color: #3085C3\n"
"}"));
        label_total->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame_thuchi);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(55, 10, 61, 31));
        label_3->setFont(font6);
        label_3->setStyleSheet(QString::fromUtf8("color: #3085C3"));
        label_4 = new QLabel(frame_thuchi);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 5, 40, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/manager.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(frame_thuchi);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(530, 60, 28, 28));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-revenue-48.png")));
        label_5->setScaledContents(true);
        pushButton_Excel = new QPushButton(frame_thuchi);
        pushButton_Excel->setObjectName("pushButton_Excel");
        pushButton_Excel->setGeometry(QRect(530, 10, 31, 31));
        pushButton_Excel->setStyleSheet(QString::fromUtf8("#pushButton_Excel\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_Excel::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_Excel::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Icon/Image/icons8-excel-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Excel->setIcon(icon10);
        pushButton_Excel->setIconSize(QSize(40, 40));
        pushButton_hide = new QPushButton(frame_thuchi);
        pushButton_hide->setObjectName("pushButton_hide");
        pushButton_hide->setGeometry(QRect(490, 27, 21, 20));
        pushButton_hide->setStyleSheet(QString::fromUtf8("#pushButton_hide\n"
"{\n"
"	border: 0px solid white;\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}\n"
"#pushButton_hide::pressed\n"
"{\n"
"	background-color: #99FFFF;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_hide::hover\n"
"{\n"
"	background-color: #BBBBBB;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Icon/Image/icons8-eye-15.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_hide->setIcon(icon11);
        pushButton_hide->setIconSize(QSize(40, 40));
        frame_plan_note = new QFrame(frame);
        frame_plan_note->setObjectName("frame_plan_note");
        frame_plan_note->setGeometry(QRect(150, 370, 551, 371));
        frame_plan_note->setStyleSheet(QString::fromUtf8("#frame_plan_note{\n"
"	background-color: white;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_plan_note->setFrameShape(QFrame::StyledPanel);
        frame_plan_note->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_plan_note);
        horizontalLayout->setObjectName("horizontalLayout");
        frame_plan = new QFrame(frame_plan_note);
        frame_plan->setObjectName("frame_plan");
        frame_plan->setStyleSheet(QString::fromUtf8("#frame_plan{\n"
"	background-color: #B5CB99;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_plan->setFrameShape(QFrame::StyledPanel);
        frame_plan->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_plan);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(5, 0, 31, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-plan-30.png")));
        label_8->setScaledContents(true);

        horizontalLayout->addWidget(frame_plan);

        frame_note = new QFrame(frame_plan_note);
        frame_note->setObjectName("frame_note");
        frame_note->setStyleSheet(QString::fromUtf8("#frame_note{\n"
"	background-color: #F8F6F4;\n"
"	border-radius: 15;\n"
"	border: 1px solid white;\n"
"}"));
        frame_note->setFrameShape(QFrame::StyledPanel);
        frame_note->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_note);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(5, 5, 25, 25));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/Icon/Image/icons8-note-30.png")));
        label_7->setScaledContents(true);

        horizontalLayout->addWidget(frame_note);

        pushButton_back = new QPushButton(frame);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(150, 170, 30, 30));
        pushButton_back->setStyleSheet(QString::fromUtf8("#pushButton_back\n"
"{\n"
"	background-color: white ;\n"
"	border-radius: 15;\n"
"}\n"
"#pushButton_back:pressed\n"
"{\n"
"	background-color: white;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_back:hover\n"
"{\n"
"	background-color: #CCFFFF;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Icon/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon12);
        pushButton_back->setIconSize(QSize(30, 30));
        pushButton_next = new QPushButton(frame);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setGeometry(QRect(670, 170, 30, 30));
        pushButton_next->setStyleSheet(QString::fromUtf8("#pushButton_next\n"
"{\n"
"	background-color :white ;\n"
"	border-radius: 15;\n"
"}\n"
"#pushButton_next:pressed\n"
"{\n"
"	background-color: white;\n"
"	border-style: inset;\n"
"}\n"
"#pushButton_next:hover\n"
"{\n"
"	background-color: #CCFFFF;\n"
"	border-style: inset;\n"
"}"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Icon/Image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next->setIcon(icon13);
        pushButton_next->setIconSize(QSize(30, 30));
        frame_Image->raise();
        frame_usual_app->raise();
        frame_thuchi->raise();
        frame_plan_note->raise();
        pushButton_back->raise();
        pushButton_next->raise();
        MyApp->setCentralWidget(centralwidget);

        retranslateUi(MyApp);

        comboBox->setCurrentIndex(0);
        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyApp);
    } // setupUi

    void retranslateUi(QMainWindow *MyApp)
    {
        MyApp->setWindowTitle(QCoreApplication::translate("MyApp", "MyApp", nullptr));
        VSCodeButton->setText(QString());
        GithubButton->setText(QString());
        ZaloButton->setText(QString());
        YoutubeButton->setText(QString());
        FacebookButton->setText(QString());
        GoogleButton->setText(QString());
        label_9->setText(QString());
        label_10->setText(QCoreApplication::translate("MyApp", "\304\220\303\254nh\n"
" Thu\341\272\255n", nullptr));
        pushButton_menu->setText(QString());
        pushButton_login->setText(QString());
        pushButton_Plus_pass->setText(QCoreApplication::translate("MyApp", "+", nullptr));
        pushButton_password->setText(QString());
        label_time->setText(QCoreApplication::translate("MyApp", "23:05", nullptr));
        label_thu->setText(QCoreApplication::translate("MyApp", "Friday", nullptr));
        label_sun->setText(QString());
        label_night->setText(QString());
        label_day->setText(QCoreApplication::translate("MyApp", "30", nullptr));
        label_image->setText(QString());
        label_image_2->setText(QString());
        pushButton_Plus_thu->setText(QCoreApplication::translate("MyApp", "+", nullptr));
        label_total_thu->setText(QCoreApplication::translate("MyApp", "T\341\273\225ng: 10 000 000 VN\304\220", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MyApp", "L\306\260\306\241ng th\303\241ng", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MyApp", "Kh\303\241c", nullptr));

        plainTextEdit_2->setPlainText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label->setText(QCoreApplication::translate("MyApp", "VN\304\220", nullptr));
        pushButton_SetThu->setText(QCoreApplication::translate("MyApp", "Enter", nullptr));
        plainTextEdit_3->setPlainText(QString());
        pushButton_Plus_chi->setText(QCoreApplication::translate("MyApp", "-", nullptr));
        label_6->setText(QString());
        label_total_chi->setText(QCoreApplication::translate("MyApp", "T\341\273\225ng: 10 000 000 VN\304\220", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MyApp", "Ti\341\273\201n tr\341\273\215", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MyApp", "Sinh ho\341\272\241t", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MyApp", "\304\220i ch\306\241i", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MyApp", "\304\202n u\341\273\221ng", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MyApp", "Kh\303\241c", nullptr));

        plainTextEdit_4->setPlainText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_2->setText(QCoreApplication::translate("MyApp", "VN\304\220", nullptr));
        pushButton_SetChi->setText(QCoreApplication::translate("MyApp", "Enter", nullptr));
        plainTextEdit_5->setPlainText(QString());
        label_total->setText(QCoreApplication::translate("MyApp", "T\341\273\225ng t\303\255ch l\305\251y: *** *** *** VN\304\220", nullptr));
        label_3->setText(QCoreApplication::translate("MyApp", "Qu\341\272\243n l\303\275 \n"
"thu chi", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton_Excel->setText(QString());
        pushButton_hide->setText(QString());
        label_8->setText(QString());
        label_7->setText(QString());
        pushButton_back->setText(QString());
        pushButton_next->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyApp: public Ui_MyApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HORIZONTAL_WINDOW_H
