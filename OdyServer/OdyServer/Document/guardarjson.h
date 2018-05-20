#ifndef GUARDARJSON_H
#define GUARDARJSON_H
#include <c++/5/string>
#include <QtCore/QJsonObject>
#include <fstream>
#include <QtCore/QJsonArray>
#include "QDir"
/**
 * Clase para guardar en disco la información de los usuarios y la metadata
 */
class guardarJson {

private:
    /**
     * Directorio en donde se guardará la información de los usuarios
     */
    std::string dirUsers = QDir::homePath().toStdString().append("/Music/Odyssey/data/userInfo.bin");
    /**
     * Directorio en donde se guardará la información de la metadata
     */
    std::string dirMetadata = QDir::homePath().toStdString().append("/Music/Odyssey/data/metadata.bin");

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

#endif // GUARDARJSON_H
