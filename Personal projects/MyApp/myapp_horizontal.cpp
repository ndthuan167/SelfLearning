#include "myapp_horizontal.h"
#include "ui_myapp_horizontal.h"
#include "myapp.h"

myApp_horizontal::myApp_horizontal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myApp_horizontal)
{
    ui->setupUi(this);
    MyApp *myapp = new MyApp;

    this->setFixedSize(1320,770);

    connect(ui->YoutubeButton, QPushButton::clicked, myapp, myapp->OpenYoutubeWebsite);
    connect(ui->FacebookButton, QPushButton::clicked, myapp, myapp->OpenFacebookWebsite);
    connect(ui->GoogleButton, QPushButton::clicked, myapp, myapp->OpenGoogleSearch);
    connect(ui->GithubButton, QPushButton::clicked, myapp, myapp->OpenGithubWebsite);
    connect(ui->VSCodeButton, QPushButton::clicked, myapp, myapp->OpenVSCode);
    connect(ui->ZaloButton, QPushButton::clicked, myapp, myapp->OpenZaloApp);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTimeinHorizontal_layout()));
    timer->start(1000);

    // Animation for Image
    QTimer *timer_image = new QTimer(this);
    connect(timer_image, SIGNAL(timeout()), this, SLOT(NextImage()));
    timer_image->start(5000);

    connect(ui->pushButton_login, SIGNAL(clicked(bool)), this, SLOT(ChangeToHorizontalLayout()));
    connect(ui->pushButton_hide, SIGNAL(clicked(bool)), this, SLOT(HidetheTotal()));
    connect(ui->pushButton_back, SIGNAL(clicked(bool)), this, SLOT(BackImage()));
    connect(ui->pushButton_next, SIGNAL(clicked(bool)), this, SLOT(NextImage()));
    connect(ui->pushButton_Plus_thu, SIGNAL(clicked(bool)), this, SLOT(ShowFrameTest()));
    connect(ui->pushButton_SetThu, SIGNAL(clicked(bool)), this, SLOT(EnterThuAndClose()));

    connect(ui->pushButton_Plus_chi, SIGNAL(clicked(bool)), this, SLOT(ShowPopUpChi()));
    connect(ui->pushButton_SetChi, SIGNAL(clicked(bool)), this, SLOT(EnterChiAndClose()));

    connect(ui->pushButton_Selectday, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_Selectday_Thu, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_SelectedDay, SIGNAL(clicked(bool)), this, SLOT(PopupselectDay()));
    connect(ui->pushButton_SelectedDay_Thu, SIGNAL(clicked(bool)), this, SLOT(PopupselectDay()));

    connect(ui->pushButton_back_day, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_back_day_Thu, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_next_day, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_next_day_Thu, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_SelectedDay, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));
    connect(ui->pushButton_SelectedDay_Thu, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));


}

void myApp_horizontal::ChangeToHorizontalLayout()
{
    this->hide();
    MyApp *myapp = new MyApp(this);
    myapp->show();
}

void myApp_horizontal::HidetheTotal()
{
    if (Hide == false)  Hide = true;
    else    Hide = false;

    if (Hide == true)
        ui->label_total->setText("Tổng tích lũy: 100 000 000 VNĐ");
    else
        ui->label_total->setText("Tổng tích lũy: *** *** *** VNĐ");
}

void myApp_horizontal::ShowTimeinHorizontal_layout()
{
    QString text_thu;
    QTime time = QTime::currentTime();
    QDate day = QDate::currentDate();
    QString text_day = day.toString("dd");
    text_thu = day.toString("dddd");
    QString text = time.toString("hh:mm");
    ui->label_time->setText(text);
    ui->label_day->setText(text_day);
    ui->label_thu->setText(text_thu);

    QString text_hour = time.toString("hh");
    int hour = text_hour.toInt();
    QString StyleSheetDay = "background-color:  "+ SunNight + "; color: #3085C3; border-radius: 25px";
    if (hour >= 18 || (hour >= 0 && hour <= 5))
    {
        SunNight = "#CBBCF6";
        QPixmap pixmap(":/Icon/Image/night.png");
        ui->label_night->setPixmap(pixmap);
        ui->label_day->setStyleSheet(StyleSheetDay);
    }
    else
    {
        SunNight = "#FDFFAE";
        QPixmap pixmap(":/Icon/Image/sun.png");
        ui->label_sun->setPixmap(pixmap);
        ui->label_day->setStyleSheet(StyleSheetDay);
    }

}

void myApp_horizontal::BackImage()
{
    numberofimage--;
    if (numberofimage == 0)
        numberofimage = 11;
    QString string1 = "border-image: url(:/ImagePersonal/Image/ImagePersonal/";
    QString string2 = QString::number(numberofimage);
    QString string3 = ".jpg) 0 0 0 0 stretch stretch;";
    QString stringplus = string1 + string2 + string3;
    ui->label_image->setStyleSheet( stringplus +
                                   "border-radius: 15px;"
                                   "border: 1pxsolid white;");
}

void myApp_horizontal::NextImage()
{
    numberofimage++;
    if (numberofimage > 11)
        numberofimage = 1;
    QString string1 = "border-image: url(:/ImagePersonal/Image/ImagePersonal/";
    QString string2 = QString::number(numberofimage);
    QString string3 = ".jpg) 0 0 0 0 stretch stretch;";
    QString stringplus = string1 + string2 + string3;
    ui->label_image->setStyleSheet( stringplus +
                                   "border-radius: 15px;"
                                   "border: 1pxsolid white;");

    QPropertyAnimation *animation_image = new QPropertyAnimation(ui->label_image, "geometry");
    ui->label_image->setGeometry(5,5,521,331);
    animation_image->setDuration(500);
    animation_image->setEndValue(QRect(ui->label_image->geometry().x(), ui->label_image->geometry().y(), 521, 331));
    animation_image->setStartValue(QRect(ui->label_image->geometry().x()-521, ui->label_image->geometry().y(), 521, 331));

    animation_image->start();

    QPropertyAnimation *animation_image_2 = new QPropertyAnimation(ui->label_image_2, "geometry");
    ui->label_image_2->setGeometry(10,5,521,331);
    animation_image_2->setDuration(500);
    animation_image_2->setEndValue(QRect(ui->label_image_2->geometry().x() + 521, ui->label_image_2->geometry().y(), 521, 331));
    animation_image_2->setStartValue(QRect(ui->label_image_2->geometry().x(), ui->label_image_2->geometry().y(), 521, 331));

    animation_image_2->start();
    QString string1_2 = "border-image: url(:/ImagePersonal/Image/ImagePersonal/";
    numberofimage_2 = numberofimage - 1;
    if (numberofimage_2 == 0)
        numberofimage_2 = 11;
    QString string2_2 = QString::number(numberofimage_2);
    QString string3_2 = ".jpg) 0 0 0 0 stretch stretch;";
    QString stringplus_2 = string1_2 + string2_2 + string3_2;
    ui->label_image_2->setStyleSheet( stringplus_2 +
                                   "border-radius: 15px;"
                                   "border: 1pxsolid white;");
}

void myApp_horizontal::ShowFrameTest()
{
    if (showframetest == false) showframetest = true;
    else    showframetest = false;

    if (showframetest == true)
    {
        ui->frametest->setGeometry(740, 150 ,201,181);

        QPropertyAnimation *animation = new QPropertyAnimation(ui->frametest, "geometry");
        animation->setDuration(100);
        animation->setStartValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y()+ui->frametest->geometry().height(), 0, 0));
        animation->setEndValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y(), ui->frametest->geometry().width(), ui->frametest->geometry().height()));

        animation->start();
    }
    else
    {
        QPropertyAnimation *animation = new QPropertyAnimation(ui->frametest, "geometry");
        animation->setDuration(100);
        animation->setEndValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y()+ui->frametest->geometry().height(), 0, 0));
        animation->setStartValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y(), ui->frametest->geometry().width(), ui->frametest->geometry().height()));

        animation->start();
    }
}

void myApp_horizontal::EnterThuAndClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->frametest, "geometry");
    animation->setDuration(100);
    animation->setEndValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y()+ui->frametest->geometry().height(), 0, 0));
    animation->setStartValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y(), ui->frametest->geometry().width(), ui->frametest->geometry().height()));

    animation->start();
    showframetest = false;

}

void myApp_horizontal::ShowPopUpChi()
{
    if (showPopupChi == false) showPopupChi = true;
    else    showPopupChi = false;

    if (showPopupChi == true)
    {
        ui->PopupChi->setGeometry(740, 510,200,181);

        QPropertyAnimation *animation = new QPropertyAnimation(ui->PopupChi, "geometry");
        animation->setDuration(100);
        animation->setStartValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y()+ui->PopupChi->geometry().height(), 0, 0));
        animation->setEndValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y(), ui->PopupChi->geometry().width(), ui->PopupChi->geometry().height()));

        animation->start();
    }
    else
    {

        QPropertyAnimation *animation = new QPropertyAnimation(ui->PopupChi, "geometry");
        animation->setDuration(100);
        animation->setEndValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y()+ui->PopupChi->geometry().height(), 0, 0));
        animation->setStartValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y(), ui->PopupChi->geometry().width(), ui->PopupChi->geometry().height()));

        animation->start();
    }
}

void myApp_horizontal::EnterChiAndClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->PopupChi, "geometry");
    animation->setDuration(100);
    animation->setEndValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y()+ui->PopupChi->geometry().height(), 0, 0));
    animation->setStartValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y(), ui->PopupChi->geometry().width(), ui->PopupChi->geometry().height()));

    animation->start();
    showPopupChi = false;

}

void myApp_horizontal::ShowCalendarSelection()
{
    if (showPopupChi == true)
    {
        ui->PopupselectDay->setGeometry(QRect(930,440, 190, 71));
       // ui->PopupChi->hide();
        QDate date = QDate::currentDate();
        QString current_date = date.toString("dd/MM/yyyy");
        ui->label_date_select->setText(current_date);
        today = date.toString("dd").toInt() ;
    }
    if (showframetest == true)
    {
        ui->PopupselectDay_Thu->setGeometry(QRect(930,80, 190, 71));
        //ui->frametest->hide();
        QDate date = QDate::currentDate();
        QString current_date = date.toString("dd/MM/yyyy");
        ui->label_date_select->setText(current_date);
        today = date.toString("dd").toInt() ;
    }
}

void myApp_horizontal::BackDayinCalendar()
{
    today--;
    QString today_string = QString::number(today);
    QDate day = QDate::currentDate();
    QString tomonth = day.toString("MM");
    QString toyear = day.toString("yyyy");
    if (today < 10)
        total_date = "0" + today_string  + "/" + tomonth + "/" + toyear;
    else
        total_date = today_string  + "/" + tomonth + "/" + toyear;
    if (showPopupChi == true)
        ui->label_date_select->setText(total_date);
    if (showframetest == true)
        ui->label_date_select_Thu->setText(total_date);
}

void myApp_horizontal::NextDayinCalendar()
{
    today++;
    QString today_string = QString::number(today);
    QDate day = QDate::currentDate();
    QString tomonth = day.toString("MM");
    QString toyear = day.toString("yyyy");
    if (today < 10)
        total_date = "0" + today_string  + "/" + tomonth + "/" + toyear;
    else
        total_date = today_string  + "/" + tomonth + "/" + toyear;
    if (showPopupChi == true)
        ui->label_date_select->setText(total_date);
    if (showframetest == true)
        ui->label_date_select_Thu->setText(total_date);
}

void myApp_horizontal::SetDateCalendar()
{
    if (showPopupChi == true)
        ui->label_date_selected->setText(total_date);
    if (showframetest == true)
        ui->label_date_selected_Thu->setText(total_date);
}

void myApp_horizontal::PopupselectDay()
{
    if (showPopupChi == true)
    {
        ui->PopupChi->show();
        ui->PopupselectDay->setGeometry(QRect(1780,580, 190, 71));
    }
    else if (showframetest == true)
    {
        ui->frametest->show();
        ui->PopupselectDay_Thu->setGeometry(QRect(1780,180, 190, 71));
    }
}

myApp_horizontal::~myApp_horizontal()
{
    delete ui;
}

