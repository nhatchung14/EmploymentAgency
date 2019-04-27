#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    // create a counter for ids
    counter = 0;
}

SignUp::~SignUp()
{
    delete ui;
}

bool SignUp::emailExisted(QString &email) {
    // Query for entered user from the database
    QSqlQuery query;
    query.prepare("SELECT A.email FROM login_account A WHERE A.email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        // There must be only ONE user of the same email
        if (query.next()) {
            QMessageBox::information(this, "Signup", "Email already taken.");
            return true;
        }
        else {
            return false;
        }
    } else {
        qDebug() << "Signup check failed";
    }
    return false;
}

int SignUp::getCount()
{
    return counter;
}

// when 'Submit' button is clicked
void SignUp::on_pushButton_submit_clicked()
{
    // retrieving data
    QString email = ui->lineEdit_email->text();

    if (emailExisted(email))
        return;

    QString password = ui->lineEdit_password->text();
    QString gender = ui->comboBox_gender->currentText();
    QDate dob = ui->dateEdit->date();
    QString phone_num = ui->lineEdit_contact->text();

    QString user_type = ui->comboBox_type->currentText();

    // setting up INSERT query
    QSqlQuery query;
    query.prepare(QString("INSERT INTO login_account(id, email, password, user_type, gender, date_of_birth, phone_number, account_image, registration_date) ")
                   + QString("VALUES(:id, :email, :password, :user_type, :gender, :date_of_birth, :phone_number, :account_image, :registration_date)"));

    // binding tag-along column data
    query.bindValue(":id", ++this->counter);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.bindValue(":user_type", user_type);

    query.bindValue(":gender", gender);
    query.bindValue(":date_of_birth", dob);

    query.bindValue(":phone_number", phone_num);
    query.bindValue(":account_image", NULL);

    query.bindValue(":registration_date", QDate::currentDate());

    if (query.exec()) {
        hide();
        if (user_type == "Applicant") {
            ui_app = new SignUp_apply(this);
            ui_app->show();
        } else if (user_type == "Recruiter") {
            ui_rec = new SignUp_recruit(this);
            ui_rec->show();
        }
    }
    else
        qDebug() << "signup.cpp query failed";
}

// when 'Back' button is clicked
void SignUp::on_pushButton_back_clicked()
{
    this->hide();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}
