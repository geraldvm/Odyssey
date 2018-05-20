#ifndef LEERJSON_H
#define LEERJSON_H
#include <QtCore/QJsonArray>
#include "DataStructures/SimpleList/simplelist.h"
#include <fstream>
#include <QtCore/QJsonObject>
#include <c++/5/iostream>
#include "QDir"

/**
 * Clase que carga todos los Json contenidos en un archivo
 */
class leerJson {
private:
    /**
     * Lista que va a contener todos los Json
     */
    std::vector<QJsonObject> listaArchivosJson;
    /**
     * Directorio en donde está cargada la información de los usuarios
     */
    std::string dirUsers = QDir::homePath().append("/Music/Odyssey/data/usersInfo.bin").toStdString();
    /**
     * Dirección en donde está cargada la información de la metadata
     */
    std::string dirMetadata = QDir::homePath().append("/Music/Odyssey/data/metadada.bin").toStdString();

public:
    /**
     * Función para leer los Json que corresponden a un usuario
     * @return Lista con todos los Json
     */
    std::vector<QJsonObject> getUsersInfo();
    /**
     * Función para leer todos los Json que corresponden a la metadata
     * @return Lista con todos los Json
     */
    std::vector<QJsonObject> getMetadata();
};

#endif // LEERJSON_H
