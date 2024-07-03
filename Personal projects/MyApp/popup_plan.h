#ifndef POPUP_PLAN_H
#define POPUP_PLAN_H

#include <QDialog>
#include "QDate"

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
    void ConnectDataPlanning(const QString &lsDataDatePlanning, const QString &lsDataTimePlanning, const QString &data_textdetail_plan);

public slots:
    void ShowCalendarSelection(void);
    void BackDayinCalendar(void);
    void NextDayinCalendar(void);
    void SetDateCalendar(void);

private slots:
    void on_pushButton_SetPlan_clicked();

private:
    Ui::Popup_Plan *ui;
    int giToday = 0;
    QString gsSettingDate;
};

#endif // POPUP_PLAN_H
