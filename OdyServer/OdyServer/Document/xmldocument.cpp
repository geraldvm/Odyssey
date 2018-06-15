#include "xmldocument.h"


XMLDocument::XMLDocument()
{
    path=QDir::homePath().append("/Music/Odyssey/Temp/myXml.xml");
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);

}

void XMLDocument::userVerification(bool status)
{
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
    docXml.writeStartDocument();
    docXml.writeStartElement("userVerification");
    docXml.writeStartElement("user");
    docXml.writeAttribute("Status",QString::number((int)status));
    docXml.writeEndElement();
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();

}

void XMLDocument::sendSong(int size, std::string name)
{
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
    docXml.writeStartDocument();
    docXml.writeStartElement("Song");
    //docXml.writeStartElement("Name");
    docXml.writeAttribute("Size",size);
    docXml.writeAttribute("Name",name);
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
        docXml.writeAttribute("Name",*(array+i)->c_str());
        //docXml.writeAttribute("Name",name);
        docXml.writeEndElement();
    }
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}

void XMLDocument::newUser(bool status){
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
    docXml.writeStartDocument();
    docXml.writeStartElement("newUser");
    docXml.writeAttribute("Status",QString::number((int)status));
    docXml.writeEndElement();
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}

void XMLDocument::modifyMetadata(bool status){
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
    docXml.writeStartDocument();
    docXml.writeStartElement("modifyMetadata");
    docXml.writeAttribute("Status",QString::number((int)status));
    docXml.writeEndElement();
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}

void XMLDocument::deleteSong(bool status){
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
    docXml.writeStartDocument();
    docXml.writeStartElement("deleteSong");
    docXml.writeAttribute("Status",QString::number((int)status));
    docXml.writeEndElement();
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}

void XMLDocument::searchPhrase(QString nombre){
    QFile xml(path);
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter docXml(&xml);
    docXml.setAutoFormatting(true);
    docXml.writeStartDocument();
    docXml.writeStartElement("Busqueda Frase");
    docXml.writeAttribute("Cancion",nombre);
    docXml.writeEndElement();
    docXml.writeEndElement();
    docXml.writeEndDocument();
    xml.close();
}
