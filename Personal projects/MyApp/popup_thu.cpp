#include "popup_thu.h"
#include "ui_popup_thu.h"
#include "QDate"

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
    connect(this, &popup_Thu::finished, this, [this](){
        emit dataAvaiable_Thu(QString(ui->label_date_selected_Thu->text()).mid(0,2), QString(ui->plainTextEdit_3->toPlainText()), QString(ui->comboBox->currentText()) , QString(ui->plainTextEdit_2->toPlainText()));
    });

    connect(ui->pushButton_Selectday_Thu, SIGNAL(clicked(bool)), this, SLOT(ShowCalendarSelection()));
    connect(ui->pushButton_back_day_Thu, SIGNAL(clicked(bool)), this, SLOT(BackDayinCalendar()));
    connect(ui->pushButton_next_day_Thu, SIGNAL(clicked(bool)), this, SLOT(NextDayinCalendar()));
    connect(ui->pushButton_SelectedDay_Thu, SIGNAL(clicked(bool)), this, SLOT(SetDateCalendar()));


    this->setFixedSize(QSize(240,227));
    this->setWindowTitle("Dữ liệu Thu");
    QDate date = QDate::currentDate();
    QString current_date = date.toString("dd/MM/yyyy");
    ui->label_date_selected_Thu->setText(current_date);
}

popup_Thu::~popup_Thu()
{
    delete ui;
}

void popup_Thu::on_pushButton_SetThu_clicked()
{
    close();
}

void popup_Thu::ShowCalendarSelection()
{
    ui->PopupselectDay_Thu->setGeometry(QRect(30,10, 190, 71));
    QDate date = QDate::currentDate();
    QString current_date = date.toString("dd/MM/yyyy");
    ui->label_date_select_Thu->setText(current_date);
    today = date.toString("dd").toInt() ;
}

void popup_Thu::BackDayinCalendar()
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

void popup_Thu::NextDayinCalendar()
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
void popup_Thu::SetDateCalendar()
{
    if (total_date == "")
    {
        QDate date = QDate::currentDate();
        total_date = date.toString("dd/MM/yyyy");
    }
    ui->label_date_selected_Thu->setText(total_date);
    ui->PopupselectDay_Thu->setGeometry(QRect(310,40, 190, 71));


}
