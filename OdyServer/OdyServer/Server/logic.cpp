#include "logic.h"


Logic::Logic(ParserXML *parser, QTcpSocket *socket)
{
    xml = parser;
    this->page= new Page();
    this->socket=socket;
}

void Logic::decision()
{
    string x=xml->getRoot();

    if(x=="NewUser"){
        xml->newUserParser();
        //Agregar en Database
        //POST->newUser(xml->newUserParser());
    }
    else if(x=="userVerification"){
        POST->userVerification(xml->userVerificationParser());
        //socket->write();
    }
    else if(x=="ModifyMetaData"){
       //POST->modifyMetadata(xml->modifyMetaData());
        xml->modifyMetaData();//Modificar en Database
       //DATABASE
    }
    else if(x=="pageRequested"){
        //Llamar metodo para cargar paginas
        xml->pageRequested();
        POST->songList(page->getData(3),page->getSize(1));
        //POST.songList();
        //enviar POST a cliente
    }
    else if(x=="songRequested"){
        //Llamar metodo para cargar Cancion
        //enviar POST a cliente
        
        //Cambiar por HUFFMAN
        std::string name = xml->songRequested();
        POST->sendSong(inputFile.size(),name);//Hacer la peticion al Raid Controller
        this->sendFile();
       
        QString path = QDir::homePath().append("/Music/Odyssey/Library/Get Busy.mp3");
        //File desde RAID
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
        std::cout<<"SEND MP3/MP4"<<std::endl;
    }
    else if(x=="deleteSong"){
        POST->deleteSong(xml->deleteSong());
        //ELIMINAR EN DATABASE
        //ELIMINAR EN RAID MANAGER
    }
    else if(x=="newMsg"){
        //
    }
    else if(x == "buscarFrase"){
        QString songName = BT.buscar(xml->buscarFrase());
        POST->searchPhrase(songName);
        sendFile();
    }

}

void Logic::setGET(string GET)
{
    this->GET=GET;
}

void Logic::writeGET()
{
    ofstream file;
    file.open (QDir::homePath().toStdString()+"/Music/Odyssey/Temp/requested.xml");
    file << GET;
    file.close();
}

void Logic::getFileList()
{
    string path = QDir::homePath().toStdString()+"/Music/Odyssey/Library";
    /*for (auto & file : filesystem::directory_iterator(path)){
        //put file into array
    }*/
}

void Logic::sendFile()
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
