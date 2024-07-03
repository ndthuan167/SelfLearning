#include "popup_plan.h"
#include "ui_popup_plan.h"

Popup_Plan::Popup_Plan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup_Plan)
{
    ui->setupUi(this);
}

Popup_Plan::Popup_Plan(QWidget *parent, QString message):
    QDialog(parent),
    ui(new Ui::Popup_Plan)
{
    ui->setupUi(this);
    
    // Close PopupPlan -> send data to Main Window
    connect(this, &Popup_Plan::finished, this, [this](){
        emit ConnectDataPlanning(QString(ui->label_date_selected_Plan->text()).mid(0,2), \
        QString(ui->plainTextEdit_Time->toPlainText()), QString(ui->plainTextEdit_detailPlan->toPlainText()));
    });
    this->setFixedSize(QSize(200,165));
    this->setWindowTitle("Dữ liệu Plan");

    connect(ui->pushButton_Selectday_Plan, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_back_day_Thu, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_next_day_Thu, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_SelectedDay_Thu, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));

    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd/MM/yyyy");
    ui->label_date_selected_Plan->setText(lsCurrentDate);
}

/**
  * @fn     ShowCalendarSelection(void)
  * @brief  Open the Calendar window to select plan days
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   07/01/2024
  * @return void
  * @param  void
  */
void Popup_Plan::ShowCalendarSelection(void)
{
    ui->PopupselectDay_Thu->setGeometry(QRect(5,10, 190, 71));
    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd/MM/yyyy");
    ui->label_date_select_Thu->setText(lsCurrentDate);
    giToday = ldDate.toString("dd").toInt() ;
}

/**
  * @fn     BackDayinCalendar(void)
  * @brief  Minus the date to select plan date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   07/01/2024
  * @return void
  * @param  void
  */
void Popup_Plan::BackDayinCalendar(void)
{
    giToday--;
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
  * @fn     NextDayinCalendar(void)
  * @brief  Plus the date to select plan date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   07/01/2024
  * @return void
  * @param  void
  */
void Popup_Plan::NextDayinCalendar(void)
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
  * @brief  Set the plan date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   07/01/2024
  * @return void
  * @param  void
  */
void Popup_Plan::SetDateCalendar(void)
{
    if (gsSettingDate == "")
    {
        QDate ldDate = QDate::currentDate();
        gsSettingDate = ldDate.toString("dd/MM/yyyy");
    }
    ui->label_date_selected_Plan->setText(gsSettingDate);
    ui->PopupselectDay_Thu->setGeometry(QRect(310,40, 190, 71));

}

/**
  * @fn     
  * @brief  Close the Popup Chi window by click Enter button
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   07/01/2024
  * @return ->> dataAvaiable_Plan function (return time/date/description of plan)
  * @param  void
  */
Popup_Plan::~Popup_Plan()
{
    delete ui;
}

void Popup_Plan::on_pushButton_SetPlan_clicked()
{
    close();
}
