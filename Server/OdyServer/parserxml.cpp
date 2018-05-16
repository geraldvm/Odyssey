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

void ParserXML::newUserParser()
{
    QDomElement user =this->getHeader().firstChild().toElement();
    QString username = user.attribute("Username","");
    QString pass = user.attribute("Password","");
    QString lastn = user.attribute("Lastname","");
    QString name = user.attribute("Name","");
    QString age = user.attribute("Age","");
    QString genre = user.attribute("Genre","");

    std::cout<<"username: "<<username.toStdString()<<"password: "<<pass.toStdString()<<std::endl;
}

void ParserXML::userVerificationParser()
{

    QDomElement user =this->getHeader().firstChild().toElement();
    QString username = user.attribute("Username","");
    QString pass = user.attribute("Password","");
    std::cout<<"username: "<<username.toStdString()<<"password: "<<pass.toStdString()<<std::endl;
    //std::cout<<"username: "<<username.toStdString()<<"password: "<<pass.toStdString()<<std::endl;
}

void ParserXML::modifyMetaData()
{

    QDomElement song =this->getHeader().firstChild().toElement();
    QString oldName = song.attribute("OldName","");
    QString newName = song.attribute("NewName","");
    QString artist= song.attribute("Artist","");
    QString album= song.attribute("Album","");
    QString yaer= song.attribute("Year","");
    QString lyrics= song.attribute("Lyrics","");
    QString genre= song.attribute("Genre","");
    QString score= song.attribute("Score","");
}

void ParserXML::pageRequested()
{
    QDomElement page =this->getHeader().firstChild().toElement();
    QString pageNum = page.attribute("Num","");
    QString pageType = page.attribute("Type","");
    QString pageValue = page.attribute("Value","");
    //std::cout<<"pageNum: "<<username.toStdString()<<"passw
}

void ParserXML::songRequested()
{
    QDomElement song =this->getHeader().firstChild().toElement();
    QString name = song.attribute("Name","");
}

void ParserXML::deleteSong()
{
    QDomElement song =this->getHeader().firstChild().toElement();
    QString name = song.attribute("Name","");
}

void ParserXML::sendMsg()
{

    QDomElement Msg =this->getHeader().firstChild().toElement();
    QString sender = Msg.attribute("Sender","");
    QString receiver = Msg.attribute("Receiver","");
    QString song = Msg.attribute("Song","");

}
