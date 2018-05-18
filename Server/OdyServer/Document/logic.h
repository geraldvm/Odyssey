#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include "parserxml.h"
#include "xmldocument.h"
#include <string>
#include <iostream>
#include "page.h"


using namespace std;
class Logic
{
public:
    Logic();
    void decision();
    void setGET(string GET);

private:
    string GET;
    XMLDocument *POST= new XMLDocument();
    ParserXML *xml= new ParserXML();
    /**
     * @brief writeGET create requested.xml
     */
    void writeGET();
    void getFileList();
    Page* page;


};

#endif // LOGIC_H
