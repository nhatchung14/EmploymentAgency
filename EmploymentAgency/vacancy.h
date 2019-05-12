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
    void setReadOnly();
    void setSession(int ID, int Type);
    void loadLocations();
    void closeLocationButtons();

private slots:
    void on_pushButton_add_vacancy_clicked();

    void on_pushButton_back_clicked();

    // Get Vacancy ID
    void CounterInit();

    void on_pushButton_apply_clicked();

    void on_pushButton_del_location_clicked();

    void on_pushButton_add_location_clicked();

    void on_pushButton_reload_clicked();

private:
    Ui::vacancy *ui;
    QSqlQueryModel *location_model;

    // counter for vacancy
    int counter;

    // this applies if the vacancy exists
    int id;              // id of the vacancy

    // this applies if the vacancy is in adding mode
    int idRecruiter;

    // the session info
    int sessionID, sessionType;
};

#endif // VACANCY_H
