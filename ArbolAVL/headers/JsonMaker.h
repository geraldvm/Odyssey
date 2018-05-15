//
// Created by andres on 05/05/18.
//

#ifndef ARBOLAVL_JSONMAKER_H
#define ARBOLAVL_JSONMAKER_H

//checkusernotrepeated

#include <QtCore/QJsonObject>
#include <vector>
#include <QtCore/QJsonArray>
#include "../estructuras/headers/ListaSimple.h"

using namespace std;

class JsonMaker {

public:
    JsonMaker(string titulo, string artista, string album, string genero, int numeroPista, int numeroDisco, int anno, int calificacion, string letra);
    JsonMaker(string user, string nombre, string apellido, int edad, QJsonArray favoritos, int pass, QJsonArray amigosUsers);
    QJsonObject getJson();

private:
    QJsonObject jsonObject;
    bool modificarMetadata(string titulo, ListaSimple<ListaSimple<string>> cambios);
};


#endif //ARBOLAVL_JSONMAKER_H
