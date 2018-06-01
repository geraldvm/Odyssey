#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H


#include <iostream>
#include <QFile>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "DataStructures/SimpleList/simplelist.h"
#include "Objects/message.h"
#include <QDir>

class XMLDocument
{
public:
    XMLDocument();

    void newUser(bool status);
    void modifyMetadata(bool status);
    void deleteSong(bool status);
    void userVerification(bool status);

    void song(std::string number, std::string data);
    void songList(string *array, int size);//como parametro lista enlazada o arreglo con las 10 canciones
    void userList(SimpleList<std::string> users);
    void sendMsg(SimpleList<Message> messageList);

private:
    QString path;
};

#endif // XMLDOCUMENT_H
