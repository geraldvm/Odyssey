#include "converter.h"

Converter::Converter()
{
    //path=QDir::homePath().append("/Music/Library/newVideo.mp3");
    path=QDir::homePath().append("/Music/Library/");

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
    QFile file(QDir::homePath().append("/Music/Library/newVideo.mp4"));
    file.open(QIODevice::WriteOnly);
    file.write(bytes);
    file.close();
}
