#ifndef PAGE_H
#define PAGE_H



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Page
{
public:
    Page(string *array);
    ~Page();
    string * getData(int page);

private:
    string *array;
    string *temp;
    int tam;
};



#endif // PAGE_H
