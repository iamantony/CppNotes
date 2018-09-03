#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <string>
#include <iostream>

// https://www.geeksforgeeks.org/arrays-in-c-language-set-1-introduction/
// https://www.geeksforgeeks.org/g-fact/
// https://www.geeksforgeeks.org/difference-pointer-array-c/

namespace Types::Arrays {

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

void AccessElementIn2DArray() {
    /*
     https://www.geeksforgeeks.org/multidimensional-pointer-arithmetic-in-cc/amp/

    In C/C++, arrays and pointers have similar semantics, except on type
    information.

    As an example, given a 3D array

    int buffer[5][7][6];

    An element at location [2][1][2] can be accessed as “buffer[2][1][2]” or
    *( *( *(buffer + 2) + 1) + 2).

    Observe the following declaration:
    T *p; // p is a pointer to an object of type T

    When a pointer p is pointing to an object of type T, the expression *p is
    of type T. For example buffer is of type array of 5 two dimensional arrays.
    The type of the expression *buffer is “array of arrays (i.e.
    two dimensional array)”.

    Based on the above concept translating the expression
    *( *( *(buffer + 2) + 1) + 2) step-by-step makes it more clear.

    1. buffer – An array of 5 two dimensional arrays, i.e. its type is
    “array of 5 two dimensional arrays”.

    2. buffer + 2 – displacement for 3rd element in the array of
    5 two dimensional arrays.

    3. *(buffer + 2) – dereferencing, i.e. its type is now two dimensional array.
    4. *(buffer + 2) + 1 – displacement to access 2nd element in the array of
    7 one dimensional arrays.

    5. *( *(buffer + 2) + 1) – dereferencing (accessing), now the type of
    expression “*( *(buffer + 2) + 1)” is an array of integers.

    6. *( *(buffer + 2) + 1) + 2 – displacement to get element at 3rd position
    in the single dimension array of integers.

    7. *( *( *(buffer + 2) + 1) + 2) – accessing the element at 3rd position
    (the overall expression type is int now).
     */

    int buffer[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    std::cout << "Element [1][2][3]: " << buffer[1][2][3] << std::endl;

    std::cout << "Element [1][2][3] via pointer: " <<
                 *(*(*(buffer + 1) + 2) + 3) << std::endl;

    *(*(*(buffer + 1) + 2) + 3) = 60;
    std::cout << "Element [1][2][3] via pointer after edit: " <<
                 *(*(*(buffer + 1) + 2) + 3) << std::endl;
}

void Start() {
    InitArray();
    InitArrayString();
    PointerVsArray();
    AccessElementIn2DArray();
}

}

#endif // ARRAYS_HPP

