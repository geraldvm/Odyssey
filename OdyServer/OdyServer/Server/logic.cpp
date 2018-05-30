#include "logic.h"


Logic::Logic(QTcpSocket* socket)
{
    this->socket= socket;
    //this->page= new Page();
}

void Logic::decision()
{
    string x=xml->getRoot();

    if(x=="NewUser"){
        POST->newUser(xml->newUserParser());
        this->sendFile();
    }
    else if(x=="userVerification"){
        POST->userVerification(xml->userVerificationParser());
        this->sendFile();
    }
    else if(x=="ModifyMetaData"){
        POST->modifyMetadata(xml->modifyMetaData());
        this->sendFile();
    }
    else if(x=="pageRequested"){
        //Llamar metodo para cargar paginas
        //xml->pageRequested();
        //POST->songList(page->getData(3),page->getSize(1));
        //POST.songList();
        //enviar POST a cliente
        this->sendFile();
    }
    else if(x=="songRequested"){
        //Llamar metodo para cargar Cancion
        //enviar POST a cliente
        QString fileName = xml->songRequested().getValue();
        fileName.append(".mp3");
        this->sendMP3(fileName);
        POST->song(fileName);
        this->sendFile();
    }
    else if(x=="deleteSong"){
        //POST->deleteSong();
    }
    else if(x=="newMsg"){
        //
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

void Logic::sendMP3(QString fileName)
{
    QString path = QDir::homePath().append("/Music/Odyssey/Library/");
    path.append(fileName);
    QFile inputFile(path);
    QByteArray read ;
    inputFile.open(QIODevice::ReadOnly);
    while(1)
    {
        read.clear();
        inputFile.size();
        read = inputFile.readAll();
        //read = inputFile.read(32768*8);
        if(read.size()==0)
           break;
        socket->write(read);
        socket->waitForBytesWritten();
        read.clear();
    }
    inputFile.close();
    std::cout<<"SEND SONG"<<std::endl;
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
        read = inputFile.readAll();
        if(read.size()==0)
           break;
        socket->write(read+"\n");
        socket->waitForBytesWritten();
        read.clear();
    }
    inputFile.close();
    std::cout<<"SEND MSG"<<std::endl;
}


