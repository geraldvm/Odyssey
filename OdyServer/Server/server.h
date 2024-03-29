#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QApplication>
#include <fstream>
#include "logic.h"
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
    QTcpServer *server;
    void sendFile(QTcpSocket *socket);
    void writeRequested(std::string data);
    void readRequested();
    Logic logic;
    Converter converter;


};

#endif // SERVER_H
