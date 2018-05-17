#ifndef GUARDARJSON_H
#define GUARDARJSON_H



#include <string>
#include <QtCore/QJsonObject>
#include <fstream>
#include <QtCore/QJsonArray>
/**
 * Clase para guardar en disco la información de los usuarios y la metadata
 */
class guardarJson {

private:
    /**
     * Directorio en donde se guardará la información de los usuarios
     */
    std::string dirUsers = "../data/users/usersInfo";
    /**
     * Directorio en donde se guardará la información de la metadata
     */
    std::string dirMetadata = "../data/metadata/metadata";

public:
    /**
     * Función para guardar el Json que corresponde a un usuario
     * @param archivo : Json a guardar
     */
    void guardarJsonUsers(QJsonObject archivo);
    /**
     * Función para almacenar el Json con la metadata de una canción
     * @param archivo : Json a guardar
     */
    void guardarJsonMetadata(QJsonObject archivo);

};

2

#endif // GUARDARJSON_H
