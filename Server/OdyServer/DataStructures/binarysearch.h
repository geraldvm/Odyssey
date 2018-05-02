#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

template<typename T>
/**
 * @brief The BinarySearch class
 */
class BinarySearch
{
public:
    BinarySearch(T array);
    search(T data);

private:
    T array[];
    search(int l, int r, T data);
};

#endif // BINARYSEARCH_H
