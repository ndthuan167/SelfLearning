#ifndef MYAPP_H
#define MYAPP_H

#include <QMainWindow>
#include "IncludeLibrary.h"
#include "myapp_horizontal.h"
#include "ui_myapp_horizontal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyApp; }
QT_END_NAMESPACE

class MyApp : public QMainWindow
{
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);
    ~MyApp();

    int numberofimage = 0;
    int numberofimage_2;

public slots:
    void OpenYoutubeWebsite();
    void OpenGithubWebsite();
    void OpenFacebookWebsite();
    void OpenZaloApp();
    void OpenVSCode();
    void OpenGoogleSearch();
    void showTime();
    void HidetheTotal();

    void ShowFrameTest();
    void ShowPopUpChi();

    void BackImage();
    void NextImage();

    void ChangeToHorizontalLayout();
    void ShowDataFromDataSource();

    void onDataAvailable(const QString &data_textday, const QString &data_textmoney, const QString &data_texttype, const QString &data_textcontent);
    void onDataAvailable_Thu(const QString &data_textday_thu, const QString &data_textmoney_thu, const QString &data_texttype_thu, const QString &data_textcontent_thu);

private:
    Ui::MyApp *ui;
    myApp_horizontal *myapp_horizon;
    Ui::myApp_horizontal *horizon_ui;

    bool Hide = false;

    int today = 0;
    QString total_date;

    QString money_thu;
    int int_money_thu = 0;
    QString money_chi;
    int int_money_chi = 0;
    QString money_tichluy = "0";

    QString SunNight;
    bool showframetest = false;
    bool showPopupChi = false;
    bool set_horizontal_layout = false;
};
#endif // MYAPP_H
