#include "popupchi.h"
#include "ui_popupchi.h"

PopupChi::PopupChi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupChi)
{
    ui->setupUi(this);
}

PopupChi::PopupChi(QWidget *parent, QString message):
    QDialog(parent),
    ui(new Ui::PopupChi)
{
    ui->setupUi(this);
    connect(ui->pushButton_Selectday, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_back_day, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_next_day, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_SelectedDay, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));

    // Close PopupChi -> send data to Main Window
    connect(this, &PopupChi::finished, this, [this](){
        emit ConnectDataSpending(QString(ui->label_date_selected->text()).mid(0,2), QString(ui->plainTextEdit_5->toPlainText()), \ 
        QString(ui->comboBox_2->currentText()), QString(ui->plainTextEdit_4->toPlainText()));
    });

    this->setFixedSize(QSize(240,227));
    this->setWindowTitle("Dữ liệu chi");
    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd/MM/yyyy");
    ui->label_date_selected->setText(lsCurrentDate);
}

/**
  * @fn     ShowCalendarSelection(void)
  * @brief  Open the Calendar window to select spending days
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void PopupChi::ShowCalendarSelection(void)
{
    ui->PopupselectDay->setGeometry(QRect(30,10, 190, 71));
    QDate ldDate = QDate::currentDate();
    QString lsCurrentDate = ldDate.toString("dd/MM/yyyy");
    ui->label_date_select->setText(lsCurrentDate);
    giToday = ldDate.toString("dd").toInt() ;
}

/**
  * @fn     BackDayinCalendar(void)
  * @brief  Minus the date to select spending date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void PopupChi::BackDayinCalendar(void)
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
    ui->label_date_select->setText(gsSettingDate);
}

/**
  * @fn     NextDayinCalendar(void)
  * @brief  Plus the date to select spending date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void PopupChi::NextDayinCalendar(void)
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
    ui->label_date_select->setText(gsSettingDate);
}

/**
  * @fn     SetDateCalendar(void)
  * @brief  Set the spending date
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return void
  * @param  void
  */
void PopupChi::SetDateCalendar(void)
{
    if (gsSettingDate == "")
    {
        QDate ldDate = QDate::currentDate();
        gsSettingDate = ldDate.toString("dd/MM/yyyy");
    }
    ui->label_date_selected->setText(gsSettingDate);
    ui->PopupselectDay->setGeometry(QRect(310,40, 190, 71));

}

/**
  * @fn     
  * @brief  Close the Popup Chi window by click Enter button
  * @author Nguyen Dinh Thuan (ndthuan167)
  * @date   13/12/2023
  * @return ->> ConnectDataSpending function (return day/type/amount/description of spending)
  * @param  void
  */

PopupChi::~PopupChi()
{
    delete ui;
}

void PopupChi::on_pushButton_SetChi_clicked()
{
    close();
}
