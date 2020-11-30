QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
#    chancecards.cpp \
    board.cpp \
    button.cpp \
    game.cpp \
    main.cpp \
    myRect.cpp \
    pawn1.cpp \
    showCardsMenu.cpp

HEADERS += \
#    chancecards.h \
    board.h \
    button.h \
    game.h \
    myRect.h \
    pawn1.h \
    printf.h \
    showCardsMenu.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
