#ifndef PARSERXML_H
#define PARSERXML_H
#include <iostream>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QObject>
#include <QFile>
#include <QDir>
#include "DataStructures/SimpleList/simplelist.h"
#include "Objects/attribute.h"
#include <QString>
using namespace std;
class ParserXML
{
public:
    ParserXML();
    std::string getRoot();
    string* newUserParser();
    SimpleList<Attribute> *userVerificationParser();
    SimpleList<Attribute> *modifyMetaData();
    SimpleList<Attribute> *pageRequested();
    Attribute songRequested();
    string deleteSong();
    SimpleList<Attribute> *sendMsg();
    string spotifyRequested();

private:
    QDomDocument *xmlTemp;
    QDomElement getHeader();

};


#endif // PARSERXML_H
