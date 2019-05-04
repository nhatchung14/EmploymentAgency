#include "add_vacancy.h"
#include "ui_add_vacancy.h"
#include "mainwindow.h"

add_vacancy::add_vacancy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_vacancy)
{
    ui->setupUi(this);

    CounterInit();
}

add_vacancy::~add_vacancy()
{
    delete ui;
}

void add_vacancy::setRecruiterID(int ID)
{
    idRecruiter = ID;
}

void add_vacancy::on_pushButton_add_vacancy_clicked()
{
    //getting the data
    QString published = ui->dateEdit_published->text();
    QString closed = ui->dateEdit_closed->text();
    QString desc = ui->textEdit_desc->toPlainText();
    QString salary = ui->lineEdit_salary->text();
    bool    nego = ui->checkBox_nego->isChecked();
    QString require = ui->textEdit_require->toPlainText();
    QString benefit = ui->textEdit_bene->toPlainText();
    QString other = ui->textEdit_other->toPlainText();

    // Debug
    qDebug() << counter;
    qDebug() << idRecruiter;
    qDebug() << published;
    qDebug() << closed;
    qDebug() << desc;
    qDebug() << salary;
    qDebug() << nego;
    qDebug() << require;
    qDebug() << benefit;
    qDebug() << other;

    int True = 1;
    int False = 0;

    //setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO vacancy(vacancy_id, recruiter_id, published_date, closed_date, job_description, salary, negotiable, requirements, benefits, other_details)")
                          + QString("VALUES(:vacancy_id, :recruiter_id, :published_date, :closed_date, :job_description, :salary, :negotiable, :requirements, :benefits, :other_details)"));
    query.bindValue(":vacancy_id", counter);
    query.bindValue(":recruiter_id", idRecruiter);
    query.bindValue(":published_date", published);
    query.bindValue(":closed_date", closed);
    query.bindValue(":job_description", desc);
    query.bindValue(":salary", salary);
    /*if (nego == true)
        query.bindValue(":negotiable", True);
    else    query.bindValue(":negotiable", False);*/
    query.bindValue(":negotiable", nego);
    query.bindValue(":requirements", require);
    query.bindValue(":benefits", benefit);
    query.bindValue(":other_details", other);

    if (query.exec()) {
        // successfull query will insert the new entry
        hide();
        parentWidget()->show();
    } else
        qDebug() << "add vacancy query unsuccessful";
}

void add_vacancy::on_pushButton_back_clicked()
{
    hide();
    parentWidget()->show();
}

void add_vacancy::CounterInit()
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
