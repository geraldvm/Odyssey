#include "server.h"


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
        //stripping();
        //recovery();
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

void Server::stripping()
{
    QString path = QDir::homePath().append("/Music/Library/cancion.mp3");
    QFile inputFile(path);
    inputFile.open(QIODevice::ReadOnly);
    QByteArray blob = inputFile.readAll();
    int strip= blob.size()/2;
    //Strip 1
    QByteArray bytes = blob.mid( 0, strip);
    converter.setPath("strip1.mp3");
    converter.toFile(bytes);
    //std::cout<<strip<<std::endl;
    //Strip 2
    bytes = blob.mid(strip,2*strip);
    converter.setPath("strip2.mp3");
    converter.toFile(bytes);
}

void Server::recovery()
{
    QString path = QDir::homePath().append("/Music/Library/cancion.mp3");
    QFile inputFile(path);
    inputFile.open(QIODevice::ReadOnly);
    QByteArray blob = inputFile.readAll();
    int strip= blob.size()/2;

    //Strip 1
    QByteArray bytes1 = blob.mid(0, strip);
    //Strip 2
    //std::cout << "blob."+ (QString::number(blob.size())).toStdString() << std::endl;
    //QByteArray bytes3 = calcularParidad(blob);
    inputFile.close();

    QBitArray bits1 = convertirABits(bytes1);
    QBitArray bits3 = calcularParidad(blob);

    //XOR Operation
    converter.setPath("xorResult.mp3");

    std::cout << "b1."+ (QString::number(bits1.size())).toStdString() << std::endl;
    std::cout << "b3."+ (QString::number(bits3.size())).toStdString() << std::endl;

    QBitArray xorBits(bits1.count());

    for(int bitPos=0;bitPos<bits1.size();++bitPos){

        //std::cout<<bits3.at(bitPos);

        xorBits.setBit(bitPos,bits1.at(bitPos) ^ bits3.at(bitPos));

    }

    std::cout << "final" << std::endl;

    QByteArray xorBytes = convertirABytes(xorBits);

    converter.toFile(xorBytes);
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

QBitArray Server::calcularParidad(QByteArray in){

    QBitArray bits = QBitArray(in.size());

    std::cout << "in."+ (QString::number(in.size())).toStdString() << std::endl;
    std::cout << "bs."+ (QString::number(bits.size())).toStdString() << std::endl;

    for(int byte = 0; byte < in.size(); byte++){

        QByteArray byteAux = QByteArray();

        byteAux.push_back(in.at(byte));

        QBitArray bitsAux = convertirABits(byteAux);

        int paridad = 1;

        for(int bit = 0; bit < 8; bit++){
            if((bool) bitsAux.at(bit)){
                paridad++;
            }
        }

        if(paridad%2 == 0) {
            bits.setBit(byte,false);
        } else {
            bits.setBit(byte,true);
        }
    }

    return bits;
}
