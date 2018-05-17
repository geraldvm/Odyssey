#ifndef CANCION_H
#define CANCION_H
#include <QtCore/QJsonObject>

using namespace std;
/**
 * @brief The cancion class : Clase para almacenar una canción y sus datos
 */
class Cancion {

private:
    /**
     * @brief nombre : Nombre de  la canción
     */
    string nombre;
    /**
     * @brief dir : Directorio en donde se encuentra la canción
     */
    string dir;
    /**
     * @brief metadata : Json con la información de la canción
     */
    QJsonObject metadata;

public:
    /**
     * @brief Cancion : Constructor de la clase
     * @param in : Nombre de la Cancion
     * @param data : Json con la metadata
     * @param direccion : Dirección en donde se encuesntra la canción
     */
    Cancion(string in, QJsonObject data, string direccion);
    /**
     * @brief setMetadata : Setter metadata
     * @param in : json con la metadata
     */
    void setMetadata(QJsonObject in);
    /**
     * @brief get : Getter de algún valor almacenado en la metadata
     * @param key : Valor a buscar
     * @return : Valor en el Json
     */
    string get(string key);
    /**
     * @brief getDir : Getter del directorio de la canción
     * @return : Directorio de la canción
     */
    string getDir();
    /**
     * @brief getMetadata : Getter del Json que contiene la metadata
     * @return : Json con la metadata
     */
    QJsonObject getMetadata();

};

#endif // CANCION_H
