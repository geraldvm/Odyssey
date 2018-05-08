#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QXmlStreamWriter>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    QString getAdministrador(QString dato);
    QString getDatoAdministrador(QString dato);
    void on_buttonBuscar_clicked();

    void on_buttonBuscarEtiqueta_clicked();

private:

    Ui::MainWindow *ui;
    QDomDocument *xmlTemporal;
};

#endif // MAINWINDOW_H
