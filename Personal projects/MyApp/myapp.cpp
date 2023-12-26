#include "myapp.h"
#include "ui_myapp.h"
#include "popupchi.h"
#include "popup_thu.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "xlsxworksheet.h"

using namespace QXlsx;

MyApp::MyApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MyApp)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    QDate day = QDate::currentDate();
    int current_month_show = day.toString("MM").toInt();
    ui->comboBox_MonthThu->setCurrentIndex(current_month_show - 1);

    // Animation for Image
    QTimer *timer_image = new QTimer(this);
    connect(timer_image, SIGNAL(timeout()), this, SLOT(NextImage()));
    timer_image->start(5000);

    QTimer *timer_updatedata = new QTimer(this);
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(ShowDataFromDataSource()));
    timer_updatedata->start(100);

    this->setFixedSize(460, 690);
    this->setWindowTitle("Thuan's App");
    this->setWindowIcon(QIcon(":/Icon/Image/Icon.jpg"));

    connect(ui->YoutubeButton, SIGNAL(clicked(bool)), this, SLOT(OpenYoutubeWebsite()));
    connect(ui->GithubButton, SIGNAL(clicked(bool)), this, SLOT(OpenGithubWebsite()));
    connect(ui->FacebookButton, SIGNAL(clicked(bool)), this, SLOT(OpenFacebookWebsite()));
    connect(ui->ZaloButton, SIGNAL(clicked(bool)), this, SLOT(OpenZaloApp()));
    connect(ui->VSCodeButton, SIGNAL(clicked(bool)), this, SLOT(OpenVSCode()));
    connect(ui->GoogleButton, SIGNAL(clicked(bool)), this, SLOT(OpenGoogleSearch()));
    connect(ui->pushButton_Excel, SIGNAL(clicked(bool)), this, SLOT(OpenExcelDataSource()));

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

void MyApp::OpenExcelDataSource()
{
    //    QProcess::execute("C:/Program Files/Microsoft Office/root/Office16/EXCEL.EXE", QStringList() << "Data_source.xlsx");
    //    QFileDialog::getOpenFileName(this, "Data_source.xlsx");
}

void MyApp::ChangeToHorizontalLayout()
{
    if (set_horizontal_layout == false)
        set_horizontal_layout = true;
    else
        set_horizontal_layout = false;

    if (set_horizontal_layout == true)
    {
        QPixmap pixmap(":/Icon/Image/icons8-login-rounded-up-35.png");
        ui->pushButton_login->setIcon(QIcon(pixmap));
        ui->pushButton_login->setIconSize(QSize(35,35));
        // Change Geometry to horizontal layout
        this->setFixedSize(1310, 760);
        ui->frame->setGeometry(QRect(5, 5, 1300, 750));
        ui->frame_usual_app->setGeometry(QRect(10, 10, 131, 730));
        ui->frame_usual_app->setStyleSheet("background-color: #4FC1E9");
        ui->frame_password_2->setGeometry(QRect(20, 690, 111, 41));
        ui->frame_password_2->setStyleSheet("#frame_password_2{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->pushButton_menu->setGeometry(QRect(15, 5, 30, 30));
        ui->pushButton_login->setGeometry(QRect(65, 5, 31, 31));

        ui->frame_info->setGeometry(QRect(20, 640, 111, 45));
        ui->frame_info->setStyleSheet("#frame_info{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}}");
        ui->label_9->setGeometry(QRect(15, 7, 31, 31));
        ui->label_10->setGeometry(QRect(50, 3, 51, 41));

        ui->frame_password->setGeometry(QRect(20, 590, 111, 45));
        ui->frame_password->setStyleSheet("#frame_password{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->pushButton_password->setGeometry(QRect(15, 7, 30, 30));
        ui->pushButton_Plus_pass->setGeometry(QRect(70, 8, 30, 30));

        ui->frame_plan_note->setGeometry(QRect(150, 370, 551, 371));
        ui->frame_plan->setGeometry(QRect(10, 10, 263, 351));
        ui->frame_note->setGeometry(QRect(279, 10, 262, 351));

        ui->frame_Image->setGeometry(QRect(150, 10, 551, 351));
        ui->frame_2->setGeometry(QRect(10, 5, 531, 341));
        ui->label_image_2->setGeometry(QRect(5, 5, 521, 331));
        ui->label_image->setGeometry(QRect(530 + 5, 5, 521, 331));

        ui->pushButton_next->setGeometry(QRect(670, 170, 30, 30));
        ui->pushButton_back->setGeometry(QRect(150, 170, 30, 30));

        ui->frame_thuchi->setGeometry(QRect(710, 10, 581, 731));
        ui->frame_thu->setGeometry(QRect(10, 50, 561, 221));
        ui->comboBox_MonthThu->setGeometry(QRect(20, 10, 151, 25));
        ui->label_5->setGeometry(QRect(530, 55, 28, 28));
        ui->pushButton_Plus_thu->setGeometry(QRect(5, 182, 31, 31));
        ui->label_total_thu->setGeometry(QRect(40, 188, 151, 25));

        ui->frame_chi->setGeometry(QRect(10, 278, 561, 445));
        ui->comboBox_MonthChi->setGeometry(QRect(20, 10, 151, 25));
        ui->label_6->setGeometry(QRect(520, 10, 28, 28));
        ui->pushButton_Plus_chi->setGeometry(QRect(5, 405, 31, 31));
        ui->label_total_chi->setGeometry(QRect(40, 410, 151, 25));

        ui->pushButton_Excel->setGeometry(QRect(530, 10, 31, 31));
        ui->pushButton_hide->setGeometry(QRect(490, 27, 21, 20));
        ui->label_total->setGeometry(QRect(130, 10, 371, 31));

        ui->frame_day_time->setGeometry(QRect(20, 20, 111, 141));
        ui->frame_day_time->raise();
        ui->label_thu->setGeometry(QRect(15, 5, 85, 28));
        ui->label_day->setGeometry(QRect(25, 37, 60, 55));
        ui->label_time->setGeometry(QRect(15, 95, 87, 35));
        ui->label_night->setGeometry(QRect(75, 75, 21, 21));
        ui->label_sun->setGeometry(QRect(75, 35, 21, 21));

        ui->frame_Enter_app->setGeometry(QRect(10, 160, 111, 261));
        ui->frame_Enter_app->setStyleSheet("#frame_Enter_app{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->ZaloButton->setGeometry(QRect(9, 15, 93, 50));
        ui->ZaloButton->setStyleSheet(" #ZaloButton"
                                      "{"
                                      "border: 0px solid white;"
                                      "background-color: white;"
                                      "border-radius: 20px;"
                                      "}"
                                      "#ZaloButton::pressed"
                                      "{"
                                      "background-color: #99FFFF;"
                                      "border-style: inset;"
                                      "}"
                                      "#ZaloButton::hover"
                                      "{"
                                      "background-color: #BBBBBB;"
                                      "border-style: inset;"
                                      "}");
        ui->YoutubeButton->setGeometry(QRect(9, 77, 93, 50));
        ui->YoutubeButton->setStyleSheet(" #YoutubeButton"
                                         "{"
                                         "border: 0px solid white;"
                                         "background-color: white;"
                                         "border-radius: 20px;"
                                         "}"
                                         "#YoutubeButton::pressed"
                                         "{"
                                         "background-color: #99FFFF;"
                                         "border-style: inset;"
                                         "}"
                                         "#YoutubeButton::hover"
                                         "{"
                                         "background-color: #BBBBBB;"
                                         "border-style: inset;"
                                         "}");
        ui->FacebookButton->setGeometry(QRect(9, 136, 93, 50));
        ui->FacebookButton->setStyleSheet(" #FacebookButton"
                                          "{"
                                          "border: 0px solid white;"
                                          "background-color: white;"
                                          "border-radius: 20px;"
                                          "}"
                                          "#FacebookButton::pressed"
                                          "{"
                                          "background-color: #99FFFF;"
                                          "border-style: inset;"
                                          "}"
                                          "#FacebookButton::hover"
                                          "{"
                                          "background-color: #BBBBBB;"
                                          "border-style: inset;"
                                          "}");
        ui->GoogleButton->setGeometry(QRect(9, 196, 93, 50));
        ui->GoogleButton->setStyleSheet(" #GoogleButton"
                                        "{"
                                        "border: 0px solid white;"
                                        "background-color: white;"
                                        "border-radius: 20px;"
                                        "}"
                                        "#GoogleButton::pressed"
                                        "{"
                                        "background-color: #99FFFF;"
                                        "border-style: inset;"
                                        "}"
                                        "#GoogleButton::hover"
                                        "{"
                                        "background-color: #BBBBBB;"
                                        "border-style: inset;"
                                        "}");
        ui->frame_coding_app->setGeometry(QRect(10, 430, 111, 141));
        ui->frame_coding_app->setStyleSheet("#frame_coding_app{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->VSCodeButton->setGeometry(QRect(9, 14, 93, 50));
        ui->VSCodeButton->setStyleSheet(" #VSCodeButton"
                                        "{"
                                        "border: 0px solid white;"
                                        "background-color: white;"
                                        "border-radius: 20px;"
                                        "}"
                                        "#VSCodeButton::pressed"
                                        "{"
                                        "background-color: #99FFFF;"
                                        "border-style: inset;"
                                        "}"
                                        "#VSCodeButton::hover"
                                        "{"
                                        "background-color: #BBBBBB;"
                                        "border-style: inset;"
                                        "}");
        ui->GithubButton->setGeometry(QRect(9, 75, 93, 50));
        ui->GithubButton->setStyleSheet(" #GithubButton"
                                        "{"
                                        "border: 0px solid white;"
                                        "background-color: white;"
                                        "border-radius: 20px;"
                                        "}"
                                        "#GithubButton::pressed"
                                        "{"
                                        "background-color: #99FFFF;"
                                        "border-style: inset;"
                                        "}"
                                        "#GithubButton::hover"
                                        "{"
                                        "background-color: #BBBBBB;"
                                        "border-style: inset;"
                                        "}");
    }
    else
    {
        QPixmap pixmap(":/Icon/Image/icons8-login-48.png");
        ui->pushButton_login->setIcon(QIcon(pixmap));
        ui->pushButton_login->setIconSize(QSize(35,35));

        ShowDataFromDataSource();
        // Change Geometry to vertical layout
        this->setFixedSize(460, 690);
        ui->frame->setGeometry(QRect(5, 5, 451, 680));
        ui->frame_usual_app->setGeometry(QRect(10, 580, 431, 91));
        ui->frame_usual_app->setStyleSheet("background-color: #EEF2F5");
        ui->frame_password_2->setGeometry(QRect(10, 100, 91, 41));
        ui->frame_password_2->setStyleSheet("#frame_password_2{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->pushButton_menu->setGeometry(QRect(10, 5, 30, 30));
        ui->pushButton_login->setGeometry(QRect(50, 5, 30, 30));

        ui->frame_info->setGeometry(QRect(10, 10, 90, 40));
        ui->frame_info->setStyleSheet("#frame_info{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}}");
        ui->label_9->setGeometry(QRect(10, 5, 31, 31));
        ui->label_10->setGeometry(QRect(35, 0, 51, 41));

        ui->frame_password->setGeometry(QRect(10, 55, 91, 41));
        ui->frame_password->setStyleSheet("#frame_password{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->pushButton_password->setGeometry(QRect(10, 5, 30, 30));
        ui->pushButton_Plus_pass->setGeometry(QRect(50, 8, 28, 28));

        ui->frame_plan_note->setGeometry(QRect(10, 150, 431, 141));
        ui->frame_plan->setGeometry(QRect(7, 12, 205, 117));
        ui->frame_note->setGeometry(QRect(220, 12, 205, 117));

        ui->frame_Image->setGeometry(QRect(115, 10, 215, 135));
        ui->frame_2->setGeometry(QRect(10, 5, 195, 125));
        ui->label_image_2->setGeometry(QRect(5, 5, 185, 115));
        ui->label_image->setGeometry(QRect(5 + 190, 5, 185, 115));
        ui->pushButton_next->setGeometry(QRect(310, 60, 30, 30));
        ui->pushButton_back->setGeometry(QRect(105, 60, 30, 30));

        ui->frame_thuchi->setGeometry(QRect(10, 300, 431, 271));
        ui->frame_thu->setGeometry(QRect(7, 50, 205, 211));
        ui->comboBox_MonthThu->setGeometry(QRect(10, 5, 134, 25));
        ui->label_5->setGeometry(QRect(175, 55, 28, 28));
        ui->pushButton_Plus_thu->setGeometry(QRect(5, 175, 31, 31));
        ui->label_total_thu->setGeometry(QRect(40, 180, 151, 25));

        ui->frame_chi->setGeometry(QRect(220, 50, 205, 211));
        ui->comboBox_MonthChi->setGeometry(QRect(10, 5, 134, 25));
        ui->label_6->setGeometry(QRect(170, 5, 28, 28));
        ui->pushButton_Plus_chi->setGeometry(QRect(5, 175, 31, 31));
        ui->label_total_chi->setGeometry(QRect(40, 180, 151, 25));

        ui->pushButton_Excel->setGeometry(QRect(387, 10, 31, 31));
        ui->pushButton_hide->setGeometry(QRect(350, 27, 21, 20));
        ui->label_total->setGeometry(QRect(110, 10, 251, 31));

        ui->frame_day_time->setGeometry(QRect(340, 10, 101, 135));
        ui->frame_day_time->raise();
        ui->label_thu->setGeometry(QRect(8, 5, 85, 28));
        ui->label_day->setGeometry(QRect(20, 37, 60, 55));
        ui->label_time->setGeometry(QRect(8, 95, 87, 35));
        ui->label_night->setGeometry(QRect(70, 75, 21, 21));
        ui->label_sun->setGeometry(QRect(70, 35, 21, 21));

        ui->frame_Enter_app->setGeometry(QRect(11, 11, 251, 69));
        ui->frame_Enter_app->setStyleSheet("#frame_Enter_app{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->ZaloButton->setGeometry(QRect(188, 9, 54, 50));
        ui->ZaloButton->setStyleSheet(" #ZaloButton"
                                      "{"
                                      "border: 0px solid white;"
                                      "background-color: white;"
                                      "border-radius: 20px;"
                                      "}"
                                      "#ZaloButton::pressed"
                                      "{"
                                      "background-color: #99FFFF;"
                                      "border-style: inset;"
                                      "}"
                                      "#ZaloButton::hover"
                                      "{"
                                      "background-color: #BBBBBB;"
                                      "border-style: inset;"
                                      "}");
        ui->YoutubeButton->setGeometry(QRect(128, 11, 54, 47));
        ui->YoutubeButton->setStyleSheet(" #YoutubeButton"
                                         "{"
                                         "border: 0px solid white;"
                                         "background-color: white;"
                                         "border-radius: 20px;"
                                         "}"
                                         "#YoutubeButton::pressed"
                                         "{"
                                         "background-color: #99FFFF;"
                                         "border-style: inset;"
                                         "}"
                                         "#YoutubeButton::hover"
                                         "{"
                                         "background-color: #BBBBBB;"
                                         "border-style: inset;"
                                         "}");
        ui->FacebookButton->setGeometry(QRect(69, 10, 52, 48));
        ui->FacebookButton->setStyleSheet(" #FacebookButton"
                                          "{"
                                          "border: 0px solid white;"
                                          "background-color: white;"
                                          "border-radius: 20px;"
                                          "}"
                                          "#FacebookButton::pressed"
                                          "{"
                                          "background-color: #99FFFF;"
                                          "border-style: inset;"
                                          "}"
                                          "#FacebookButton::hover"
                                          "{"
                                          "background-color: #BBBBBB;"
                                          "border-style: inset;"
                                          "}");
        ui->GoogleButton->setGeometry(QRect(9, 10, 52, 48));
        ui->GoogleButton->setStyleSheet(" #GoogleButton"
                                        "{"
                                        "border: 0px solid white;"
                                        "background-color: white;"
                                        "border-radius: 20px;"
                                        "}"
                                        "#GoogleButton::pressed"
                                        "{"
                                        "background-color: #99FFFF;"
                                        "border-style: inset;"
                                        "}"
                                        "#GoogleButton::hover"
                                        "{"
                                        "background-color: #BBBBBB;"
                                        "border-style: inset;"
                                        "}");
        ui->frame_coding_app->setGeometry(QRect(269, 11, 151, 69));
        ui->frame_coding_app->setStyleSheet("#frame_coding_app{\n	background-color: white;\n	border-radius: 15;\n	border: 1px solid white;\n}");
        ui->VSCodeButton->setGeometry(QRect(79, 9, 54, 50));
        ui->VSCodeButton->setStyleSheet(" #VSCodeButton"
                                        "{"
                                        "border: 0px solid white;"
                                        "background-color: white;"
                                        "border-radius: 20px;"
                                        "}"
                                        "#VSCodeButton::pressed"
                                        "{"
                                        "background-color: #99FFFF;"
                                        "border-style: inset;"
                                        "}"
                                        "#VSCodeButton::hover"
                                        "{"
                                        "background-color: #BBBBBB;"
                                        "border-style: inset;"
                                        "}");
        ui->GithubButton->setGeometry(QRect(9, 9, 54, 50));
        ui->GithubButton->setStyleSheet(" #GithubButton"
                                        "{"
                                        "border: 0px solid white;"
                                        "background-color: white;"
                                        "border-radius: 20px;"
                                        "}"
                                        "#GithubButton::pressed"
                                        "{"
                                        "background-color: #99FFFF;"
                                        "border-style: inset;"
                                        "}"
                                        "#GithubButton::hover"
                                        "{"
                                        "background-color: #BBBBBB;"
                                        "border-style: inset;"
                                        "}");
    }
}

void MyApp::onDataAvailable(const QString &data_textday, const QString &data_textmoney, const QString &data_texttype, const QString &data_textcontent)
{
    Document xlsx("Data_source.xlsx");

    int index_month_thu = ui->comboBox_MonthThu->currentIndex();
    xlsx.selectSheet(index_month_thu);

    if (data_textmoney != "" && data_textcontent != "")
    {
        while (xlsx.read(number_data_write_chi_index, 7).toInt() != 0)
        {
            number_data_write_chi_index++;
        }

        xlsx.write(number_data_write_chi_index, 7, data_textday);
        xlsx.write(number_data_write_chi_index, 8, data_textmoney);
        xlsx.write(number_data_write_chi_index, 9, data_texttype);
        xlsx.write(number_data_write_chi_index, 10, data_textcontent);

        xlsx.saveAs("Data_source.xlsx");
        number_data_write_chi_index = 5;
    }
}

void MyApp::onDataAvailable_Thu(const QString &data_textday_thu, const QString &data_textmoney_thu, const QString &data_texttype_thu, const QString &data_textcontent_thu)
{
    Document xlsx("Data_source.xlsx");

    int index_month_thu = ui->comboBox_MonthThu->currentIndex();
    xlsx.selectSheet(index_month_thu);

    if(data_textmoney_thu != "" && data_textcontent_thu != "")
    {
        while (xlsx.read(number_data_write_thu_index, 1).toInt() != 0)
        {
            number_data_write_thu_index++;
        }

        xlsx.write(number_data_write_thu_index, 1, data_textday_thu);
        xlsx.write(number_data_write_thu_index, 3, data_textmoney_thu);
        xlsx.write(number_data_write_thu_index, 2, data_texttype_thu);
        xlsx.write(number_data_write_thu_index, 4, data_textcontent_thu);

        xlsx.saveAs("Data_source.xlsx");
        number_data_write_thu_index = 5;
    }
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
    ui->label_image->setStyleSheet(stringplus +
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
    ui->label_image->setStyleSheet(stringplus +
                                   "border-radius: 15px;"
                                   "border: 1pxsolid white;");

    QPropertyAnimation *animation_image = new QPropertyAnimation(ui->label_image, "geometry");
    animation_image->setDuration(500);

    if (set_horizontal_layout == true)
    {
        ui->label_image->setGeometry(5, 5, 521, 331);
        animation_image->setEndValue(QRect(ui->label_image->geometry().x(), ui->label_image->geometry().y(), 521, 331));
        animation_image->setStartValue(QRect(ui->label_image->geometry().x() - 521, ui->label_image->geometry().y(), 521, 331));
    }
    else
    {
        ui->label_image->setGeometry(5, 5, 185, 115);
        animation_image->setEndValue(QRect(ui->label_image->geometry().x(), ui->label_image->geometry().y(), 185, 115));
        animation_image->setStartValue(QRect(ui->label_image->geometry().x() - 185, ui->label_image->geometry().y(), 185, 115));
    }
    animation_image->start();

    QPropertyAnimation *animation_image_2 = new QPropertyAnimation(ui->label_image_2, "geometry");
    animation_image_2->setDuration(500);

    if (set_horizontal_layout == true)
    {
        ui->label_image_2->setGeometry(5, 5, 521, 331);
        animation_image_2->setEndValue(QRect(ui->label_image_2->geometry().x() + 530, ui->label_image_2->geometry().y(), 521, 331));
        animation_image_2->setStartValue(QRect(ui->label_image_2->geometry().x(), ui->label_image_2->geometry().y(), 521, 331));
    }
    else
    {
        ui->label_image_2->setGeometry(10, 5, 185, 115);
        animation_image_2->setEndValue(QRect(ui->label_image_2->geometry().x() + 185, ui->label_image_2->geometry().y(), 185, 115));
        animation_image_2->setStartValue(QRect(ui->label_image_2->geometry().x(), ui->label_image_2->geometry().y(), 185, 115));
    }
    animation_image_2->start();
    QString string1_2 = "border-image: url(:/ImagePersonal/Image/ImagePersonal/";
    numberofimage_2 = numberofimage - 1;
    if (numberofimage_2 == 0)
        numberofimage_2 = 11;
    QString string2_2 = QString::number(numberofimage_2);
    QString string3_2 = ".jpg) 0 0 0 0 stretch stretch;";
    QString stringplus_2 = string1_2 + string2_2 + string3_2;
    ui->label_image_2->setStyleSheet(stringplus_2 +
                                     "border-radius: 15px;"
                                     "border: 1pxsolid white;");
}

void MyApp::HidetheTotal()
{
    if (Hide == false)
    {
        Hide = true;
        ui->pushButton_hide->setIcon(QIcon(":/Icon/Image/icons8-hide-15.png"));
    }
    else
    {
        Hide = false;
        ui->pushButton_hide->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));
    }
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
    QString StyleSheetDay = "background-color:  " + SunNight + "; color: #3085C3; border-radius: 25px";
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

void MyApp::ShowDataFromDataSource()
{
    Document xlsx("Data_source.xlsx");

    int index_month_thu = ui->comboBox_MonthThu->currentIndex();
    ui->comboBox_MonthChi->setCurrentIndex(index_month_thu);
    xlsx.selectSheet(index_month_thu);

    while (xlsx.read(number_data_thu_index, 1).toInt() != 0)
    {
        number_data_thu_index++;
        number_data_thu++;
    }
    if (number_data_thu >= 8)
        number_data_thu -= (number_data_thu - 8);

    if (number_data_thu >= 1)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_1->setGeometry(QRect(740, 110, 265, 28));
        else
            ui->frame_Thu_1->setGeometry(QRect(27, 395, 97, 28));
        ui->label_day_thu1->setText(xlsx.read(number_data_thu_index - number_data_thu, 1).toString());
        ui->label_money_thu1->setText(xlsx.read(number_data_thu_index - number_data_thu, 3).toString());
        ui->label_typethu1->setText(xlsx.read(number_data_thu_index - number_data_thu, 2).toString());
        ui->label_content_thu1->setText(xlsx.read(number_data_thu_index - number_data_thu, 4).toString());
    }
    else
        ui->frame_Thu_1->setGeometry(QRect(2400, 395, 97, 28));

    if (number_data_thu >= 2)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_2->setGeometry(QRect(740 + 265 + 5, 110, 265, 28));
        else
            ui->frame_Thu_2->setGeometry(QRect(27 + 97 + 2, 395, 97, 28));
        ui->label_day_thu2->setText(xlsx.read(number_data_thu_index - number_data_thu + 1, 1).toString());
        ui->label_money_thu2->setText(xlsx.read(number_data_thu_index - number_data_thu + 1, 3).toString());
        ui->label_typethu2->setText(xlsx.read(number_data_thu_index - number_data_thu + 1, 2).toString());
        ui->label_content_thu2->setText(xlsx.read(number_data_thu_index - number_data_thu + 1, 4).toString());
    }
    else
        ui->frame_Thu_2->setGeometry(QRect(2400, 395, 97, 28));

    if (number_data_thu >= 3)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_3->setGeometry(QRect(740, 110 + 28 + 5, 265, 28));
        else
            ui->frame_Thu_3->setGeometry(QRect(27, 395 + 28 + 5, 97, 28));
        ui->label_day_thu3->setText(xlsx.read(number_data_thu_index - number_data_thu + 2, 1).toString());
        ui->label_money_thu3->setText(xlsx.read(number_data_thu_index - number_data_thu + 2, 3).toString());
        ui->label_typethu3->setText(xlsx.read(number_data_thu_index - number_data_thu + 2, 2).toString());
        ui->label_content_thu3->setText(xlsx.read(number_data_thu_index - number_data_thu + 2, 4).toString());
    }
    else
        ui->frame_Thu_3->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (number_data_thu >= 4)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_4->setGeometry(QRect(740 + 265 + 5, 110 + 28 + 5, 265, 28));
        else
            ui->frame_Thu_4->setGeometry(QRect(27 + 97 + 2, 395 + 28 + 5, 97, 28));
        ui->label_day_thu4->setText(xlsx.read(number_data_thu_index - number_data_thu + 3, 1).toString());
        ui->label_money_thu4->setText(xlsx.read(number_data_thu_index - number_data_thu + 3, 3).toString());
        ui->label_typethu4->setText(xlsx.read(number_data_thu_index - number_data_thu + 3, 2).toString());
        ui->label_content_thu4->setText(xlsx.read(number_data_thu_index - number_data_thu + 3, 4).toString());
    }
    else
        ui->frame_Thu_4->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (number_data_thu >= 5)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_5->setGeometry(QRect(740, 110 + 2 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_5->setGeometry(QRect(27, 395 + 2 * (28 + 5), 97, 28));
        ui->label_day_thu5->setText(xlsx.read(number_data_thu_index - number_data_thu + 4, 1).toString());
        ui->label_money_thu5->setText(xlsx.read(number_data_thu_index - number_data_thu + 4, 3).toString());
        ui->label_typethu5->setText(xlsx.read(number_data_thu_index - number_data_thu + 4, 2).toString());
        ui->label_content_thu5->setText(xlsx.read(number_data_thu_index - number_data_thu + 4, 4).toString());
    }
    else
        ui->frame_Thu_5->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (number_data_thu >= 6)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_6->setGeometry(QRect(740 + 265 + 5, 110 + 2 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_6->setGeometry(QRect(27 + 97 + 2, 395 + 2 * (28 + 5), 97, 28));
        ui->label_day_thu6->setText(xlsx.read(number_data_thu_index - number_data_thu + 5, 1).toString());
        ui->label_money_thu6->setText(xlsx.read(number_data_thu_index - number_data_thu + 5, 3).toString());
        ui->label_typethu6->setText(xlsx.read(number_data_thu_index - number_data_thu + 5, 2).toString());
        ui->label_content_thu6->setText(xlsx.read(number_data_thu_index - number_data_thu + 5, 4).toString());
    }
    else
        ui->frame_Thu_6->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (number_data_thu >= 7)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_7->setGeometry(QRect(740, 110 + 3 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_7->setGeometry(QRect(27, 395 + 3 * (28 + 5), 97, 28));
        ui->label_day_thu7->setText(xlsx.read(number_data_thu_index - number_data_thu + 6, 1).toString());
        ui->label_money_thu7->setText(xlsx.read(number_data_thu_index - number_data_thu + 6, 3).toString());
        ui->label_typethu7->setText(xlsx.read(number_data_thu_index - number_data_thu + 6, 2).toString());
        ui->label_content_thu7->setText(xlsx.read(number_data_thu_index - number_data_thu + 6, 4).toString());
    }
    else
        ui->frame_Thu_7->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (number_data_thu >= 8)
    {
        if (set_horizontal_layout == true)
            ui->frame_Thu_8->setGeometry(QRect(740 + 265 + 5, 110 + 3 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_8->setGeometry(QRect(27 + 97 + 2, 395 + 3 * (28 + 5), 97, 28));
        ui->label_day_thu8->setText(xlsx.read(number_data_thu_index - number_data_thu + 7, 1).toString());
        ui->label_money_thu8->setText(xlsx.read(number_data_thu_index - number_data_thu + 7, 3).toString());
        ui->label_typethu8->setText(xlsx.read(number_data_thu_index - number_data_thu + 7, 2).toString());
        ui->label_content_thu8->setText(xlsx.read(number_data_thu_index - number_data_thu + 7, 4).toString());
    }
    else
        ui->frame_Thu_8->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    while (xlsx.read(number_data_chi_index, 7).toInt() != 0)
    {
        number_data_chi_index++;
        number_data_chi++;
    }

    if (number_data_chi >= 22)
        number_data_chi -= (number_data_chi - 22);

    if (number_data_chi >= 1)
    {
        ui->label_day_chi1->setText(xlsx.read(number_data_chi_index - number_data_chi, 7).toString());
        ui->label_money_chi1->setText(xlsx.read(number_data_chi_index - number_data_chi, 8).toString());
        ui->label_typechi1->setText(xlsx.read(number_data_chi_index - number_data_chi, 9).toString());
        ui->label_content_chi1->setText(xlsx.read(number_data_chi_index - number_data_chi, 10).toString());

        if (set_horizontal_layout == true)
        {
            ui->frame_Chi_1->setGeometry(QRect(740, 340, 265, 28));
        }
        else
        {
            ui->frame_Chi_1->setGeometry(QRect(240, 395, 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi1->setText(xlsx.read(number_data_chi_index - 8, 7).toString());
                ui->label_money_chi1->setText(xlsx.read(number_data_chi_index - 8, 8).toString());
                ui->label_typechi1->setText(xlsx.read(number_data_chi_index - 8, 9).toString());
                ui->label_content_chi1->setText(xlsx.read(number_data_chi_index - 8, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_1->setGeometry(QRect(2400, 395, 97, 28));

    if (number_data_chi >= 2)
    {
        ui->label_day_chi2->setText(xlsx.read(number_data_chi_index - number_data_chi + 1, 7).toString());
        ui->label_money_chi2->setText(xlsx.read(number_data_chi_index - number_data_chi + 1, 8).toString());
        ui->label_typechi2->setText(xlsx.read(number_data_chi_index - number_data_chi + 1, 9).toString());
        ui->label_content_chi2->setText(xlsx.read(number_data_chi_index - number_data_chi + 1, 10).toString());

        if (set_horizontal_layout == true)
        {
            ui->frame_Chi_2->setGeometry(QRect(740 + 265 + 5, 340, 265, 28));
        }
        else
        {
            ui->frame_Chi_2->setGeometry(QRect(240 + 98 + 2, 395, 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi2->setText(xlsx.read(number_data_chi_index - 8 + 1, 7).toString());
                ui->label_money_chi2->setText(xlsx.read(number_data_chi_index - 8 + 1, 8).toString());
                ui->label_typechi2->setText(xlsx.read(number_data_chi_index - 8 + 1, 9).toString());
                ui->label_content_chi2->setText(xlsx.read(number_data_chi_index - 8 + 1, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_2->setGeometry(QRect(2400 + 98 + 2, 395, 97, 28));

    if (number_data_chi >= 3)
    {
        ui->label_day_chi3->setText(xlsx.read(number_data_chi_index - number_data_chi + 2, 7).toString());
        ui->label_money_chi3->setText(xlsx.read(number_data_chi_index - number_data_chi + 2, 8).toString());
        ui->label_typechi3->setText(xlsx.read(number_data_chi_index - number_data_chi + 2, 9).toString());
        ui->label_content_chi3->setText(xlsx.read(number_data_chi_index - number_data_chi + 2, 10).toString());

        if (set_horizontal_layout == true)
            ui->frame_Chi_3->setGeometry(QRect(740, 340 + 28 + 5, 265, 28));
        else
        {
            ui->frame_Chi_3->setGeometry(QRect(240, 395 + 28 + 5, 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi3->setText(xlsx.read(number_data_chi_index - 8 + 2, 7).toString());
                ui->label_money_chi3->setText(xlsx.read(number_data_chi_index - 8 + 2, 8).toString());
                ui->label_typechi3->setText(xlsx.read(number_data_chi_index - 8 + 2, 9).toString());
                ui->label_content_chi3->setText(xlsx.read(number_data_chi_index - 8 + 2, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_3->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (number_data_chi >= 4)
    {
        ui->label_day_chi4->setText(xlsx.read(number_data_chi_index - number_data_chi + 3, 7).toString());
        ui->label_money_chi4->setText(xlsx.read(number_data_chi_index - number_data_chi + 3, 8).toString());
        ui->label_typechi4->setText(xlsx.read(number_data_chi_index - number_data_chi + 3, 9).toString());
        ui->label_content_chi4->setText(xlsx.read(number_data_chi_index - number_data_chi + 3, 10).toString());

        if (set_horizontal_layout == true)
            ui->frame_Chi_4->setGeometry(QRect(740 + 265 + 5, 340 + 28 + 5, 265, 28));
        else
        {
            ui->frame_Chi_4->setGeometry(QRect(240 + 98 + 2, 395 + 28 + 5, 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi4->setText(xlsx.read(number_data_chi_index - 8 + 3, 7).toString());
                ui->label_money_chi4->setText(xlsx.read(number_data_chi_index - 8 + 3, 8).toString());
                ui->label_typechi4->setText(xlsx.read(number_data_chi_index - 8 + 3, 9).toString());
                ui->label_content_chi4->setText(xlsx.read(number_data_chi_index - 8 + 3, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_4->setGeometry(QRect(2400 + 98 + 2, 395 + 28 + 5, 97, 28));

    if (number_data_chi >= 5)
    {
        ui->label_day_chi5->setText(xlsx.read(number_data_chi_index - number_data_chi + 4, 7).toString());
        ui->label_money_chi5->setText(xlsx.read(number_data_chi_index - number_data_chi + 4, 8).toString());
        ui->label_typechi5->setText(xlsx.read(number_data_chi_index - number_data_chi + 4, 9).toString());
        ui->label_content_chi5->setText(xlsx.read(number_data_chi_index - number_data_chi + 4, 10).toString());
        if (set_horizontal_layout == true)
            ui->frame_Chi_5->setGeometry(QRect(740, 340 + 2 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_5->setGeometry(QRect(240, 395 + 2 * (28 + 5), 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi5->setText(xlsx.read(number_data_chi_index - 8 + 4, 7).toString());
                ui->label_money_chi5->setText(xlsx.read(number_data_chi_index - 8 + 4, 8).toString());
                ui->label_typechi5->setText(xlsx.read(number_data_chi_index - 8 + 4, 9).toString());
                ui->label_content_chi5->setText(xlsx.read(number_data_chi_index - 8 + 4, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_5->setGeometry(QRect(2400, 395 + 2 * (28 + 5), 97, 28));

    if (number_data_chi >= 6)
    {
        ui->label_day_chi6->setText(xlsx.read(number_data_chi_index - number_data_chi + 5, 7).toString());
        ui->label_money_chi6->setText(xlsx.read(number_data_chi_index - number_data_chi + 5, 8).toString());
        ui->label_typechi6->setText(xlsx.read(number_data_chi_index - number_data_chi + 5, 9).toString());
        ui->label_content_chi6->setText(xlsx.read(number_data_chi_index - number_data_chi + 5, 10).toString());
        if (set_horizontal_layout == true)
            ui->frame_Chi_6->setGeometry(QRect(740 + 265 + 5, 340 + 2 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_6->setGeometry(QRect(240 + 98 + 2, 395 + 2 * (28 + 5), 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi6->setText(xlsx.read(number_data_chi_index - 8 + 5, 7).toString());
                ui->label_money_chi6->setText(xlsx.read(number_data_chi_index - 8 + 5, 8).toString());
                ui->label_typechi6->setText(xlsx.read(number_data_chi_index - 8 + 5, 9).toString());
                ui->label_content_chi6->setText(xlsx.read(number_data_chi_index - 8 + 5, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_6->setGeometry(QRect(2400 + 98 + 2, 395 + 2 * (28 + 5), 97, 28));

    if (number_data_chi >= 7)
    {
        ui->label_day_chi7->setText(xlsx.read(number_data_chi_index - number_data_chi + 6, 7).toString());
        ui->label_money_chi7->setText(xlsx.read(number_data_chi_index - number_data_chi + 6, 8).toString());
        ui->label_typechi7->setText(xlsx.read(number_data_chi_index - number_data_chi + 6, 9).toString());
        ui->label_content_chi7->setText(xlsx.read(number_data_chi_index - number_data_chi + 6, 10).toString());
        if (set_horizontal_layout == true)
            ui->frame_Chi_7->setGeometry(QRect(740, 340 + 3 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_7->setGeometry(QRect(240, 395 + 3 * (28 + 5), 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi7->setText(xlsx.read(number_data_chi_index - 8 + 6, 7).toString());
                ui->label_money_chi7->setText(xlsx.read(number_data_chi_index - 8 + 6, 8).toString());
                ui->label_typechi7->setText(xlsx.read(number_data_chi_index - 8 + 6, 9).toString());
                ui->label_content_chi7->setText(xlsx.read(number_data_chi_index - 8 + 6, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_7->setGeometry(QRect(2400, 395 + 3 * (28 + 5), 97, 28));

    if (number_data_chi >= 8)
    {
        ui->label_day_chi8->setText(xlsx.read(number_data_chi_index - number_data_chi + 7, 7).toString());
        ui->label_money_chi8->setText(xlsx.read(number_data_chi_index - number_data_chi + 7, 8).toString());
        ui->label_typechi8->setText(xlsx.read(number_data_chi_index - number_data_chi + 7, 9).toString());
        ui->label_content_chi8->setText(xlsx.read(number_data_chi_index - number_data_chi + 7, 10).toString());
        if (set_horizontal_layout == true)
            ui->frame_Chi_8->setGeometry(QRect(740 + 265 + 5, 340 + 3 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_8->setGeometry(QRect(240 + 98 + 2, 395 + 3 * (28 + 5), 97, 28));
            if (number_data_chi >= 8)
            {
                ui->label_day_chi8->setText(xlsx.read(number_data_chi_index - 8 + 7, 7).toString());
                ui->label_money_chi8->setText(xlsx.read(number_data_chi_index - 8 + 7, 8).toString());
                ui->label_typechi8->setText(xlsx.read(number_data_chi_index - 8 + 7, 9).toString());
                ui->label_content_chi8->setText(xlsx.read(number_data_chi_index - 8 + 7, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_8->setGeometry(QRect(2400 + 98 + 2, 395 + 3 * (28 + 5), 97, 28));

    if (set_horizontal_layout == true)
    {
        if (number_data_chi >= 9)
        {
            ui->frame_Chi_9->setGeometry(QRect(740, 340 + 4 * (28 + 5), 265, 28));
            ui->label_day_chi9->setText(xlsx.read(number_data_chi_index - number_data_chi + 8, 7).toString());
            ui->label_money_chi9->setText(xlsx.read(number_data_chi_index - number_data_chi + 8, 8).toString());
            ui->label_typechi9->setText(xlsx.read(number_data_chi_index - number_data_chi + 8, 9).toString());
            ui->label_content_chi9->setText(xlsx.read(number_data_chi_index - number_data_chi + 8, 10).toString());
        }
        else
            ui->frame_Chi_9->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (number_data_chi >= 10)
        {
            ui->frame_Chi_10->setGeometry(QRect(740 + 265 + 5, 340 + 4 * (28 + 5), 265, 28));
            ui->label_day_chi10->setText(xlsx.read(number_data_chi_index - number_data_chi + 9, 7).toString());
            ui->label_money_chi10->setText(xlsx.read(number_data_chi_index - number_data_chi + 9, 8).toString());
            ui->label_typechi10->setText(xlsx.read(number_data_chi_index - number_data_chi + 9, 9).toString());
            ui->label_content_chi10->setText(xlsx.read(number_data_chi_index - number_data_chi + 9, 10).toString());
        }
        else
            ui->frame_Chi_10->setGeometry(QRect(7040, 340 + 6 * (28 + 5), 265, 28));

        if (number_data_chi >= 11)
        {
            ui->frame_Chi_11->setGeometry(QRect(740, 340 + 5 * (28 + 5), 265, 28));
            ui->label_day_chi11->setText(xlsx.read(number_data_chi_index - number_data_chi + 10, 7).toString());
            ui->label_money_chi11->setText(xlsx.read(number_data_chi_index - number_data_chi + 10, 8).toString());
            ui->label_typechi11->setText(xlsx.read(number_data_chi_index - number_data_chi + 10, 9).toString());
            ui->label_content_chi11->setText(xlsx.read(number_data_chi_index - number_data_chi + 10, 10).toString());
        }
        else
            ui->frame_Chi_11->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (number_data_chi >= 12)
        {
            ui->frame_Chi_12->setGeometry(QRect(740 + 265 + 5, 340 + 5 * (28 + 5), 265, 28));
            ui->label_day_chi12->setText(xlsx.read(number_data_chi_index - number_data_chi + 11, 7).toString());
            ui->label_money_chi12->setText(xlsx.read(number_data_chi_index - number_data_chi + 11, 8).toString());
            ui->label_typechi12->setText(xlsx.read(number_data_chi_index - number_data_chi + 11, 9).toString());
            ui->label_content_chi12->setText(xlsx.read(number_data_chi_index - number_data_chi + 11, 10).toString());
        }
        else
            ui->frame_Chi_12->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (number_data_chi >= 13)
        {
            ui->frame_Chi_13->setGeometry(QRect(740, 340 + 6 * (28 + 5), 265, 28));
            ui->label_day_chi13->setText(xlsx.read(number_data_chi_index - number_data_chi + 12, 7).toString());
            ui->label_money_chi13->setText(xlsx.read(number_data_chi_index - number_data_chi + 12, 8).toString());
            ui->label_typechi13->setText(xlsx.read(number_data_chi_index - number_data_chi + 12, 9).toString());
            ui->label_content_chi13->setText(xlsx.read(number_data_chi_index - number_data_chi + 12, 10).toString());
        }
        else
            ui->frame_Chi_13->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (number_data_chi >= 14)
        {
            ui->frame_Chi_14->setGeometry(QRect(740 + 265 + 5, 340 + 6 * (28 + 5), 265, 28));
            ui->label_day_chi14->setText(xlsx.read(number_data_chi_index - number_data_chi + 13, 7).toString());
            ui->label_money_chi14->setText(xlsx.read(number_data_chi_index - number_data_chi + 13, 8).toString());
            ui->label_typechi14->setText(xlsx.read(number_data_chi_index - number_data_chi + 13, 9).toString());
            ui->label_content_chi14->setText(xlsx.read(number_data_chi_index - number_data_chi + 13, 10).toString());
        }
        else
            ui->frame_Chi_14->setGeometry(QRect(7400 + 265 + 5, 340 + 6 * (28 + 5), 265, 28));

        if (number_data_chi >= 15)
        {
            ui->frame_Chi_15->setGeometry(QRect(740, 340 + 7 * (28 + 5), 265, 28));
            ui->label_day_chi15->setText(xlsx.read(number_data_chi_index - number_data_chi + 14, 7).toString());
            ui->label_money_chi15->setText(xlsx.read(number_data_chi_index - number_data_chi + 14, 8).toString());
            ui->label_typechi15->setText(xlsx.read(number_data_chi_index - number_data_chi + 14, 9).toString());
            ui->label_content_chi15->setText(xlsx.read(number_data_chi_index - number_data_chi + 14, 10).toString());
        }
        else
            ui->frame_Chi_15->setGeometry(QRect(7400, 340 + 7 * (28 + 5), 265, 28));

        if (number_data_chi >= 16)
        {
            ui->frame_Chi_16->setGeometry(QRect(740 + 265 + 5, 340 + 7 * (28 + 5), 265, 28));
            ui->label_day_chi16->setText(xlsx.read(number_data_chi_index - number_data_chi + 15, 7).toString());
            ui->label_money_chi16->setText(xlsx.read(number_data_chi_index - number_data_chi + 15, 8).toString());
            ui->label_typechi16->setText(xlsx.read(number_data_chi_index - number_data_chi + 15, 9).toString());
            ui->label_content_chi16->setText(xlsx.read(number_data_chi_index - number_data_chi + 15, 10).toString());
        }
        else
            ui->frame_Chi_16->setGeometry(QRect(7400 + 265 + 5, 340 + 7 * (28 + 5), 265, 28));

        if (number_data_chi >= 17)
        {
            ui->frame_Chi_17->setGeometry(QRect(740, 340 + 8 * (28 + 5), 265, 28));
            ui->label_day_chi17->setText(xlsx.read(number_data_chi_index - number_data_chi + 16, 7).toString());
            ui->label_money_chi17->setText(xlsx.read(number_data_chi_index - number_data_chi + 16, 8).toString());
            ui->label_typechi17->setText(xlsx.read(number_data_chi_index - number_data_chi + 16, 9).toString());
            ui->label_content_chi17->setText(xlsx.read(number_data_chi_index - number_data_chi + 16, 10).toString());
        }
        else
            ui->frame_Chi_17->setGeometry(QRect(7400, 340 + 8 * (28 + 5), 265, 28));

        if (number_data_chi >= 18)
        {
            ui->frame_Chi_18->setGeometry(QRect(740 + 265 + 5, 340 + 8 * (28 + 5), 265, 28));
            ui->label_day_chi18->setText(xlsx.read(number_data_chi_index - number_data_chi + 17, 7).toString());
            ui->label_money_chi18->setText(xlsx.read(number_data_chi_index - number_data_chi + 17, 8).toString());
            ui->label_typechi18->setText(xlsx.read(number_data_chi_index - number_data_chi + 17, 9).toString());
            ui->label_content_chi18->setText(xlsx.read(number_data_chi_index - number_data_chi + 17, 10).toString());
        }
        else
            ui->frame_Chi_18->setGeometry(QRect(7400 + 265 + 5, 340 + 8 * (28 + 5), 265, 28));

        if (number_data_chi >= 19)
        {
            ui->frame_Chi_19->setGeometry(QRect(740, 340 + 9 * (28 + 5), 265, 28));
            ui->label_day_chi19->setText(xlsx.read(number_data_chi_index - number_data_chi + 18, 7).toString());
            ui->label_money_chi19->setText(xlsx.read(number_data_chi_index - number_data_chi + 18, 8).toString());
            ui->label_typechi19->setText(xlsx.read(number_data_chi_index - number_data_chi + 18, 9).toString());
            ui->label_content_chi19->setText(xlsx.read(number_data_chi_index - number_data_chi + 18, 10).toString());
        }
        else
            ui->frame_Chi_19->setGeometry(QRect(7400, 340 + 9 * (28 + 5), 265, 28));

        if (number_data_chi >= 20)
        {
            ui->frame_Chi_20->setGeometry(QRect(740 + 265 + 5, 340 + 9 * (28 + 5), 265, 28));
            ui->label_day_chi20->setText(xlsx.read(number_data_chi_index - number_data_chi + 19, 7).toString());
            ui->label_money_chi20->setText(xlsx.read(number_data_chi_index - number_data_chi + 19, 8).toString());
            ui->label_typechi20->setText(xlsx.read(number_data_chi_index - number_data_chi + 19, 9).toString());
            ui->label_content_chi20->setText(xlsx.read(number_data_chi_index - number_data_chi + 19, 10).toString());
        }
        else
            ui->frame_Chi_20->setGeometry(QRect(7400 + 265 + 5, 340 + 9 * (28 + 5), 265, 28));

        if (number_data_chi >= 21)
        {
            ui->frame_Chi_21->setGeometry(QRect(740, 340 + 10 * (28 + 5), 265, 28));
            ui->label_day_chi21->setText(xlsx.read(number_data_chi_index - number_data_chi + 20, 7).toString());
            ui->label_money_chi21->setText(xlsx.read(number_data_chi_index - number_data_chi + 20, 8).toString());
            ui->label_typechi21->setText(xlsx.read(number_data_chi_index - number_data_chi + 20, 9).toString());
            ui->label_content_chi21->setText(xlsx.read(number_data_chi_index - number_data_chi + 20, 10).toString());
        }
        else
            ui->frame_Chi_21->setGeometry(QRect(7400, 340 + 10 * (28 + 5), 265, 28));

        if (number_data_chi >= 22)
        {
            ui->frame_Chi_22->setGeometry(QRect(740 + 265 + 5, 340 + 10 * (28 + 5), 265, 28));
            ui->label_day_chi22->setText(xlsx.read(number_data_chi_index - number_data_chi + 21, 7).toString());
            ui->label_money_chi22->setText(xlsx.read(number_data_chi_index - number_data_chi + 21, 8).toString());
            ui->label_typechi22->setText(xlsx.read(number_data_chi_index - number_data_chi + 21, 9).toString());
            ui->label_content_chi22->setText(xlsx.read(number_data_chi_index - number_data_chi + 21, 10).toString());
        }
        else
            ui->frame_Chi_22->setGeometry(QRect(7400 + 265 + 5, 340 + 10 * (28 + 5), 265, 28));
    }

    for (int i = 0; i < 12; i++)
    {
        xlsx.selectSheet(i);
        for (int j = 5; j <= number_data_chi_index - 1; j++)
        {
            int_money_chi += xlsx.read(j, 8).toInt();
        }
        for (int k = 5; k <= number_data_thu_index - 1; k++)
        {
            int_money_thu += xlsx.read(k, 3).toInt();
        }
        //        int_money_thu = xlsx.read(5, 3).toInt();
        data_money_thu.push_back(int_money_thu);
        data_money_chi.push_back(int_money_chi);
        int_money_thu = 0;
        int_money_chi = 0;
    }

    money_thu = "Tổng: " + QString::number(data_money_thu.at(index_month_thu)) + " VNĐ";
    ui->label_total_thu->setText(money_thu);
    money_chi = "Tổng: " + QString::number(data_money_chi.at(index_month_thu)) + " VNĐ";
    ui->label_total_chi->setText(money_chi);
    money_tichluy = QString::number(data_money_thu.at(index_month_thu) - data_money_chi.at(index_month_thu));

    if (set_horizontal_layout == true)
    {
        if (Hide == true)
        {
            ui->label_total->setText("Tổng tích lũy tháng " + QString::number(index_month_thu + 1) + " : " + money_tichluy + " VNĐ");
        }
        else
        {
            ui->label_total_thu->setText("Tổng: *** *** *** VNĐ");
            ui->label_total_chi->setText("Tổng: *** *** *** VNĐ");
            ui->label_total->setText("Tổng tích lũy tháng " + QString::number(index_month_thu + 1) + " : *** *** *** VNĐ");
        }
    }
    else
    {
        if (Hide == true)
        {
            ui->label_total->setText("Tích lũy tháng " + QString::number(index_month_thu + 1) + " : " + money_tichluy + " VNĐ");
        }
        else
        {
            ui->label_total->setText("Tích lũy tháng " + QString::number(index_month_thu + 1) + " : *** *** *** VNĐ");
            ui->label_total_chi->setText("Tổng: *** *** *** VNĐ");
            ui->label_total_thu->setText("Tổng: *** *** *** VNĐ");
        }
    }

    QString total_tichluy_string = "Tích lũy tháng " + QString::number(index_month_thu + 1) + " : " + money_tichluy + " VNĐ";
    xlsx.selectSheet(index_month_thu);
    xlsx.write("A1", total_tichluy_string);
    xlsx.saveAs("Data_source.xlsx");

    data_money_thu.clear();
    data_money_chi.clear();
    number_data_chi_index = 5;
    number_data_chi = 0;
    number_data_thu_index = 5;
    number_data_thu = 0;
}
