#ifndef VARIADIC_TEMPLATES_HPP
#define VARIADIC_TEMPLATES_HPP

/*
We need to implement variadic template function that takes arbitrary number
of arguments of unknown types and it should return sum of the arguments with
type int.
*/

#include <iostream>

namespace Templates::VariadicTemplates {

template<typename... Args>
int CalcInts() {
    return 0;
}

template<typename T, typename... Args>
int CalcInts(T /*value*/, Args... args) {
    return 0 + CalcInts(args...);
}

template<typename... Args>
int CalcInts(int /*value*/, Args... args) {
    return 1 + CalcInts(args...);
}

template<typename T>
int CalcInts(T /*value*/) {
    return 0;
}

template<>
int CalcInts<int>(int /*value*/) {
    return 1;
}

void SumIntegersViaVariadicTemplate() {
    std::cout << "Take 1: " << CalcInts() << std::endl;
    std::cout << "Take 2: " << CalcInts(1) << std::endl;
    std::cout << "Take 3: " << CalcInts("abc") << std::endl;
    std::cout << "Take 4: " << CalcInts(1, 2) << std::endl;
    std::cout << "Take 5: " << CalcInts("ab", 2) << std::endl;
    std::cout << "Take 6: " << CalcInts(5, "ab", 2) << std::endl;
}

void Start() {
    SumIntegersViaVariadicTemplate();
}

}

#endif // VARIADIC_TEMPLATES_HPP
