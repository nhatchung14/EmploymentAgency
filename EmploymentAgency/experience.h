#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class experience;
}

class experience : public QDialog
{
    Q_OBJECT

public:
    explicit experience(QWidget *parent = nullptr);
    ~experience();
    void setID(int);
    int id;

private slots:
    void on_pushButton_clicked();

private:
    Ui::experience *ui;
};

#endif // EXPERIENCE_H
