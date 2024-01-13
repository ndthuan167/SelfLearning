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
    void OpenExcelDataSource();

    void showTime();
    void HidetheTotal();

    void ShowFrameTest();
    void ShowPopUpChi();
    void ShowPopUpPlan();

    void BackImage();
    void NextImage();

    void ChangeToHorizontalLayout();
    void ShowDataFromDataSource();
    void ShowDataPlan();

    void onDataAvailable(const QString &data_textday, const QString &data_textmoney, const QString &data_texttype, const QString &data_textcontent);
    void onDataAvailable_Thu(const QString &data_textday_thu, const QString &data_textmoney_thu, const QString &data_texttype_thu, const QString &data_textcontent_thu);
    void onDataAvailable_Plan(const QString &data_textday_plan, const QString &data_texttime_plan, const QString &data_textdetailPlan);

    void HandleCheckBoxPlan();

private:
    Ui::MyApp *ui;
    myApp_horizontal *myapp_horizon;
    Ui::myApp_horizontal *horizon_ui;

    bool Hide = false;

    int today = 0;
    QString total_date;

    QVector <int> data_money_thu;
    QVector <int> data_money_chi;
    QString money_thu;
    int int_money_thu = 0;
    QString money_chi;
    int int_money_chi = 0;
    QString money_tichluy = "0";

    QString SunNight;
    bool showframetest = false;
    bool showPopupChi = false;
    bool set_horizontal_layout = false;

    int number_data_chi_index = 5;
    int number_data_chi = 0;

    int number_data_thu_index = 5;
    int number_data_thu = 0;

    int number_data_write_chi_index = 5;
    int number_data_write_thu_index = 5;
    int number_data_write_plan_index = 4;

    QVector <int> index_plan_unchecked;
    QVector <int> index_plan_check;
    int index_plan_unchecked_show[4];
    int index_plan_check_show[4];
    int numberofplan = 4 ;

};
#endif // MYAPP_H
