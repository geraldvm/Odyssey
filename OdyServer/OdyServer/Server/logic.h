#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include "Document/parserxml.h"
#include "Document/xmldocument.h"
#include <string>
#include <iostream>
//#include "page.h"


using namespace std;
class Logic
{
public:
    Logic();
    void decision();
    void setGET(string GET);
    /**
     * @brief writeGET create requested.xml
     */
    void writeGET();

private:
    string GET;
    XMLDocument *POST= new XMLDocument();
    ParserXML *xml= new ParserXML();

    void getFileList();
    //Page* page;


};


#endif // LOGIC_H
