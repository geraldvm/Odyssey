#ifndef PAGE_H
#define PAGE_H



class Page
{
public:
    Page();
    ~Page();
    string * getData(int page);
    void setArray(string *array);
    int getSize(int page);

private:
    string *array;

#endif // PAGE_H
