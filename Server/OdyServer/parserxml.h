#ifndef PARSERXML_H
#define PARSERXML_H
#include <iostream>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QObject>
#include <QFile>

class ParserXML
{
public:
    ParserXML();
    void getRoot();

private:
    QDomDocument *xmlTemp;
    QDomElement getHeader();
    void newUserParser();
    void userVerificationParser();
};

#endif // PARSERXML_H
