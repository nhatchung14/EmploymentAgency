#ifndef ADD_VACANCY_H
#define ADD_VACANCY_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class add_vacancy;
}

class add_vacancy : public QDialog
{
    Q_OBJECT

public:
    explicit add_vacancy(QWidget *parent = nullptr);
    ~add_vacancy();
    void setRecruiterID(int);

private slots:
    void on_pushButton_add_vacancy_clicked();

    void on_pushButton_back_clicked();

    // Get Vacancy ID
    void CounterInit();

private:
    Ui::add_vacancy *ui;

    // counter for vacancy
    int counter;

    int idRecruiter;

};

#endif // ADD_VACANCY_H
