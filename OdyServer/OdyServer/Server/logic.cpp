#include "logic.h"


Logic::Logic(ParserXML *parser)
{
    xml = parser;
    //this->page= new Page();
}

void Logic::decision()
{
    string x=xml->getRoot();

    if(x=="NewUser"){
        POST->newUser(xml->newUserParser());
    }
    else if(x=="userVerification"){
        POST->userVerification(xml->userVerificationParser());
    }
    else if(x=="ModifyMetaData"){
       POST->modifyMetadata(xml->modifyMetaData());
    }
    else if(x=="pageRequested"){
        //Llamar metodo para cargar paginas
        //xml->pageRequested();
        //POST->songList(page->getData(3),page->getSize(1));
        //POST.songList();
        //enviar POST a cliente
    }
    else if(x=="songRequested"){
        //Llamar metodo para cargar Cancion
        //enviar POST a cliente
        //POST.song();
    }
    else if(x=="deleteSong"){
        POST->deleteSong(xml->deleteSong());
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
