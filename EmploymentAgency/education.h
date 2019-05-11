#ifndef EDUCATION_H
#define EDUCATION_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class education;
}

class education : public QDialog
{
    Q_OBJECT

public:
    explicit education(QWidget *parent = nullptr);
    ~education();
    int id;
    void setID(int);


private slots:
    void on_pushButton_clicked();

private:
    Ui::education *ui;
};

#endif // EDUCATION_H
