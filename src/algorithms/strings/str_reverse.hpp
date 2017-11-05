#ifndef STR_REVERSE_HPP_
#define STR_REVERSE_HPP_

// Implement a function void reverse(char* str) in C or C++ which reverses a
// null-terminated string

#include <cstring>

void ReverseString(char* str)
{
    size_t size = strlen(str);
    if (size < 2)
    {
        return;
    }

    char* i = str;
    char* j = str + size - 1;
    while(i < j)
    {
        char buff = *i;
        *i++ = *j;
        *j-- = buff;
    }
}

#endif /* STR_REVERSE_HPP_ */
