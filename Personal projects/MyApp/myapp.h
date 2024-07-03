#ifndef MYAPP_H
#define MYAPP_H

#include <QMainWindow>
#include "IncludeLibrary.h"
#include "popupchi.h"
#include "popup_thu.h"
#include "popup_plan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyApp; }
QT_END_NAMESPACE

class MyApp : public QMainWindow
{
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);
    ~MyApp();

    int giNumberOfImageBefore = 0;
    int giNumberOfImageAfter;

public slots:
    // Website/App Opening
    void OpenYoutubeWebsite(void);
    void OpenGithubWebsite(void);
    void OpenFacebookWebsite(void);
    void OpenZaloApp(void);
    void OpenVSCode(void);
    void OpenGoogleSearch(void);
    void OpenExcelDataSource(void);

    // Time/Date Display (Calendar)
    void CurrentDateTime(void);

    // Image Animation
    void BackImage(void);
    void NextImage(void);

    // Earning/Spending management
    void ShowEarningWindow(void);
    void ShowSpendingWindow(void);
    void HidetheTotal(void);
    void ShowEarningSpendingDataFromSource(void);
    void HandleDataSpending(const QString &lsDataDateSpending, const QString &lsDataMoneySpending, const QString &lsDataMoneyTypeSpending, const QString &lsDataContentSpending);
    void HandleDataEarning(const QString &lsDataDateEaning, const QString &lsDataMoneyEaning, const QString &lsDataTypeMoneyEaning, const QString &lsDataContentEaning);
    void HandleDataPlanning(const QString &lsDataDatePlanning, const QString &lsDataTimePlanning, const QString &lsDataDetailsPlanning);

    // Vertical/Horizontal layout management
    void ChangeToHorizontalLayout(void);
    
    // Planning management
    void ShowPlanWindow(void);
    void ShowDataPlan(void);
    void HandleCheckBoxPlan(void);

    // Password management
    void ShowPasswordManager(void);
    void ExitPasswordWindow(void);
    void CheckEnterCharecter(void);
    void ShowPasswordFollowCharecter(void);
    void NoHidePassword(void);
    void EnterKeyToSeePasswordAndClose(void);
    void ReloadCheckPassword(void);
    void ExitKeyEnter(void);
    void AddPassword(void);
    void CloseAddPassword(void);
    void SetNewPasswordAndClose(void);
    void ShowPasswordAdjustment(void);
    void ExitPasswordAdjustmentAndReshowManager(void);
    void EnterPasswordAdjustmentAndReshowManager(void);
    void CheckEnterCharecterOfNameChange(void);
    bool CheckCharecterEnterInVector(QString liCharecterEntering);

    // Electrical Device Control
    void ShowSettingUartForElecDeviceControlWindow(void);
    void SettingUart();
    void ConnectUart(void);
    void DisconnectUart(void);
    void receiveMessage();
    void SendMsgFanControl(void);
    void FanControl(bool IsFanOn);
    void SendMsgLightControl(void);
    void LightControl(bool IsLightOn);

private:
    Ui::MyApp *ui;

    bool gbHide = false;
    QVector <int> gvDataMoneyEarning;
    QVector <int> gvDataMoneySpending;
    QString gsMoneyEarning;
    int giIndexMoneyEarning = 0;
    QString gsMoneySpending;
    int giIndexMoneySpending = 0;
    QString gsMoneyAccumulate = "0";

    QString gsSunOrNight;
    bool gbIsHorizontalLayoutSet = false;

    int giIndexDataSpending = 5;
    int giNumberOfDataSpending = 0;

    int giIndexDataEarning = 5;
    int giNumberOfDataEarning = 0;

    int giWriteIndexSpending = 5;
    int giWriteIndexEarning = 5;
    int giWriteIndexPlanning = 4;

    QVector <int> gvIndexPlanningUnChecked;
    QVector <int> gvIndexPlanningChecked;
    int gaiShowIndexPlanningUnchecked[4];
    int gaiShowIndexPlanningChecked[4];
    int giNumberOfPlan = 4 ;

    bool gbIsPasswordWindowOn = false;
    int giIndexDataPassword = 3;
    int gIndexDataAdditionalPassword = 3;
    int gIndexDataAddedPassword = 3;
    QVector <QString> gvsPasswordSaved;
    QVector <QString> gvsPasswordAdded;
    int giIndexOfPassword;
    bool gbIsKeyEnterTrue = false;
    bool gbIsHidePasswordOn = false;
    bool gbIsAdditionalPasswordWindowOn = false;
    int giIndexOfPasswordNameChange;
    bool gbIsPasswordShow = false;

// Electrical Device Control
    bool gbIsUartSettingShow = false;
    QSerialPort* serialPort;
    QString gsUartDataReceived;
    const QChar gacCharecterTable[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' ,'i','j' ,'k' , 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    bool gbIsFanOn = false;
    bool gbIsLightOn = false;
};
#endif // MYAPP_H
