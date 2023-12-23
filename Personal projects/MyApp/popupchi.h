#ifndef POPUPCHI_H
#define POPUPCHI_H

#include <QDialog>

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
    void dataAvaiable(const QString &data_textday, const QString &data_textmoney, const QString &data_texttype, const QString &data_textcontent);
private slots:
    void on_pushButton_SetChi_clicked();

public slots:
    void ShowCalendarSelection();
    void BackDayinCalendar();
    void NextDayinCalendar();
    void SetDateCalendar();

private:
    Ui::PopupChi *ui;
    int today = 0;
    QString total_date;


};

#endif // POPUPCHI_H
