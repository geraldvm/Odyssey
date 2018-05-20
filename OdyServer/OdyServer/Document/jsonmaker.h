#ifndef JSONMAKER_H
#define JSONMAKER_H

#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <vector>
#include "DataStructures/SimpleList/simplelist.h"

using namespace std;
/**
 * Clase para crear los Json de la metadata y los usuarios
 */
class JsonMaker {

public:
    /**
     * Constructor de la clase para una canción
     * @param titulo
     * @param artista
     * @param album
     * @param genero
     * @param numeroPista
     * @param numeroDisco
     * @param anno
     * @param calificacion
     * @param letra
     */
    JsonMaker(string titulo, string artista, string album, string genero, int numeroPista, int numeroDisco, int anno, int calificacion, string letra);
    /**
     * Constructor de la clase para un usuario
     * @param user
     * @param nombre
     * @param apellido
     * @param edad
     * @param favoritos
     * @param pass
     * @param amigosUsers
     */
    JsonMaker(string user, string nombre, string apellido, int edad, QJsonArray favoritos, int pass, QJsonArray amigosUsers);
    /**
     * Getter del objeto construido
     * @return
     */
    QJsonObject getJson();
    /**
     * Función para modificar el Json de la metadata
     * @param titulo : Nombre de la canción a modificar
     * @param cambios : Lista con los cambios a realizar
     * @param valor : Lista con las valores nuevos
     * @return : Boleano que indica si el cambio se pudo realizar o no
     */
    bool modificarMetadata(string titulo, vector<string> cambios, vector<string> valor);

private:
    /**
     * Variable con el objeto construido
     */
    QJsonObject jsonObject;

};

#endif // JSONMAKER_H
