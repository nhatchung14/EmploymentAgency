#include "vacancylocation.h"
#include "ui_vacancylocation.h"
#include "vacancy.h"
#include <QSqlQuery>

VacancyLocation::VacancyLocation(QWidget *parent, int vacancy_id) :
    QDialog(parent),
    ui(new Ui::VacancyLocation)
{
    ui->setupUi(this);

    vid = vacancy_id;
}

VacancyLocation::~VacancyLocation()
{
    delete ui;
}

void VacancyLocation::on_pushButton_clicked()
{
    QString addr = ui->lineEdit_addr->text();
    QString ward = ui->lineEdit_ward->text();
    QString district = ui->lineEdit_district->text();
    QString city = ui->lineEdit_city->text();
    if (addr.size() > 0 && district.size() > 0 && city.size() > 0) {
        QSqlQuery query;
        query.prepare("INSERT INTO vacancy_location(vacancy_id, street_addr, ward, district, city, other_details) VALUES (:vid, :addr, :ward, :district, :city, NULL)");
        query.bindValue(":vid", this->vid);
        query.bindValue(":addr", addr);
        query.bindValue(":ward", ward);
        query.bindValue(":district", district);
        query.bindValue(":city", city);
        if (query.exec()) {
            hide();
            ((vacancy*) parentWidget())->loadLocations();
            parentWidget()->show();
            delete ui;
        }
    }
}
