#ifndef SEEKERPROFILE_H
#define SEEKERPROFILE_H

#include <QDialog>
#include "education.h"
#include "experience.h"
#include "search.h"

namespace Ui {
class seekerprofile;
}

class seekerprofile : public QDialog
{
    Q_OBJECT

public:
    // there will be two perspectives,
    // | 0 will be interactive
    // | 1 will be non-interactive

    explicit seekerprofile(QWidget *parent = nullptr, int id = -1, int perspective = 0);
    ~seekerprofile();
    void loadProfile();
    void loadEducation();
    void loadExperience();
    int getID();
    void setSession(int ID);

private slots:

    void on_pushButton_addEduInfo_clicked();

    void on_pushButton_addExpInfo_clicked();

    void on_pushButton_reload_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_editMode_clicked();

    void on_pushButton_delEduInfo_clicked();

    void on_pushButton_delExpInfo_clicked();

private:
    Ui::seekerprofile *ui;

    QSqlQueryModel *edu_model;
    QSqlQueryModel *exp_model;

    Search      *searcher;

    int sessionID;
    int editMode; // 1 is read-only, 0 is read/write
    int id;
};

#endif // SEEKERPROFILE_H
