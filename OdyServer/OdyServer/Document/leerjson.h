#ifndef LEERJSON_H
#define LEERJSON_H

#include <QtCore/QJsonArray>
#include <fstream>
#include <QtCore/QJsonObject>
#include <iostream>
#include "QDir"
#include "DataStructures/SimpleList/listasimple.h"

/**
 * Clase que carga todos los Json contenidos en un archivo
 */
class leerJson {
private:
    /**
     * Lista que va a contener todos los Json
     */
    ListaSimple<QJsonObject> listaArchivosJson;
    /**
     * Directorio en donde está cargada la información de los usuarios
     */
    std::string dirUsers = QDir::homePath().toStdString().append("/Music/Odyssey/data/userInfo.txt");
    /**
     * Directorio en donde se guardará la información de la metadata
     */
    std::string dirMetadata = QDir::homePath().toStdString().append("/Music/Odyssey/data/metadata.txt");

public:
    /**
     * Función para leer los Json que corresponden a un usuario
     * @return Lista con todos los Json
     */
    ListaSimple<QJsonObject> getUsersInfo();
    /**
     * Función para leer todos los Json que corresponden a la metadata
     * @return Lista con todos los Json
     */
    ListaSimple<QJsonObject> getMetadata();
};

#endif // LEERJSON_H
