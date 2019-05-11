#ifndef VACANCY_H
#define VACANCY_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class vacancy;
}

class vacancy : public QDialog
{
    Q_OBJECT

public:
    explicit vacancy(QWidget *parent = nullptr);
    ~vacancy();
    void setRecruiterID(int);
    void setID(int);
    void setPerspective(int);
    void setReadOnly();
    void setSession(int ID);
    void loadLocations();
    void closeButton_1();
    void closeButtons_2();

private slots:
    void on_pushButton_add_vacancy_clicked();

    void on_pushButton_back_clicked();

    // Get Vacancy ID
    void CounterInit();

    void on_pushButton_apply_clicked();

    void on_pushButton_del_location_clicked();

    void on_pushButton_add_location_clicked();

private:
    Ui::vacancy *ui;
    QSqlQueryModel *location_model;

    // counter for vacancy
    int counter;

    // these two applies if the vacancy exists
    int id;              // id of the vacancy
    int perspective = 0; // 0 is standard, 1 is the seeker view

    // if the session belongs to the owner
    int idRecruiter;

    // `ID` of the session
    int sessionID;
};

#endif // VACANCY_H
