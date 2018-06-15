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
#include "Document/backtracking.h"

using namespace std;
class ParserXML
{
public:
    ParserXML(arbolBB<QJsonObject> user, hashmap mapa);
    std::string getRoot();
    bool newUserParser();
    bool userVerificationParser();
    bool modifyMetaData();
    SimpleList<Attribute> *pageRequested();
    Attribute songRequested();
    bool deleteSong();
    SimpleList<Attribute> *sendMsg();
    string spotifyRequested();
    QString buscarFrase();

private:

    MySQLDB sql = MySQLDB();
    arbolBB<QJsonObject> userInfo;
    hashmap passMap;

    backtracking backtrack = backtracking();
    ListaSimple<QJsonObject> listaCambios = ListaSimple<QJsonObject>();
    QDomDocument *xmlTemp;
    QDomElement getHeader();

};


#endif // PARSERXML_H
