#include "server.h"
#include "Document/converter.cpp"

Server::Server(QObject *parent) :
    QObject(parent)
{
    server= new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,7777)){
        std::cout<<"Server could not start!"<<std::endl;
    }else{
        std::cout<<"Server started!"<<std::endl;

        ListaSimple<QJsonObject> listaUsers = cargarInfo.getUsersInfo();
        for (int i = 0; i < listaUsers.size; i++) {
            infoUsers.insert(listaUsers.get(i));
        }

        usersPass.leerMapa();
        xm = new ParserXML(infoUsers,usersPass);
        xm->getRoot();
        logic = new Logic(xm);
        //stripping("cancion.mp3");
        recovery("cancion.mp3");
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

void Server::stripping(QString nombre)
{
    QString path = QDir::homePath().append("/Music/Odyssey/Library/Repository/").append(nombre);

    QFile inputFile(path);
    inputFile.open(QIODevice::ReadOnly);
    QByteArray blob = inputFile.readAll();
    int strip= blob.size()/2;

    //Strip 1
    QByteArray bytes1 = blob.mid( 0, strip);
    converter.setPath("Disc1/"+nombre);
    converter.toFile(bytes1);

    //Strip 2
    QByteArray bytes2 = blob.mid(strip,2*strip);
    converter.setPath("Disc2/"+nombre);
    converter.toFile(bytes2);

    QByteArray paridad = calcularParidad(bytes1,bytes2);
    converter.setPath("Disc3/"+nombre);
    converter.toFile(paridad);

}

void Server::recovery(QString nombre)
{

    QString pathP1 = QDir::homePath().append("/Music/Odyssey/Library/Disc1/");
    QString pathP2 = QDir::homePath().append("/Music/Odyssey/Library/Disc2/");
    QString pathPAR = QDir::homePath().append("/Music/Odyssey/Library/Disc3/");

    QFile disco1(pathP1.append(nombre));
    QFile disco2(pathP2.append(nombre));
    QFile disco3(pathPAR.append(nombre));

    QByteArray p1;
    QByteArray p2;

    if (disco1.exists() && disco2.exists() && disco3.exists()){
        disco1.open(QIODevice::ReadOnly);
        p1 = disco1.readAll();
        disco2.open(QIODevice::ReadOnly);
        p2 = disco2.readAll();
        std::cout << "fine"<< std::endl;;
    } else {
        if (disco1.exists() && disco2.exists()){
            std::cout << "error en el 3"<< std::endl;;
            disco1.open(QIODevice::ReadOnly);
            p1 = disco1.readAll();
            disco2.open(QIODevice::ReadOnly);
            p2 = disco2.readAll();
            QByteArray par = calcularParidad(p1, p2);
            QDir().mkdir(pathPAR);
            converter.setPath("Disc3/"+nombre);
            converter.toFile(par);
        } else {
            if (disco3.exists()){
                 if(disco1.exists()){
                     std::cout << "error en el 2"<< std::endl;;
                     disco1.open(QIODevice::ReadOnly);
                     p1 = disco1.readAll();
                     disco3.open(QIODevice::ReadOnly);
                     QByteArray par = disco3.readAll();
                     p2 = calcularParidad(par,p1);
                     QDir().mkdir(QDir::homePath().append("/Music/Odyssey/Library/Disc2"));
                     converter.setPath("Disco2/"+nombre);
                     converter.toFile(p2);
                 } else {
                     std::cout << "error en el 1"<< std::endl;;
                     disco2.open(QIODevice::ReadOnly);
                     p2 = disco2.readAll();
                     disco3.open(QIODevice::ReadOnly);
                     QByteArray par = disco3.readAll();
                     p1 = calcularParidad(p2,par);
                     QDir().mkdir(QDir::homePath().append("/Music/Odyssey/Library/Disc1"));
                     converter.setPath("Disco1/"+nombre);
                     converter.toFile(p1);
                 }

            } else {
                std::cout << "error irrecuperable en mas de 1 disco" << std::endl;
                return;
            }
        }
    }
    converter.setPath("Repository/cancionEnviar.mp3");
    converter.toFile(p1+p2);
    std::cout << "done" << std::endl;
}

QBitArray Server::convertirABits(QByteArray in){
    QBitArray out(in.count()*8);
    for (int bytePos = 0; bytePos < in.count(); bytePos++){
        for (int bitPos = 0; bitPos < 8; bitPos++){
            int bitIndex = bytePos*8+bitPos;
            out.setBit(bitIndex,in.at(bytePos)&(1<<bitPos));
        }
    }
    return out;
}

QByteArray Server::convertirABytes(QBitArray in){
    QByteArray out;
    out.resize(in.count()/8);
    for (int posBit = 0; posBit < out.count(); posBit++){
        out[posBit/8] = ( out.at(posBit/8) | ((in[posBit]?1:0)<<(posBit%8)));
    }
    return out;
}

QByteArray Server::calcularParidad(QByteArray p1, QByteArray p2){

    QBitArray bits1 = convertirABits(p1);
    QBitArray bits2 = convertirABits(p2);
    QBitArray res = QBitArray(bits1.size());

    for (int bitPos = 0; bitPos < bits1.size(); bitPos++) {
        res.setBit(bitPos,(bits1.at(bitPos) ^ bits2.at(bitPos)));
    }

    return convertirABytes(res);
}
