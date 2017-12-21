#ifndef CPPN_PREPROCESSOR_DEFINE_USAGE_HPP_
#define CPPN_PREPROCESSOR_DEFINE_USAGE_HPP_

#include <iostream>

// How to declare macros functions via define
#define SUMM_TWO_VALUES(a, b) ((a)+(b))
#define GET_MAX(a, b) ((a) > (b) ? (a) : (b))

void DefineFunctionsExamples() {
    std::cout << "Examples of defined functions" << std::endl;

    std::cout << "Lets calculate sum of two values using "
                 "#define SUMM_TWO_VALUES" << std::endl;

    int first = 1, second = 5;
    std::cout << first << " + " << second << " = " <<
                 SUMM_TWO_VALUES(first, second) << std::endl;

    std::cout << "No when calling SUMM_TWO_VALUES increment first value"
              << std::endl;

    int result = SUMM_TWO_VALUES(++first, second);
    std::cout << first << " + " << second << " = " <<
                  result << std::endl;

    std::cout << "Lets get max of two values using #define GET_MAX."
                 " Our values: " << first << " and " << second << std::endl;

    std::cout << "Max = " << GET_MAX(first, second) << std::endl;

    std::cout << "No when calling GET_MAX increment second value" << std::endl;
    std::cout << "Max = " << GET_MAX(first, ++second) << std::endl;
    std::cout << "second value was incremented two times!" << std::endl;
}

#endif
