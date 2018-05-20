#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T04:29:29
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OdyServer
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Server/server.cpp \
    Document/xmldocument.cpp \
    Objects/message.cpp \
    DataStructures/SimpleList/node.cpp \
    Server/logic.cpp \
    Document/parserxml.cpp \
    Objects/attribute.cpp \
    Document/converter.cpp \
    DataStructures/SimpleList/nodoavl.cpp \
    Objects/cancion.cpp \
    Document/jsonmaker.cpp \
    Document/guardarjson.cpp \
    Document/leerjson.cpp \
    DataStructures/SimpleList/simplelist.cpp

HEADERS += \
        mainwindow.h \
    Server/server.h \
    Document/xmldocument.h \
    Objects/message.h \
    DataStructures/SimpleList/simplelist.h \
    DataStructures/SimpleList/node.h \
    Server/logic.h \
    Document/parserxml.h \
    Objects/attribute.h \
    Document/converter.h \
    DataStructures/SimpleList/arbolavl.h \
    DataStructures/SimpleList/nodoavl.h \
    DataStructures/SimpleList/mapa.h \
    Objects/cancion.h \
    Document/jsonmaker.h \
    Document/guardarjson.h \
    Document/leerjson.h \
    DataStructures/SimpleList/hashmap.h

FORMS += \
        mainwindow.ui
