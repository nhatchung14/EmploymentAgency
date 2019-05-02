#ifndef ADD_EXPERIENCE_H
#define ADD_EXPERIENCE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class add_experience;
}

class add_experience : public QDialog
{
    Q_OBJECT

public:
    explicit add_experience(QWidget *parent = nullptr);
    ~add_experience();
    void setID(int);
    int id;

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_experience *ui;
};

#endif // ADD_EXPERIENCE_H
