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

    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //Server mserver;

    Converter c;

    c.toFile(c.toBytes("Firestone.mp4"));


    return a.exec();
}
