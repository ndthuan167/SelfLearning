#ifndef POPUPCHI_H
#define POPUPCHI_H

#include <QDialog>
#include "QDate"

namespace Ui {
class PopupChi;
}

class PopupChi : public QDialog
{
    Q_OBJECT

public:
    explicit PopupChi(QWidget *parent = nullptr);
    PopupChi(QWidget *parent = nullptr, QString message = "default");
    ~PopupChi();
signals:
    void ConnectDataSpending(const QString &lsDataDateSpending, const QString &lsDataMoneySpending, const QString &lsDataMoneyTypeSpending, const QString &lsDataContentSpending);
private slots:
    void on_pushButton_SetChi_clicked();

public slots:
    void ShowCalendarSelection(void);
    void BackDayinCalendar(void);
    void NextDayinCalendar(void);
    void SetDateCalendar(void);

private:
    Ui::PopupChi *ui;
    int giToday = 0;
    QString gsSettingDate;
};

#endif // POPUPCHI_H
