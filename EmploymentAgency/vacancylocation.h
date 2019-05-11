#ifndef VACANCYLOCATION_H
#define VACANCYLOCATION_H

#include <QDialog>

namespace Ui {
class VacancyLocation;
}

class VacancyLocation : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyLocation(QWidget *parent = nullptr, int vacancy_id = -1);
    ~VacancyLocation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VacancyLocation *ui;
    int vid;
};

#endif // VACANCYLOCATION_H
