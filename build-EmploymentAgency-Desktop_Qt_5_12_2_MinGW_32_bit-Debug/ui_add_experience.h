/********************************************************************************
** Form generated from reading UI file 'add_experience.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_EXPERIENCE_H
#define UI_ADD_EXPERIENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_add_experience
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_company;
    QLabel *label_2;
    QLineEdit *lineEdit_job;
    QLabel *label_3;
    QLineEdit *lineEdit_work_address;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *textEdit_details;
    QDateEdit *dateEdit_start;
    QDateEdit *dateEdit_end;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *add_experience)
    {
        if (add_experience->objectName().isEmpty())
            add_experience->setObjectName(QString::fromUtf8("add_experience"));
        add_experience->resize(456, 397);
        gridLayout = new QGridLayout(add_experience);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(add_experience);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_company = new QLineEdit(add_experience);
        lineEdit_company->setObjectName(QString::fromUtf8("lineEdit_company"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_company);

        label_2 = new QLabel(add_experience);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_job = new QLineEdit(add_experience);
        lineEdit_job->setObjectName(QString::fromUtf8("lineEdit_job"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_job);

        label_3 = new QLabel(add_experience);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_work_address = new QLineEdit(add_experience);
        lineEdit_work_address->setObjectName(QString::fromUtf8("lineEdit_work_address"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_work_address);

        label_4 = new QLabel(add_experience);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(add_experience);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(add_experience);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        textEdit_details = new QTextEdit(add_experience);
        textEdit_details->setObjectName(QString::fromUtf8("textEdit_details"));

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit_details);

        dateEdit_start = new QDateEdit(add_experience);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit_start);

        dateEdit_end = new QDateEdit(add_experience);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));

        formLayout->setWidget(4, QFormLayout::FieldRole, dateEdit_end);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(add_experience);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(add_experience);

        QMetaObject::connectSlotsByName(add_experience);
    } // setupUi

    void retranslateUi(QDialog *add_experience)
    {
        add_experience->setWindowTitle(QApplication::translate("add_experience", "Dialog", nullptr));
        label->setText(QApplication::translate("add_experience", "Company name:", nullptr));
        label_2->setText(QApplication::translate("add_experience", "Job title:", nullptr));
        label_3->setText(QApplication::translate("add_experience", "Work address:", nullptr));
        label_4->setText(QApplication::translate("add_experience", "Start date:", nullptr));
        label_5->setText(QApplication::translate("add_experience", "End date:", nullptr));
        label_6->setText(QApplication::translate("add_experience", "Other details:", nullptr));
        pushButton->setText(QApplication::translate("add_experience", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_experience: public Ui_add_experience {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EXPERIENCE_H
