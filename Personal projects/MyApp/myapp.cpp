#include "myapp.h"
#include "ui_myapp.h"
#include "popupchi.h"
#include "popup_thu.h"

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

    connect(ui->pushButton_Plus_chi, SIGNAL(clicked(bool)), this, SLOT(ShowPopUpChi()));
    connect(ui->pushButton_login, SIGNAL(clicked(bool)), this, SLOT(ChangeToHorizontalLayout()));

}

MyApp::~MyApp()
{
    delete ui;
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

void MyApp::ChangeToHorizontalLayout()
{
    this->hide();
    myapp_horizon = new myApp_horizontal(this);
    myapp_horizon->show();
}

void MyApp::onDataAvailable(const QString &data_textday, const QString &data_textmoney, const QString &data_textcontent)
{
    number_testtest++;
        if (number_testtest == 1)
            MyApp::SetThuFrameResult("Chi", 240, 395, data_textday, data_textmoney, data_textcontent);
        if (number_testtest == 2)
            MyApp::SetThuFrameResult("Chi", 240,395 + 28 +5, data_textday, data_textmoney, data_textcontent);
        if (number_testtest == 3)
            MyApp::SetThuFrameResult("Chi", 240,395 + 2*(28 +5), data_textday, data_textmoney, data_textcontent);
        if (number_testtest == 4)
            MyApp::SetThuFrameResult("Chi", 240,395 + 3*(28 +5), data_textday, data_textmoney, data_textcontent);

}

void MyApp::onDataAvailable_Thu(const QString &data_textday_thu, const QString &data_textmoney_thu, const QString &data_textcontent_thu)
{
    number_testtest_Thu++;
    if (number_testtest_Thu == 1)
        MyApp::SetThuFrameResult("Thu", 27,395, data_textday_thu, data_textmoney_thu, data_textcontent_thu);
    if (number_testtest_Thu == 2)
        MyApp::SetThuFrameResult("Thu", 27,395 + 28 +5, data_textday_thu, data_textmoney_thu, data_textcontent_thu);
    if (number_testtest_Thu == 3)
        MyApp::SetThuFrameResult("Thu", 27,395 + 2*(28 +5), data_textday_thu, data_textmoney_thu, data_textcontent_thu);
    if (number_testtest_Thu == 4)
        MyApp::SetThuFrameResult("Thu", 27,395 + 3*(28 +5), data_textday_thu, data_textmoney_thu, data_textcontent_thu);
}

void MyApp::ShowFrameTest()
{
    popup_Thu *mypopup_thu = new popup_Thu(this, "Hello1");
    mypopup_thu->show();
    connect(mypopup_thu, &popup_Thu::dataAvaiable_Thu, this, &MyApp::onDataAvailable_Thu);
}

void MyApp::ShowPopUpChi()
{
    PopupChi *mypopup = new PopupChi(this, "Hello");
    mypopup->show();
    connect(mypopup, &PopupChi::dataAvaiable, this, &MyApp::onDataAvailable);
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
