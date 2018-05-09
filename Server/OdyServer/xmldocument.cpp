#include "xmldocument.h"

XMLDocument::XMLDocument()
{
    QFile xml("myXml.xml");
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
}

void XMLDocument::userVerification(std::string status)
{
    docXml.writeStartDocument();

    docXml.writeStartElement("userVerification");

    docXml.writeStartElement("user");
    docXml.writeAttribute("Status",status);
    docXml.writeEndElement();

    docXml.writeEndElement();

    docXml.writeEndDocument();
    xml.close();

}

void XMLDocument::song(std::string number, std::data)
{

    docXml.writeStartDocument();

    docXml.writeStartElement("Song");

    docXml.writeStartElement("Chunk");
    docXml.writeAttribute("Part",number);
    docXml.writeAttribute("Data",data);
    docXml.writeEndElement();

    docXml.writeEndElement();

    docXml.writeEndDocument();
    xml.close();

}

void XMLDocument::songList()
{
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


