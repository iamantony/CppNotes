#ifndef MULTY_INHERITANCE_H_
#define MULTY_INHERITANCE_H_

#include <iostream>

namespace Classes::MutliInheritance {

class First {
public:
    First() {
        std::cout << "In First constructor" <<  std::endl;
    };

    virtual ~First() {
        std::cout << "In First destructor" << std::endl;
    };
};

class Second {
public:
    Second() {
        std::cout << "In Second constructor" <<  std::endl;
    };

    virtual ~Second() {
        std::cout << "In Second destructor" << std::endl;
    };
};

class Derived : public First, public Second {
public:
    Derived() {
        std::cout << "In Derived constructor" <<  std::endl;
    };

    virtual ~Derived() override {
        std::cout << "In Derived destructor" << std::endl;
    };
};

void StartMI() {
    std::cout << "multi_inheritance" << std::endl << std::endl;

    std::cout << "Create Derived class object:" << std::endl;
    Derived *derivedObject = new Derived();

    std::cout << "Delete Derived class object:" << std::endl;
    delete derivedObject;
}

}

#endif /* MULTY_INHERITANCE_H_ */
