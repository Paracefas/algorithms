#include <functional>
#include <iostream>
#include <stdio.h>

struct array_t
{
    int* data;
    size_t size;
};

array_t* mk_array (size_t s)
{
    array_t* result = (array_t*) malloc(sizeof(array_t));
    result->size = s;
    result->data = (int*) malloc (sizeof(int)*s);
    return result;
}

int main (int argc, char const** argv)
{
    array_t* arr = mk_array(10);
    for (int i = 0; i < arr->size; ++i)
        arr->data[i] = i +1;
    for (int i = 0; i < arr->size; ++i)
        std::cout << arr->data[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < arr->size/2; ++i)
    {
        int t = arr->data[i];
        std::cout << "t: " << t << "\n";
        arr->data[i] = arr->data[arr->size -i -1];
        std::cout << "data i: " << arr->data[i] << '\n';
        arr->data[arr->size -i -1] = t;
        std::cout << "data size -i -1: " << arr->data[arr->size -i -1] << '\n';
    }

    for (int i = 0; i < arr->size; ++i)
        std::cout << arr->data[i] << " ";
    std::cout << "\n";

}
