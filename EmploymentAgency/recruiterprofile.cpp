#include "recruiterprofile.h"
#include "ui_recruiterprofile.h"

#include "seekerprofile.h"
#include <QMessageBox>

recruiterprofile::recruiterprofile(QWidget *parent, int id, int perspective) :
    QDialog(parent),
    ui(new Ui::recruiterprofile)
{
    ui->setupUi(this);

    // set the id
    this->id = id;

    // models for table views
    vacancy_model = new QSqlQueryModel();
    ui->tableView_vacancies->setSelectionBehavior(QAbstractItemView::SelectRows); // select items as rows
    applicant_model = new QSqlQueryModel();
    ui->tableView_application->setSelectionBehavior(QAbstractItemView::SelectRows);

    // loading information
    loadProfile();
    loadVacancies();
    loadJobApplications();

    // only the owner of the profile can click these buttons
    this->perspective = perspective;
    if (perspective != -1) {
        // close all buttons
        ui->pushButton_logout->close();
        ui->pushButton_search->close();
        ui->pushButton_addVacancy->close();
        ui->pushButton_delVacancy->close();
        ui->pushButton_editMode->close();
    }

    // set to read-only
    editMode = 1;
}

recruiterprofile::~recruiterprofile()
{
    delete ui;
}

void recruiterprofile::setSession(int ID) {
    this->sessionID = ID;
}

void recruiterprofile::loadProfile()
{
    QSqlQuery qry;

    qry.prepare("SELECT L.email, L.gender, L.date_of_birth, L.phone_number, L.registration_date, R.name, R.job_title, R.from_company, R.company_description, R.company_url FROM login_account L, recruiter R WHERE L.id = R.recruiter_id AND L.id = :id");
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

        // job title
        QString title = qry.value(6).toString();
        ui->lineEdit_title->setText(title);

        // company
        QString company = qry.value(7).toString();
        ui->lineEdit_company->setText(company);

        // short description
        QString description = qry.value(8).toString();
        ui->plainTextEdit_description->setPlainText(description);

        // company url
        QString url = qry.value(9).toString();
        ui->lineEdit_url->setText(url);
    } else {
        qDebug() << "recruiterprofile.cpp query failed";
    }
}

void recruiterprofile::loadVacancies() {

    QSqlQuery query;
    query.prepare("SELECT vacancy_id, position, published_date, closed_date FROM vacancy WHERE recruiter_id=:id");
    query.bindValue(":id", this->id);
    query.exec();

    // set query for the model
    vacancy_model->setQuery(query);

    // finally setting the model for tableView
    ui->tableView_vacancies->setModel(vacancy_model);
}

void recruiterprofile::loadJobApplications() {
    QSqlQuery query;
    query.prepare("SELECT L.email, V.position FROM job_application J, login_account L, vacancy V WHERE J.seeker_id = L.id AND J.vacancy_id = V.vacancy_id AND V.recruiter_id = :rec_id");
    query.bindValue(":rec_id", this->id);
    if (!query.exec()) {
        qDebug() << "Failed to load applications";
    }

    // set query for the model
    applicant_model->setQuery(query);

    // finally setting the model for tableView
    ui->tableView_application->setModel(applicant_model);
}

void recruiterprofile::on_pushButton_reload_clicked()
{
    loadProfile();
    loadVacancies();
    loadJobApplications();
}

void recruiterprofile::on_pushButton_addVacancy_clicked()
{
    hide();
    vacancy_ = new vacancy(this);
    vacancy_->setRecruiterID(id);
    vacancy_->setSession(this->sessionID);
    vacancy_->show();
}

void recruiterprofile::on_pushButton_delVacancy_clicked()
{
    if (ui->tableView_vacancies->selectionModel()->currentIndex().isValid()) {
        int rowidx = ui->tableView_vacancies->selectionModel()->currentIndex().row();
        QMessageBox::information(this, "Call", vacancy_model->index(rowidx, 0).data().toString());
        QSqlQuery qry;

        qry.prepare("DELETE FROM vacancy WHERE vacancy_id = :id");
        qry.bindValue(":id", vacancy_model->index(rowidx , 0).data().toString());
        qry.exec();
    }
}

void recruiterprofile::on_pushButton_search_clicked()
{
    this->hide();
    searcher = new Search(this);
    searcher->setSession(this->sessionID);
    searcher->show();
}

void recruiterprofile::on_pushButton_logout_clicked()
{
    this->hide();
    parentWidget()->show();
    delete ui;
}

void recruiterprofile::on_pushButton_editMode_clicked()
{
    editMode ^= 1;

    // set edit mode accordingly
    ui->lineEdit_dob->setReadOnly(editMode);
    ui->lineEdit_url->setReadOnly(editMode);
    ui->lineEdit_name->setReadOnly(editMode);
    ui->lineEdit_phone->setReadOnly(editMode);
    ui->lineEdit_gender->setReadOnly(editMode);
    ui->lineEdit_company->setReadOnly(editMode);
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
        if (query.exec()) {
            qDebug() << "query 1 executed";
        }

        // query two
        query.prepare("UPDATE recruiter SET name = :name, job_title = :job_title, from_company = :from_company, company_description = :company_description, company_url = :url WHERE recruiter_id = :id");
        query.bindValue(":name", ui->lineEdit_name->text());
        query.bindValue(":job_title", ui->lineEdit_title->text());
        query.bindValue(":from_company", ui->lineEdit_company->text());
        query.bindValue(":company_description", ui->plainTextEdit_description->toPlainText());
        query.bindValue(":url", ui->lineEdit_url->text());
        query.bindValue(":id", this->id);

        ui->pushButton_editMode->setText("Read");
    } else {
        ui->pushButton_editMode->setText("Write");
    }
}

void recruiterprofile::on_tableView_vacancies_doubleClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        int rowidx = ui->tableView_vacancies->selectionModel()->currentIndex().row(); // get the selected row

        int id = vacancy_model->index(rowidx , 0).data().toInt();

        // get `id` from the selected row
        vacancy *cur = new vacancy(this);
        cur->setSession(this->sessionID);

        cur->setID(id);

        if (perspective != 1) { // standard view
            cur->closeButton_1();
            cur->setPerspective(0); // perspective argument will be max(0, perspective)
            if (this->id != this->sessionID)
                cur->closeButtons_2();
        }
        else {
            // seeker view
            cur->setPerspective(1);
            cur->closeButtons_2();
        }
        cur->setModal(true);
        cur->exec();
    }
}
