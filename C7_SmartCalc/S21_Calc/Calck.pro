QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Back/s21_calc.c \
    Back/parser.c \
    Back/revnotation.c \
    Back/stack.c \
    Back/validate.c \
    Back/calculate.c \
    credit.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    Back/stack.h\
    Back/validate.h\
    credit.h \
    graph.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    depoz.ui \
    graph.ui \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
