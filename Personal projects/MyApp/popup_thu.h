#ifndef POPUP_THU_H
#define POPUP_THU_H

#include <QDialog>

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
    void dataAvaiable_Thu(const QString &data_textday_thu, const QString &data_textmoney_thu, const QString &data_texttype_thu , const QString &data_textcontent_thu);

private slots:
    void on_pushButton_SetThu_clicked();

public slots:
    void ShowCalendarSelection();
    void BackDayinCalendar();
    void NextDayinCalendar();
    void SetDateCalendar();

private:
    Ui::popup_Thu *ui;
    int today = 0;
    QString total_date;
};

#endif // POPUP_THU_H
