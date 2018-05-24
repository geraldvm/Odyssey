#include "parserxml.h"
#include "DataStructures/SimpleList/simplelist.h"
#include "Document/jsonmaker.h"
#include "DataStructures/SimpleList/hashmap.h"
#include "DataStructures/SimpleList/arbolbb.cpp"

//contraseña mysql root: ServerOdy2.0

ParserXML::ParserXML()
{
    mapa.leerMapa();
    QFile xml(QDir::homePath().append("/Music/Odyssey/Temp/requested.xml"));
    xml.open(QIODevice::ReadOnly);
    xmlTemp= new QDomDocument();
    xmlTemp->setContent(&xml);
    xml.close();
}

std::string ParserXML::getRoot()
{
    QDomElement root =xmlTemp->documentElement();
    return root.tagName().toStdString();
    /*
    QFile xml("myXml.xml");
    xml.open(QIODevice::ReadOnly);
    xmlTemporal= new QDomDocument();
    xmlTemporal->setContent(&xml);
    xml.close();*/
}

QDomElement ParserXML::getHeader()
{
    return xmlTemp->documentElement();
}

bool ParserXML::newUserParser()
{
    QDomElement user = this->getHeader().firstChild().toElement();
    if (!ab.search(user.attribute("Username",""))) {
        QJsonArray generos = QJsonArray();
        QStringList lista = user.attribute("Genre","").split(',');
        for (QString texto: lista) {
            generos.append(texto);
        }
        lista = user.attribute("Friends","").split(",");
        QJsonArray amigos = QJsonArray();
        for (QString texto: lista) {
            amigos.append(texto);
        }
        mapa.escribirPass(user.attribute("Username","").toStdString(),user.attribute("Password","").toStdString());
        JsonMaker jsonMaker = JsonMaker(user.attribute("Username","").toStdString(),
                                        user.attribute("Name","").toStdString(),
                                        user.attribute("Lastname","").toStdString(),
                                        user.attribute("Age","").toInt(),
                                        generos,
                                        mapa.generarId(user.attribute("Username","").toStdString()),
                                        amigos);
        ab.insert(jsonMaker.getJson());
        return true;
    }
    return false;

}

bool ParserXML::userVerificationParser()
{
    QDomElement user =this->getHeader().firstChild().toElement();
    return mapa.confirmarPass(user.attribute("Username","").toStdString(),user.attribute("Password","").toStdString());
}

void ParserXML::modifyMetaData()
{
    QDomElement song =this->getHeader().firstChild().toElement();
    QJsonObject instruccion = QJsonObject();
    instruccion.insert("OldName",song.attribute("OldName",""));
    instruccion.insert("Name",song.attribute("NewName",""));
    instruccion.insert("Artist",song.attribute("Artist",""));
    instruccion.insert("Album",song.attribute("Album",""));
    instruccion.insert("Year", song.attribute("Year",""));
    instruccion.insert("Lyrics", song.attribute("Lyrics",""));
    instruccion.insert("Genre",song.attribute("Genre",""));
    instruccion.insert("Score", song.attribute("Score",""));
    listaCambios.push_back(instruccion);
}

/*
SimpleList<Attribute> *ParserXML::pageRequested()
{
    SimpleList<Attribute>* list= new SimpleList<Attribute>();
    QDomElement page =this->getHeader().firstChild().toElement();
    Attribute* attr = new Attribute("Num",page.attribute("Num","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Type", page.attribute("Type","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Value", page.attribute("Value","").toStdString());
    list->addLast(*attr);
    //std::cout<<"pageNum: "<<username.toStdString()<<"passw
    return list;
}

Attribute ParserXML::songRequested()
{
    QDomElement song =this->getHeader().firstChild().toElement();
    Attribute* attr = new Attribute("Name",song.attribute("Name","").toStdString());
    return *attr;
}

string ParserXML::deleteSong()
{
    QDomElement song =this->getHeader().firstChild().toElement();
    return song.attribute("Name","").toStdString();
}

SimpleList<Attribute>* ParserXML::sendMsg()
{
    SimpleList<Attribute>* list= new SimpleList<Attribute>();
    QDomElement Msg =this->getHeader().firstChild().toElement();
    Attribute* attr = new Attribute("Sender", Msg.attribute("Sender","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Receiver",Msg.attribute("Receiver","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Song",Msg.attribute("Song","").toStdString());
    list->addLast(*attr);
    return list;

}
*/
/*
string ParserXML::spotifyRequested()
{

    QDomElement Spotify =this->getHeader().firstChild().toElement();
    return Spotify.attribute("Name","").toStdString();

}
*/

