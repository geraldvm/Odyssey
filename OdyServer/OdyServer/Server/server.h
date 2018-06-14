#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <iostream>
#include <QApplication>
#include <fstream>
#include <QDir>
#include <QBitArray>
#include <QFileInfo>
#include "logic.h"
#include "DataStructures/SimpleList/arbolbb.h"
#include "DataStructures/SimpleList/hashmap.h"
#include "DataStructures/SimpleList/listasimple.h"
#include "Document/converter.h"
#include "Document/parserxml.h"
#include "Document/leerjson.h"
#include "Document/mysqldb.h"
#include "Document/converter.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void stop();

signals:

public slots:
    void newConnection();

private:

    Converter converter;
    arbolBB<QJsonObject> infoUsers;
    hashmap usersPass;
    leerJson cargarInfo = leerJson();
    QTcpServer *server;

    void sendFile(QTcpSocket *socket);
    void writeRequested(std::string data);
    void readRequested();

    ParserXML* xm;
    Logic *logic = nullptr;

};

#endif // SERVER_H
