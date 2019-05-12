#include "education.h"
#include "ui_education.h"
#include "seekerprofile.h"

education::education(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::education)
{
    ui->setupUi(this);
}

education::~education()
{
    delete ui;
}

void education::on_pushButton_clicked()
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
    if (gpa != "")
        query.bindValue(":gpa", gpa.toFloat());
    else
        query.bindValue(":gpa", 0.0);
    query.bindValue(":other_details", details);

    if (query.exec()) {
        // successfull query will insert the new entry
        hide();
        ((seekerprofile*) parentWidget())->loadEducation();
        parentWidget()->show();
        delete ui;
    } else
        qDebug() << "signup_apply.cpp query unsuccessful";
}

void education::setID(int i){
    id = i;
}
