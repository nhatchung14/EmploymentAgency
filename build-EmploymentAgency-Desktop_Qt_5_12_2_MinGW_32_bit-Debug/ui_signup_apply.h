/********************************************************************************
** Form generated from reading UI file 'signup_apply.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_APPLY_H
#define UI_SIGNUP_APPLY_H

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

class Ui_SignUp_apply
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_description;
    QTextEdit *textEdit_description;
    QPushButton *pushButton_finish;

    void setupUi(QDialog *SignUp_apply)
    {
        if (SignUp_apply->objectName().isEmpty())
            SignUp_apply->setObjectName(QString::fromUtf8("SignUp_apply"));
        SignUp_apply->resize(720, 480);
        layoutWidget = new QWidget(SignUp_apply);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 100, 330, 260));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        label_description = new QLabel(layoutWidget);
        label_description->setObjectName(QString::fromUtf8("label_description"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_description);

        textEdit_description = new QTextEdit(layoutWidget);
        textEdit_description->setObjectName(QString::fromUtf8("textEdit_description"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_description);


        verticalLayout->addLayout(formLayout);

        pushButton_finish = new QPushButton(layoutWidget);
        pushButton_finish->setObjectName(QString::fromUtf8("pushButton_finish"));

        verticalLayout->addWidget(pushButton_finish);


        retranslateUi(SignUp_apply);

        QMetaObject::connectSlotsByName(SignUp_apply);
    } // setupUi

    void retranslateUi(QDialog *SignUp_apply)
    {
        SignUp_apply->setWindowTitle(QApplication::translate("SignUp_apply", "Employment Agency", nullptr));
        label_name->setText(QApplication::translate("SignUp_apply", "Name", nullptr));
        label_description->setText(QApplication::translate("SignUp_apply", "Description", nullptr));
        pushButton_finish->setText(QApplication::translate("SignUp_apply", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp_apply: public Ui_SignUp_apply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_APPLY_H
