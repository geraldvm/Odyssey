#include "page.h"


Page::Page()
{

}

Page::~Page(){

}

string *Page::getData(int page){

}

void Page::setArray(string *array)
{
    this->array = array;
}

int Page::getSize(int page)
{
    int size;
    if(tam/10== page){
        size = tam%10;
        return size;
    }
    else{
        return 10;
    }
}
