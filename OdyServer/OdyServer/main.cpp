#include "mainwindow.h"
#include <QApplication>
#include "DataStructures/SimpleList/simplelist.h"
#include "Server/server.h"
#include "Document/jsonmaker.h"
#include "Document/guardarjson.h"
#include "Document/leerjson.h"
#include "DataStructures/SimpleList/hashmap.h"

int main(int argc, char *argv[])
{

    leerJson lJ = leerJson();

    std::cout << ((QJsonObject)lJ.getUsersInfo().get(0)).value("nombre").toString().toStdString();
    hashmap mapa = hashmap();
    mapa.escribirPass("user","pass");
    mapa.guardarMapa();
    mapa.leerMapa();
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Server mserver;

    return a.exec();
}
