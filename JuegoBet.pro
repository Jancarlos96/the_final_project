QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GameObject.cpp \
    game.cpp \
    juego.cpp \
    jugador.cpp \
    main.cpp \
    mapas.cpp \
    pantalla1.cpp \
    pantalla2.cpp \
    personaje.cpp \
    play.cpp \
    recorridos.cpp \
    tripulantes.cpp \
    view.cpp

HEADERS += \
    GameObject.h \
    game.h \
    juego.h \
    jugador.h \
    mapas.h \
    pantalla1.h \
    pantalla2.h \
    play.h \
    view.h

FORMS += \
    juego.ui \
    pantalla1.ui \
    pantalla2.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc
