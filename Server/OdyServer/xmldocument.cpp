#include "xmldocument.h"
#include <QDir>
XMLDocument::XMLDocument()
{
    path=QDir::homePath().append("/Music/Odyssey/Temp/myXml.xml");
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

}

void XMLDocument::userVerification(std::string status)
{
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

    docXml.writeStartDocument();

    docXml.writeStartElement("userVerification");

    docXml.writeStartElement("user");
    //docXml.writeAttribute("Status",status);
    docXml.writeEndElement();

    docXml.writeEndElement();

    docXml.writeEndDocument();
    xml.close();

}

void XMLDocument::song(std::string number, std::string data)
{

    QFile xml(path);
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

    docXml.writeStartDocument();

    docXml.writeStartElement("Song");

    docXml.writeStartElement("Chunk");
    //docXml.writeAttribute("Part",number);
    //docXml.writeAttribute("Data",data);
    docXml.writeEndElement();

    docXml.writeEndElement();

    docXml.writeEndDocument();
    xml.close();

}

void XMLDocument::userList(SimpleList<std::string> users)
{
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

    docXml.writeStartDocument();

    docXml.writeStartElement("UserList");
    /*for(int i =0;i<users.getLength();i++){
        docXml.writeStartElement("user");
        docXml.writeAttribute("username",QString::fromStdString(users.findPos(i)));
        docXml.writeEndElement();
    }*/


    docXml.writeEndElement();

    docXml.writeEndDocument();
    xml.close();

}

void XMLDocument::sendMsg(SimpleList<Message> messageList)
{

}

void XMLDocument::songList(SimpleList<std::string> song)
{
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

    docXml.writeStartDocument();

    docXml.writeStartElement("SongList");
    for(int i =0;i<10;i++){ //i<list.lenght
        docXml.writeStartElement("Song");
        docXml.writeAttribute("Name","");
        docXml.writeAttribute("Artist","");
        docXml.writeAttribute("Album","");
        docXml.writeAttribute("Genre","");
        docXml.writeAttribute("Year","");
        docXml.writeAttribute("Lyrics","");
        docXml.writeEndElement();
    }
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}


