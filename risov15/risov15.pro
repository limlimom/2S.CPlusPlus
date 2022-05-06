QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = risov15
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
    brushdialog.cpp \
    canvas.cpp \
    main.cpp \
    mainwindow.cpp \
    arc.cpp \
    brush.cpp \
    color.cpp \
    curve.cpp \
    ellipse.cpp \
    elliptic.cpp \
    line.cpp \
    pen.cpp \
    pendialog.cpp \
    pixel.cpp \
    point.cpp \
    pointsdialog.cpp \
    polygon.cpp \
    primitive.cpp \
    rectangle.cpp

HEADERS += \
    brushdialog.h \
    canvas.h \
    mainwindow.h \
    arc.h \
    brush.h \
    color.h \
    curve.h \
    ellipse.h \
    elliptic.h \
    line.h \
    pen.h \
    pendialog.h \
    pixel.h \
    point.h \
    pointsdialog.h \
    polygon.h \
    primitive.h \
    rectangle.h

FORMS += \
    brushdialog.ui \
    mainwindow.ui \
    pendialog.ui \
    pointsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
