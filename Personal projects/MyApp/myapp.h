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

    void BackImage();
    void NextImage();

    void ShowFrameTest();
    void EnterThuAndClose();

    void ShowPopUpChi();
    void EnterChiAndClose();

    void ChangeToHorizontalLayout();

    void ShowCalendarSelection();
    void PopupselectDay();

    void BackDayinCalendar();
    void NextDayinCalendar();
    void SetDateCalendar();

    int ReturnNumberOfImage();

private:
    Ui::MyApp *ui;
    myApp_horizontal *myapp_horizon;
    Ui::myApp_horizontal *horizon_ui;

    bool Hide = false;

    int today = 0;
    QString total_date;

    QString SunNight;
    bool showframetest = false;
    bool showPopupChi = false;
    bool set_horizontal_layout = false;
};
#endif // MYAPP_H
