#include "converter.h"

Converter::Converter()
{
    path=QDir::homePath().append("/Music/Odyssey/Library/");

}

QByteArray Converter::toBytes(QString name)
{
    QFile file(path.append(name));
    file.open(QIODevice::ReadOnly);
    QByteArray bytes = file.readAll();
    return bytes;

}

void Converter::toFile(QByteArray bytes)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    file.write(bytes);
    file.close();
}

void Converter::setPath(QString dir){
    path = QDir::homePath().append("/Music/Odyssey/Library/"+dir);
}

void Converter::setPathFull(QString dir){
    path = dir;
}
