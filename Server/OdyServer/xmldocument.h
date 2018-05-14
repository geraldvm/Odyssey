#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H
#include <iostream>
#include <QFile>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <iostream>


class XMLDocument
{
public:
    XMLDocument();
    void userVerification(std::string status);
    void song(std::string number, std::string data);
    void songList();//como parametro lista enlazada o arreglo con las 10 canciones

};

#endif // XMLDOCUMENT_H
