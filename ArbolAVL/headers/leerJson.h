//
// Created by andres on 05/05/18.
//

#ifndef ARBOLAVL_LEERJSON_H
#define ARBOLAVL_LEERJSON_H


#include <QtCore/QJsonArray>
#include "../estructuras/headers/ListaSimple.h"
#include <fstream>
#include <QtCore/QJsonObject>
#include <c++/5/iostream>
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


#endif //ARBOLAVL_LEERJSON_H
