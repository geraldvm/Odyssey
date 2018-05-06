#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile xml("myXml.xml");
    xml.open(QIODevice::WriteOnly);

    QXmlStreamWriter escritorXml(&xml);
    //escritorXml.autoFormatting();
    escritorXml.setAutoFormatting(true);
    escritorXml.writeStartDocument();


    escritorXml.writeStartElement("administradores");
    escritorXml.writeStartElement("administrador");
    escritorXml.writeStartElement("datos");
    escritorXml.writeAttribute("nombre","Pablo");
    escritorXml.writeAttribute("equipo","1");

    //Etiqueta con caracteres
    escritorXml.writeStartElement("nivel");
    escritorXml.writeCharacters("Intermedio");
    escritorXml.writeEndElement();

    escritorXml.writeStartElement("puntos");
    escritorXml.writeCharacters("800");
    escritorXml.writeEndElement();

    escritorXml.writeEndElement();
    escritorXml.writeEndElement();

    escritorXml.writeStartElement("administrador");
    //Etiqueta con atributos
    escritorXml.writeStartElement("datos");
    escritorXml.writeAttribute("nombre","Juan");
    escritorXml.writeAttribute("equipo","2");
    //Etiqueta con caracteres
    escritorXml.writeStartElement("nivel");
    escritorXml.writeCharacters("Pro");
    escritorXml.writeEndElement();

    escritorXml.writeStartElement("puntos");
    escritorXml.writeCharacters("100");
    escritorXml.writeEndElement();


    escritorXml.writeEndElement();
    escritorXml.writeEndElement();

    escritorXml.writeStartElement("administrador");
    escritorXml.writeStartElement("datos");
    escritorXml.writeAttribute("nombre","Jose");
    escritorXml.writeAttribute("equipo","3");

    //Etiqueta con caracteres
    escritorXml.writeStartElement("nivel");
    escritorXml.writeCharacters("Semi pro");
    escritorXml.writeEndElement();

    escritorXml.writeStartElement("puntos");
    escritorXml.writeCharacters("552");
    escritorXml.writeEndElement();

    escritorXml.writeEndElement();
    escritorXml.writeEndElement();



    escritorXml.writeEndElement();
    escritorXml.writeEndDocument();
    xml.close();

    QFile salida("myXml.xml");
    salida.open(QIODevice::ReadOnly);
    QTextStream leer(&salida);
    ui->plainTextEdit->setPlainText(leer.readAll());

    salida.close();


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getAdministrador(QString dato)
{
    QFile xml("myXml.xml");
    xml.open(QIODevice::ReadOnly);
    xmlTemporal= new QDomDocument();
    xmlTemporal->setContent(&xml);
    xml.close();

    QDomElement raiz =xmlTemporal->documentElement();
    QDomElement Administradores = raiz.firstChildElement().toElement();

    while(!Administradores.isNull()){
        if(Administradores.tagName()=="administrador"){
            QDomElement administrador = Administradores.firstChild().toElement();
            while (!administrador.isNull()) {
                QString nombre = administrador.attribute("nombre","sin nombre");
                QString equipo = administrador.attribute("equipo","sin nombre");
                QString Resultado;
                if(!ui->radioNombre->isChecked()){
                    Resultado=equipo;
                    if(nombre==dato){
                        return Resultado;
                    }
                }else{
                    Resultado=nombre;
                    if(equipo==dato){
                        return Resultado;
                    }
                }
                administrador=administrador.nextSibling().toElement();

            }
        }
        Administradores = Administradores.nextSiblingElement().toElement();

    }

    return "Sin resultado";
}

QString MainWindow::getDatoAdministrador(QString dato)
{
    QFile xml("myXml.xml");
    xml.open(QIODevice::ReadOnly);
    xmlTemporal= new QDomDocument();
    xmlTemporal->setContent(&xml);
    xml.close();

    QDomElement raiz =xmlTemporal->documentElement();
    QDomElement Administradores = raiz.firstChildElement().toElement();

    while(!Administradores.isNull()){
        if(Administradores.tagName()=="administrador"){
            QDomElement administrador = Administradores.firstChild().toElement();
            while (!administrador.isNull()) {
                QString nombre = administrador.attribute("nombre","sin nombre");


                QDomElement datosAdministrador=administrador.firstChild().toElement();
                while (!datosAdministrador.isNull()) {

                    QString Resultado;
                    if(ui->radioNivel->isChecked()){
                        if(datosAdministrador.tagName()=="nivel"&&nombre==dato){
                            Resultado=datosAdministrador.firstChild().toText().data();
                            return Resultado;
                        }
                    }else{
                        if(datosAdministrador.tagName()=="puntos"&&nombre==dato){
                            Resultado=datosAdministrador.firstChild().toText().data();
                            return Resultado;
                        }

                    }datosAdministrador=datosAdministrador.nextSibling().toElement();
                }

                administrador=administrador.nextSibling().toElement();

            }
        }
        Administradores = Administradores.nextSiblingElement().toElement();

    }

    return "Sin resultado";
}

void MainWindow::on_buttonBuscar_clicked()
{
    ui->lineResultado->setText(getAdministrador(ui->lineBuscador->text()));
}

void MainWindow::on_buttonBuscarEtiqueta_clicked()
{
    ui->lineResultadoEtiqueta->setText(getDatoAdministrador(ui->lineBuscadorEtiqueta->text()));
}
