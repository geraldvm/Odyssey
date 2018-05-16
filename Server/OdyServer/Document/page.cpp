#include "page.h"

Page::Page(string *array)
{
    this->array = array;
    this->temp = temp;
    this->tam = 16;

}

Page::~Page()
{
    free(this->array);
    delete[]temp;
}

string *Page::getData(int page)
{
    if((tam %10 != 0) && ((page*10) == (tam-(tam%10)))){
            temp = new string[tam%10];

            for(int i = 0; i<=(tam%10)-1; i++){

                temp[i] = this->array[(page * 10) + i];
                cout << "Arr" << i << "=" << temp[i] << endl;

            }

            cout<<"Arreglo"<<temp<<endl;
            return this->temp;


        }else {
            temp = new string[10];
            cout<<"jjjjj";

            for(int i = 0; i<=9; i++){

                temp[i] = this->array[(page * 10) + i];
                cout << "Arr" << i << "=" << temp[i] << endl;

            }

            cout<<"Arreglo"<<temp<<endl;
            return this->temp;
}

}
