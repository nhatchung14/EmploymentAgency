/********************************************************************************
** Form generated from reading UI file 'add_education.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_EDUCATION_H
#define UI_ADD_EDUCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_add_education
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_degree;
    QLabel *label_3;
    QLineEdit *lineEdit_major;
    QLabel *label_4;
    QLineEdit *lineEdit_school;
    QLabel *label_5;
    QLineEdit *lineEdit_gpa;
    QLabel *label_6;
    QTextEdit *textEdit_other;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *add_education)
    {
        if (add_education->objectName().isEmpty())
            add_education->setObjectName(QString::fromUtf8("add_education"));
        add_education->resize(424, 362);
        gridLayout = new QGridLayout(add_education);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(2, -1, -1, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(add_education);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_degree = new QLineEdit(add_education);
        lineEdit_degree->setObjectName(QString::fromUtf8("lineEdit_degree"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_degree);

        label_3 = new QLabel(add_education);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_major = new QLineEdit(add_education);
        lineEdit_major->setObjectName(QString::fromUtf8("lineEdit_major"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_major);

        label_4 = new QLabel(add_education);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_school = new QLineEdit(add_education);
        lineEdit_school->setObjectName(QString::fromUtf8("lineEdit_school"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_school);

        label_5 = new QLabel(add_education);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEdit_gpa = new QLineEdit(add_education);
        lineEdit_gpa->setObjectName(QString::fromUtf8("lineEdit_gpa"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_gpa);

        label_6 = new QLabel(add_education);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        textEdit_other = new QTextEdit(add_education);
        textEdit_other->setObjectName(QString::fromUtf8("textEdit_other"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_other);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(add_education);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        retranslateUi(add_education);

        QMetaObject::connectSlotsByName(add_education);
    } // setupUi

    void retranslateUi(QDialog *add_education)
    {
        add_education->setWindowTitle(QApplication::translate("add_education", "Dialog", nullptr));
        label_2->setText(QApplication::translate("add_education", "Degree name:", nullptr));
        label_3->setText(QApplication::translate("add_education", "Major:", nullptr));
        label_4->setText(QApplication::translate("add_education", "School name:", nullptr));
        label_5->setText(QApplication::translate("add_education", "GPA:", nullptr));
        label_6->setText(QApplication::translate("add_education", "Other details:", nullptr));
        pushButton->setText(QApplication::translate("add_education", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_education: public Ui_add_education {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EDUCATION_H
