QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
TARGET = TPQt
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    mainwindow.cpp \
    identification.cpp \
    sabout.cpp \
    nclient.cpp \
    npersonnel.cpp \
    cclient.cpp \
    CRdv.cpp \
    ctriclient.cpp \
    c_init_bd.cpp \
<<<<<<< HEAD
=======
    connection.cpp \
    c_ressource.cpp \
>>>>>>> f13c80a8d724ed26a1c16c2755118edcef839a78
    db_manager.cpp

FORMS += \
    mainwindow.ui \
    identification.ui \
    sabout.ui \
    npersonnel.ui \
    nclient.ui \
    c_ressource.ui

HEADERS += \
    mainwindow.h \
    identification.h\
    npersonnel.h \
    nclient.h \
    sabout.h \
    cclient.h \
    CRdv.h \
    ctriclient.h \
    c_init_bd.h \
<<<<<<< HEAD
=======
    connection.h \
    c_ressource.h \
>>>>>>> f13c80a8d724ed26a1c16c2755118edcef839a78
    db_manager.h

RESOURCES += \
    image.qrc

