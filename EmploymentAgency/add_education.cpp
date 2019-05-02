#include "add_education.h"
#include "ui_add_education.h"
#include "mainwindow.h"

add_education::add_education(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_education)
{
    ui->setupUi(this);
}

add_education::~add_education()
{
    delete ui;
}

void add_education::on_pushButton_clicked()
{
    //getting the data
    QString degree = ui->lineEdit_degree->text();
    QString major = ui->lineEdit_major->text();
    QString school = ui->lineEdit_school->text();
    QString gpa = ui->lineEdit_gpa->text();
    QString details = ui->textEdit_other->toPlainText();

    //setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO education_info(seeker_id, degree_name, major, school_name, gpa, other_details)")
                          + QString("VALUES(:seeker_id, :degree_name, :major, :school_name, :gpa, :other_details)"));
    query.bindValue(":seeker_id", id);
    query.bindValue(":degree_name", degree);
    query.bindValue(":major", major);
    query.bindValue(":school_name", school);
    query.bindValue(":gpa", gpa);
    query.bindValue(":other_details", details);

    if (query.exec()) {
        // successfull query will insert the new entry
        hide();
        parentWidget()->show();
    } else
        qDebug() << "signup_apply.cpp query unsuccessful";
}

void add_education::setID(int i){
    id = i;
}
