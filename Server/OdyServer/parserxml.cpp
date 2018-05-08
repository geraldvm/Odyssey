#include "parserxml.h"

ParserXML::ParserXML()
{
    QFile xml("requested.xml");
    xml.open(QIODevice::ReadOnly);
    xmlTemp= new QDomDocument();
    xmlTemp->setContent(&xml);
    xml.close();
}

void ParserXML::getRoot()
{


    QDomElement root =xmlTemp->documentElement();
    std::cout<<root.tagName().toStdString()<<std::endl;

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
}
