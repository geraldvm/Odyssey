#include "binarysearch.h"
BinarySearch::BinarySearch(string file){
    this->file=file;

}
template<class T>
int BinarySearch::binarySearch(int l, int r, T data)
{

    ifstream file("database.dat", ios::binary);
    int temp=0;
    while (l <= r)
    {
        int m = l + (r-l)/2;


        // Check if x is present at mid
        file.seekg(m*sizeof(int), ios_base::beg);
        file.read((char*)&temp, sizeof(int));
        if (temp == data)
            return m;

        // If x greater, ignore left half
        if (temp < data)
            l = m + 1;

            // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}



int BinarySearch::binarySearch(T data) {
    ifstream file("database.dat", ios::binary);
    file.seekg(sizeof(T), ios_base::end);
    return binarySearch(0,(file.tellg()/sizeof(T))-1,data);
}


BinarySearch::~BinarySearch(){

}