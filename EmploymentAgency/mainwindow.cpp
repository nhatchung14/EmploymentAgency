#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logInButton_clicked()
{
    qDebug() << (signUp == nullptr);
}

void MainWindow::on_signUpButton_clicked()
{
    hide();
    signUp = new SignUp(this);
    signUp->show();

}
