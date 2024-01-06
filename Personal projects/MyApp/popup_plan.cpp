#include "popup_plan.h"
#include "ui_popup_plan.h"
#include "QDate"

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
    connect(this, &Popup_Plan::finished, this, [this](){
        emit dataAvaiable_Plan(QString(ui->label_date_selected_Plan->text()).mid(0,2), QString(ui->plainTextEdit_Time->toPlainText()), QString(ui->plainTextEdit_detailPlan->toPlainText()));
    });
    this->setFixedSize(QSize(201,165));
    this->setWindowTitle("Dữ liệu Plan");

    connect(ui->pushButton_Selectday_Plan, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_back_day_Thu, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_next_day_Thu, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_SelectedDay_Thu, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));

    QDate date = QDate::currentDate();
    QString current_date = date.toString("dd/MM/yyyy");
    ui->label_date_selected_Plan->setText(current_date);
}

Popup_Plan::~Popup_Plan()
{
    delete ui;
}

void Popup_Plan::on_pushButton_SetPlan_clicked()
{
    close();
}


void Popup_Plan::ShowCalendarSelection()
{
    ui->PopupselectDay_Thu->setGeometry(QRect(5,10, 190, 71));
    QDate date = QDate::currentDate();
    QString current_date = date.toString("dd/MM/yyyy");
    ui->label_date_select_Thu->setText(current_date);
    today = date.toString("dd").toInt() ;
}

void Popup_Plan::BackDayinCalendar()
{
    today--;
    QString today_string = QString::number(today);
    QDate day = QDate::currentDate();
    QString tomonth = day.toString("MM");
    QString toyear = day.toString("yyyy");
    if (today < 10)
        total_date = "0" + today_string  + "/" + tomonth + "/" + toyear;
    else
        total_date = today_string  + "/" + tomonth + "/" + toyear;
    ui->label_date_select_Thu->setText(total_date);
}

void Popup_Plan::NextDayinCalendar()
{
    today++;
    QString today_string = QString::number(today);
    QDate day = QDate::currentDate();
    QString tomonth = day.toString("MM");
    QString toyear = day.toString("yyyy");
    if (today < 10)
        total_date = "0" + today_string  + "/" + tomonth + "/" + toyear;
    else
        total_date = today_string  + "/" + tomonth + "/" + toyear;
    ui->label_date_select_Thu->setText(total_date);
}
void Popup_Plan::SetDateCalendar()
{
    if (total_date == "")
    {
        QDate date = QDate::currentDate();
        total_date = date.toString("dd/MM/yyyy");
    }
    ui->label_date_selected_Plan->setText(total_date);
    ui->PopupselectDay_Thu->setGeometry(QRect(310,40, 190, 71));


}
