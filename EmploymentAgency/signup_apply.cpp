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
    // setting up database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Gigster1409");
    db.setDatabaseName("employment_agency_v1.0");

    // getting the data
    QString name = ui->lineEdit_name->text();
    QString details = ui->textEdit_description->toPlainText();

    if (db.open()) {
        // setting up INSERT query
        QSqlQuery query;
        query.prepare("INSERT INTO seekers(seeker_id, name, CV, other_details)"
                                "VALUES(:seeker_id, :name, :CV, :other_details)");

        query.bindValue(":seeker_id", ((SignUp*)parentWidget())->getCount());
        query.bindValue(":name", name);
        query.bindValue(":CV", NULL);
        query.bindValue(":other_details", details);

        query.exec();
    }
}
