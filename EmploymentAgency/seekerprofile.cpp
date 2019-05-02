#include "seekerprofile.h"
#include "ui_seekerprofile.h"
#include "mainwindow.h"

seekerprofile::seekerprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seekerprofile)
{
    ui->setupUi(this);
    if(true){}
}

seekerprofile::~seekerprofile()
{
    delete ui;
}




void seekerprofile::on_pushButton_clicked()
{

    MainWindow mainwin;
    QString temp;

    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(mainwin.db);

    qry->prepare("select id from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->line_edit_id->setText(temp);
        id = temp.toInt();
    }

    qry->prepare("select email from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->line_edit_email->setText(temp);
    }

    qry->prepare("select gender from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->line_edit_gender->setText(temp);
    }

    qry->prepare("select date_of_birth from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->line_edit_dob->setText(temp);
    }

    qry->prepare("select phone_number from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->line_edit_phone->setText(temp);
    }

    qry->prepare("select registration_date from login_account where email=:email");

    qry->bindValue(":email", email);

    if(qry->exec()){
        qry->first();
        temp = qry->value(0).toString();
        ui->line_edit_registration_date->setText(temp);
    }

    qDebug() << (model->rowCount());
}

void seekerprofile::setEmail(QString n){
    email = n;
}

void seekerprofile::on_pushButton_2_clicked()
{
    this->hide();
    edu = new add_education(this);
    edu->setID(id);
    edu->setModal(true);
    edu->exec();
}

void seekerprofile::on_pushButton_3_clicked()
{
    this->hide();
    exp = new add_experience(this);
    exp->setID(id);
    exp->setModal(true);
    exp->exec();
}
