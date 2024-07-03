#ifndef POPUP_THU_H
#define POPUP_THU_H

#include <QDialog>
#include "QDate"

namespace Ui {
class popup_Thu;
}

class popup_Thu : public QDialog
{
    Q_OBJECT

public:
    explicit popup_Thu(QWidget *parent = nullptr);
    popup_Thu(QWidget *parent = nullptr, QString message = "default");

    ~popup_Thu();

signals:
    void ConnectDataEarning(const QString &lsDataDateEaning, const QString &lsDataMoneyEaning, const QString &lsDataTypeMoneyEaning , const QString &lsDataContentEaning);

private slots:
    void on_pushButton_SetThu_clicked();

public slots:
    void ShowCalendarSelection(void);
    void BackDayinCalendar(void);
    void NextDayinCalendar(void);
    void SetDateCalendar(void);

private:
    Ui::popup_Thu *ui;
    int giToday = 0;
    QString gsSettingDate;
};

#endif // POPUP_THU_H
