#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <QString>
#include "DataStructures/SimpleList/listasimple.h"
#include "Document/mysqldb.h"

class backtracking
{
public:
    backtracking();
    QString buscar(QString frase);

private:
    int indiceFrase = 0;
    MySQLDB base;
    QStringList palabrasFrase;
    ListaSimple<QString> canciones;
    bool buscarAux(QStringList letraFull);

};

#endif // BACKTRACKING_H
