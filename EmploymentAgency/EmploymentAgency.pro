#-------------------------------------------------
#
# Project created by QtCreator 2019-03-31T11:50:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmploymentAgency
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    add_vacancy.cpp \
        main.cpp \
        mainwindow.cpp \
    recruiterprofile.cpp \
    signup.cpp \
    signup_recruit.cpp \
    signup_apply.cpp \
    seekerprofile.cpp \
    add_education.cpp \
    add_experience.cpp

HEADERS += \
    add_vacancy.h \
        mainwindow.h \
    recruiterprofile.h \
    signup.h \
    signup_recruit.h \
    signup_apply.h \
    seekerprofile.h \
    add_education.h \
    add_experience.h

FORMS += \
    add_vacancy.ui \
        mainwindow.ui \
    recruiterprofile.ui \
    signup.ui \
    signup_recruit.ui \
    signup_apply.ui \
    seekerprofile.ui \
    add_education.ui \
    add_experience.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
