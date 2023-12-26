#include "popupchi.h"
#include "ui_popupchi.h"
#include "QDate"

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

    connect(this, &PopupChi::finished, this, [this](){
        emit dataAvaiable(QString(ui->label_date_selected->text()).mid(0,2), QString(ui->plainTextEdit_5->toPlainText()), QString(ui->comboBox_2->currentText()), QString(ui->plainTextEdit_4->toPlainText()));
    });

    this->setFixedSize(QSize(240,227));
    this->setWindowTitle("Dữ liệu chi");
    QDate date = QDate::currentDate();
    QString current_date = date.toString("dd/MM/yyyy");
    ui->label_date_selected->setText(current_date);
}

PopupChi::~PopupChi()
{
    delete ui;
}

void PopupChi::on_pushButton_SetChi_clicked()
{
    close();
}

void PopupChi::ShowCalendarSelection()
{
    ui->PopupselectDay->setGeometry(QRect(30,10, 190, 71));
    QDate date = QDate::currentDate();
    QString current_date = date.toString("dd/MM/yyyy");
    ui->label_date_select->setText(current_date);
    today = date.toString("dd").toInt() ;
}

void PopupChi::BackDayinCalendar()
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
    ui->label_date_select->setText(total_date);
}

void PopupChi::NextDayinCalendar()
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
    ui->label_date_select->setText(total_date);
}
void PopupChi::SetDateCalendar()
{
    if (total_date == "")
    {
        QDate date = QDate::currentDate();
        total_date = date.toString("dd/MM/yyyy");
    }
    ui->label_date_selected->setText(total_date);
    ui->PopupselectDay->setGeometry(QRect(310,40, 190, 71));


}
