#include "myserver.h"
#include <iostream>
MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    server= new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,1234)){
        std::cout<<"Server could not start!";
         qDebug()<<"Server could not started!";
    }else{
        //std::cout<<"Server ";
        qDebug()<<"Server started!";
    }


}
void MyServer::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);//Wait 3 seconds
    socket->close();

}
