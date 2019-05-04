#include "recruiterprofile.h"
#include "ui_recruiterprofile.h"
#include "mainwindow.h"

recruiterprofile::recruiterprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recruiterprofile)
{
    ui->setupUi(this);
    //LoadRecruiterProf(); // return many QSqlQuery::value: not positioned on a valid record
    if(true) {}
}

recruiterprofile::~recruiterprofile()
{
    delete ui;
}

void recruiterprofile::setEmail(QString Email)
{
    email = Email;
}

void recruiterprofile::LoadRecruiterProf()
{
    MainWindow mainwin;
    QString temp;

    QSqlQuery* qry = new QSqlQuery(mainwin.db);

    qry->prepare("select id from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->lineEdit_id->setText(temp);
        id = temp.toInt();
    }

    qry->prepare("select email from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->lineEdit_email->setText(temp);
    }

    qry->prepare("select gender from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->lineEdit_gender->setText(temp);
    }

    qry->prepare("select date_of_birth from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->lineEdit_dob->setText(temp);
    }

    qry->prepare("select phone_number from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->lineEdit_phone->setText(temp);
    }

    qry->prepare("select registration_date from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->lineEdit_regdate->setText(temp);
    }
}

void recruiterprofile::on_pushButton_loadprof_clicked()
{
    LoadRecruiterProf();
}

void recruiterprofile::on_pushButton_addVancancy_clicked()
{
    hide();
    auto vacancy = new add_vacancy(this);
    vacancy->setRecruiterID(id);
    vacancy->setModal(true);
    vacancy->exec();
}
