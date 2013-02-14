#-------------------------------------------------
#
# Project created by QtCreator 2011-07-01T09:24:59
#
#-------------------------------------------------

QT       += core gui

TARGET = sivia_simple
TEMPLATE = app

SOURCES += main.cpp\
 mainwindow.cpp \
 sivia.cpp \
 frame.cpp \
    DrawV.cpp \
    simu.cpp \
    drawf.cpp \
    drawsolve.cpp

HEADERS += mainwindow.h \
 frame.h \
 sivia.h \
    drawv.h \
    simu.h \
    drawf.h \
    drawsolve.h

FORMS += mainwindow.ui

 CONFIG += link_pkgconfig
 PKGCONFIG += /home23/pinheima/IBEX_PACK_LINUX64/INSTALL/IBEX/share/pkgconfig/ibex.pc


OTHER_FILES += \
    myFunction.txt \
    pendule.txt
