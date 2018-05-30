#include "server.h"

Server::Server(QObject *parent) :
    QObject(parent)
{
    ListaSimple<QJsonObject> listaUsers = cargarInfo.getUsersInfo();
    for (int i = 0; i < listaUsers.size; i++) {
        infoUsers.insert(listaUsers.get(i));
    }

    usersPass.leerMapa();

    server= new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,7777)){
        std::cout<<"Server could not start!"<<std::endl;
    }else{
        std::cout<<"Server started!"<<std::endl;
        ParserXML* xm = new ParserXML();
        xm->getRoot();
    }
}

void Server::stop()
{
    server->close();
}

void Server::newConnection(){

    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->waitForReadyRead(3000);
    while(true){
        if(socket->bytesAvailable()>0){
            //std::cout<<"Reading "<<socket->bytesAvailable()<<std::endl;
            converter.toFile(socket->readAll());
            std::cout<<"MP# LISTO"<<std::endl;
            /*std::string GET = socket->readAll().toStdString();
            GET.erase(0,2);
            logic.setGET(GET);
            logic.writeGET();
            logic.decision();
            sendFile(socket);
            */

            //std::cout<<"Client: "<<GET<<std::endl;
            socket->waitForReadyRead(3000);
            //writeRequested(st);
            //sendFile(socket);
           // socket->write("YESSS\n");
            //socket->waitForBytesWritten(1000);
            //std::cout<<"COMPARE "<<std::endl;
            /*if(st.compare("send")==2){
                std::cout<<"Send Data "<<std::endl;
                sendFile(socket);
                socket->waitForBytesWritten(3000);
            }*/
            //std::cout<<"Client: "<<st<std::endl;
        }else{
            socket->waitForReadyRead(3000);
        }
    //socket->close();
    }
}
/**
 * @brief Server::sendFile
 * @param socket
 */
void Server::sendFile(QTcpSocket* socket)
{
    QString path = QDir::homePath().append("/Music/Odyssey/Temp/myXml.xml");
    QFile inputFile(path);
    QByteArray read ;
    inputFile.open(QIODevice::ReadOnly);
    while(1)
    {
        read.clear();
        read = inputFile.read(32768*8);
        if(read.size()==0)
           break;
        socket->write(read+"\n");
        socket->waitForBytesWritten();
        read.clear();
    }
    inputFile.close();
    std::cout<<"SEND MSG"<<std::endl;
}
/**
 * @brief Server::readRequested
 */
void Server::readRequested()
{

}

