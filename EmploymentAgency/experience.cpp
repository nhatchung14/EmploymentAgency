#include "experience.h"
#include "ui_experience.h"
#include "seekerprofile.h"

experience::experience(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::experience)
{
    ui->setupUi(this);
}

experience::~experience()
{
    delete ui;
}

void experience::on_pushButton_clicked()
{
    //getting the data
    QString company = ui->lineEdit_company->text();
    QString job = ui->lineEdit_job->text();
    QString addr = ui->lineEdit_work_address->text();
    QDate start = ui->dateEdit_start->date();
    QDate end = ui->dateEdit_end->date();
    QString details = ui->textEdit_details->toPlainText();

    //setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO experience_info(seeker_id, company_name, job_title, work_address, start_date, end_date, other_details)")
                          + QString("VALUES(:seeker_id, :company_name, :job_title, :work_address, :start_date, :end_date, :other_details)"));
    query.bindValue(":seeker_id", id);
    query.bindValue(":company_name", company);
    query.bindValue(":job_title", job);
    query.bindValue(":work_address", addr);
    query.bindValue(":start_date", start);
    query.bindValue(":end_date", end);
    query.bindValue(":other_details", details);

    if (query.exec()) {
        // successfull query will insert the new entry
        hide();
        ((seekerprofile*) parentWidget())->loadExperience();
        parentWidget()->show();

        delete ui;
    } else
        qDebug() << "signup_apply.cpp query unsuccessful";
}


void experience::setID(int i){
    id = i;
}
