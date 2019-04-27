#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <signup.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_logInButton_clicked();

    void on_signUpButton_clicked();

private:
    Ui::MainWindow *ui;
    SignUp *signUp;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
