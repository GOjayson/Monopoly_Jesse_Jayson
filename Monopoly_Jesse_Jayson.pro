QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
#    chancecards.cpp \
    board-UI.cpp \
    button-UI.cpp \
    dice.cpp \
    game-UI.cpp \
    main.cpp \
    myRect.cpp \
    pawnP1-UI.cpp \
    pawnP2-UI.cpp \
    showCardsMenu-UI.cpp

HEADERS += \
#    chancecards.h \
    board-UI.h \
    button-UI.h \
    dice.h \
    game-UI.h \
    myRect.h \
    pawnP1-UI.h \
    pawnP2-UI.h \
    printf.h \
    showCardsMenu-UI.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
