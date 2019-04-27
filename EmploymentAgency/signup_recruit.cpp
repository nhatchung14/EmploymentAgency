#include "signup_recruit.h"
#include "ui_signup_recruit.h"
#include "signup.h"

SignUp_recruit::SignUp_recruit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp_recruit)
{
    ui->setupUi(this);
}

SignUp_recruit::~SignUp_recruit()
{
    delete ui;
}

void SignUp_recruit::on_pushButton_finish_clicked()
{
    // getting the data
    QString company = ui->lineEdit_company->text();
    QString name  = ui->lineEdit_name->text();
    QString title = ui->lineEdit_title->text();
    QString url  = ui->lineEdit_url->text();
    QString details = ui->textEdit_details->toPlainText();

    // setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO recruiter(recruiter_id, name, job_title, from_company, company_description, company_image, company_url)")
                          +  QString("VALUES(:recruiter_id, :name, :job_title, :from_company, :company_description, :company_image, :company_url)"));

    query.bindValue(":recruiter_id", ((SignUp*)parentWidget())->getCount());
    query.bindValue(":name", name);
    query.bindValue(":job_title", title);
    query.bindValue(":from_company", company);
    query.bindValue(":company_description", details);
    query.bindValue(":company_image", NULL);
    query.bindValue(":company_url", url);

    if (query.exec()) {
        // successfull query will insert the new entry

        hide();
        parentWidget()->parentWidget()->show();
    } else
        qDebug() << "signup_recruit.cpp query unsuccessful";

}
