#include "mainwindow.h"
#include <QApplication>
#include "Server/server.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Server mserver;

    return a.exec();
}
