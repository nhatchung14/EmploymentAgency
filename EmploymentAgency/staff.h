#ifndef STAFF_H
#define STAFF_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Staff;
}

class Staff : public QDialog
{
    Q_OBJECT

public:
    explicit Staff(QWidget *parent = nullptr, int id = -1);
    ~Staff();

private slots:
    void on_pushButton_run_clicked();

    void on_pushButton_logout_clicked();

private:
    Ui::Staff *ui;
    QSqlQueryModel *model;

    int id;
};

#endif // STAFF_H
