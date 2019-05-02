#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect the database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/wokhu/sqlite3/EmploymentAgency");
    if (db.open()) {}
    else {
        QMessageBox::information(this, "Login call", "Database failed");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetSeekerProfile(QString email)
{
    auto seekprof = new seekerprofile(this);
    seekprof->setEmail(email);
    seekprof->setModal(true);
    seekprof->exec();
}

void MainWindow::GetRecruiterProfile(QString email)
{
    auto recruitprof = new recruiterprofile(this);
    recruitprof->setEmail(email);
    recruitprof->setModal(true);
    recruitprof->exec();
}

void MainWindow::on_logInButton_clicked()
{
    // Retrieve textual data
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();

    // Query for entered user from the database
    QSqlQuery query, query_user_type;
    query.prepare("SELECT A.email, A.password FROM login_account A WHERE A.email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        // There must be only ONE user of the same email
        if (query.next()) {
            if (password == query.value(1).toString()) {
                // Log in successful, start checking user_type
                query_user_type.prepare("SELECT B.user_type FROM login_account B WHERE B.email = :email");
                query_user_type.bindValue(":email", email);

                if (query_user_type.value(1).toString().compare("Applicant") == 0) {
                    hide();
                    GetSeekerProfile(email);
                }
                else {
                    hide();
                    GetRecruiterProfile(email);
                }


            } else {
                // Log in unsuccessful
                QMessageBox::information(this, "Login call", "Login unsuccessful");
            }
        }
        else {
            // Log in unsuccessful
            QMessageBox::information(this, "Login call", "Login unsuccessful");
        }
    }
}

void MainWindow::on_signUpButton_clicked()
{
    hide();
    signUp = new SignUp(this);
    signUp->show();
}
