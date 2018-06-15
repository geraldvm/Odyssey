#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <QString>
#include <QFile>
#include <QDir>

class Converter
{
public:
    Converter();
    QString path;
    QByteArray toBytes(QString name);
    void toFile(QByteArray bytes);
    void setPath(QString dir);
    void setPathFull(QString dir);

};

#endif // CONVERTER_H
