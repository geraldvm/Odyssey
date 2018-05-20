#include "parserxml.h"

ParserXML::ParserXML()
{
    QFile xml(QDir::homePath().append("/Music/Odyssey/Temp/requested.xml"));
    xml.open(QIODevice::ReadOnly);
    xmlTemp= new QDomDocument();
    xmlTemp->setContent(&xml);
    xml.close();
}


std::string ParserXML::getRoot()
{

    QDomElement root =xmlTemp->documentElement();
    std::cout<<root.tagName().toStdString()<<std::endl;
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

string *ParserXML::newUserParser()
{

    QDomElement user =this->getHeader().firstChild().toElement();
    string arr[6]={ user.attribute("Username","").toStdString(),
                user.attribute("Password","").toStdString(),
                    user.attribute("Name","").toStdString(),
                  user.attribute("Lastname","").toStdString(),
                  user.attribute("Age","").toStdString(),
                  user.attribute("Genre","").toStdString()};

    return arr;


    //std::cout<<"username: "<<username.toStdString()<<"password: "<<pass.toStdString()<<std::endl;
}
/*
SimpleList<Attribute>* ParserXML::userVerificationParser()
{

    SimpleList<Attribute>* list = new SimpleList<Attribute>();
    QDomElement user =this->getHeader().firstChild().toElement();
    Attribute* attr = new Attribute("Username",user.attribute("Username","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Password", user.attribute("Password","").toStdString());
    list->addLast(*attr);
    //std::cout<<"username: "<<username.toStdString()<<"password: "<<pass.toStdString()<<std::endl;
    //std::cout<<"username: "<<username.toStdString()<<"password: "<<pass.toStdString()<<std::endl;
    return list;
}

SimpleList<Attribute> *ParserXML::modifyMetaData()
{
    SimpleList<Attribute>* list= new SimpleList<Attribute>();
    QDomElement song =this->getHeader().firstChild().toElement();
    Attribute* attr = new Attribute("OldName",song.attribute("OldName","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("NewName",song.attribute("NewName","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Artist",song.attribute("Artist","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Album",song.attribute("Album","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Year", song.attribute("Year","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Lyrics", song.attribute("Lyrics","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Genre",song.attribute("Genre","").toStdString());
    list->addLast(*attr);
    attr->setAttribute("Score", song.attribute("Score","").toStdString());
    list->addLast(*attr);
    return list;
}

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

string ParserXML::spotifyRequested()
{

    QDomElement Spotify =this->getHeader().firstChild().toElement();
    return Spotify.attribute("Name","").toStdString();

}



*/
