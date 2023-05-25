#QT -= gui

greaterThan(QT_MAJOR_VERSION,4):QT += widgets
QT += core gui
CONFIG += c++17 console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Qitem.cpp \
        main.cpp\
        board.cpp\
        direction.cpp\
        game.cpp\
        item.cpp\
        level.cpp\
        position.cpp\
        qboard.cpp \
        square.cpp\
        startWindow.cpp \
        view/gui.cpp \
        view/view.cpp\
        controller/controller.cpp\
#        main-console.cpp






# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        Qitem.h \
        board.h\
        direction.h\
        game.h\
        item.h\
        position.h\
        level.h\
        qboard.h \
        square.h\
        startWindow.h \
        type.h\
        typeStatus.h\
        controller/controller.h\
        view/gui.h \
        view/view.h\
        observer/observer.h\
        status.h


RESOURCES += \
    recource.qrc

