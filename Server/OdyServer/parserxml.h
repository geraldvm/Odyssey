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

class ParserXML
{
public:
    ParserXML();
    void getRoot();
    void newUserParser();
    void userVerificationParser();
    void modifyMetaData();
    void pageRequested();
    void songRequested();
    void deleteSong();
    void sendMsg();

private:
    QDomDocument *xmlTemp;
    QDomElement getHeader();

};

#endif // PARSERXML_H
