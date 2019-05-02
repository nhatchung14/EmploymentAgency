/********************************************************************************
** Form generated from reading UI file 'seekerprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEKERPROFILE_H
#define UI_SEEKERPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seekerprofile
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *line_edit_id;
    QLabel *label_2;
    QLineEdit *line_edit_email;
    QLabel *label_3;
    QLineEdit *line_edit_gender;
    QLabel *label_5;
    QLineEdit *line_edit_dob;
    QLabel *label_6;
    QLineEdit *line_edit_phone;
    QLabel *label_7;
    QLineEdit *line_edit_registration_date;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *seekerprofile)
    {
        if (seekerprofile->objectName().isEmpty())
            seekerprofile->setObjectName(QString::fromUtf8("seekerprofile"));
        seekerprofile->resize(458, 381);
        gridLayout = new QGridLayout(seekerprofile);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(seekerprofile);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget = new QWidget(seekerprofile);
        widget->setObjectName(QString::fromUtf8("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        line_edit_id = new QLineEdit(widget);
        line_edit_id->setObjectName(QString::fromUtf8("line_edit_id"));

        formLayout->setWidget(1, QFormLayout::FieldRole, line_edit_id);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        line_edit_email = new QLineEdit(widget);
        line_edit_email->setObjectName(QString::fromUtf8("line_edit_email"));

        formLayout->setWidget(2, QFormLayout::FieldRole, line_edit_email);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        line_edit_gender = new QLineEdit(widget);
        line_edit_gender->setObjectName(QString::fromUtf8("line_edit_gender"));

        formLayout->setWidget(3, QFormLayout::FieldRole, line_edit_gender);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        line_edit_dob = new QLineEdit(widget);
        line_edit_dob->setObjectName(QString::fromUtf8("line_edit_dob"));

        formLayout->setWidget(4, QFormLayout::FieldRole, line_edit_dob);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        line_edit_phone = new QLineEdit(widget);
        line_edit_phone->setObjectName(QString::fromUtf8("line_edit_phone"));

        formLayout->setWidget(6, QFormLayout::FieldRole, line_edit_phone);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        line_edit_registration_date = new QLineEdit(widget);
        line_edit_registration_date->setObjectName(QString::fromUtf8("line_edit_registration_date"));

        formLayout->setWidget(7, QFormLayout::FieldRole, line_edit_registration_date);


        gridLayout->addWidget(widget, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(seekerprofile);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        pushButton = new QPushButton(seekerprofile);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        retranslateUi(seekerprofile);

        QMetaObject::connectSlotsByName(seekerprofile);
    } // setupUi

    void retranslateUi(QDialog *seekerprofile)
    {
        seekerprofile->setWindowTitle(QApplication::translate("seekerprofile", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("seekerprofile", "Add Education Information", nullptr));
        label->setText(QApplication::translate("seekerprofile", "ID:", nullptr));
        label_2->setText(QApplication::translate("seekerprofile", "Email:", nullptr));
        label_3->setText(QApplication::translate("seekerprofile", "Gender:", nullptr));
        label_5->setText(QApplication::translate("seekerprofile", "Date of birth:", nullptr));
        label_6->setText(QApplication::translate("seekerprofile", "Phone number:", nullptr));
        label_7->setText(QApplication::translate("seekerprofile", "Registration date:", nullptr));
        pushButton_3->setText(QApplication::translate("seekerprofile", "Add Experience Information", nullptr));
        pushButton->setText(QApplication::translate("seekerprofile", "Show profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seekerprofile: public Ui_seekerprofile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEKERPROFILE_H
