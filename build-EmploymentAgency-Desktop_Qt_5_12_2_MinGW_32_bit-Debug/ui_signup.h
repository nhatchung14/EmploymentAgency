/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QLabel *label_contact;
    QLineEdit *lineEdit_contact;
    QLabel *label_DoB;
    QDateEdit *dateEdit;
    QLabel *label_type;
    QComboBox *comboBox_type;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_back;
    QPushButton *pushButton_submit;
    QComboBox *comboBox_gender;
    QLabel *label_gender;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(720, 480);
        widget = new QWidget(SignUp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 100, 401, 296));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_email = new QLabel(widget);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_email);

        lineEdit_email = new QLineEdit(widget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_email);

        label_password = new QLabel(widget);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);

        label_contact = new QLabel(widget);
        label_contact->setObjectName(QString::fromUtf8("label_contact"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_contact);

        lineEdit_contact = new QLineEdit(widget);
        lineEdit_contact->setObjectName(QString::fromUtf8("lineEdit_contact"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_contact);

        label_DoB = new QLabel(widget);
        label_DoB->setObjectName(QString::fromUtf8("label_DoB"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_DoB);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, dateEdit);

        label_type = new QLabel(widget);
        label_type->setObjectName(QString::fromUtf8("label_type"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_type);

        comboBox_type = new QComboBox(widget);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBox_type);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_back = new QPushButton(widget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));

        verticalLayout->addWidget(pushButton_back);

        pushButton_submit = new QPushButton(widget);
        pushButton_submit->setObjectName(QString::fromUtf8("pushButton_submit"));

        verticalLayout->addWidget(pushButton_submit);


        formLayout->setLayout(10, QFormLayout::FieldRole, verticalLayout);

        comboBox_gender = new QComboBox(widget);
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox_gender);

        label_gender = new QLabel(widget);
        label_gender->setObjectName(QString::fromUtf8("label_gender"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_gender);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Employment Agency", nullptr));
        label_email->setText(QApplication::translate("SignUp", "Email", nullptr));
        label_password->setText(QApplication::translate("SignUp", "Password", nullptr));
        label_contact->setText(QApplication::translate("SignUp", "Contact", nullptr));
        label_DoB->setText(QApplication::translate("SignUp", "DoB", nullptr));
        label_type->setText(QApplication::translate("SignUp", "Type", nullptr));
        comboBox_type->setItemText(0, QApplication::translate("SignUp", "Applicant", nullptr));
        comboBox_type->setItemText(1, QApplication::translate("SignUp", "Recruiter", nullptr));

        pushButton_back->setText(QApplication::translate("SignUp", "Back", nullptr));
        pushButton_submit->setText(QApplication::translate("SignUp", "Next", nullptr));
        comboBox_gender->setItemText(0, QApplication::translate("SignUp", "Male", nullptr));
        comboBox_gender->setItemText(1, QApplication::translate("SignUp", "Female", nullptr));
        comboBox_gender->setItemText(2, QApplication::translate("SignUp", "Other", nullptr));

        label_gender->setText(QApplication::translate("SignUp", "Gender", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
