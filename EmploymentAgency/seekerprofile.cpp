#include "seekerprofile.h"
#include "ui_seekerprofile.h"

seekerprofile::seekerprofile(QWidget *parent, int id, int perspective) :
    QDialog(parent),
    ui(new Ui::seekerprofile)
{
    ui->setupUi(this);

    // inilization
    this->id = id;

    exp_model = new QSqlQueryModel();
    edu_model = new QSqlQueryModel();
    ui->tableView_experience->setSelectionBehavior(QAbstractItemView::SelectRows); // select items as rows
    ui->tableView_education->setSelectionBehavior(QAbstractItemView::SelectRows); // select items as rows

    // loading date
    loadProfile();
    loadEducation();
    loadExperience();

    //
    if (perspective == 1) {
        // close all buttons
        ui->pushButton_logout->close();
        ui->pushButton_search->close();
        ui->pushButton_addEduInfo->close();
        ui->pushButton_delEduInfo->close();
        ui->pushButton_addExpInfo->close();
        ui->pushButton_delExpInfo->close();
        ui->pushButton_editMode->close();
    }

    // edit mode is initially read-only
    editMode = 1;
}

seekerprofile::~seekerprofile()
{
    delete ui;
}

void seekerprofile::setSession(int ID) {
    this->sessionID = ID;
}

void seekerprofile::loadProfile()
{
    QSqlQuery qry;

    qry.prepare("SELECT L.email, L.gender, L.date_of_birth, L.phone_number, L.registration_date, S.name, S.other_details FROM login_account L, seeker S WHERE L.id = S.seeker_id AND L.id = :id");
    qry.bindValue(":id", this->id);

    // retrieving info
    if(qry.exec() && qry.first()){
        // email
        QString email = qry.value(0).toString();
        ui->lineEdit_email->setText(email);

        // gender
        QString gender = qry.value(1).toString();
        ui->lineEdit_gender->setText(gender);

        // dob
        QString dob = qry.value(2).toString();
        ui->lineEdit_dob->setText(dob);

        // phone number
        QString phone = qry.value(3).toString();
        ui->lineEdit_phone->setText(phone);

        // registration date
        QString regdate = qry.value(4).toString();
        ui->lineEdit_regdate->setText(regdate);

        // recruiter name
        QString name = qry.value(5).toString();
        ui->lineEdit_name->setText(name);

        // short description
        QString description = qry.value(6).toString();
        ui->plainTextEdit_description->setPlainText(description);

    } else {
        qDebug() << "seekerprofile.cpp query failed";
    }
}

void seekerprofile::loadEducation() {

    QSqlQuery query;
    query.prepare("SELECT school_name, major, degree_name FROM education_info WHERE seeker_id=:id");
    query.bindValue(":id", this->id);
    query.exec();

    // set query for the model
    edu_model->setQuery(query);

    // finally setting the model for tableView
    ui->tableView_education->setModel(edu_model);
}

void seekerprofile::loadExperience() {

    QSqlQuery query;
    query.prepare("SELECT company_name, job_title, start_date, end_date FROM experience_info WHERE seeker_id=:id");
    query.bindValue(":id", this->id);
    query.exec();

    // set query for the model
    exp_model->setQuery(query);

    // finally setting the model for tableView
    ui->tableView_experience->setModel(exp_model);
}

void seekerprofile::on_pushButton_addEduInfo_clicked()
{
    education *edu = new education(this);
    edu->setID(id);
    edu->setModal(true);
    edu->exec();
}

void seekerprofile::on_pushButton_delEduInfo_clicked()
{
    if (ui->tableView_education->selectionModel()->currentIndex().isValid()) {
        int rowidx = ui->tableView_education->selectionModel()->currentIndex().row();
        //QMessageBox::information(this, "Call", vacancy_model->index(rowidx, 0).data().toString());
        QSqlQuery qry;

        qry.prepare("DELETE FROM education_info WHERE seeker_id = :id AND school_name = :sname AND major = :major AND degree_name = :dname");
        qry.bindValue(":id", this->id);
        qry.bindValue(":sname", edu_model->index(rowidx , 0).data().toString());
        qry.bindValue(":major", edu_model->index(rowidx , 1).data().toString());
        qry.bindValue(":dname", edu_model->index(rowidx , 2).data().toString());
        qry.exec();
    }
}

void seekerprofile::on_pushButton_addExpInfo_clicked()
{
    experience *exp = new experience(this);
    exp->setID(id);
    exp->setModal(true);
    exp->exec();
}

void seekerprofile::on_pushButton_delExpInfo_clicked()
{
    if (ui->tableView_experience->selectionModel()->currentIndex().isValid()) {
        int rowidx = ui->tableView_experience->selectionModel()->currentIndex().row();
        //QMessageBox::information(this, "Call", vacancy_model->index(rowidx, 0).data().toString());
        QSqlQuery qry;

        qry.prepare("DELETE FROM experience_info WHERE seeker_id = :id AND company_name = :cname AND job_title = :title");
        qry.bindValue(":id", this->id);
        qry.bindValue(":cname", edu_model->index(rowidx , 0).data().toString());
        qry.bindValue(":title", edu_model->index(rowidx , 1).data().toString());
        qry.exec();
    }
}

void seekerprofile::on_pushButton_reload_clicked()
{
    loadProfile();
    loadEducation();
    loadExperience();
}

void seekerprofile::on_pushButton_search_clicked()
{
    this->hide();
    searcher = new Search(this, 1);
    searcher->setSession(this->sessionID);
    searcher->show();
}

void seekerprofile::on_pushButton_logout_clicked()
{
    this->hide();
    parentWidget()->show();
    delete ui;
}

void seekerprofile::on_pushButton_editMode_clicked()
{
    editMode ^= 1;

    // set edit mode accordingly
    ui->lineEdit_dob->setReadOnly(editMode);
    ui->lineEdit_name->setReadOnly(editMode);
    ui->lineEdit_phone->setReadOnly(editMode);
    ui->lineEdit_gender->setReadOnly(editMode);
    ui->plainTextEdit_description->setReadOnly(editMode);
    if (editMode == 1) {
        QSqlQuery query;
        // query one
        query.prepare("UPDATE login_account SET gender = :gender, date_of_birth = :date_of_birth, phone_number = :phone_number WHERE id = :id");
        query.bindValue(":gender", ui->lineEdit_gender->text());
        query.bindValue(":date_of_birth", ui->lineEdit_dob->text());
        query.bindValue(":phone_number", ui->lineEdit_phone->text());
        query.bindValue(":id", this->id);
        query.exec();

        // query two
        query.prepare("UPDATE seeker SET name = :name, other_details = :description WHERE seeker_id = :id");
        query.bindValue(":name", ui->lineEdit_name->text());
        query.bindValue(":description", ui->plainTextEdit_description->toPlainText());
        query.bindValue(":id", this->id);

        ui->pushButton_editMode->setText("Read");
    } else {
        ui->pushButton_editMode->setText("Write");
    }
}
