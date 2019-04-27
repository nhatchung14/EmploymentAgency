// This is the header for account insertion

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

#include <signup_recruit.h>
#include <signup_apply.h>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    bool emailExisted(QString &email);
    int getCount();          // this function returns the number of insertions

    ~SignUp();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::SignUp *ui;
    SignUp_recruit *ui_rec;
    SignUp_apply   *ui_app;

    int counter; // count number of insertions
};

#endif // SIGNUP_H
