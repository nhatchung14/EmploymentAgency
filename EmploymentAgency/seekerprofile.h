#ifndef SEEKERPROFILE_H
#define SEEKERPROFILE_H

#include <QDialog>
#include"add_education.h"
#include"add_experience.h"


namespace Ui {
class seekerprofile;
}

class seekerprofile : public QDialog
{
    Q_OBJECT

public:
    explicit seekerprofile(QWidget *parent = nullptr);
    ~seekerprofile();
    void setEmail(QString);
    QString email;
    int id;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::seekerprofile *ui;
    add_education *edu;
    add_experience *exp;
};

#endif // SEEKERPROFILE_H
