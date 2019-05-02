/********************************************************************************
** Form generated from reading UI file 'signup_recruit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_RECRUIT_H
#define UI_SIGNUP_RECRUIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp_recruit
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLabel *label_title;
    QLabel *label_company;
    QLabel *label_url;
    QLabel *label_description;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_title;
    QLineEdit *lineEdit_company;
    QLineEdit *lineEdit_url;
    QTextEdit *textEdit_details;
    QPushButton *pushButton_finish;

    void setupUi(QDialog *SignUp_recruit)
    {
        if (SignUp_recruit->objectName().isEmpty())
            SignUp_recruit->setObjectName(QString::fromUtf8("SignUp_recruit"));
        SignUp_recruit->resize(720, 480);
        layoutWidget = new QWidget(SignUp_recruit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 60, 401, 347));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        label_title = new QLabel(layoutWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_title);

        label_company = new QLabel(layoutWidget);
        label_company->setObjectName(QString::fromUtf8("label_company"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_company);

        label_url = new QLabel(layoutWidget);
        label_url->setObjectName(QString::fromUtf8("label_url"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_url);

        label_description = new QLabel(layoutWidget);
        label_description->setObjectName(QString::fromUtf8("label_description"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_description);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        lineEdit_title = new QLineEdit(layoutWidget);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_title);

        lineEdit_company = new QLineEdit(layoutWidget);
        lineEdit_company->setObjectName(QString::fromUtf8("lineEdit_company"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_company);

        lineEdit_url = new QLineEdit(layoutWidget);
        lineEdit_url->setObjectName(QString::fromUtf8("lineEdit_url"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_url);

        textEdit_details = new QTextEdit(layoutWidget);
        textEdit_details->setObjectName(QString::fromUtf8("textEdit_details"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_details);


        verticalLayout->addLayout(formLayout);

        pushButton_finish = new QPushButton(layoutWidget);
        pushButton_finish->setObjectName(QString::fromUtf8("pushButton_finish"));

        verticalLayout->addWidget(pushButton_finish);


        retranslateUi(SignUp_recruit);

        QMetaObject::connectSlotsByName(SignUp_recruit);
    } // setupUi

    void retranslateUi(QDialog *SignUp_recruit)
    {
        SignUp_recruit->setWindowTitle(QApplication::translate("SignUp_recruit", "Employment Agency", nullptr));
        label_name->setText(QApplication::translate("SignUp_recruit", "Name", nullptr));
        label_title->setText(QApplication::translate("SignUp_recruit", "Title", nullptr));
        label_company->setText(QApplication::translate("SignUp_recruit", "Company", nullptr));
        label_url->setText(QApplication::translate("SignUp_recruit", "Url", nullptr));
        label_description->setText(QApplication::translate("SignUp_recruit", "Description", nullptr));
        pushButton_finish->setText(QApplication::translate("SignUp_recruit", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp_recruit: public Ui_SignUp_recruit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_RECRUIT_H
