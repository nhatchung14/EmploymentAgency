#ifndef RECRUITERPROFILE_H
#define RECRUITERPROFILE_H

#include <QDialog>
#include "add_vacancy.h"

namespace Ui {
class recruiterprofile;
}

class recruiterprofile : public QDialog
{
    Q_OBJECT

public:
    explicit recruiterprofile(QWidget *parent = nullptr);
    ~recruiterprofile();
    void setEmail(QString);
    int id;

private slots:
    void on_pushButton_loadprof_clicked();

    void on_pushButton_addVancancy_clicked();

private:
    Ui::recruiterprofile *ui;
    void LoadRecruiterProf();
    QString email;
};

#endif // RECRUITERPROFILE_H
