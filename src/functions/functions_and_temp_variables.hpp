#ifndef FUNCTIONS_AND_TEMP_VARIABLES_HPP
#define FUNCTIONS_AND_TEMP_VARIABLES_HPP

// http://alenacpp.blogspot.com/2008/02/rvo-nrvo.html

#include <iostream>

namespace Functions {

class Base {
public:
    // Default constructor
    Base() { std::cout << "Base()" << std::endl; }

    // Converion constructor: from int to Base object
    Base(const int& value) : m_value(value) {
        std::cout << "Base(const int&)" << std::endl;
    }

    // Copy constructor
    Base(const Base& other) : m_value(other.m_value) {
        std::cout << "Base(const Base&)" << std::endl;
    }

    // Move constructor
    Base(Base&& other) : m_value(std::move(other.m_value)) {
        std::cout << "Base(Base&&)" << std::endl;
    }

    // Destructor
    ~Base() { std::cout << "~Base(): " << m_value << std::endl; }

    int m_value = 0;
};

int CalcSum(const Base& object, const int& value) {
    std::cout << "In CalcSum()" << std::endl;
    return object.m_value + value;
}

// RVO - Return Value optimization
// Compilator could not create temp object and construct the object defined by
// the return expression inside the memory allotted for the object.
Base InitBaseRVO(const int& value) {
    std::cout << "In InitBaseRVO()" << std::endl;
    return Base(value);
}

// NRVO - Named Return Value Optimization
// Compilator would create only one object, which would be returned to caller
Base InitBaseNRVO(const int& value) {
    std::cout << "In InitBaseNRVO()" << std::endl;
    Base object;
    object.m_value = value;
    return object;
}

void Start() {
    // Here we would create temp Base object from argument '5', pass it to
    // function CalcSum(), and after return destroy temp object.
    int sum =  CalcSum(5, 4);
    std::cout << "Sum is " << sum << std::endl;

    // Here we would use RVO compiler optimisation. No temp objects would be
    // created, only one - result
    Base result = InitBaseRVO(10);
    std::cout << "Inited Base object have value " << result.m_value <<
                 std::endl;

    Base resultNRVO = InitBaseNRVO(15);
    std::cout << "NRVO-Inited Base object have value " << resultNRVO.m_value <<
                 std::endl;
}

}

#endif // FUNCTIONS_AND_TEMP_VARIABLES_HPP
