#ifndef MYAPP_HORIZONTAL_H
#define MYAPP_HORIZONTAL_H

#include <QMainWindow>
#include "IncludeLibrary.h"

namespace Ui {
class myApp_horizontal;
}

class myApp_horizontal : public QMainWindow
{
    Q_OBJECT

public:
    explicit myApp_horizontal(QWidget *parent = nullptr);
    ~myApp_horizontal();

public slots:
    void ShowTimeinHorizontal_layout();
    void ChangeToHorizontalLayout();

    void HidetheTotal();

    void BackImage();
    void NextImage();

    void ShowFrameTest();
    void EnterThuAndClose();

    void ShowPopUpChi();
    void EnterChiAndClose();

    void ShowCalendarSelection();
    void PopupselectDay();

    void BackDayinCalendar();
    void NextDayinCalendar();
    void SetDateCalendar();


private:
    Ui::myApp_horizontal *ui;
    QString SunNight;
    bool Hide = false;
    int numberofimage = 0;
    int numberofimage_2;
    bool showframetest = false;
    bool showPopupChi = false;

    int today = 0;
    QString total_date;
};

#endif // MYAPP_HORIZONTAL_H
