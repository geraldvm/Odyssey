#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H
#include <iostream>
#include <QFile>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "DataStructures/simplelist.h"

class XMLDocument
{
public:
    XMLDocument();
    void userVerification(std::string status);
    void song(std::string number, std::string data);
    void songList(SimpleList<std::string> songs);//como parametro lista enlazada o arreglo con las 10 canciones
    void userList(SimpleList<std::string> users);
private:
    QString path;

};

#endif // XMLDOCUMENT_H
