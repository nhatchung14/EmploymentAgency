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
    db.setDatabaseName("C:/Users/Admin/Documents/GitHub/EmploymentAgency/Database/EmploymentAgency");
    if (db.open()) {}
    else {
        QMessageBox::information(this, "Login call", "Database failed");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logInButton_clicked()
{
    // Retrieve textual data
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();

    // Query for entered user from the database
    QSqlQuery query;
    query.prepare("SELECT A.email, A.password FROM login_account A WHERE A.email = :email AND user_type='Applicant'");
    query.bindValue(":email", email);

    if (query.exec()) {
        // There must be only ONE user of the same email
        if (query.next()) {
            if (password == query.value(1).toString()) {
                // Log in successful
                hide();
                seekprof = new seekerprofile(this);
                seekprof->setEmail(email);
                seekprof->setModal(true);
                seekprof->exec();

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
