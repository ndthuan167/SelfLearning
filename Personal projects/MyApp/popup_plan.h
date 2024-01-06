#ifndef POPUP_PLAN_H
#define POPUP_PLAN_H

#include <QDialog>

namespace Ui {
class Popup_Plan;
}

class Popup_Plan : public QDialog
{
    Q_OBJECT

public:
    explicit Popup_Plan(QWidget *parent = nullptr);
    Popup_Plan(QWidget *parent = nullptr, QString message = "default");

    ~Popup_Plan();

signals:
    void dataAvaiable_Plan(const QString &data_textday_plan, const QString &data_texttime_plan, const QString &data_textdetail_plan);

public slots:
    void ShowCalendarSelection();
    void BackDayinCalendar();
    void NextDayinCalendar();
    void SetDateCalendar();

private slots:
    void on_pushButton_SetPlan_clicked();

private:
    Ui::Popup_Plan *ui;
    int today = 0;
    QString total_date;
};

#endif // POPUP_PLAN_H
