#ifndef LEERJSON_H
#define LEERJSON_H




#include <QtCore/QJsonArray>
#include "DataStructures/listasimple.h"
#include <fstream>
#include <QtCore/QJsonObject>
#include <iostream>
/**
 * Clase que carga todos los Json contenidos en un archivo
 */
class leerJson {
private:
    /**
     * Lista que va a contener todos los Json
     */
    ListaSimple<QJsonObject> listaArchivosJson = ListaSimple<QJsonObject>();
    /**
     * Directorio en donde está cargada la información de los usuarios
     */
    std::string dirUsers = "../data/users/usersInfo";
    /**
     * Dirección en donde está cargada la información de la metadata
     */
    std::string dirMetadata = "../data/metadata/metadata";

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
