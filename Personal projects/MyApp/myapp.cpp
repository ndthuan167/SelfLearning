#include "myapp.h"
#include "ui_myapp.h"

using namespace QXlsx;

MyApp::MyApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MyApp)
{
    ui->setupUi(this);
    this->setFixedSize(460, 690);
    this->setWindowTitle("Thuan's App");
    this->setWindowIcon(QIcon(":/Icon/Image/Icon.jpg"));

    // Time/Date Display (Calendar)
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(CurrentDateTime()));
    timer->start(1000);

    QDate ldDate = QDate::currentDate();
    int liCurrentMonth = ldDate.toString("MM").toInt();
    ui->comboBox_MonthThu->setCurrentIndex(liCurrentMonth - 1);

    // Website/App Opening
    connect(ui->YoutubeButton, SIGNAL(clicked(bool)), this, SLOT(OpenYoutubeWebsite()));
    connect(ui->GithubButton, SIGNAL(clicked(bool)), this, SLOT(OpenGithubWebsite()));
    connect(ui->FacebookButton, SIGNAL(clicked(bool)), this, SLOT(OpenFacebookWebsite()));
    connect(ui->ZaloButton, SIGNAL(clicked(bool)), this, SLOT(OpenZaloApp()));
    connect(ui->VSCodeButton, SIGNAL(clicked(bool)), this, SLOT(OpenVSCode()));
    connect(ui->GoogleButton, SIGNAL(clicked(bool)), this, SLOT(OpenGoogleSearch()));
    connect(ui->pushButton_Excel, SIGNAL(clicked(bool)), this, SLOT(OpenExcelDataSource()));

    // Image Animation
    QTimer *timer_image = new QTimer(this);
    connect(timer_image, SIGNAL(timeout()), this, SLOT(NextImage()));
    timer_image->start(5000);
    connect(ui->pushButton_back, SIGNAL(clicked(bool)), this, SLOT(BackImage()));
    connect(ui->pushButton_next, SIGNAL(clicked(bool)), this, SLOT(NextImage()));

    // Earning/Spending management
    connect(ui->pushButton_Plus_thu, SIGNAL(clicked(bool)), this, SLOT(ShowEarningWindow()));
    connect(ui->pushButton_Plus_chi, SIGNAL(clicked(bool)), this, SLOT(ShowSpendingWindow()));
    connect(ui->pushButton_hide, SIGNAL(clicked(bool)), this, SLOT(HidetheTotal()));

    // Planning management
    connect(ui->pushButton_Plus_plan, SIGNAL(clicked(bool)), this, SLOT(ShowPlanWindow()));

    // Vertical/Horizontal layout management
    connect(ui->pushButton_login, SIGNAL(clicked(bool)), this, SLOT(ChangeToHorizontalLayout()));

    // Password management
    connect(ui->pushButton_password, SIGNAL(clicked(bool)), this, SLOT(ShowPasswordManager()));
    connect(ui->pushButton_exitpassword, SIGNAL(clicked(bool)), this, SLOT(ExitPasswordWindow()));
    connect(ui->pushButton_search, SIGNAL(clicked(bool)), this, SLOT(ShowPasswordFollowCharecter()));
    connect(ui->pushButton_hide_2, SIGNAL(clicked(bool)), this, SLOT(NoHidePassword()));
    connect(ui->pushButton_exitpassword_2, SIGNAL(clicked(bool)), this, SLOT(ExitKeyEnter()));
    connect(ui->pushButton_reload, SIGNAL(clicked(bool)), this, SLOT(ReloadCheckPassword()));
    connect(ui->pushButton_Plus_pass, SIGNAL(clicked(bool)), this, SLOT(AddPassword()));
    connect(ui->pushButton_exitpassword_3, SIGNAL(clicked(bool)), this, SLOT(CloseAddPassword()));
    connect(ui->pushButton_Setpassword, SIGNAL(clicked(bool)), this, SLOT(SetNewPasswordAndClose()));
    connect(ui->pushButton_AdjustPass, SIGNAL(clicked(bool)), this, SLOT(ShowPasswordAdjustment()));
    connect(ui->pushButton_exitpassword_4, SIGNAL(clicked(bool)), this, SLOT(ExitPasswordAdjustmentAndReshowManager()));
    connect(ui->pushButton_changed, SIGNAL(clicked(bool)), this, SLOT(EnterPasswordAdjustmentAndReshowManager()));

    // Electrical Device Control
    connect(ui->UartSettingButton, SIGNAL(clicked(bool)), this, SLOT(ShowSettingUartForElecDeviceControlWindow()));
    connect(ui->pushButton_connectUart, SIGNAL(clicked(bool)), this, SLOT(ConnectUart()));
    connect(ui->pushButton_disconnect, SIGNAL(clicked(bool)), this, SLOT(DisconnectUart()));
    SettingUart();
    connect(ui->Fanbutton, SIGNAL(clicked(bool)), this, SLOT(SendMsgFanControl()));
    connect(ui->Lightbutton, SIGNAL(clicked(bool)), this, SLOT(SendMsgLightControl()));

    // Using Timer function
    QTimer *timer_updatedata = new QTimer(this);
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(ShowEarningSpendingDataFromSource()));
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(ShowDataPlan()));
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(HandleCheckBoxPlan()));
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(CheckEnterCharecter()));
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(CheckEnterCharecterOfNameChange()));
    connect(timer_updatedata, SIGNAL(timeout()), this, SLOT(EnterKeyToSeePasswordAndClose()));

    timer_updatedata->start(100);

}

/* ======================================================================================================================= */
/*                                                     WEBSITE/APP OPENING                                                 */
/* ======================================================================================================================= */

/**
 * @fn     OpenYoutubeWebsite(void)
 * @brief  Open youtube website from url
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenYoutubeWebsite(void)
{
    const QString lsYoutubeURL = "https://www.youtube.com/";
    QDesktopServices::openUrl(QUrl(lsYoutubeURL));
}

/**
 * @fn     OpenGithubWebsite(void)
 * @brief  Open my github page from url
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenGithubWebsite(void)
{
    const QString lsMyGithubURL = "https://github.com/ndthuan167";
    QDesktopServices::openUrl(QUrl(lsMyGithubURL));
}

/**
 * @fn     OpenFacebookWebsite(void)
 * @brief  Open facebook website from url
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenFacebookWebsite(void)
{
    const QString lsFacebookURL = "https://www.facebook.com/";
    QDesktopServices::openUrl(QUrl(lsFacebookURL));
}

/**
 * @fn     OpenGoogleSearch(void)
 * @brief  Open google search website from url
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenGoogleSearch(void)
{
    const QString lsGoogleSearchURL = "https://www.google.com/";
    QDesktopServices::openUrl(QUrl(lsGoogleSearchURL));
}

/**
 * @fn     OpenZaloApp(void)
 * @brief  Open Zalo App from Zalo.exe file
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenZaloApp(void)
{
    QProcess::startDetached("C:/Users/dinht/AppData/Local/Programs/Zalo/Zalo.exe");
}

/**
 * @fn     OpenVSCode(void)
 * @brief  Open VSCode App from .exe file
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenVSCode()
{
    QProcess::startDetached("D:/Phanmemhoctap/Visual Studio Code/Microsoft VS Code/Code.exe");
}

/**
 * @fn     OpenExcelDataSource(void)
 * @brief  Open Data_source.xlsx file (data source) by click to icon Excel using system() function.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/12/2023
 * @return void
 * @param  void
 */
void MyApp::OpenExcelDataSource(void)
{
    const char* lcOpenExcelCommand = "start excel.exe Data_source.xlsx";
    system(lcOpenExcelCommand);
}

/* ======================================================================================================================= */
/*                                                    IMAGE ANIMATION                                                      */
/* ======================================================================================================================= */

/**
 * @fn     BackImage(void)
 * @brief  Minus the number of image to show the previous image.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   10/12/2023
 * @return void
 * @param   void
 */
void MyApp::BackImage(void)
{
    giNumberOfImageBefore--;
    if (giNumberOfImageBefore == 0)
        giNumberOfImageBefore = 11;
    QString lsStringImageDirectory1 = "border-image: url(:/ImagePersonal/Image/ImagePersonal/";
    QString lsStringImageDirectory2 = QString::number(giNumberOfImageBefore);
    QString lsStringImageDirectory3 = ".jpg) 0 0 0 0 stretch stretch;";
    QString lsStringImageDirectory = lsStringImageDirectory1 + lsStringImageDirectory2 + lsStringImageDirectory3;
    ui->label_image->setStyleSheet(lsStringImageDirectory +
                                   "border-radius: 15px;"
                                   "border: 1pxsolid white;");
}

/**
 * @fn     NextImage(void)
 * @brief  Plus the number of image to show the after image and transfer Animation.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   10/12/2023
 * @return void
 * @param   void
 */
void MyApp::NextImage()
{
    giNumberOfImageBefore++;
    if (giNumberOfImageBefore > 11)
        giNumberOfImageBefore = 1;
    QString lsStringImageDirectory1 = "border-image: url(:/ImagePersonal/Image/ImagePersonal/";
    QString lsStringImageDirectory2 = QString::number(giNumberOfImageBefore);
    QString lsStringImageDirectory3 = ".jpg) 0 0 0 0 stretch stretch;";
    QString lsStringImageDirectory = lsStringImageDirectory1 + lsStringImageDirectory2 + lsStringImageDirectory3;
    ui->label_image->setStyleSheet(lsStringImageDirectory +
                                   "border-radius: 15px;"
                                   "border: 1pxsolid white;");

    QPropertyAnimation *animation_image = new QPropertyAnimation(ui->label_image, "geometry");
    animation_image->setDuration(500);

    if (gbIsHorizontalLayoutSet == true)
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

    if (gbIsHorizontalLayoutSet == true)
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
    giNumberOfImageAfter = giNumberOfImageBefore - 1;
    if (giNumberOfImageAfter == 0)
        giNumberOfImageAfter = 11;
    QString string2_2 = QString::number(giNumberOfImageAfter);
    QString string3_2 = ".jpg) 0 0 0 0 stretch stretch;";
    QString stringplus_2 = string1_2 + string2_2 + string3_2;
    ui->label_image_2->setStyleSheet(stringplus_2 +
                                     "border-radius: 15px;"
                                     "border: 1pxsolid white;");
}

/* ======================================================================================================================= */
/*                                            TIME/DATE DISPLAY (CALENDAR)                                                 */
/* ======================================================================================================================= */

/**
 * @fn     CurrentDateTime(void)
 * @brief  Show current date and ltCurrentTime and handle icon in Date/Time section.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   10/12/2023
 * @return void
 * @param   void
 */
void MyApp::CurrentDateTime(void)
{
    QTime ltCurrentTime = QTime::currentTime();
    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd");
    QString lsCurrentThu = ldDate.toString("dddd");
    QString lsCurrentTimeHourMinute = ltCurrentTime.toString("hh:mm");
    ui->label_time->setText(lsCurrentTimeHourMinute);
    ui->label_day->setText(lsCurrentDate);
    ui->label_thu->setText(lsCurrentThu);

    QString lsCurrentTimeHour = ltCurrentTime.toString("hh");
    int liCurrentTimeHour = lsCurrentTimeHour.toInt();
    QString lsStyleSheetDay = "background-color:  " + gsSunOrNight + "; color: #3085C3; border-radius: 25px";
    if (liCurrentTimeHour >= 18 || (liCurrentTimeHour >= 0 && liCurrentTimeHour <= 5))
    {
        gsSunOrNight = "#CBBCF6";
        QPixmap pixmap(":/Icon/Image/night.png");
        ui->label_night->setPixmap(pixmap);
        ui->label_day->setStyleSheet(lsStyleSheetDay);
    }
    else
    {
        gsSunOrNight = "#FDFFAE";
        QPixmap pixmap(":/Icon/Image/sun.png");
        ui->label_sun->setPixmap(pixmap);
        ui->label_day->setStyleSheet(lsStyleSheetDay);
    }
}

/* ======================================================================================================================= */
/*                                              VERTICAL/HORIZONTAL LAYOUT SETTING                                         */
/* ======================================================================================================================= */

/**
 * @fn     ChangeToHorizontalLayout(void)
 * @brief  Convert items from Vertical layout to Horizontal layout.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   24/12/2023
 * @return void
 * @param  void
 */
void MyApp::ChangeToHorizontalLayout(void)
{
    if (gbIsHorizontalLayoutSet == false)
        gbIsHorizontalLayoutSet = true;
    else
        gbIsHorizontalLayoutSet = false;

    if (gbIsHorizontalLayoutSet == true)
    {
        QPixmap pixmap(":/Icon/Image/icons8-login-rounded-up-35.png");
        ui->pushButton_login->setIcon(QIcon(pixmap));
        ui->pushButton_login->setIconSize(QSize(35, 35));

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
        ui->frame_plan->setGeometry(QRect(230, 10, 311, 351));
        ui->frame_note->setGeometry(QRect(10, 10, 211, 351));
        ui->pushButton_Plus_plan->setGeometry(QRect(280, 320, 25, 25));

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
        if (gbIsPasswordWindowOn == true && gbIsPasswordShow == false)
            ui->frame_password_manage->setGeometry(QRect(600, 250, 270, 150));
        if (gbIsAdditionalPasswordWindowOn == true)
            ui->frame_password_manage_4->setGeometry(QRect(180, 450, 190, 180));
        if (gbIsPasswordShow == true)
            ui->frame_password_manage_5->setGeometry(QRect(630, 190, 220, 140));
        if (gbIsUartSettingShow == true)
            ui->frameUart->setGeometry(QRect(190, 420, 210, 180));

        // Electrical Device Control
        ui->UartSettingButton->setGeometry(QRect(10, 10, 25, 25));
        ui->label_35->setGeometry(QRect(50, 10, 120, 20));
        ui->label_35->setText("Device Control");
        ui->label_36->setGeometry(QRect(60, 50, 80, 80));
        ui->label_34->setGeometry(QRect(80, 142, 45, 16));
        if (gbIsFanOn == true)
            ui->Fanbutton->setGeometry(QRect(80 + 25, 140, 20, 20));
        else
            ui->Fanbutton->setGeometry(QRect(80, 140, 20, 20));
        ui->label_39->setGeometry(QRect(68, 1365, 31, 16));
        ui->label_40->setGeometry(QRect(120, 1365, 31, 16));
        ui->label_38->setGeometry(QRect(60, 200, 80, 80));
        ui->label_37->setGeometry(QRect(80, 300, 45, 16));
        if (gbIsLightOn == true)
            ui->Lightbutton->setGeometry(QRect(80 + 25, 298, 20, 20));
        else
            ui->Lightbutton->setGeometry(QRect(80, 298, 20, 20));
    }
    else
    {
        QPixmap pixmap(":/Icon/Image/icons8-login-48.png");
        ui->pushButton_login->setIcon(QIcon(pixmap));
        ui->pushButton_login->setIconSize(QSize(35, 35));

        ShowEarningSpendingDataFromSource();
        ShowDataPlan();
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
        ui->frame_plan->setGeometry(QRect(115, 5, 313, 131));
        ui->label_8->setGeometry(QRect(275, 3, 31, 31));
        ui->frame_note->setGeometry(QRect(5, 5, 105, 131));
        ui->pushButton_Plus_plan->setGeometry(QRect(280, 95, 25, 25));

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
        if (gbIsPasswordWindowOn == true && gbIsPasswordShow == false)
            ui->frame_password_manage->setGeometry(QRect(100, 250, 270, 150));
        if (gbIsAdditionalPasswordWindowOn == true)
            ui->frame_password_manage_4->setGeometry(QRect(100, 70, 190, 180));
        if (gbIsPasswordShow == true)
            ui->frame_password_manage_5->setGeometry(QRect(110, 190, 220, 140));
        if (gbIsUartSettingShow == true)
            ui->frameUart->setGeometry(QRect(60, 180, 210, 180));

        // Electrical Device Control
        ui->UartSettingButton->setGeometry(QRect(10, 5, 25, 25));
        ui->label_35->setGeometry(QRect(40, 10, 120, 20));
        ui->label_35->setText("Control");
        ui->label_36->setGeometry(QRect(63, 32, 37, 37));
        ui->label_34->setGeometry(QRect(10, 42, 45, 16));
        if (gbIsFanOn == true)
            ui->Fanbutton->setGeometry(QRect(10 + 25, 40, 20, 20));
        else
            ui->Fanbutton->setGeometry(QRect(10, 40, 20, 20));
        ui->label_39->setGeometry(QRect(8, 70, 31, 16));
        ui->label_40->setGeometry(QRect(40, 70, 31, 16));
        ui->label_38->setGeometry(QRect(60, 85, 40, 40));
        ui->label_37->setGeometry(QRect(10, 95, 45, 16));
        if (gbIsLightOn == true)
            ui->Lightbutton->setGeometry(QRect(10 + 25, 93, 20, 20));
        else
            ui->Lightbutton->setGeometry(QRect(10, 93, 20, 20));
    }
}

/* ======================================================================================================================= */
/*                                                    EARNING/SPENDING MANAGEMENT                                          */
/* ======================================================================================================================= */

/**
 * @fn     ShowEarningWindow(void)
 * @brief  Connect with Popup Thu and show.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/01/2024
 * @return void
 * @param   void
 */
void MyApp::ShowEarningWindow(void)
{
    popup_Thu *mypopup_thu = new popup_Thu(this, "Hello1");
    mypopup_thu->show();
    connect(mypopup_thu, &popup_Thu::ConnectDataEarning, this, &MyApp::HandleDataEarning);
}

/**
 * @fn     HandleDataEarning()
 * @brief  Receive data from Popup_Thu dialog.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/01/2024
 * @return void
 * @param   const QString &lsDataDateEaning, const QString &lsDataMoneyEaning, const QString &lsDataTypeMoneyEaning, const QString &lsDataContentEaning
 */
void MyApp::HandleDataEarning(const QString &lsDataDateEaning, const QString &lsDataMoneyEaning, const QString &lsDataTypeMoneyEaning, const QString &lsDataContentEaning)
{
    Document xlsx("Data_source.xlsx");

    int liIndexOfMonthEarning = ui->comboBox_MonthThu->currentIndex();
    xlsx.selectSheet(liIndexOfMonthEarning);

    if (lsDataMoneyEaning != "" && lsDataContentEaning != "")
    {
        while (xlsx.read(giWriteIndexEarning, 1).toInt() != 0)
        {
            giWriteIndexEarning++;
        }

        xlsx.write(giWriteIndexEarning, 1, lsDataDateEaning);
        xlsx.write(giWriteIndexEarning, 3, lsDataMoneyEaning);
        xlsx.write(giWriteIndexEarning, 2, lsDataTypeMoneyEaning);
        xlsx.write(giWriteIndexEarning, 4, lsDataContentEaning);

        xlsx.saveAs("Data_source.xlsx");
        giWriteIndexEarning = 5;
    }
}

/**
 * @fn     ShowSpendingWindow(void)
 * @brief  Connect with Popup Chi tieu and show.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/01/2024
 * @return void
 * @param   void
 */
void MyApp::ShowSpendingWindow(void)
{
    PopupChi *mypopup = new PopupChi(this, "Hello");
    mypopup->show();
    connect(mypopup, &PopupChi::ConnectDataSpending, this, &MyApp::HandleDataSpending);
}

/**
 * @fn     HandleDataSpending()
 * @brief  Receive data from Popup_Chi dialog.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   26/12/2023
 * @return void
 * @param   const QString &lsDataDateSpending, const QString &lsDataMoneySpending, const QString &lsDataMoneyTypeSpending, const QString &lsDataContentSpending
 */
void MyApp::HandleDataSpending(const QString &lsDataDateSpending, const QString &lsDataMoneySpending, const QString &lsDataMoneyTypeSpending, const QString &lsDataContentSpending)
{
    Document xlsx("Data_source.xlsx");

    int liIndexOfMonthEarning = ui->comboBox_MonthThu->currentIndex();
    xlsx.selectSheet(liIndexOfMonthEarning);

    if (lsDataMoneySpending != "" && lsDataContentSpending != "")
    {
        while (xlsx.read(giWriteIndexSpending, 7).toInt() != 0)
        {
            giWriteIndexSpending++;
        }

        xlsx.write(giWriteIndexSpending, 7, lsDataDateSpending);
        xlsx.write(giWriteIndexSpending, 8, lsDataMoneySpending);
        xlsx.write(giWriteIndexSpending, 9, lsDataMoneyTypeSpending);
        xlsx.write(giWriteIndexSpending, 10, lsDataContentSpending);

        xlsx.saveAs("Data_source.xlsx");
        giWriteIndexSpending = 5;
    }
}


/**
 * @fn     ShowEarningSpendingDataFromSource(void)
 * @brief  Read Earning/Spending data from Excel source to show in App in Vertical and Horizontal layout.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   26/12/2023
 * @return void
 * @param   void
 */
void MyApp::ShowEarningSpendingDataFromSource(void)
{
    Document xlsx("Data_source.xlsx");

    int liIndexOfMonthEarning = ui->comboBox_MonthThu->currentIndex();
    ui->comboBox_MonthChi->setCurrentIndex(liIndexOfMonthEarning);
    xlsx.selectSheet(liIndexOfMonthEarning);

    while (xlsx.read(giIndexDataEarning, 1).toInt() != 0)
    {
        giIndexDataEarning++;
        giNumberOfDataEarning++;
    }
    if (giNumberOfDataEarning >= 8)
        giNumberOfDataEarning -= (giNumberOfDataEarning - 8);

    if (giNumberOfDataEarning >= 1)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_1->setGeometry(QRect(740, 110, 265, 28));
        else
            ui->frame_Thu_1->setGeometry(QRect(27, 395, 97, 28));
        ui->label_day_thu1->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning, 1).toString());
        ui->label_money_thu1->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning, 3).toString());
        ui->label_typethu1->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning, 2).toString());
        ui->label_content_thu1->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning, 4).toString());
    }
    else
        ui->frame_Thu_1->setGeometry(QRect(2400, 395, 97, 28));

    if (giNumberOfDataEarning >= 2)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_2->setGeometry(QRect(740 + 265 + 5, 110, 265, 28));
        else
            ui->frame_Thu_2->setGeometry(QRect(27 + 97 + 2, 395, 97, 28));
        ui->label_day_thu2->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 1, 1).toString());
        ui->label_money_thu2->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 1, 3).toString());
        ui->label_typethu2->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 1, 2).toString());
        ui->label_content_thu2->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 1, 4).toString());
    }
    else
        ui->frame_Thu_2->setGeometry(QRect(2400, 395, 97, 28));

    if (giNumberOfDataEarning >= 3)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_3->setGeometry(QRect(740, 110 + 28 + 5, 265, 28));
        else
            ui->frame_Thu_3->setGeometry(QRect(27, 395 + 28 + 5, 97, 28));
        ui->label_day_thu3->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 2, 1).toString());
        ui->label_money_thu3->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 2, 3).toString());
        ui->label_typethu3->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 2, 2).toString());
        ui->label_content_thu3->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 2, 4).toString());
    }
    else
        ui->frame_Thu_3->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataEarning >= 4)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_4->setGeometry(QRect(740 + 265 + 5, 110 + 28 + 5, 265, 28));
        else
            ui->frame_Thu_4->setGeometry(QRect(27 + 97 + 2, 395 + 28 + 5, 97, 28));
        ui->label_day_thu4->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 3, 1).toString());
        ui->label_money_thu4->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 3, 3).toString());
        ui->label_typethu4->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 3, 2).toString());
        ui->label_content_thu4->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 3, 4).toString());
    }
    else
        ui->frame_Thu_4->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataEarning >= 5)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_5->setGeometry(QRect(740, 110 + 2 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_5->setGeometry(QRect(27, 395 + 2 * (28 + 5), 97, 28));
        ui->label_day_thu5->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 4, 1).toString());
        ui->label_money_thu5->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 4, 3).toString());
        ui->label_typethu5->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 4, 2).toString());
        ui->label_content_thu5->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 4, 4).toString());
    }
    else
        ui->frame_Thu_5->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataEarning >= 6)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_6->setGeometry(QRect(740 + 265 + 5, 110 + 2 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_6->setGeometry(QRect(27 + 97 + 2, 395 + 2 * (28 + 5), 97, 28));
        ui->label_day_thu6->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 5, 1).toString());
        ui->label_money_thu6->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 5, 3).toString());
        ui->label_typethu6->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 5, 2).toString());
        ui->label_content_thu6->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 5, 4).toString());
    }
    else
        ui->frame_Thu_6->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataEarning >= 7)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_7->setGeometry(QRect(740, 110 + 3 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_7->setGeometry(QRect(27, 395 + 3 * (28 + 5), 97, 28));
        ui->label_day_thu7->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 6, 1).toString());
        ui->label_money_thu7->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 6, 3).toString());
        ui->label_typethu7->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 6, 2).toString());
        ui->label_content_thu7->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 6, 4).toString());
    }
    else
        ui->frame_Thu_7->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataEarning >= 8)
    {
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Thu_8->setGeometry(QRect(740 + 265 + 5, 110 + 3 * (28 + 5), 265, 28));
        else
            ui->frame_Thu_8->setGeometry(QRect(27 + 97 + 2, 395 + 3 * (28 + 5), 97, 28));
        ui->label_day_thu8->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 7, 1).toString());
        ui->label_money_thu8->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 7, 3).toString());
        ui->label_typethu8->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 7, 2).toString());
        ui->label_content_thu8->setText(xlsx.read(giIndexDataEarning - giNumberOfDataEarning + 7, 4).toString());
    }
    else
        ui->frame_Thu_8->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    while (xlsx.read(giIndexDataSpending, 7).toInt() != 0)
    {
        giIndexDataSpending++;
        giNumberOfDataSpending++;
    }
    if (giNumberOfDataSpending >= 22)
        giNumberOfDataSpending -= (giNumberOfDataSpending - 22);

    if (giNumberOfDataSpending >= 1)
    {
        ui->label_day_chi1->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending, 7).toString());
        ui->label_money_chi1->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending, 8).toString());
        ui->label_typechi1->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending, 9).toString());
        ui->label_content_chi1->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending, 10).toString());

        if (gbIsHorizontalLayoutSet == true)
        {
            ui->frame_Chi_1->setGeometry(QRect(740, 340, 265, 28));
        }
        else
        {
            ui->frame_Chi_1->setGeometry(QRect(240, 395, 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi1->setText(xlsx.read(giIndexDataSpending - 8, 7).toString());
                ui->label_money_chi1->setText(xlsx.read(giIndexDataSpending - 8, 8).toString());
                ui->label_typechi1->setText(xlsx.read(giIndexDataSpending - 8, 9).toString());
                ui->label_content_chi1->setText(xlsx.read(giIndexDataSpending - 8, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_1->setGeometry(QRect(2400, 395, 97, 28));

    if (giNumberOfDataSpending >= 2)
    {
        ui->label_day_chi2->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 1, 7).toString());
        ui->label_money_chi2->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 1, 8).toString());
        ui->label_typechi2->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 1, 9).toString());
        ui->label_content_chi2->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 1, 10).toString());

        if (gbIsHorizontalLayoutSet == true)
        {
            ui->frame_Chi_2->setGeometry(QRect(740 + 265 + 5, 340, 265, 28));
        }
        else
        {
            ui->frame_Chi_2->setGeometry(QRect(240 + 98 + 2, 395, 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi2->setText(xlsx.read(giIndexDataSpending - 8 + 1, 7).toString());
                ui->label_money_chi2->setText(xlsx.read(giIndexDataSpending - 8 + 1, 8).toString());
                ui->label_typechi2->setText(xlsx.read(giIndexDataSpending - 8 + 1, 9).toString());
                ui->label_content_chi2->setText(xlsx.read(giIndexDataSpending - 8 + 1, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_2->setGeometry(QRect(2400 + 98 + 2, 395, 97, 28));

    if (giNumberOfDataSpending >= 3)
    {
        ui->label_day_chi3->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 2, 7).toString());
        ui->label_money_chi3->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 2, 8).toString());
        ui->label_typechi3->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 2, 9).toString());
        ui->label_content_chi3->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 2, 10).toString());

        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Chi_3->setGeometry(QRect(740, 340 + 28 + 5, 265, 28));
        else
        {
            ui->frame_Chi_3->setGeometry(QRect(240, 395 + 28 + 5, 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi3->setText(xlsx.read(giIndexDataSpending - 8 + 2, 7).toString());
                ui->label_money_chi3->setText(xlsx.read(giIndexDataSpending - 8 + 2, 8).toString());
                ui->label_typechi3->setText(xlsx.read(giIndexDataSpending - 8 + 2, 9).toString());
                ui->label_content_chi3->setText(xlsx.read(giIndexDataSpending - 8 + 2, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_3->setGeometry(QRect(2400, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataSpending >= 4)
    {
        ui->label_day_chi4->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 3, 7).toString());
        ui->label_money_chi4->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 3, 8).toString());
        ui->label_typechi4->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 3, 9).toString());
        ui->label_content_chi4->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 3, 10).toString());

        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Chi_4->setGeometry(QRect(740 + 265 + 5, 340 + 28 + 5, 265, 28));
        else
        {
            ui->frame_Chi_4->setGeometry(QRect(240 + 98 + 2, 395 + 28 + 5, 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi4->setText(xlsx.read(giIndexDataSpending - 8 + 3, 7).toString());
                ui->label_money_chi4->setText(xlsx.read(giIndexDataSpending - 8 + 3, 8).toString());
                ui->label_typechi4->setText(xlsx.read(giIndexDataSpending - 8 + 3, 9).toString());
                ui->label_content_chi4->setText(xlsx.read(giIndexDataSpending - 8 + 3, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_4->setGeometry(QRect(2400 + 98 + 2, 395 + 28 + 5, 97, 28));

    if (giNumberOfDataSpending >= 5)
    {
        ui->label_day_chi5->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 4, 7).toString());
        ui->label_money_chi5->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 4, 8).toString());
        ui->label_typechi5->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 4, 9).toString());
        ui->label_content_chi5->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 4, 10).toString());
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Chi_5->setGeometry(QRect(740, 340 + 2 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_5->setGeometry(QRect(240, 395 + 2 * (28 + 5), 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi5->setText(xlsx.read(giIndexDataSpending - 8 + 4, 7).toString());
                ui->label_money_chi5->setText(xlsx.read(giIndexDataSpending - 8 + 4, 8).toString());
                ui->label_typechi5->setText(xlsx.read(giIndexDataSpending - 8 + 4, 9).toString());
                ui->label_content_chi5->setText(xlsx.read(giIndexDataSpending - 8 + 4, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_5->setGeometry(QRect(2400, 395 + 2 * (28 + 5), 97, 28));

    if (giNumberOfDataSpending >= 6)
    {
        ui->label_day_chi6->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 5, 7).toString());
        ui->label_money_chi6->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 5, 8).toString());
        ui->label_typechi6->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 5, 9).toString());
        ui->label_content_chi6->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 5, 10).toString());
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Chi_6->setGeometry(QRect(740 + 265 + 5, 340 + 2 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_6->setGeometry(QRect(240 + 98 + 2, 395 + 2 * (28 + 5), 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi6->setText(xlsx.read(giIndexDataSpending - 8 + 5, 7).toString());
                ui->label_money_chi6->setText(xlsx.read(giIndexDataSpending - 8 + 5, 8).toString());
                ui->label_typechi6->setText(xlsx.read(giIndexDataSpending - 8 + 5, 9).toString());
                ui->label_content_chi6->setText(xlsx.read(giIndexDataSpending - 8 + 5, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_6->setGeometry(QRect(2400 + 98 + 2, 395 + 2 * (28 + 5), 97, 28));

    if (giNumberOfDataSpending >= 7)
    {
        ui->label_day_chi7->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 6, 7).toString());
        ui->label_money_chi7->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 6, 8).toString());
        ui->label_typechi7->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 6, 9).toString());
        ui->label_content_chi7->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 6, 10).toString());
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Chi_7->setGeometry(QRect(740, 340 + 3 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_7->setGeometry(QRect(240, 395 + 3 * (28 + 5), 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi7->setText(xlsx.read(giIndexDataSpending - 8 + 6, 7).toString());
                ui->label_money_chi7->setText(xlsx.read(giIndexDataSpending - 8 + 6, 8).toString());
                ui->label_typechi7->setText(xlsx.read(giIndexDataSpending - 8 + 6, 9).toString());
                ui->label_content_chi7->setText(xlsx.read(giIndexDataSpending - 8 + 6, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_7->setGeometry(QRect(2400, 395 + 3 * (28 + 5), 97, 28));

    if (giNumberOfDataSpending >= 8)
    {
        ui->label_day_chi8->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 7, 7).toString());
        ui->label_money_chi8->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 7, 8).toString());
        ui->label_typechi8->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 7, 9).toString());
        ui->label_content_chi8->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 7, 10).toString());
        if (gbIsHorizontalLayoutSet == true)
            ui->frame_Chi_8->setGeometry(QRect(740 + 265 + 5, 340 + 3 * (28 + 5), 265, 28));
        else
        {
            ui->frame_Chi_8->setGeometry(QRect(240 + 98 + 2, 395 + 3 * (28 + 5), 97, 28));
            if (giNumberOfDataSpending >= 8)
            {
                ui->label_day_chi8->setText(xlsx.read(giIndexDataSpending - 8 + 7, 7).toString());
                ui->label_money_chi8->setText(xlsx.read(giIndexDataSpending - 8 + 7, 8).toString());
                ui->label_typechi8->setText(xlsx.read(giIndexDataSpending - 8 + 7, 9).toString());
                ui->label_content_chi8->setText(xlsx.read(giIndexDataSpending - 8 + 7, 10).toString());
            }
        }
    }
    else
        ui->frame_Chi_8->setGeometry(QRect(2400 + 98 + 2, 395 + 3 * (28 + 5), 97, 28));

    if (gbIsHorizontalLayoutSet == true)
    {
        if (giNumberOfDataSpending >= 9)
        {
            ui->frame_Chi_9->setGeometry(QRect(740, 340 + 4 * (28 + 5), 265, 28));
            ui->label_day_chi9->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 8, 7).toString());
            ui->label_money_chi9->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 8, 8).toString());
            ui->label_typechi9->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 8, 9).toString());
            ui->label_content_chi9->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 8, 10).toString());
        }
        else
            ui->frame_Chi_9->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 10)
        {
            ui->frame_Chi_10->setGeometry(QRect(740 + 265 + 5, 340 + 4 * (28 + 5), 265, 28));
            ui->label_day_chi10->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 9, 7).toString());
            ui->label_money_chi10->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 9, 8).toString());
            ui->label_typechi10->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 9, 9).toString());
            ui->label_content_chi10->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 9, 10).toString());
        }
        else
            ui->frame_Chi_10->setGeometry(QRect(7040, 340 + 6 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 11)
        {
            ui->frame_Chi_11->setGeometry(QRect(740, 340 + 5 * (28 + 5), 265, 28));
            ui->label_day_chi11->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 10, 7).toString());
            ui->label_money_chi11->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 10, 8).toString());
            ui->label_typechi11->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 10, 9).toString());
            ui->label_content_chi11->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 10, 10).toString());
        }
        else
            ui->frame_Chi_11->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 12)
        {
            ui->frame_Chi_12->setGeometry(QRect(740 + 265 + 5, 340 + 5 * (28 + 5), 265, 28));
            ui->label_day_chi12->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 11, 7).toString());
            ui->label_money_chi12->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 11, 8).toString());
            ui->label_typechi12->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 11, 9).toString());
            ui->label_content_chi12->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 11, 10).toString());
        }
        else
            ui->frame_Chi_12->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 13)
        {
            ui->frame_Chi_13->setGeometry(QRect(740, 340 + 6 * (28 + 5), 265, 28));
            ui->label_day_chi13->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 12, 7).toString());
            ui->label_money_chi13->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 12, 8).toString());
            ui->label_typechi13->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 12, 9).toString());
            ui->label_content_chi13->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 12, 10).toString());
        }
        else
            ui->frame_Chi_13->setGeometry(QRect(7400, 340 + 6 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 14)
        {
            ui->frame_Chi_14->setGeometry(QRect(740 + 265 + 5, 340 + 6 * (28 + 5), 265, 28));
            ui->label_day_chi14->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 13, 7).toString());
            ui->label_money_chi14->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 13, 8).toString());
            ui->label_typechi14->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 13, 9).toString());
            ui->label_content_chi14->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 13, 10).toString());
        }
        else
            ui->frame_Chi_14->setGeometry(QRect(7400 + 265 + 5, 340 + 6 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 15)
        {
            ui->frame_Chi_15->setGeometry(QRect(740, 340 + 7 * (28 + 5), 265, 28));
            ui->label_day_chi15->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 14, 7).toString());
            ui->label_money_chi15->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 14, 8).toString());
            ui->label_typechi15->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 14, 9).toString());
            ui->label_content_chi15->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 14, 10).toString());
        }
        else
            ui->frame_Chi_15->setGeometry(QRect(7400, 340 + 7 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 16)
        {
            ui->frame_Chi_16->setGeometry(QRect(740 + 265 + 5, 340 + 7 * (28 + 5), 265, 28));
            ui->label_day_chi16->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 15, 7).toString());
            ui->label_money_chi16->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 15, 8).toString());
            ui->label_typechi16->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 15, 9).toString());
            ui->label_content_chi16->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 15, 10).toString());
        }
        else
            ui->frame_Chi_16->setGeometry(QRect(7400 + 265 + 5, 340 + 7 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 17)
        {
            ui->frame_Chi_17->setGeometry(QRect(740, 340 + 8 * (28 + 5), 265, 28));
            ui->label_day_chi17->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 16, 7).toString());
            ui->label_money_chi17->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 16, 8).toString());
            ui->label_typechi17->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 16, 9).toString());
            ui->label_content_chi17->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 16, 10).toString());
        }
        else
            ui->frame_Chi_17->setGeometry(QRect(7400, 340 + 8 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 18)
        {
            ui->frame_Chi_18->setGeometry(QRect(740 + 265 + 5, 340 + 8 * (28 + 5), 265, 28));
            ui->label_day_chi18->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 17, 7).toString());
            ui->label_money_chi18->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 17, 8).toString());
            ui->label_typechi18->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 17, 9).toString());
            ui->label_content_chi18->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 17, 10).toString());
        }
        else
            ui->frame_Chi_18->setGeometry(QRect(7400 + 265 + 5, 340 + 8 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 19)
        {
            ui->frame_Chi_19->setGeometry(QRect(740, 340 + 9 * (28 + 5), 265, 28));
            ui->label_day_chi19->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 18, 7).toString());
            ui->label_money_chi19->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 18, 8).toString());
            ui->label_typechi19->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 18, 9).toString());
            ui->label_content_chi19->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 18, 10).toString());
        }
        else
            ui->frame_Chi_19->setGeometry(QRect(7400, 340 + 9 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 20)
        {
            ui->frame_Chi_20->setGeometry(QRect(740 + 265 + 5, 340 + 9 * (28 + 5), 265, 28));
            ui->label_day_chi20->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 19, 7).toString());
            ui->label_money_chi20->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 19, 8).toString());
            ui->label_typechi20->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 19, 9).toString());
            ui->label_content_chi20->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 19, 10).toString());
        }
        else
            ui->frame_Chi_20->setGeometry(QRect(7400 + 265 + 5, 340 + 9 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 21)
        {
            ui->frame_Chi_21->setGeometry(QRect(740, 340 + 10 * (28 + 5), 265, 28));
            ui->label_day_chi21->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 20, 7).toString());
            ui->label_money_chi21->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 20, 8).toString());
            ui->label_typechi21->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 20, 9).toString());
            ui->label_content_chi21->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 20, 10).toString());
        }
        else
            ui->frame_Chi_21->setGeometry(QRect(7400, 340 + 10 * (28 + 5), 265, 28));

        if (giNumberOfDataSpending >= 22)
        {
            ui->frame_Chi_22->setGeometry(QRect(740 + 265 + 5, 340 + 10 * (28 + 5), 265, 28));
            ui->label_day_chi22->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 21, 7).toString());
            ui->label_money_chi22->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 21, 8).toString());
            ui->label_typechi22->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 21, 9).toString());
            ui->label_content_chi22->setText(xlsx.read(giIndexDataSpending - giNumberOfDataSpending + 21, 10).toString());
        }
        else
            ui->frame_Chi_22->setGeometry(QRect(7400 + 265 + 5, 340 + 10 * (28 + 5), 265, 28));
    }

    for (int iIndex = 0; iIndex < 12; iIndex++)
    {
        xlsx.selectSheet(iIndex);
        for (int j = 5; j <= giIndexDataSpending - 1; j++)
        {
            giIndexMoneySpending += xlsx.read(j, 8).toInt();
        }
        for (int k = 5; k <= giIndexDataEarning - 1; k++)
        {
            giIndexMoneyEarning += xlsx.read(k, 3).toInt();
        }
        gvDataMoneyEarning.push_back(giIndexMoneyEarning);
        gvDataMoneySpending.push_back(giIndexMoneySpending);
        giIndexMoneyEarning = 0;
        giIndexMoneySpending = 0;
    }

    gsMoneyEarning = "Tổng: " + QString::number(gvDataMoneyEarning.at(liIndexOfMonthEarning)) + " VNĐ";
    ui->label_total_thu->setText(gsMoneyEarning);
    gsMoneySpending = "Tổng: " + QString::number(gvDataMoneySpending.at(liIndexOfMonthEarning)) + " VNĐ";
    ui->label_total_chi->setText(gsMoneySpending);
    gsMoneyAccumulate = QString::number(gvDataMoneyEarning.at(liIndexOfMonthEarning) - gvDataMoneySpending.at(liIndexOfMonthEarning));

    if (gbIsHorizontalLayoutSet == true)
    {
        if (gbHide == true)
        {
            ui->label_total->setText("Tổng tích lũy tháng " + QString::number(liIndexOfMonthEarning + 1) + " : " + gsMoneyAccumulate + " VNĐ");
        }
        else
        {
            ui->label_total_thu->setText("Tổng: *** *** *** VNĐ");
            ui->label_total_chi->setText("Tổng: *** *** *** VNĐ");
            ui->label_total->setText("Tổng tích lũy tháng " + QString::number(liIndexOfMonthEarning + 1) + " : *** *** *** VNĐ");
        }
    }
    else
    {
        if (gbHide == true)
        {
            ui->label_total->setText("Tích lũy tháng " + QString::number(liIndexOfMonthEarning + 1) + " : " + gsMoneyAccumulate + " VNĐ");
        }
        else
        {
            ui->label_total->setText("Tích lũy tháng " + QString::number(liIndexOfMonthEarning + 1) + " : *** *** *** VNĐ");
            ui->label_total_chi->setText("Tổng: *** *** *** VNĐ");
            ui->label_total_thu->setText("Tổng: *** *** *** VNĐ");
        }
    }

    QString total_tichluy_string = "Tích lũy tháng " + QString::number(liIndexOfMonthEarning + 1) + " : " + gsMoneyAccumulate + " VNĐ";
    xlsx.selectSheet(liIndexOfMonthEarning);
    xlsx.write("A1", total_tichluy_string);
    xlsx.saveAs("Data_source.xlsx");

    gvDataMoneyEarning.clear();
    gvDataMoneySpending.clear();
    giIndexDataSpending = 5;
    giNumberOfDataSpending = 0;
    giIndexDataEarning = 5;
    giNumberOfDataEarning = 0;
}

/* ======================================================================================================================= */
/*                                                      PLANNING MANAGEMENT                                                */
/* ======================================================================================================================= */

/**
 * @fn     HandleDataPlanning()
 * @brief  Receive data from Popup_Plan dialog.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   07/01/2024
 * @return void
 * @param   const QString &lsDataDatePlanning, const QString &lsDataTimePlanning, const QString &lsDataDetailsPlanning
 */
void MyApp::HandleDataPlanning(const QString &lsDataDatePlanning, const QString &lsDataTimePlanning, const QString &lsDataDetailsPlanning)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(12);

    if (lsDataDetailsPlanning != "" && lsDataTimePlanning != "")
    {
        while (xlsx.read(giWriteIndexPlanning, 2).toInt() != 0)
        {
            giWriteIndexPlanning++;
        }

        xlsx.write(giWriteIndexPlanning, 1, "X");
        xlsx.write(giWriteIndexPlanning, 2, lsDataDatePlanning);
        xlsx.write(giWriteIndexPlanning, 3, lsDataTimePlanning);
        xlsx.write(giWriteIndexPlanning, 4, lsDataDetailsPlanning);

        xlsx.saveAs("Data_source.xlsx");
        giWriteIndexPlanning = 4;
    }
}

/**
 * @fn     HandleCheckBoxPlan(void)
 * @brief  Handle staus of checkbox plan when the plan is planed or implemented in App and in Excel source.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/01/2024
 * @return void
 * @param   void
 */
void MyApp::HandleCheckBoxPlan(void)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(12);

    int liIndexOfPlan = 4;
    while (liIndexOfPlan < giNumberOfPlan)
    {
        if (xlsx.read(liIndexOfPlan, 1).toString() == "X")
        {
            gvIndexPlanningChecked.push_back(liIndexOfPlan);
        }
        liIndexOfPlan++;
    }

    if (gvIndexPlanningChecked.size() <= 4)
    {
        for (int iIndex = 0; iIndex < gvIndexPlanningChecked.size(); iIndex++)
            gaiShowIndexPlanningChecked[iIndex] = gvIndexPlanningChecked.at(iIndex);
    }
    else
    {
        for (int iIndex = 0; iIndex < 4; iIndex++)
            gaiShowIndexPlanningChecked[iIndex] = gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (4 - iIndex));
    }

    if (gvIndexPlanningChecked.size() > 4)
    {
        if (gbIsHorizontalLayoutSet == false)
        {
            if (ui->checkBox_1->isChecked() == true)
                xlsx.write(gaiShowIndexPlanningChecked[0], 1, "O");
            if (ui->checkBox_2->isChecked() == true)
                xlsx.write(gaiShowIndexPlanningChecked[1], 1, "O");
            if (ui->checkBox_3->isChecked() == true)
                xlsx.write(gaiShowIndexPlanningChecked[2], 1, "O");
            if (ui->checkBox_4->isChecked() == true)
                xlsx.write(gaiShowIndexPlanningChecked[3], 1, "O");
        }
        else
        {
            if (gvIndexPlanningChecked.size() > 11)
            {
                if (ui->checkBox_1->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 0)), 1, "O");
                if (ui->checkBox_2->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 1)), 1, "O");
                if (ui->checkBox_3->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 2)), 1, "O");
                if (ui->checkBox_4->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 3)), 1, "O");
                if (ui->checkBox_5->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 4)), 1, "O");
                if (ui->checkBox_6->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 5)), 1, "O");
                if (ui->checkBox_7->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 6)), 1, "O");
                if (ui->checkBox_8->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 7)), 1, "O");
                if (ui->checkBox_9->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 8)), 1, "O");
                if (ui->checkBox_10->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 9)), 1, "O");
                if (ui->checkBox_11->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(gvIndexPlanningChecked.size() - (11 - 10)), 1, "O");
            }
            else
            {
                if (ui->checkBox_1->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(0), 1, "O");
                if (ui->checkBox_2->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(1), 1, "O");
                if (ui->checkBox_3->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(2), 1, "O");
                if (ui->checkBox_4->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(3), 1, "O");
                if (ui->checkBox_5->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(4), 1, "O");
                if (ui->checkBox_6->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(5), 1, "O");
                if (ui->checkBox_7->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(6), 1, "O");
                if (ui->checkBox_8->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(7), 1, "O");
                if (ui->checkBox_9->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(8), 1, "O");
                if (ui->checkBox_10->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(9), 1, "O");
                if (ui->checkBox_11->isChecked() == true)
                    xlsx.write(gvIndexPlanningChecked.at(10), 1, "O");
            }
        }
    }
    else
    {
        if (ui->checkBox_1->isChecked() == true)
            xlsx.write(gaiShowIndexPlanningChecked[0], 1, "O");
        if (ui->checkBox_2->isChecked() == true)
            xlsx.write(gaiShowIndexPlanningChecked[1], 1, "O");
        if (ui->checkBox_3->isChecked() == true)
            xlsx.write(gaiShowIndexPlanningChecked[2], 1, "O");
        if (ui->checkBox_4->isChecked() == true)
            xlsx.write(gaiShowIndexPlanningChecked[3], 1, "O");
    }

    xlsx.saveAs("Data_source.xlsx");

    ui->checkBox_1->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);

    gvIndexPlanningChecked.clear();
}

/**
 * @fn     ShowPlanWindow(void)
 * @brief  Connect with Popup Plan and show.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   07/01/2024
 * @return void
 * @param   void
 */
void MyApp::ShowPlanWindow(void)
{
    Popup_Plan *MyPopupPlan = new Popup_Plan(this, "helloPlan");
    MyPopupPlan->show();
    connect(MyPopupPlan, &Popup_Plan::ConnectDataPlanning, this, &MyApp::HandleDataPlanning);
}

/**
 * @fn     HidetheTotal(void)
 * @brief  Handle Hide/Show icon and set hide/unhide condition.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   10/12/2023
 * @return void
 * @param   void
 */
void MyApp::HidetheTotal(void)
{
    if (gbHide == false)
    {
        gbHide = true;
        ui->pushButton_hide->setIcon(QIcon(":/Icon/Image/icons8-hide-15.png"));
    }
    else
    {
        gbHide = false;
        ui->pushButton_hide->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));
    }
}

/**
 * @fn     ShowDataPlan(void)
 * @brief  Read status of plan was set from Excel source to App in vertical and horizontal layout.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   13/01/2024
 * @return void
 * @param   void
 */
void MyApp::ShowDataPlan(void)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(12);

    while (xlsx.read(giNumberOfPlan, 2).toInt() != 0)
    {
        giNumberOfPlan++;
    }

    int liIndexOfPlan = 4;
    while (liIndexOfPlan < giNumberOfPlan)
    {
        if (xlsx.read(liIndexOfPlan, 1).toString() == "X")
        {
            gvIndexPlanningUnChecked.push_back(liIndexOfPlan);
        }
        liIndexOfPlan++;
    }

    if (gvIndexPlanningUnChecked.size() <= 4)
    {
        for (int iIndex = 0; iIndex < gvIndexPlanningUnChecked.size(); iIndex++)
        {
            gaiShowIndexPlanningUnchecked[iIndex] = gvIndexPlanningUnChecked.at(iIndex);
        }
    }
    else
    {
        for (int iIndex = 0; iIndex < 4; iIndex++)
        {
            gaiShowIndexPlanningUnchecked[iIndex] = gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (4 - iIndex));
        }
    }

    if (gvIndexPlanningUnChecked.size() != 0)
        ui->label_no_data->setGeometry(QRect(2138, 165, 265, 26));
    else
    {
        if (gbIsHorizontalLayoutSet == false)
            ui->label_no_data->setGeometry(QRect(80, 50, 161, 21));
        else
            ui->label_no_data->setGeometry(QRect(80, 150, 161, 21));
    }

    if (gvIndexPlanningUnChecked.size() >= 1)
    {
        ui->label_day_plan1->setText(xlsx.read(gaiShowIndexPlanningUnchecked[0], 2).toString());
        ui->label_time_plan1->setText(xlsx.read(gaiShowIndexPlanningUnchecked[0], 3).toString());
        ui->label_content_plan_1->setText(xlsx.read(gaiShowIndexPlanningUnchecked[0], 4).toString());

        if (gbIsHorizontalLayoutSet == true)
        {
            ui->frame_Plan_1->setGeometry(QRect(393, 392, 265, 26));
            if (gvIndexPlanningUnChecked.size() >= 4)
            {
                if (gvIndexPlanningUnChecked.size() > 11)
                {
                    ui->label_day_plan1->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 0)), 2).toString());
                    ui->label_time_plan1->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 0)), 3).toString());
                    ui->label_content_plan_1->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 0)), 4).toString());
                }
                else
                {
                    ui->label_day_plan1->setText(xlsx.read(gvIndexPlanningUnChecked.at(0), 2).toString());
                    ui->label_time_plan1->setText(xlsx.read(gvIndexPlanningUnChecked.at(0), 3).toString());
                    ui->label_content_plan_1->setText(xlsx.read(gvIndexPlanningUnChecked.at(0), 4).toString());
                }
            }
        }
        else
        {
            ui->frame_Plan_1->setGeometry(QRect(138, 165, 265, 26));
        }
    }
    else
        ui->frame_Plan_1->setGeometry(QRect(2138, 165, 265, 26));

    if (gvIndexPlanningUnChecked.size() >= 2)
    {
        ui->label_day_plan1_2->setText(xlsx.read(gaiShowIndexPlanningUnchecked[1], 2).toString());
        ui->label_time_plan1_2->setText(xlsx.read(gaiShowIndexPlanningUnchecked[1], 3).toString());
        ui->label_content_plan_2->setText(xlsx.read(gaiShowIndexPlanningUnchecked[1], 4).toString());

        if (gbIsHorizontalLayoutSet == true)
        {
            ui->frame_Plan_2->setGeometry(QRect(393, 397 + 26, 265, 26));
            if (gvIndexPlanningUnChecked.size() >= 4)
            {
                if (gvIndexPlanningUnChecked.size() > 11)
                {
                    ui->label_day_plan1_2->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 1)), 2).toString());
                    ui->label_time_plan1_2->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 1)), 3).toString());
                    ui->label_content_plan_2->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 1)), 4).toString());
                }
                else
                {
                    ui->label_day_plan1_2->setText(xlsx.read(gvIndexPlanningUnChecked.at(1), 2).toString());
                    ui->label_time_plan1_2->setText(xlsx.read(gvIndexPlanningUnChecked.at(1), 3).toString());
                    ui->label_content_plan_2->setText(xlsx.read(gvIndexPlanningUnChecked.at(1), 4).toString());
                }
            }
        }
        else
        {
            ui->frame_Plan_2->setGeometry(QRect(138, 170 + 26, 265, 26));
        }
    }
    else
        ui->frame_Plan_2->setGeometry(QRect(2355, 165 + 26 + 5, 265, 26));

    if (gvIndexPlanningUnChecked.size() >= 3)
    {
        ui->label_day_plan1_3->setText(xlsx.read(gaiShowIndexPlanningUnchecked[2], 2).toString());
        ui->label_time_plan1_3->setText(xlsx.read(gaiShowIndexPlanningUnchecked[2], 3).toString());
        ui->label_content_plan_3->setText(xlsx.read(gaiShowIndexPlanningUnchecked[2], 4).toString());

        if (gbIsHorizontalLayoutSet == true)
        {
            ui->frame_Plan_3->setGeometry(QRect(393, 392 + 2 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() >= 4)
            {
                if (gvIndexPlanningUnChecked.size() > 11)
                {
                    ui->label_day_plan1_3->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 2)), 2).toString());
                    ui->label_time_plan1_3->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 2)), 3).toString());
                    ui->label_content_plan_3->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 2)), 4).toString());
                }
                else
                {
                    ui->label_day_plan1_3->setText(xlsx.read(gvIndexPlanningUnChecked.at(2), 2).toString());
                    ui->label_time_plan1_3->setText(xlsx.read(gvIndexPlanningUnChecked.at(2), 3).toString());
                    ui->label_content_plan_3->setText(xlsx.read(gvIndexPlanningUnChecked.at(2), 4).toString());
                }
            }
        }
        else
        {
            ui->frame_Plan_3->setGeometry(QRect(138, 165 + 2 * (26 + 5), 265, 26));
        }
    }
    else
        ui->frame_Plan_3->setGeometry(QRect(2355, 165 + 26 + 5, 265, 26));

    if (gvIndexPlanningUnChecked.size() >= 4)
    {
        ui->label_day_plan1_4->setText(xlsx.read(gaiShowIndexPlanningUnchecked[3], 2).toString());
        ui->label_time_plan1_4->setText(xlsx.read(gaiShowIndexPlanningUnchecked[3], 3).toString());
        ui->label_content_plan_4->setText(xlsx.read(gaiShowIndexPlanningUnchecked[3], 4).toString());

        if (gbIsHorizontalLayoutSet == true)
        {
            ui->frame_Plan_4->setGeometry(QRect(393, 392 + 3 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() >= 4)
            {
                if (gvIndexPlanningUnChecked.size() > 11)
                {
                    ui->label_day_plan1_4->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 3)), 2).toString());
                    ui->label_time_plan1_4->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 3)), 3).toString());
                    ui->label_content_plan_4->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 3)), 4).toString());
                }
                else
                {
                    ui->label_day_plan1_4->setText(xlsx.read(gvIndexPlanningUnChecked.at(3), 2).toString());
                    ui->label_time_plan1_4->setText(xlsx.read(gvIndexPlanningUnChecked.at(3), 3).toString());
                    ui->label_content_plan_4->setText(xlsx.read(gvIndexPlanningUnChecked.at(3), 4).toString());
                }
            }
        }
        else
        {
            ui->frame_Plan_4->setGeometry(QRect(138, 165 + 3 * (26 + 5), 265, 26));
        }
    }
    else
        ui->frame_Plan_4->setGeometry(QRect(2355, 165 + 26 + 5, 265, 26));

    if (gbIsHorizontalLayoutSet == true)
    {
        if (gvIndexPlanningUnChecked.size() >= 5)
        {
            ui->frame_Plan_5->setGeometry(QRect(388, 387 + 4 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_5->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 4)), 2).toString());
                ui->label_time_plan1_5->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 4)), 3).toString());
                ui->label_content_plan_5->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 4)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_5->setText(xlsx.read(gvIndexPlanningUnChecked.at(4), 2).toString());
                ui->label_time_plan1_5->setText(xlsx.read(gvIndexPlanningUnChecked.at(4), 3).toString());
                ui->label_content_plan_5->setText(xlsx.read(gvIndexPlanningUnChecked.at(4), 4).toString());
            }
        }
        else
            ui->frame_Plan_5->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));

        if (gvIndexPlanningUnChecked.size() >= 6)
        {
            ui->frame_Plan_6->setGeometry(QRect(388, 387 + 5 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_6->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 5)), 2).toString());
                ui->label_time_plan1_6->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 5)), 3).toString());
                ui->label_content_plan_6->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 5)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_6->setText(xlsx.read(gvIndexPlanningUnChecked.at(5), 2).toString());
                ui->label_time_plan1_6->setText(xlsx.read(gvIndexPlanningUnChecked.at(5), 3).toString());
                ui->label_content_plan_6->setText(xlsx.read(gvIndexPlanningUnChecked.at(5), 4).toString());
            }
        }
        else
            ui->frame_Plan_6->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));

        if (gvIndexPlanningUnChecked.size() >= 7)
        {
            ui->frame_Plan_7->setGeometry(QRect(388, 387 + 6 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_7->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 6)), 2).toString());
                ui->label_time_plan1_7->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 6)), 3).toString());
                ui->label_content_plan_7->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 6)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_7->setText(xlsx.read(gvIndexPlanningUnChecked.at(6), 2).toString());
                ui->label_time_plan1_7->setText(xlsx.read(gvIndexPlanningUnChecked.at(6), 3).toString());
                ui->label_content_plan_7->setText(xlsx.read(gvIndexPlanningUnChecked.at(6), 4).toString());
            }
        }
        else
            ui->frame_Plan_7->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));

        if (gvIndexPlanningUnChecked.size() >= 8)
        {
            ui->frame_Plan_8->setGeometry(QRect(388, 387 + 7 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_8->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 7)), 2).toString());
                ui->label_time_plan1_8->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 7)), 3).toString());
                ui->label_content_plan_8->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 7)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_8->setText(xlsx.read(gvIndexPlanningUnChecked.at(7), 2).toString());
                ui->label_time_plan1_8->setText(xlsx.read(gvIndexPlanningUnChecked.at(7), 3).toString());
                ui->label_content_plan_8->setText(xlsx.read(gvIndexPlanningUnChecked.at(7), 4).toString());
            }
        }
        else
            ui->frame_Plan_8->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));

        if (gvIndexPlanningUnChecked.size() >= 9)
        {
            ui->frame_Plan_9->setGeometry(QRect(388, 387 + 8 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_9->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 8)), 2).toString());
                ui->label_time_plan1_9->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 8)), 3).toString());
                ui->label_content_plan_9->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 8)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_9->setText(xlsx.read(gvIndexPlanningUnChecked.at(8), 2).toString());
                ui->label_time_plan1_9->setText(xlsx.read(gvIndexPlanningUnChecked.at(8), 3).toString());
                ui->label_content_plan_9->setText(xlsx.read(gvIndexPlanningUnChecked.at(8), 4).toString());
            }
        }
        else
            ui->frame_Plan_9->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));

        if (gvIndexPlanningUnChecked.size() >= 10)
        {
            ui->frame_Plan_10->setGeometry(QRect(388, 387 + 9 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_10->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 9)), 2).toString());
                ui->label_time_plan1_10->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 9)), 3).toString());
                ui->label_content_plan_10->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 9)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_10->setText(xlsx.read(gvIndexPlanningUnChecked.at(9), 2).toString());
                ui->label_time_plan1_10->setText(xlsx.read(gvIndexPlanningUnChecked.at(9), 3).toString());
                ui->label_content_plan_10->setText(xlsx.read(gvIndexPlanningUnChecked.at(9), 4).toString());
            }
        }
        else
            ui->frame_Plan_10->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));

        if (gvIndexPlanningUnChecked.size() >= 11)
        {
            ui->frame_Plan_11->setGeometry(QRect(388, 387 + 10 * (26 + 5), 265, 26));
            if (gvIndexPlanningUnChecked.size() > 11)
            {
                ui->label_day_plan1_11->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 10)), 2).toString());
                ui->label_time_plan1_11->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 10)), 3).toString());
                ui->label_content_plan_11->setText(xlsx.read(gvIndexPlanningUnChecked.at(gvIndexPlanningUnChecked.size() - (11 - 10)), 4).toString());
            }
            else
            {
                ui->label_day_plan1_11->setText(xlsx.read(gvIndexPlanningUnChecked.at(10), 2).toString());
                ui->label_time_plan1_11->setText(xlsx.read(gvIndexPlanningUnChecked.at(10), 3).toString());
                ui->label_content_plan_11->setText(xlsx.read(gvIndexPlanningUnChecked.at(10), 4).toString());
            }
        }
        else
            ui->frame_Plan_11->setGeometry(QRect(2393, 392 + 4 * (26 + 5), 265, 26));
    }
    else
    {
        ui->frame_Plan_11->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
        ui->frame_Plan_10->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
        ui->frame_Plan_9->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
        ui->frame_Plan_8->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
        ui->frame_Plan_7->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
        ui->frame_Plan_6->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
        ui->frame_Plan_5->setGeometry(QRect(1393, 392 + 4 * (26 + 5), 265, 26));
    }

    gvIndexPlanningUnChecked.clear();
}

/* ======================================================================================================================= */
/*                                                      PASSWORD MANAGEMENT                                                */
/* ======================================================================================================================= */

/**
 * @fn     ShowPasswordManager(void)
 * @brief  Show Password manager window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ShowPasswordManager(void)
{
    if (gbIsPasswordWindowOn == false)
    {
        gbIsPasswordWindowOn = true;
        if (gbIsHorizontalLayoutSet == false)
            ui->frame_password_manage->setGeometry(QRect(100, 250, 270, 150));
        else
            ui->frame_password_manage->setGeometry(QRect(600, 250, 270, 150));
    }
    else
        gbIsPasswordWindowOn = false;
}

/**
 * @fn     ShowPasswordManager(void)
 * @brief  Show Password manager window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ExitPasswordWindow(void)
{
    ui->frame_password_manage->setGeometry(QRect(100, 2500, 270, 150));
    QPixmap pix_wrong(":/Icon/Image/icons8-x-20.png");
    ui->label_check_charecter->setPixmap(pix_wrong);
    ui->textEdit_search->setPlainText("");
    ui->label_ID->setText("---------");
    ui->label_password->setText("**********");
    ui->textEdit_key_pass->setText("");
    ui->pushButton_hide_2->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));
    gbIsHidePasswordOn = false;
    gbIsPasswordWindowOn = false;
}

/**
 * @fn     CheckCharecterEnterInVector(void)
 * @brief  Check the gacCharecterTable was entered is mapping with the password type was set before or not.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return bool
 * @param   QString liCharecterEntering
 */
bool MyApp::CheckCharecterEnterInVector(QString liCharecterEntering)
{
    bool lbReturn = false;
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(13);

    while (xlsx.read(gIndexDataAddedPassword, 1).toString() != "")
    {
        gvsPasswordAdded.push_back(xlsx.read(gIndexDataAddedPassword, 1).toString());
        gIndexDataAddedPassword++;
    }

    for (int iIndex = 0; iIndex < gvsPasswordAdded.size(); iIndex++)
    {
        if (liCharecterEntering == gvsPasswordAdded.at(iIndex))
        {
            giIndexOfPasswordNameChange = iIndex + 3;
            lbReturn = true;
        }
    }
    return lbReturn;
}

/**
 * @fn     CheckEnterCharecter(void)
 * @brief  Show tick True icon or X icon with the gacCharecterTable was entered.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::CheckEnterCharecter(void)
{
    QString liCharecterEntering = ui->textEdit_search->toPlainText();

    if (CheckCharecterEnterInVector(liCharecterEntering) == true)
    {
        QPixmap pix_tick(":/Icon/Image/icons8-tick-25.png");
        ui->label_check_charecter->setPixmap(pix_tick);
    }
    else
    {
        QPixmap pix_wrong(":/Icon/Image/icons8-x-20.png");
        ui->label_check_charecter->setPixmap(pix_wrong);
    }
}

/**
 * @fn     ShowPasswordFollowCharecter(void)
 * @brief  set the password of password type was enter -> show ******** first in gbHide status.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ShowPasswordFollowCharecter(void)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(13);

    ui->label_password->setText("**********");
    gbIsHidePasswordOn = false;
    ui->pushButton_hide_2->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));

    while (xlsx.read(giIndexDataPassword, 1).toString() != "")
    {
        gvsPasswordSaved.push_back(xlsx.read(giIndexDataPassword, 1).toString());
        giIndexDataPassword++;
    }

    QString liCharecterEntering = ui->textEdit_search->toPlainText();

    for (int iIndex = 0; iIndex < gvsPasswordSaved.size(); iIndex++)
    {
        if (liCharecterEntering == gvsPasswordSaved.at(iIndex))
        {
            giIndexOfPassword = iIndex;
            ui->label_ID->setText(xlsx.read(iIndex + 3, 2).toString());
        }
    }
}

/**
 * @fn     ShowPasswordFollowCharecter(void)
 * @brief  Set status of password is hide or no hide and change icon.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::NoHidePassword(void)
{
    if (gbIsHidePasswordOn == false)
    {
        gbIsHidePasswordOn = true;
        if (gbIsHorizontalLayoutSet == false)
            ui->frame_password_manage_3->setGeometry(QRect(130, 260, 200, 100));
        else
            ui->frame_password_manage_3->setGeometry(QRect(630, 260, 200, 100));
        ui->textEdit_key_pass->setText("");
    }
    else
    {
        ui->label_password->setText("**********");
        gbIsHidePasswordOn = false;
        ui->pushButton_hide_2->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));
    }
}

/**
 * @fn     EnterKeyToSeePasswordAndClose(void)
 * @brief  Enter the key to see the password.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::EnterKeyToSeePasswordAndClose(void)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(13);

    const QString lsKey = "1810565";
    if (ui->textEdit_key_pass->text() == lsKey)
    {
        ui->frame_password_manage_3->setGeometry(QRect(130, 2600, 200, 100));
        ui->pushButton_hide_2->setIcon(QIcon(":/Icon/Image/icons8-hide-15.png"));
        ui->label_password->setText(xlsx.read(giIndexOfPassword + 3, 3).toString());
        ui->textEdit_key_pass->setText("");
    }
}

/**
 * @fn     ExitKeyEnter(void)
 * @brief  Click exit to close the key enter window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ExitKeyEnter(void)
{
    ui->frame_password_manage_3->setGeometry(QRect(130, 2600, 200, 100));
    ui->textEdit_key_pass->setText("");
    gbIsHidePasswordOn = false;
}

/**
 * @fn     ReloadCheckPassword(void)
 * @brief  Reload the checking gacCharecterTable of password type.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ReloadCheckPassword(void)
{
    QPixmap pix_wrong(":/Icon/Image/icons8-x-20.png");
    ui->label_check_charecter->setPixmap(pix_wrong);
    ui->textEdit_search->setPlainText("");
    ui->label_ID->setText("---------");
    ui->label_password->setText("**********");
    ui->textEdit_key_pass->setText("");
    ui->pushButton_hide_2->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));
    gbIsHidePasswordOn = false;
}

/* ======================================================================================================================= */
/*                                                  PASSWORD ADDITIONAL MANAGEMENT                                         */
/* ======================================================================================================================= */
/**
 * @fn     AddPassword(void)
 * @brief  Click to show additional password window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::AddPassword(void)
{
    if (gbIsAdditionalPasswordWindowOn == false)
    {
        gbIsAdditionalPasswordWindowOn = true;
        if (gbIsHorizontalLayoutSet == false)
            ui->frame_password_manage_4->setGeometry(QRect(100, 70, 190, 180));
        else
            ui->frame_password_manage_4->setGeometry(QRect(180, 450, 190, 180));
    }
    else
        gbIsAdditionalPasswordWindowOn = false;
}

/**
 * @fn     SetNewPasswordAndClose(void)
 * @brief  Set new password was set to Excel source and close Additional password window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::SetNewPasswordAndClose(void)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(13);

    while (xlsx.read(gIndexDataAdditionalPassword, 1).toString() != "")
    {
        gIndexDataAdditionalPassword++;
    }

    xlsx.write(gIndexDataAdditionalPassword, 1, ui->textEdit_name_add->text());
    xlsx.write(gIndexDataAdditionalPassword, 2, ui->textEdit_ID_add->text());
    xlsx.write(gIndexDataAdditionalPassword, 3, ui->textEdit_key_pass_add->text());

    xlsx.saveAs("Data_source.xlsx");

    ui->frame_password_manage_4->setGeometry(QRect(180, 1450, 190, 180));
    gbIsAdditionalPasswordWindowOn = false;
    ui->textEdit_name_add->setText("");
    ui->textEdit_ID_add->setText("");
    ui->textEdit_key_pass_add->setText("");
}

/**
 * @fn     CloseAddPassword(void)
 * @brief  Click to close Additional password window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::CloseAddPassword(void)
{
    ui->frame_password_manage_4->setGeometry(QRect(180, 1450, 190, 180));
    gbIsAdditionalPasswordWindowOn = false;
    ui->textEdit_name_add->setText("");
    ui->textEdit_ID_add->setText("");
    ui->textEdit_key_pass_add->setText("");
}

/* ======================================================================================================================= */
/*                                               PASSWORD ADJUSTMENT MANAGEMENT                                            */
/* ======================================================================================================================= */
/**
 * @fn     ShowPasswordAdjustment(void)
 * @brief  Click to show Adjustment password window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ShowPasswordAdjustment(void)
{
    if (gbIsPasswordShow == false)
    {
        gbIsPasswordShow = true;
        if (gbIsHorizontalLayoutSet == false)
            ui->frame_password_manage_5->setGeometry(QRect(110, 190, 220, 140));
        else
            ui->frame_password_manage_5->setGeometry(QRect(630, 190, 220, 140));
        ui->frame_password_manage->setGeometry(QRect(110, 1890, 220, 140));
    }
    else
    {
        gbIsPasswordShow = false;
    }
}

/**
 * @fn     CheckEnterCharecterOfNameChange(void)
 * @brief  Check gacCharecterTable enter with password type was saved.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::CheckEnterCharecterOfNameChange(void)
{
    QString liCharecterEntering = ui->textEdit_name_change_2->toPlainText();

    if (CheckCharecterEnterInVector(liCharecterEntering) == true)
    {
        QPixmap pix_tick(":/Icon/Image/icons8-tick-25.png");
        ui->label_check_charecter_2->setPixmap(pix_tick);
    }
    else
    {
        QPixmap pix_wrong(":/Icon/Image/icons8-x-20.png");
        ui->label_check_charecter_2->setPixmap(pix_wrong);
    }
}

/**
 * @fn     EnterPasswordAdjustmentAndReshowManager(void)
 * @brief  Set the new password to Excel source, close adjustment window and reshow main password window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::EnterPasswordAdjustmentAndReshowManager(void)
{
    Document xlsx("Data_source.xlsx");
    xlsx.selectSheet(13);

    if (ui->textEdit_pass_change->toPlainText() != "")
    {
        xlsx.write(giIndexOfPasswordNameChange, 3, ui->textEdit_pass_change->toPlainText());
        xlsx.saveAs("Data_source.xlsx");
    }

    ui->frame_password_manage_5->setGeometry(QRect(110, 1590, 220, 140));
    ui->frame_password_manage->setGeometry(QRect(100, 250, 270, 150));
    ui->textEdit_name_change_2->setText("");
    ui->textEdit_pass_change->setText("");
    gbIsPasswordShow = false;

    QPixmap pix_wrong(":/Icon/Image/icons8-x-20.png");
    ui->label_check_charecter->setPixmap(pix_wrong);
    ui->textEdit_search->setPlainText("");
    ui->label_ID->setText("---------");
    ui->label_password->setText("**********");
    ui->textEdit_key_pass->setText("");
    ui->pushButton_hide_2->setIcon(QIcon(":/Icon/Image/icons8-eye-15.png"));
    gbIsHidePasswordOn = false;
    gbIsPasswordWindowOn = false;
}

/**
 * @fn     ExitPasswordAdjustmentAndReshowManager(void)
 * @brief  Click to close Adjustment password window and reshow Password manager window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   28/02/2024
 * @return void
 * @param   void
 */
void MyApp::ExitPasswordAdjustmentAndReshowManager(void)
{
    ui->frame_password_manage_5->setGeometry(QRect(110, 1590, 220, 140));
    if (gbIsHorizontalLayoutSet == false)
        ui->frame_password_manage->setGeometry(QRect(100, 250, 270, 150));
    else
        ui->frame_password_manage->setGeometry(QRect(600, 250, 270, 150));
    ui->textEdit_name_change_2->setText("");
    ui->textEdit_pass_change->setText("");
    gbIsPasswordShow = false;
}


/* ======================================================================================================================= */
/*                                                ELECTRICAL DEVICE CONTROL                                                */
/* ======================================================================================================================= */

/**
 * @fn     ShowSettingUartForElecDeviceControlWindow(void)
 * @brief  Click to show UART setting window.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::ShowSettingUartForElecDeviceControlWindow(void)
{
    if (gbIsUartSettingShow == false)
        gbIsUartSettingShow = true;
    else
        gbIsUartSettingShow = false;

    if (gbIsUartSettingShow == true)
        if (gbIsHorizontalLayoutSet == true)
            ui->frameUart->setGeometry(QRect(190, 420, 210, 180));
        else
            ui->frameUart->setGeometry(QRect(60, 180, 210, 180));
    else
        ui->frameUart->setGeometry(QRect(60, 1000, 210, 180));
}

/**
 * @fn     SettingUart(void)
 * @brief  Setting UART items: Port/Baudrate/DataBits/StopBits/Parity.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::SettingUart(void)
{
    // Ports
    QSerialPortInfo info;
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> llsStringPorts;
    for (int iIndex = 0; iIndex < ports.size(); iIndex++)
    {
        llsStringPorts.append(ports.at(iIndex).portName());
    }
    ui->comboBox_port->addItems(llsStringPorts);

    QList<qint32> baudRates = info.standardBaudRates();
    QList<QString> stringBaudRates;
    for (int iIndex = 0; iIndex < baudRates.size(); iIndex++)
    {
        stringBaudRates.append(QString::number(baudRates.at(iIndex)));
    }
    ui->comboBox_Baudrate->addItems(stringBaudRates);

    serialPort = new QSerialPort();

    // Port
    QString lsPortName = ui->comboBox_port->currentText();
    serialPort->setPortName(lsPortName);

    // Baudrate
    QString lsStringOfBaudrate = ui->comboBox_Baudrate->currentText();
    if (lsStringOfBaudrate == "4800")
        serialPort->setBaudRate(QSerialPort::BaudRate::Baud4800);
    else if (lsStringOfBaudrate == "9600")
        serialPort->setBaudRate(QSerialPort::BaudRate::Baud9600);
    else if (lsStringOfBaudrate == "115200")
        serialPort->setBaudRate(QSerialPort::BaudRate::Baud115200);

    // Data bits
    QString lsStringOfDataBits = ui->comboBox_Databits->currentText();
    if (lsStringOfDataBits == "5 Bits")
        serialPort->setDataBits(QSerialPort::DataBits::Data5);
    else if ((lsStringOfDataBits == "6 Bits"))
        serialPort->setDataBits(QSerialPort::DataBits::Data6);
    else if (lsStringOfDataBits == "7 Bits")
        serialPort->setDataBits(QSerialPort::DataBits::Data7);
    else if (lsStringOfDataBits == "8 Bits")
        serialPort->setDataBits(QSerialPort::DataBits::Data8);
    // Stop bits:
    QString lsStringOfStopBits = ui->comboBox_Stopbits->currentText();
    if (lsStringOfStopBits == "1 Bit")
        serialPort->setStopBits(QSerialPort::StopBits::OneStop);
    else if (lsStringOfStopBits == "1,5 Bits")
        serialPort->setStopBits(QSerialPort::StopBits::OneAndHalfStop);
    else if (lsStringOfStopBits == "2 Bits")
        serialPort->setStopBits(QSerialPort::StopBits::TwoStop);
    // Parity
    QString lsStringOfParity = ui->comboBox_parity->currentText();
    if (lsStringOfParity == "No Parity")
        serialPort->setParity(QSerialPort::Parity::NoParity);
    else if (lsStringOfParity == "Even Parity")
        serialPort->setParity(QSerialPort::Parity::EvenParity);
    else if (lsStringOfParity == "Odd Parity")
        serialPort->setParity(QSerialPort::Parity::OddParity);
    else if (lsStringOfParity == "Mark Parity")
        serialPort->setParity(QSerialPort::Parity::MarkParity);
    else if (lsStringOfParity == "Space Parity")
        serialPort->setParity(QSerialPort::Parity::SpaceParity);

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

/**
 * @fn     ConnectUart(void)
 * @brief  Click to connect UART.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::ConnectUart(void)
{
    serialPort->open(QIODevice::ReadWrite);
    ui->frameUart->setGeometry(QRect(60, 1000, 210, 180));
    gbIsUartSettingShow = false;
}

/**
 * @fn     SendMsgFanControl(void)
 * @brief  Send data to port through UART to set Turn on the FAN.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::SendMsgFanControl(void)
{
    if (gbIsFanOn == false)
        gbIsFanOn = true;
    else
        gbIsFanOn = false;

    QString lsFanStringSending = "a";
    serialPort->write(lsFanStringSending.toUtf8());
}

/**
 * @fn     receiveMessage(void)
 * @brief  Received data through UART to setting fan and light control.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::receiveMessage()
{
    QByteArray lBADataReceived = serialPort->readAll();
    gsUartDataReceived += (gacCharecterTable[(static_cast<int>(lBADataReceived[lBADataReceived.size() - 1])) - 1]);
    if (gsUartDataReceived == "fanon")
    {
        gsUartDataReceived = "";
        FanControl(true);
    }
    else if (gsUartDataReceived == "fanoff")
    {
        gsUartDataReceived = "";
        FanControl(false);
    }
    else if (gsUartDataReceived == "lighton")
    {
        gsUartDataReceived = "";
        LightControl(true);
    }
    else if (gsUartDataReceived == "lightoff")
    {
        gsUartDataReceived = "";
        LightControl(false);
    }
}

/**
 * @fn     FanControl(void)
 * @brief  Display the FAN in App (Turn On/Off) follow data receive.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   bool IsFanOn
 */
void MyApp::FanControl(bool IsFanOn)
{
    QPropertyAnimation *animation_button_fan = new QPropertyAnimation(ui->Fanbutton, "geometry");
    animation_button_fan->setDuration(50);
    if (IsFanOn == true)
    {
        animation_button_fan->setStartValue(QRect(ui->Fanbutton->geometry().x(), ui->Fanbutton->geometry().y(), 20, 20));
        animation_button_fan->setEndValue(QRect(ui->Fanbutton->geometry().x() + 25, ui->Fanbutton->geometry().y(), 20, 20));
        ui->label_34->setStyleSheet("background-color: #8E7AB5;"
                                    "border: 1px solid #8E7AB5;"
                                    "border-radius: 8px");
        QMovie *movie = new QMovie(":/IconApplication/Image/fan.gif");
        ui->label_36->setMovie(movie);
        movie->start();
    }
    else
    {
        animation_button_fan->setStartValue(QRect(ui->Fanbutton->geometry().x(), ui->Fanbutton->geometry().y(), 20, 20));
        animation_button_fan->setEndValue(QRect(ui->Fanbutton->geometry().x() - 25, ui->Fanbutton->geometry().y(), 20, 20));
        ui->label_34->setStyleSheet("background-color: white;"
                                    "border: 1px solid #8E7AB5;"
                                    "border-radius: 8px");
        QPixmap pixmap_fan(":/Icon/Image/icons8-fan-40.png");
        ui->label_36->setPixmap(pixmap_fan);
    }

    animation_button_fan->start();
}

/**
 * @fn     SendMsgLightControl(void)
 * @brief  Send data to port through UART to set Turn on the LIGHT.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::SendMsgLightControl(void)
{
    if (gbIsLightOn == false)
        gbIsLightOn = true;
    else
        gbIsLightOn = false;

    QString lsLightStringSending = "b";
    serialPort->write(lsLightStringSending.toUtf8());
}

/**
 * @fn     LightControl(void)
 * @brief  Display the LIGHT in App (Turn On/Off) follow data receive.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   bool IsLightOn
 */
void MyApp::LightControl(bool IsLightOn)
{
    QPropertyAnimation *animation_button_light = new QPropertyAnimation(ui->Lightbutton, "geometry");
    animation_button_light->setDuration(50);

    if (IsLightOn == true)
    {
        animation_button_light->setStartValue(QRect(ui->Lightbutton->geometry().x(), ui->Lightbutton->geometry().y(), 20, 20));
        animation_button_light->setEndValue(QRect(ui->Lightbutton->geometry().x() + 25, ui->Lightbutton->geometry().y(), 20, 20));
        ui->label_37->setStyleSheet("background-color: #8E7AB5;"
                                    "border: 1px solid #8E7AB5;"
                                    "border-radius: 8px");
        QPixmap pixmap_fan(":/Icon/Image/icons8-light-60.png");
        ui->label_38->setPixmap(pixmap_fan);
    }
    else
    {
        animation_button_light->setStartValue(QRect(ui->Lightbutton->geometry().x(), ui->Lightbutton->geometry().y(), 20, 20));
        animation_button_light->setEndValue(QRect(ui->Lightbutton->geometry().x() - 25, ui->Lightbutton->geometry().y(), 20, 20));
        ui->label_37->setStyleSheet("background-color: white;"
                                    "border: 1px solid #8E7AB5;"
                                    "border-radius: 8px");
        QPixmap pixmap_fan(":/Icon/Image/icons8-light-40.png");
        ui->label_38->setPixmap(pixmap_fan);
    }
    animation_button_light->start();
}

/**
 * @fn     DisconnectUart(void)
 * @brief  Click to disconnect Uart and send message to turn Off all.
 * @author Nguyen Dinh Thuan (ndthuan167)
 * @date   27/06/2024
 * @return void
 * @param   void
 */
void MyApp::DisconnectUart(void)
{
    QString lsOffDeviceStringSending = "t";
    serialPort->write(lsOffDeviceStringSending.toUtf8());
    serialPort->close();
}

MyApp::~MyApp()
{
    delete ui;
}
