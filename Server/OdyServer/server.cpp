#include "server.h"

Server::Server(QObject *parent) :
    QObject(parent)
{
    server= new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,7777)){
        std::cout<<"Server could not start!"<<std::endl;

    }else{
        //std::cout<<"Server ";
        std::cout<<"Server started!"<<std::endl;
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

    socket->waitForBytesWritten(3000);//Wait 3 seconds
    socket->waitForReadyRead(3000);

    while(true){
        if(socket->bytesAvailable()>0){
            std::cout<<"Reading "<<socket->bytesAvailable()<<std::endl;
            std::string st = socket->readAll().toStdString();
            socket->waitForReadyRead(3000);
            std::cout<<"Client: "<<st<<std::endl;
            sendFile(socket);
            //socket->write("YESSS\n");
            socket->waitForBytesWritten(1000);
            //std::cout<<"COMPARE "<<std::endl;
            if(st.compare("send")==2){
                std::cout<<"Send Data "<<std::endl;
                sendFile(socket);
                socket->waitForBytesWritten(3000);
            }
            //std::cout<<"Client: "<<st<std::endl;
        }else{

             //std::cout<<"HOLA";

            socket->waitForReadyRead(3000);
        }
    //socket->close();
    }

}

void Server::sendFile(QTcpSocket* socket)
{
    //QString path = "/home/gerald/Desktop/texto.txt";
    QString path = "/home/gerald/Desktop/data.xml";
    //QString path = "/home/gerald/Desktop/Havana.mp3";
    QFile inputFile(path);
    QByteArray read ;
    inputFile.open(QIODevice::ReadOnly);
    while(1)
    {
        read.clear();
        read = inputFile.read(32768*8);
        //std::cout<< "Read : " << read.size();
        if(read.size()==0)
           break;
        //std::cout<< "Written : " << socket->write(read);
        socket->write(read+"\n");
        socket->waitForBytesWritten();
        read.clear();
        //https://stackoverflow.com/questions/13800664/how-to-send-a-file-along-with-its-filename-over-qtcpsocket
    }
    inputFile.close();
}
