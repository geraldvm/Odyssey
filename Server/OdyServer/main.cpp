#include "mainwindow.h"
#include <QApplication>
#include "server.h"
#include "Mp3Binary/converter.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //w.show();

    /*
    std::cout<< "Current path :" << QDir::currentPath().toStdString() << std::endl;
    std::cout << "Home path :" << QDir::homePath().toStdString() << std::endl;
    std::cout << "Temporary path :" << QDir::tempPath().toStdString() << std::endl;
    std::cout << "Rooth path :" << QDir::rootPath().toStdString() << std::endl;
    */

    Converter c;
    c.mp3ToBinary();
    c.binaryToMp3();
    Server mserver;

    return a.exec();
}
