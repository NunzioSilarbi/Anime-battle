QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character_select.cpp \
    fight_page.cpp \
    main.cpp \
    animebattle.cpp \
    param.cpp \
    presets.cpp

HEADERS += \
    animebattle.h \
    character_select.h \
    fight_page.h \
    param.h \
    presets.h

FORMS += \
    animebattle.ui \
    character_select.ui \
    fight_page.ui \
    param.ui \
    presets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    AnimeBattle.qrc

DISTFILES += \
    TitleBG.png \
    preset1.txt

QT += \
    multimedia
