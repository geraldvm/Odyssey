#ifndef RAIDCONTROLLER_H
#define RAIDCONTROLLER_H

#include "Document/converter.h"
#include <iostream>
#include <QApplication>
#include <fstream>
#include <QDir>
#include <QBitArray>
#include <QFileInfo>
#include "DataStructures/SimpleList/listasimple.h"
#include <fstream>
#include <stdio.h>
#include <iostream>

class RaidController
{

private:

    Converter converter = Converter();
    QString disc1 = QDir::homePath().append("/Music/Odyssey/Library/Disc1/");
    QString disc2 = QDir::homePath().append("/Music/Odyssey/Library/Disc2/");
    QString disc3 = QDir::homePath().append("/Music/Odyssey/Library/Disc3/");
    QString auxInfo = QDir::homePath().append("/Music/Odyssey/data/RaidData/indexes.txt");

    QBitArray convertirABits(QByteArray in);
    QByteArray convertirABytes(QBitArray in);
    QByteArray calcularParidad(QByteArray p1, QByteArray p2);

    QByteArray Autorecovery(QString d1, QString d2, QString d3);
    void stripping(QByteArray in, QString d1, QString d2, QString d3);
    int indicePar = 3;

    std::vector<QString> listaNombres;
    std::vector<int> indexes;
    std::vector<int> fileSizes;
    void guardarRegistro(QString nombre, int i, int size);

public:
    RaidController();
    QByteArray songRequest(QString nombre, int pos);
    void writeSong(QString nombre, QByteArray in);
    bool deleteSong(QString nombre);

};

#endif // RAIDCONTROLLER_H
