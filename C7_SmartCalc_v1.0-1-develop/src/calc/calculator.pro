QT       += core gui printsupport
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    stack.c \
    parser.c \
    polish.c \
    validator.c \
    xdialog.cpp

HEADERS += \
    mainwindow.h \
    qcustomplot.h \
    validator.h \
    stack.h \
    polish.h \
    xdialog.h

FORMS += \
    mainwindow.ui \
    xdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../for_calc/kavo.mp3 \
    ../for_calc/kavo.wav \
    ../ryan-gosling-rayan-gosling-6553.jpeg
