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
    db.setDatabaseName("D:/#Workspace [C++]/EmploymentAgency/Database/EmploymentAgency");
    if (db.open()) {}
    else {
        QMessageBox::information(this, "Login call", "Database failed");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getSeekerProfile(int db_id)
{
    seekerprofile *seekprof = new seekerprofile(this, db_id);
    seekprof->setSession(db_id, 1); // a seeker has session type 1
    seekprof->setModal(true);
    seekprof->exec();
}

void MainWindow::getRecruiterProfile(int db_id)
{
    recruiterprofile *recruitprof = new recruiterprofile(this, db_id);
    recruitprof->setSession(db_id, 0); // a recruiter has session type 0
    recruitprof->setModal(true);
    recruitprof->exec();
}

void MainWindow::getStaffProfile(int db_id)
{
    Staff *staffprof = new Staff(this, db_id);
    staffprof->setModal(true);
    staffprof->exec();
}

void MainWindow::on_logInButton_clicked()
{
    // Retrieve textual data
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();

    // Query for entered user from the database
    QSqlQuery query;
    query.prepare("SELECT A.id, A.email, A.password, A.user_type FROM login_account A WHERE A.email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        // There must be only ONE user of the same email
        if (query.next()) {
            int     db_id       = query.value(0).toInt();
            QString db_password = query.value(2).toString();
            QString db_user_type= query.value(3).toString();

            if (password == query.value(2).toString()) {
                // Log in successful, start checking user_type
                if (query.value(3).toString().compare("Seeker") == 0) {
                    hide();
                    getSeekerProfile(db_id);
                }
                else if (query.value(3).toString().compare("Recruiter") == 0) {
                    hide();
                    getRecruiterProfile(db_id);
                }
                else {
                    // admin
                    hide();
                    getStaffProfile(db_id);
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

    SignUp *signUp = new SignUp(this);
    signUp->setModal(true);
    signUp->exec();
}
