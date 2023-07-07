// C++ Program to implement
// template Array class
#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s)
    {
        ptr = new T[s];
        size = s;
        for (int i = 0; i < size; i++)
            ptr[i] = arr[i];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            std::cout << " " << *(ptr + i);
        std::cout << std::endl;
    }
};

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);


    a.print();

    std::string arrStr[3] = {"amiraloo", "amirala", "amirali"};
    Array<std::string> stringArr(arrStr, 3);
    stringArr.print();
    return 0;
}