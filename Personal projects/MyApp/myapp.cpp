#include "myapp.h"
#include "ui_myapp.h"

MyApp::MyApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyApp)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    // Animation for Image
    QTimer *timer_image = new QTimer(this);
    connect(timer_image, SIGNAL(timeout()), this, SLOT(NextImage()));
    timer_image->start(5000);

    this->setFixedSize(460,690);
    this->setWindowTitle("Thuan's App");
    this->setWindowIcon(QIcon(":/Icon/Image/Icon.jpg"));

    connect(ui->YoutubeButton, SIGNAL(clicked(bool)), this, SLOT(OpenYoutubeWebsite()));
    connect(ui->GithubButton, SIGNAL(clicked(bool)), this, SLOT(OpenGithubWebsite()));
    connect(ui->FacebookButton, SIGNAL(clicked(bool)), this, SLOT(OpenFacebookWebsite()));
    connect(ui->ZaloButton, SIGNAL(clicked(bool)), this, SLOT(OpenZaloApp()));
    connect(ui->VSCodeButton, SIGNAL(clicked(bool)), this, SLOT(OpenVSCode()));
    connect(ui->GoogleButton, SIGNAL(clicked(bool)), this, SLOT(OpenGoogleSearch()));
    connect(ui->pushButton_hide, SIGNAL(clicked(bool)), this, SLOT(HidetheTotal()));
    connect(ui->pushButton_back, SIGNAL(clicked(bool)), this, SLOT(BackImage()));
    connect(ui->pushButton_next, SIGNAL(clicked(bool)), this, SLOT(NextImage()));
    connect(ui->pushButton_Plus_thu, SIGNAL(clicked(bool)), this, SLOT(ShowFrameTest()));
    connect(ui->pushButton_SetThu, SIGNAL(clicked(bool)), this, SLOT(EnterThuAndClose()));

    connect(ui->pushButton_Plus_chi, SIGNAL(clicked(bool)), this, SLOT(ShowPopUpChi()));
    connect(ui->pushButton_SetChi, SIGNAL(clicked(bool)), this, SLOT(EnterChiAndClose()));
    connect(ui->pushButton_login, SIGNAL(clicked(bool)), this, SLOT(ChangeToHorizontalLayout()));

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

MyApp::~MyApp()
{
    delete ui;
}

void MyApp::ChangeToHorizontalLayout()
{
    this->hide();
    myapp_horizon = new myApp_horizontal(this);
    myapp_horizon->show();
}
void MyApp::ShowFrameTest()
{
    if (showframetest == false) showframetest = true;
    else    showframetest = false;

    ui->plainTextEdit_3->setPlainText("");
    ui->plainTextEdit_2->setPlainText("");
    ui->label_date_selected_Thu->setText("");

    if (showframetest == true)
    {
        ui->frametest->setGeometry(30, 340 ,201,181);

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

void MyApp::EnterThuAndClose()
{
    number_of_setThu++;
    QPropertyAnimation *animation = new QPropertyAnimation(ui->frametest, "geometry");
    animation->setDuration(100);
    animation->setEndValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y()+ui->frametest->geometry().height(), 0, 0));
    animation->setStartValue(QRect(ui->frametest->geometry().x(), ui->frametest->geometry().y(), ui->frametest->geometry().width(), ui->frametest->geometry().height()));

    animation->start();
    showframetest = false;

    QString text_day = ui->label_date_selected_Thu->text().mid(0,2);
    QString text_content = ui->comboBox->currentText();
    QString text_money = ui->plainTextEdit_3->toPlainText();

    if (number_of_setThu == 1)
        MyApp::SetThuFrameResult("Thu", 27,395, text_day, text_money, text_content);
    if (number_of_setThu == 2)
        MyApp::SetThuFrameResult("Thu", 27,395 + 28 +5, text_day, text_money, text_content);
    if (number_of_setThu == 3)
        MyApp::SetThuFrameResult("Thu", 27,395 + 2*(28 +5), text_day, text_money, text_content);
    if (number_of_setThu == 4)
        MyApp::SetThuFrameResult("Thu", 27,395 + 3*(28 +5), text_day, text_money, text_content);
}

void MyApp::ShowPopUpChi()
{
    ui->plainTextEdit_5->setPlainText("");
    ui->plainTextEdit_4->setPlainText("");
    ui->label_date_selected->setText("");

    if (showPopupChi == false) showPopupChi = true;
    else    showPopupChi = false;

    if (showPopupChi == true)
    {
        ui->PopupChi->setGeometry(240, 340,200,181);

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

void MyApp::EnterChiAndClose()
{
    number_of_setChi++;
    QPropertyAnimation *animation = new QPropertyAnimation(ui->PopupChi, "geometry");
    animation->setDuration(100);
    animation->setEndValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y()+ui->PopupChi->geometry().height(), 0, 0));
    animation->setStartValue(QRect(ui->PopupChi->geometry().x(), ui->PopupChi->geometry().y(), ui->PopupChi->geometry().width(), ui->PopupChi->geometry().height()));

    animation->start();
    showPopupChi = false;

    QString text_day = ui->label_date_selected->text().mid(0,2);
    QString text_content = ui->comboBox_2->currentText();
    QString text_money = ui->plainTextEdit_5->toPlainText();

    if (number_of_setChi == 1)
        MyApp::SetThuFrameResult("Chi", 240, 395, text_day, text_money, text_content);
    if (number_of_setChi == 2)
        MyApp::SetThuFrameResult("Chi", 240,395 + 28 +5, text_day, text_money, text_content);
    if (number_of_setChi == 3)
        MyApp::SetThuFrameResult("Chi", 240,395 + 2*(28 +5), text_day, text_money, text_content);
    if (number_of_setChi == 4)
        MyApp::SetThuFrameResult("Chi", 240,395 + 3*(28 +5), text_day, text_money, text_content);

}

void MyApp::BackImage()
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

void MyApp::NextImage()
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
    ui->label_image->setGeometry(5,5,185,115);
    animation_image->setDuration(500);
    animation_image->setEndValue(QRect(ui->label_image->geometry().x(), ui->label_image->geometry().y(), 185, 115));
    animation_image->setStartValue(QRect(ui->label_image->geometry().x()-185, ui->label_image->geometry().y(), 185, 115));

    animation_image->start();

    QPropertyAnimation *animation_image_2 = new QPropertyAnimation(ui->label_image_2, "geometry");
    ui->label_image_2->setGeometry(10,5,185,115);
    animation_image_2->setDuration(500);
    animation_image_2->setEndValue(QRect(ui->label_image_2->geometry().x() + 185, ui->label_image_2->geometry().y(), 185, 115));
    animation_image_2->setStartValue(QRect(ui->label_image_2->geometry().x(), ui->label_image_2->geometry().y(), 185, 115));

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

int MyApp::ReturnNumberOfImage()
{
    return numberofimage;
}

void MyApp::HidetheTotal()
{
    if (Hide == false)  Hide = true;
    else    Hide = false;

    if (Hide == true)
        ui->label_total->setText("Tổng tích lũy: 100 000 000 VNĐ");
    else
        ui->label_total->setText("Tổng tích lũy: *** *** *** VNĐ");
}

void MyApp::showTime()
{
    QTime time = QTime::currentTime();
    QDate day = QDate::currentDate();
    QString text_day = day.toString("dd");
    QString text_thu = day.toString("dddd");
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

void MyApp::OpenYoutubeWebsite()
{
    QString Youtube_url = "https://www.youtube.com/";
    QDesktopServices::openUrl(QUrl(Youtube_url));
}

void MyApp::OpenGithubWebsite()
{
    QString myGithub_url = "https://github.com/ndthuan167";
    QDesktopServices::openUrl(QUrl(myGithub_url));
}

void MyApp::OpenFacebookWebsite()
{
    QString Facebook_url = "https://www.facebook.com/";
    QDesktopServices::openUrl(QUrl(Facebook_url));
}

void MyApp::OpenZaloApp()
{
    QProcess::startDetached("C:/Users/dinht/AppData/Local/Programs/Zalo/Zalo.exe");
}

void MyApp::OpenVSCode()
{
    QProcess::startDetached("D:/Phanmemhoctap/Visual Studio Code/Microsoft VS Code/Code.exe");
}

void MyApp::OpenGoogleSearch()
{
    QString Google_Search_url = "https://www.google.com/";
    QDesktopServices::openUrl(QUrl(Google_Search_url));
}

void MyApp::ShowCalendarSelection()
{
    if (showPopupChi == true)
    {
        ui->PopupselectDay->setGeometry(QRect(245,400, 190, 71));
        ui->PopupChi->hide();
        QDate date = QDate::currentDate();
        QString current_date = date.toString("dd/MM/yyyy");
        ui->label_date_select->setText(current_date);
        today = date.toString("dd").toInt() ;
    }
    if (showframetest == true)
    {
        ui->PopupselectDay_Thu->setGeometry(QRect(30,400, 190, 71));
        ui->frametest->hide();
        QDate date = QDate::currentDate();
        QString current_date = date.toString("dd/MM/yyyy");
        ui->label_date_select->setText(current_date);
        today = date.toString("dd").toInt() ;
    }
}

void MyApp::BackDayinCalendar()
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

void MyApp::NextDayinCalendar()
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

void MyApp::SetDateCalendar()
{
    if (showPopupChi == true)
        ui->label_date_selected->setText(total_date);
    if (showframetest == true)
        ui->label_date_selected_Thu->setText(total_date);
}

void MyApp::PopupselectDay()
{
    if (showPopupChi == true)
    {
        ui->PopupChi->show();
        ui->PopupselectDay->setGeometry(QRect(600,400, 190, 71));
    }
    else if (showframetest == true)
    {
        ui->frametest->show();
        ui->PopupselectDay_Thu->setGeometry(QRect(600,400, 190, 71));
    }
}

void MyApp::SetThuFrameResult(QString ThuOrChi, int x_geometry, int y_geometry, QString text_day, QString textmoney, QString textcontent)
{
    QString colorOfbackground;
    if (ThuOrChi == "Thu")
        colorOfbackground = "05BFDB";
    if (ThuOrChi == "Chi")
        colorOfbackground = "FF9209";

    QString styleSheetForFrame = "background-color: #" + colorOfbackground + "; border-radius: 10; border: 1px solid white; color: white";
    QString styleSheetForLabel = "background-color: white; border-radius: 7; border: 1px solid white; color: black" ;

    // ----> Set frame in a Scroll Area
//    QScrollArea *scrollarea =  new QScrollArea(this);
//    scrollarea->setGeometry(QRect(x_geometry, y_geometry, 190, 130));
//    scrollarea->setStyleSheet("background-color: black;");

    QFrame *frame_Thu = new QFrame(this);
    frame_Thu->setFixedSize(195,28);
    frame_Thu->setStyleSheet(styleSheetForFrame);
    frame_Thu->setGeometry(QRect(x_geometry,y_geometry,192,28));

    QLabel *label_day = new QLabel(frame_Thu);
    label_day->setGeometry(QRect(5,4,21,20));
    label_day->setStyleSheet(styleSheetForLabel);
    label_day->setText(text_day);
    label_day->setAlignment(Qt::AlignCenter);
    QFont font = label_day->font();
    font.setFamily("Samsung Sharp Sans");
    font.setPointSize(8);
    label_day->setFont(font);

    QLabel *label_money = new QLabel(frame_Thu);
    label_money->setGeometry(QRect(32,4,61,20));
    label_money->setStyleSheet(styleSheetForLabel);
    label_money->setText(textmoney);
    label_money->setAlignment(Qt::AlignCenter);
    label_money->setFont(font);

    QLabel *label_content = new QLabel(frame_Thu);
    label_content->setGeometry(QRect(100,4,91,20));
    label_content->setStyleSheet(styleSheetForLabel);
    label_content->setText(textcontent);
    label_content->setAlignment(Qt::AlignCenter);
    label_content->setFont(font);

//    scrollarea->show();
    frame_Thu->show();
}
