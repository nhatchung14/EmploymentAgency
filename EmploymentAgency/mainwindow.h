#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <signup.h>
#include"seekerprofile.h"
#include"recruiterprofile.h"
#include"staff.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setName(QString);
    QString getName();

private slots:

    void on_logInButton_clicked();

    void on_signUpButton_clicked();

private:
    Ui::MainWindow *ui;
    seekerprofile *seekprof;

    void getSeekerProfile(int db_id);
    void getRecruiterProfile(int db_id);
    void getStaffProfile(int db_id);
};

#endif // MAINWINDOW_H
