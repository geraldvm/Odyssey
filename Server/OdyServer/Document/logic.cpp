#include "logic.h"

Logic::Logic(string GET)
{
    this->GET=GET;
    this->xml=new ParserXML();
    this->POST= new XMLDocument();
}

void Logic::decision()
{
    x=xml.getRoot();
    switch (x) {
    case "NewUser":
        //Llamar metodo para guardar datos
        break;
    case "userVerification":
        //Llamar metodo para verificar datos
        POST.userVerification(true);//or False
        //enviar POST a cliente
        break;
    case "ModifyMetaData":
        //Llamar metodo para modificar Metadata
        break;
    case "pageRequested":
        //Llamar metodo para cargar paginas
        //POST.songList();
        //enviar POST a cliente
        break;
    case "songRequested":
        //Llamar metodo para cargar Cancion
        //enviar POST a cliente
        //POST.song();
        break;
    case "deleteSong":
        //Llamar metodo para eliminar Cancion
        break;
    case "newM":
        //Llamar metodo para eliminar Cancion
        break;
    default:
        break;
    }
}

void Logic::writeGET()
{
    std::ofstream file;
    file.open (QDir::homePath().toStdString()+"/Music/Odyssey/Temp/requested.xml");
    file << GET;
    file.close();
}

