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
    docXml.writeAttribute("Status",QString::fromStdString(status));
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

void XMLDocument::songList(std::string* array,int size)
{
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

    docXml.writeStartDocument();

    docXml.writeStartElement("SongList");
    QString name;
    string x;
    for(int i =0;i<size;i++){ //i<list.lenght
        docXml.writeStartElement("Song");
        x = *(array+i);
        name= QString::fromStdString(x);
                //toStdString(x);
        docXml.writeAttribute("Name",name);
        docXml.writeEndElement();
    }
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}
