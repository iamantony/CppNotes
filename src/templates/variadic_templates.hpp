#ifndef VARIADIC_TEMPLATES_HPP
#define VARIADIC_TEMPLATES_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Templates::VariadicTemplates {

/*
We need a function that accept unknown number of parameters, convert them
to strings and return vector of these strings
*/

// Template function that transform argument to a string
template<typename T>
std::string ToStringImpl(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

// Base case of the variadic template - no args
std::vector<std::string> ToString() {
    return {};
}

// Variadic template that accepts unknown number of args, pass them to
// ToStringImpl() and put result into a vector
template<typename T, typename... Args>
std::vector<std::string> ToString(const T& value, const Args& ... args) {
    std::vector<std::string> vec;
    vec.push_back(ToStringImpl(value));

    const auto remainder = ToString(args...);
    vec.insert(vec.end(), remainder.begin(), remainder.end());
    return vec;
}

// Simplified solution
template<typename... Args>
std::vector<std::string> ToStringSimplified(const Args& ... args) {
    return { ToStringImpl(args)... };
}

void TransformValuesToStrings() {
    const auto strings = ToString(1, "hello", 7.1);
    for (const auto& s : strings) {
        std::cout << s << std::endl;
    }

    const auto strings2 = ToString("world", 'a');
    for (const auto& s : strings2) {
        std::cout << s << std::endl;
    }
}

/*
We need to implement variadic template function that takes arbitrary number
of arguments of unknown types and it should return sum of the arguments with
type int.
*/

int DetectInt(int /*value*/) {
    return 1;
}

template<typename T>
int DetectInt(T /*value*/) {
    return 0;
}

int CalcInts() {
    return 0;
}

template<typename T, typename... Args>
int CalcInts(T value, Args... args) {
    return DetectInt(value) + CalcInts(args...);
}

void SumIntegersViaVariadicTemplate() {
    std::cout << "Take 1: " << CalcInts() << std::endl;
    std::cout << "Take 2: " << CalcInts(1) << std::endl;
    std::cout << "Take 3: " << CalcInts("abc") << std::endl;
    std::cout << "Take 4: " << CalcInts(1, 2) << std::endl;
    std::cout << "Take 5: " << CalcInts("ab", 2) << std::endl;
    std::cout << "Take 6: " << CalcInts(5, "ab", 2, 3) << std::endl;
}

void Start() {
    TransformValuesToStrings();
    SumIntegersViaVariadicTemplate();
}

}

#endif // VARIADIC_TEMPLATES_HPP
