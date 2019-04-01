#ifndef SIGNUP_APPLY_H
#define SIGNUP_APPLY_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class SignUp_apply;
}

class SignUp_apply : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp_apply(QWidget *parent = nullptr);
    ~SignUp_apply();

private slots:
    void on_pushButton_finish_clicked();

private:
    Ui::SignUp_apply *ui;
};

#endif // SIGNUP_APPLY_H
