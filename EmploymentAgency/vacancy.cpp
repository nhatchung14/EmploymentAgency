#include "vacancy.h"
#include "ui_vacancy.h"
#include "recruiterprofile.h"
#include "vacancylocation.h"

vacancy::vacancy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vacancy)
{
    ui->setupUi(this);

    // data view model
    location_model = new QSqlQueryModel;
    ui->tableView_locations->setSelectionBehavior(QAbstractItemView::SelectRows); // select items as rows
}

vacancy::~vacancy()
{
    delete ui;
}

void vacancy::setSession(int ID, int Type) {
    this->sessionID = ID;
    this->sessionType = Type;

    if (this->sessionType == 1) // the session belongs to a seeker
    {
        closeLocationButtons();
        ui->pushButton_add_vacancy->close();
    } else {
        ui->pushButton_apply->close();
    }
}

void vacancy::setRecruiterID(int ID)
{
    this->idRecruiter = ID;
    closeLocationButtons();
}

void vacancy::setReadOnly() {
    // read-only mode
    ui->lineEdit_position->setReadOnly(true);
    ui->lineEdit_salary->setReadOnly(true);
    ui->textEdit_bene->setReadOnly(true);
    ui->textEdit_desc->setReadOnly(true);
    ui->textEdit_require->setReadOnly(true);
    ui->textEdit_other->setReadOnly(true);
    ui->dateEdit_published->setReadOnly(true);
    ui->dateEdit_closed->setReadOnly(true);
        // check box
    ui->checkBox_nego->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->checkBox_nego->setFocusPolicy(Qt::NoFocus);
}

void vacancy::setID(int ID) {
    ui->pushButton_add_vacancy->close();

    this->id = ID;

    // get the data from database
    QSqlQuery query;
    query.prepare("SELECT position, salary, benefits, job_description, requirements, other_details, published_date, closed_date, negotiable FROM vacancy WHERE vacancy_id = :id");
    query.bindValue(":id", ID);
    if (query.exec() && query.first()) {
        // set them up
        ui->lineEdit_position->setText(query.value(0).toString());
        ui->lineEdit_salary->setText(query.value(1).toString());
        ui->textEdit_bene->setText(query.value(2).toString());
        ui->textEdit_desc->setText(query.value(3).toString());
        ui->textEdit_require->setText(query.value(4).toString());
        ui->textEdit_other->setText(query.value(5).toString());
        ui->dateEdit_published->setDate(query.value(6).toDate());
        ui->dateEdit_closed->setDate(query.value(7).toDate());
        ui->checkBox_nego->setChecked(query.value(8).toBool());
    } else {
        qDebug() << "vacancy.cpp SELECT query failed";
    }

    setReadOnly();
    loadLocations();
}

void vacancy::closeLocationButtons() {
    ui->pushButton_add_location->close();
    ui->pushButton_del_location->close();
}

void vacancy::on_pushButton_apply_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO job_application(seeker_id, vacancy_id) VALUES(:seeker_id, :vacancy_id)");
    query.bindValue(":seeker_id", this->sessionID);
    query.bindValue(":vacancy_id", this->id);
    if (!query.exec())
        qDebug() << "Job application failed.";
}

void vacancy::on_pushButton_add_vacancy_clicked()
{
    //getting the data
    QDate published = ui->dateEdit_published->date();
    QDate closed = ui->dateEdit_closed->date();
    QString position = ui->lineEdit_position->text();
    QString desc = ui->textEdit_desc->toPlainText();
    QString salary = ui->lineEdit_salary->text();
    bool    nego = ui->checkBox_nego->isChecked();
    QString require = ui->textEdit_require->toPlainText();
    QString benefit = ui->textEdit_bene->toPlainText();
    QString other = ui->textEdit_other->toPlainText();

    //setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO vacancy(vacancy_id, recruiter_id, published_date, closed_date, position, job_description, salary, negotiable, requirements, benefits, other_details)")
                          + QString("VALUES(:vacancy_id, :recruiter_id, :published_date, :closed_date, :position, :job_description, :salary, :negotiable, :requirements, :benefits, :other_details)"));

    query.bindValue(":recruiter_id", idRecruiter);
    query.bindValue(":published_date", published);
    query.bindValue(":closed_date", closed);
    query.bindValue(":position", position);
    query.bindValue(":job_description", desc);
    query.bindValue(":salary", salary);
    query.bindValue(":negotiable", nego);
    query.bindValue(":requirements", require);
    query.bindValue(":benefits", benefit);
    query.bindValue(":other_details", other);

    if (query.exec()) {
        // successfull query will insert the new entry
        hide();
        ((recruiterprofile*) parentWidget())->loadVacancies();
        parentWidget()->show();

        delete ui;
    } else
        qDebug() << "add vacancy query unsuccessful";
}

void vacancy::on_pushButton_back_clicked()
{
    hide();
    parentWidget()->show();

    delete ui;
}

void vacancy::CounterInit()
{
    QSqlQuery query;
    query.prepare("SELECT MAX(A.vacancy_id) FROM vacancy A");

    if (query.exec()) {
        if (query.next()) {
            counter = query.value(0).toInt() + 1;
            qDebug() << counter;
        }
        else {
            counter = 0;
            qDebug() << "This is %d" << counter;
        }
    } else {
        qDebug() << "Counter init failed";
    }
}

void vacancy::loadLocations() {
    QSqlQuery query;
    query.prepare("SELECT street_addr, ward, district, city FROM vacancy_location WHERE vacancy_id = :vac_id");
    query.bindValue(":vac_id", this->id);
    if (!query.exec()) {
        qDebug() << "Failed to load applications";
    }

    // set query for the model
    location_model->setQuery(query);

    // finally setting the model for tableView
    ui->tableView_locations->setModel(location_model);
}

void vacancy::on_pushButton_del_location_clicked()
{
    if (ui->tableView_locations->selectionModel()->currentIndex().isValid()) {
        int rowidx = ui->tableView_locations->selectionModel()->currentIndex().row();
        //QMessageBox::information(this, "Call", location_model->index(rowidx, 0).data().toString());
        QSqlQuery qry;

        qry.prepare("DELETE FROM vacancy_location WHERE vacancy_id = :id AND street_addr = :addr AND ward = :ward AND district = :district AND city = :city");
        qry.bindValue(":id", this->id);
        qry.bindValue(":addr", location_model->index(rowidx, 0).data().toString());
        qry.bindValue(":ward", location_model->index(rowidx, 1).data().toString());
        qry.bindValue(":district", location_model->index(rowidx, 2).data().toString());
        qry.bindValue(":city", location_model->index(rowidx, 3).data().toString());

        if (qry.exec())
            loadLocations();
    }
}

void vacancy::on_pushButton_add_location_clicked()
{
    VacancyLocation *newLocation = new VacancyLocation(this, this->id);
    newLocation->setModal(true);
    newLocation->exec();
}

void vacancy::on_pushButton_reload_clicked()
{
    loadLocations();
}
