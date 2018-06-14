#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <iostream>
#include <string>
#include <string.h>
#include "DataStructures/SimpleList/simplelist.h"
#include "DataStructures/SimpleList/node.h"
#include <dirent.h>


class File
{
public:
    File();
    void muestra_contenido_de();

private:
    QString FileName = "/Music/Odyssey/Temppp";

};

#endif // FILE_H
