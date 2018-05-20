#include "mainwindow.h"
#include <QApplication>
#include "DataStructures/SimpleList/simplelist.h"
#include "Server/server.h"
#include "Document/jsonmaker.h"
#include "Document/guardarjson.h"
#include "Document/leerjson.h"

int main(int argc, char *argv[])
{
    JsonMaker jm = JsonMaker("ltitulo","la","la","lg",1,2,2018,1,"letra");
    guardarJson gJ;
    gJ.guardarJsonMetadata(jm.getJson());
    leerJson lJ;






    std::cout << lJ.getMetadata().get(0).value("artista").toString().toStdString();





    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Server mserver;

    return a.exec();
}
