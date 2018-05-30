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
#include "Objects/attribute.h"
#include <QString>
#include "DataStructures/SimpleList/hashmap.h"
#include "DataStructures/SimpleList/arbolbb.h"
#include "DataStructures/SimpleList/simplelist.h"
#include "Document/mysqldb.h"

using namespace std;
class ParserXML
{
public:
    ParserXML();
    std::string getRoot();
    bool newUserParser();
    bool userVerificationParser();
    bool modifyMetaData();
    SimpleList<Attribute> *pageRequested();
    Attribute songRequested();
    string deleteSong();
    SimpleList<Attribute> *sendMsg();
    string spotifyRequested();

private:
    MySQLDB sql;
    arbolBB<QJsonObject> ab = arbolBB<QJsonObject>();
    hashmap mapa = hashmap();
    ListaSimple<QJsonObject> listaCambios = ListaSimple<QJsonObject>();
    QDomDocument *xmlTemp;
    QDomElement getHeader();

};


#endif // PARSERXML_H
