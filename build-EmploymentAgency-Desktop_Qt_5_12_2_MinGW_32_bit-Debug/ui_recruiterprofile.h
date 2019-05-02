/********************************************************************************
** Form generated from reading UI file 'recruiterprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECRUITERPROFILE_H
#define UI_RECRUITERPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recruiterprofile
{
public:
    QPushButton *pushButton_loadprof;
    QPushButton *pushButton_addVancancy;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_id;
    QLabel *label_2;
    QLineEdit *lineEdit_email;
    QLabel *label_3;
    QLineEdit *lineEdit_gender;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_phone;
    QLabel *label_6;
    QLineEdit *lineEdit_regdate;
    QLineEdit *lineEdit_dob;

    void setupUi(QDialog *recruiterprofile)
    {
        if (recruiterprofile->objectName().isEmpty())
            recruiterprofile->setObjectName(QString::fromUtf8("recruiterprofile"));
        recruiterprofile->resize(400, 300);
        pushButton_loadprof = new QPushButton(recruiterprofile);
        pushButton_loadprof->setObjectName(QString::fromUtf8("pushButton_loadprof"));
        pushButton_loadprof->setGeometry(QRect(170, 230, 81, 23));
        pushButton_addVancancy = new QPushButton(recruiterprofile);
        pushButton_addVancancy->setObjectName(QString::fromUtf8("pushButton_addVancancy"));
        pushButton_addVancancy->setGeometry(QRect(170, 260, 81, 23));
        widget = new QWidget(recruiterprofile);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 20, 201, 214));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_id = new QLineEdit(widget);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEdit_email = new QLineEdit(widget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_email);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        lineEdit_gender = new QLineEdit(widget);
        lineEdit_gender->setObjectName(QString::fromUtf8("lineEdit_gender"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_gender);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);

        lineEdit_phone = new QLineEdit(widget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_phone);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(10, QFormLayout::SpanningRole, label_6);

        lineEdit_regdate = new QLineEdit(widget);
        lineEdit_regdate->setObjectName(QString::fromUtf8("lineEdit_regdate"));

        formLayout->setWidget(11, QFormLayout::FieldRole, lineEdit_regdate);

        lineEdit_dob = new QLineEdit(widget);
        lineEdit_dob->setObjectName(QString::fromUtf8("lineEdit_dob"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_dob);


        retranslateUi(recruiterprofile);

        QMetaObject::connectSlotsByName(recruiterprofile);
    } // setupUi

    void retranslateUi(QDialog *recruiterprofile)
    {
        recruiterprofile->setWindowTitle(QApplication::translate("recruiterprofile", "Dialog", nullptr));
        pushButton_loadprof->setText(QApplication::translate("recruiterprofile", "Load Profile", nullptr));
        pushButton_addVancancy->setText(QApplication::translate("recruiterprofile", "Add Vancancy", nullptr));
        label->setText(QApplication::translate("recruiterprofile", "ID", nullptr));
        label_2->setText(QApplication::translate("recruiterprofile", "Email", nullptr));
        label_3->setText(QApplication::translate("recruiterprofile", "Gender", nullptr));
        label_4->setText(QApplication::translate("recruiterprofile", "Day of Birth", nullptr));
        label_5->setText(QApplication::translate("recruiterprofile", "Phone", nullptr));
        label_6->setText(QApplication::translate("recruiterprofile", "Registration Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recruiterprofile: public Ui_recruiterprofile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECRUITERPROFILE_H
