#include "backtracking.h"

backtracking::backtracking()
{
    canciones = base.obtenerCanciones();
    
}

QString backtracking::buscar(QString frase){
    bool encontrado = false;
    int indice = 0;
    palabrasFrase = frase.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    while(!encontrado){
        if (indice == canciones.size){
            return "false";
        }
        QStringList letraFull = base.obtenerLetra(canciones.get(indice)).split(QRegExp("\\s+"), QString::SkipEmptyParts);
        encontrado = buscarAux(letraFull);
        if (!encontrado) {
            indice++;
        }
    }

    return canciones.get(indice);
}

bool backtracking::buscarAux(QStringList letraFull){
    for(int i = 0; i < letraFull.size(); i++){
        if (((QString) letraFull[i]) == palabrasFrase.at(indiceFrase)){
            indiceFrase ++;
            if (indiceFrase == palabrasFrase.size()){
                return true;
            }
        } else{
            indiceFrase = 0;
        }
    }
    return false;
}
