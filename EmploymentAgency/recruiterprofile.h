#ifndef RECRUITERPROFILE_H
#define RECRUITERPROFILE_H

#include <QDialog>
#include "vacancy.h"
#include "search.h"

namespace Ui {
class recruiterprofile;
}

class recruiterprofile : public QDialog
{
    Q_OBJECT

public:
    // there will be two perspectives,
    // | 0 will be interactive
    // | 1 will be non-interactive

    explicit recruiterprofile(QWidget *parent = nullptr, int id = -1, int perspective = -1);
    ~recruiterprofile();
    void loadProfile();
    void loadVacancies();
    void loadJobApplications();
    void setSession(int ID);

private slots:
    void on_pushButton_reload_clicked();

    void on_pushButton_addVacancy_clicked();

    void on_pushButton_delVacancy_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_editMode_clicked();

    void on_tableView_vacancies_doubleClicked(const QModelIndex &index);

private:
    Ui::recruiterprofile *ui;
    QSqlQueryModel *vacancy_model;
    QSqlQueryModel *applicant_model;

    vacancy *vacancy_;
    Search *searcher;

    int editMode; // 1 is read-only, 0 is read/write
    int perspective; // -1 is owner, 0 is standard_view, 1 is seeker_view

    int sessionID;
    int id;
};

#endif // RECRUITERPROFILE_H
