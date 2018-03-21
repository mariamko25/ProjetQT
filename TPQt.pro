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
    connection.cpp \
    db_manager.cpp \
    treeitem.cpp \
    treemodel.cpp

FORMS += \
    mainwindow.ui \
    identification.ui \
    sabout.ui \
    npersonnel.ui \
    nclient.ui

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
    connection.h \
    db_manager.h \
    treeitem.h \
    treemodel.h

RESOURCES += \
    image.qrc

