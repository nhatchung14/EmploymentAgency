#include "signup.h"
#include "ui_signup.h"


SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    counter = 0;
}

SignUp::~SignUp()
{
    delete ui;
}

int SignUp::getCount()
{
    return counter;
}


// when 'Submit' button is clicked
void SignUp::on_pushButton_submit_clicked()
{
    // setting up database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Gigster1409");
    db.setDatabaseName("employment_agency_v1.0");

    // retrieving data
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();
    QString gender = ui->lineEdit_gender->text();
    QDate dob = ui->dateEdit->date();
    QString phone_num = ui->lineEdit_contact->text();

    QString user_type = ui->comboBox_type->currentText();

    if (db.open()) {
        // setting up INSERT query
        QSqlQuery query;
        query.prepare("INSERT INTO login_account(email, password, user_type, gender, date_of_birth, phone_number, account_image, registration_date)"
                                    "VALUES(:email, :password, :user_type, :gender, :date_of_birth, :phone_number, account_image, registration_date)");

        // binding tag-along column data
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        query.bindValue(":gender", gender);
        query.bindValue(":date_of_birth", dob);

        query.bindValue(":phone_number", phone_num);
        query.bindValue(":account_image", NULL);

        query.bindValue(":registration_date", QDate::currentDate());
        query.bindValue(":user_type", user_type);

        // executing the query
        if( query.exec() ) {
            QMessageBox::information(this, "Connection", email + " was added into database");
            hide();

            if (user_type == "Applicant") {
                ui_app = new SignUp_apply(this);
                ui_app->show();
            } else if (user_type == "Recruiter") {
                ui_rec = new SignUp_recruit(this);
                ui_rec->show();
            }
            counter++;
        }
    }
}

// when 'Back' button is clicked
void SignUp::on_pushButton_back_clicked()
{
    this->hide();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}
