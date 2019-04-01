#ifndef SIGNUP_RECRUIT_H
#define SIGNUP_RECRUIT_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class SignUp_recruit;
}

class SignUp_recruit : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp_recruit(QWidget *parent = nullptr);
    ~SignUp_recruit();

private slots:
    void on_pushButton_finish_clicked();

private:
    Ui::SignUp_recruit *ui;
};

#endif // SIGNUP_RECRUIT_H
