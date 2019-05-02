#ifndef ADD_EDUCATION_H
#define ADD_EDUCATION_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class add_education;
}

class add_education : public QDialog
{
    Q_OBJECT

public:
    explicit add_education(QWidget *parent = nullptr);
    ~add_education();
    int id;
    void setID(int);


private slots:
    void on_pushButton_clicked();

private:
    Ui::add_education *ui;
};

#endif // ADD_EDUCATION_H
