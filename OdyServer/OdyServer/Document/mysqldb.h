#ifndef MYSQLDB_H
#define MYSQLDB_H

#include "DataStructures/SimpleList/listasimple.h"
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <QtSql>

//clave mysql root = odyserver

class MySQLDB
{
public:
    MySQLDB();
    QJsonObject getInfoCancion(QString nombre);
    bool modificarInfoCancion(QString nombre, QJsonObject info);
    bool agregarCancion(QJsonObject info);
    bool eliminarCancion(QString nombre);

private:
    QSqlDatabase base;
    QString nombreBase = "metadata";

};

#endif // MYSQLDB_H
