/********************************************************************************
** Form generated from reading UI file 'add_vacancy.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_VACANCY_H
#define UI_ADD_VACANCY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_vacancy
{
public:
    QLabel *label;
    QLabel *label_2;
    QDateEdit *dateEdit_published;
    QDateEdit *dateEdit_closed;
    QLabel *label_3;
    QTextEdit *textEdit_desc;
    QLabel *label_5;
    QTextEdit *textEdit_require;
    QTextEdit *textEdit_bene;
    QTextEdit *textEdit_other;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_add_vacancy;
    QPushButton *pushButton_back;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_salary;
    QCheckBox *checkBox_nego;

    void setupUi(QDialog *add_vacancy)
    {
        if (add_vacancy->objectName().isEmpty())
            add_vacancy->setObjectName(QString::fromUtf8("add_vacancy"));
        add_vacancy->resize(431, 557);
        label = new QLabel(add_vacancy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(51, 21, 71, 16));
        label_2 = new QLabel(add_vacancy);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(51, 47, 58, 16));
        dateEdit_published = new QDateEdit(add_vacancy);
        dateEdit_published->setObjectName(QString::fromUtf8("dateEdit_published"));
        dateEdit_published->setGeometry(QRect(128, 21, 81, 20));
        dateEdit_closed = new QDateEdit(add_vacancy);
        dateEdit_closed->setObjectName(QString::fromUtf8("dateEdit_closed"));
        dateEdit_closed->setGeometry(QRect(130, 50, 81, 20));
        label_3 = new QLabel(add_vacancy);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 80, 81, 16));
        textEdit_desc = new QTextEdit(add_vacancy);
        textEdit_desc->setObjectName(QString::fromUtf8("textEdit_desc"));
        textEdit_desc->setGeometry(QRect(50, 100, 321, 71));
        label_5 = new QLabel(add_vacancy);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 210, 71, 16));
        textEdit_require = new QTextEdit(add_vacancy);
        textEdit_require->setObjectName(QString::fromUtf8("textEdit_require"));
        textEdit_require->setGeometry(QRect(50, 230, 321, 71));
        textEdit_bene = new QTextEdit(add_vacancy);
        textEdit_bene->setObjectName(QString::fromUtf8("textEdit_bene"));
        textEdit_bene->setGeometry(QRect(50, 330, 321, 71));
        textEdit_other = new QTextEdit(add_vacancy);
        textEdit_other->setObjectName(QString::fromUtf8("textEdit_other"));
        textEdit_other->setGeometry(QRect(50, 430, 321, 71));
        label_6 = new QLabel(add_vacancy);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 310, 47, 13));
        label_7 = new QLabel(add_vacancy);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 410, 71, 16));
        pushButton_add_vacancy = new QPushButton(add_vacancy);
        pushButton_add_vacancy->setObjectName(QString::fromUtf8("pushButton_add_vacancy"));
        pushButton_add_vacancy->setGeometry(QRect(230, 520, 75, 23));
        pushButton_back = new QPushButton(add_vacancy);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(320, 520, 75, 23));
        widget = new QWidget(add_vacancy);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 180, 251, 22));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_salary = new QLineEdit(widget);
        lineEdit_salary->setObjectName(QString::fromUtf8("lineEdit_salary"));

        gridLayout->addWidget(lineEdit_salary, 0, 1, 1, 1);

        checkBox_nego = new QCheckBox(widget);
        checkBox_nego->setObjectName(QString::fromUtf8("checkBox_nego"));

        gridLayout->addWidget(checkBox_nego, 0, 2, 1, 1);


        retranslateUi(add_vacancy);

        QMetaObject::connectSlotsByName(add_vacancy);
    } // setupUi

    void retranslateUi(QDialog *add_vacancy)
    {
        add_vacancy->setWindowTitle(QApplication::translate("add_vacancy", "Dialog", nullptr));
        label->setText(QApplication::translate("add_vacancy", "Published Date", nullptr));
        label_2->setText(QApplication::translate("add_vacancy", "Closed Date", nullptr));
        label_3->setText(QApplication::translate("add_vacancy", "Job Description", nullptr));
        label_5->setText(QApplication::translate("add_vacancy", "Requirements", nullptr));
        label_6->setText(QApplication::translate("add_vacancy", "Benefits", nullptr));
        label_7->setText(QApplication::translate("add_vacancy", "Other Details", nullptr));
        pushButton_add_vacancy->setText(QApplication::translate("add_vacancy", "OK", nullptr));
        pushButton_back->setText(QApplication::translate("add_vacancy", "Cancel", nullptr));
        label_4->setText(QApplication::translate("add_vacancy", "Salary", nullptr));
        checkBox_nego->setText(QApplication::translate("add_vacancy", "Negotiable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_vacancy: public Ui_add_vacancy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_VACANCY_H
