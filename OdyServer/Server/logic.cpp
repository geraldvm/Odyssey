#include "logic.h"


Logic::Logic()
{

    //this->page= new Page();
}

void Logic::decision()
{
    string x=xml->getRoot();

    if(x=="NewUser"){
        std::cout<<"********New USer************"<<std::endl;
        //Llamar metodo para guardar datos
    }
    else if(x=="userVerification"){
        //Llamar metodo para verificar datos
        POST->userVerification("true");//or False
        //enviar POST a cliente
    }
    else if(x=="ModifyMetaData"){
        //Llamar metodo para modificar Metadata
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
        //Llamar metodo para eliminar Cancion
    }
    else if(x=="newMsg"){
        //Llamar metodo para eliminar Cancion
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

