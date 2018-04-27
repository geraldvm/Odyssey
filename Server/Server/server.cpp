#include "server.h"
#include "ui_server.h"
#define localdir QHostAddress::LocalHost
#define localPort 1234
#include <string>
#include <QDebug>


Server::Server(QObject *parent) :
    QObject(parent)
{
    // create a QUDP socket
    socket = new QUdpSocket(this);
    socket->bind(localdir, localPort);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    clientPort=7777;
}
void Server::readyRead()
{
    // when data comes in
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(buffer.data(), buffer.size(),
                             &sender, &senderPort);


        std::string x =buffer.toStdString();
        //QString testData = QString::fromStdString(x);
        //socket->writeDatagram(testData.toLatin1(),localdir,clientPort);
        std::cout<<x<<std::endl;
}

Server::~Server()
{
    //delete ui;
}
