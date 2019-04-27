#include "signup_apply.h"
#include "ui_signup_apply.h"
#include "signup.h"

SignUp_apply::SignUp_apply(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp_apply)
{
    ui->setupUi(this);
}

SignUp_apply::~SignUp_apply()
{
    delete ui;
}

void SignUp_apply::on_pushButton_finish_clicked()
{
    // getting the data
    QString name = ui->lineEdit_name->text();
    QString details = ui->textEdit_description->toPlainText();

    // setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO seeker(seeker_id, name, CV, other_details)")
                          + QString("VALUES(:seeker_id, :name, :CV, :other_details)"));

    query.bindValue(":seeker_id", ((SignUp*) parentWidget())->getCount());
    query.bindValue(":name", name);
    query.bindValue(":CV", NULL);
    query.bindValue(":other_details", details);

    if (query.exec()) {
        // successfull query will insert the new entry

        hide();
        parentWidget()->parentWidget()->show();
    } else
        qDebug() << "signup_apply.cpp query unsuccessful";

}
