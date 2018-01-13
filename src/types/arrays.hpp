#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <string>
#include <iostream>

// https://www.geeksforgeeks.org/arrays-in-c-language-set-1-introduction/
// https://www.geeksforgeeks.org/g-fact/
// https://www.geeksforgeeks.org/difference-pointer-array-c/

namespace Arrays {

void PrintArray(int* arr, const size_t& size, const std::string& info) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << info << " " << i << ": " << arr[i] << std::endl;
    }
}

void InitArray() {
    // We can init array by differen ways:
    // 1. Only specify size of array. Values will be init to default value - 0
    int arr[5];
    PrintArray(arr, 5, "arr");

    // 2. Array declaration by initializing elements. In this case we will get
    // array of size 4
    int arr2[] = {10, 20, 30, 40};
    PrintArray(arr2, 4, "arr2");

    // 3. Array declaration by specifying size and initializing elements. In
    // this case compiler will init first 4 elements by specified values and
    // last 2 elements with default value - 0
    int arr3[6] = {10, 20, 30, 40};
    PrintArray(arr3, 6, "arr3");

    // In C++ it is compiler error to initialize an array with more elements
    // than specified size.
//    int arrErr[2] = {10, 20, 30, 40};
}

void InitArrayString() {
    // In C/C++, when a character array is initialized with a double quoted
    // string and array size is not specified, compiler automatically allocates
    // one extra space for string terminator ‘\0’

    char arrStr[] = "example";
    std::cout << "Size of arrStr: " <<
                 sizeof(arrStr)/sizeof(arrStr[0]) << std::endl;

    // Compilation error in C++:
//    char arrStr[7] = "example";

    // When character array is initialized with comma separated list of
    // characters and array size is not specified, compiler doesn’t create
    // extra space for string terminator ‘\0’
    char arrStrComma[] = {'e', 'x', 'a', 'm', 'p', 'l', 'e'};
    std::cout << "Size of arrStrComma: " <<
                 sizeof(arrStrComma)/sizeof(arrStrComma[0]) << std::endl;
}

void PointerVsArray() {
    // Behaviour of sizeof()
    int arr[] = {1, 2};
    int* ptr = arr;
    std::cout << "Size of arr: " << sizeof(arr) << std::endl;
    std::cout << "Size of pointer to arr: " << sizeof(ptr) << std::endl;

    // You can not assign any variable to array variable
    // arr = someOtherPtr;
}

void Start() {
    InitArray();
    InitArrayString();
    PointerVsArray();
}

}

#endif // ARRAYS_HPP

