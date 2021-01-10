TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += widgets

SOURCES += \
        action.cpp \
        bank.cpp \
        boardgame.cpp \
        bottomBar.cpp \
        card.cpp \
        card_money.cpp \
        card_move.cpp \
        centralwidget.cpp \
        dice.cpp \
        Game_Board.cpp \
        guiplayers.cpp \
        goToAction.cpp \
        mainwindow.cpp \
        money_action.cpp \
        move_action.cpp \
        player.cpp \
        space.cpp

HEADERS += \
        action.h \
        bank.h \
        bottomBar.h \
        card.h \
        card_money.h \
        card_move.h \
        centralwidget.h \
        dice.h \
        Game_Board.h \
        guiplayers.h \
        goToAction.h \
        mainwindow.h \
        money_action.h \
        move_action.h \
        player.h \
        space.h \
        textbox.h


