#include "popup_thu.h"
#include "ui_popup_thu.h"

popup_Thu::popup_Thu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup_Thu)
{
    ui->setupUi(this);
}

popup_Thu::popup_Thu(QWidget *parent, QString message):
    QDialog(parent),
    ui(new Ui::popup_Thu)
{
    ui->setupUi(this);

    // Close PopupThu -> send data to Main Window
    connect(this, &popup_Thu::finished, this, [this](){
        emit ConnectDataEarning(QString(ui->label_date_selected_Thu->text()).mid(0,2), \
        QString(ui->plainTextEdit_3->toPlainText()), QString(ui->comboBox->currentText()) , QString(ui->plainTextEdit_2->toPlainText()));
    });

    connect(ui->pushButton_Selectday_Thu, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_back_day_Thu, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_next_day_Thu, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_SelectedDay_Thu, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));


    this->setFixedSize(QSize(240,227));
    this->setWindowTitle("Dữ liệu Thu");
    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd/MM/yyyy");
    ui->label_date_selected_Thu->setText(lsCurrentDate);
}

/**
  * @fn     ShowCalendarSelection(void)
  * @brief  Open the Calendar window to select a earnings date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void popup_Thu::ShowCalendarSelection(void)
{
    ui->PopupselectDay_Thu->setGeometry(QRect(30,10, 190, 71));
    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd/MM/yyyy");
    ui->label_date_select_Thu->setText(lsCurrentDate);
    giToday = ldDate.toString("dd").toInt() ;
}

/**
  * @fn     BackDayinCalendar(void)
  * @brief  Minus the date to select earnings date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void popup_Thu::BackDayinCalendar(void)
{
    giToday--;
    QString lsTodayString = QString::number(giToday);
    QDate day = QDate::currentDate();
    QString lsToMonthString = day.toString("MM");
    QString lsToYearString = day.toString("yyyy");
    if (giToday < 10)
        gsSettingDate = "0" + lsTodayString  + "/" + lsToMonthString + "/" + lsToYearString;
    else
        gsSettingDate = lsTodayString  + "/" + lsToMonthString + "/" + lsToYearString;
    ui->label_date_select_Thu->setText(gsSettingDate);
}

/**
  * @fn     NextDayinCalendar(void)
  * @brief  Plus the date to select earnings date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void popup_Thu::NextDayinCalendar(void)
{
    giToday++;
    QString lsTodayString = QString::number(giToday);
    QDate ldDay = QDate::currentDate();
    QString lsToMonthString = ldDay.toString("MM");
    QString lsToYearString = ldDay.toString("yyyy");
    if (giToday < 10)
        gsSettingDate = "0" + lsTodayString  + "/" + lsToMonthString + "/" + lsToYearString;
    else
        gsSettingDate = lsTodayString  + "/" + lsToMonthString + "/" + lsToYearString;
    ui->label_date_select_Thu->setText(gsSettingDate);
}

/**
  * @fn     SetDateCalendar(void)
  * @brief  Set the earnings date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void popup_Thu::SetDateCalendar(void)
{
    if (gsSettingDate == "")
    {
        QDate ldDay = QDate::currentDate();
        gsSettingDate = ldDay.toString("dd/MM/yyyy");
    }
    ui->label_date_selected_Thu->setText(gsSettingDate);
    ui->PopupselectDay_Thu->setGeometry(QRect(310,40, 190, 71));

}

/**
  * @fn     
  * @brief  Close the Popup Chi window by click Enter button
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return ->> ConnectDataEarning function (return day/type/amount/description of earnings)
  * @param  void
  */

popup_Thu::~popup_Thu()
{
    delete ui;
}

void popup_Thu::on_pushButton_SetThu_clicked()
{
    close();
}
