#ifndef ABSTRACT_CLASS_HPP
#define ABSTRACT_CLASS_HPP

#include <iostream>

namespace PureAbstrClass {

// Pure abstract class - only abstract functions (with virtual destructor)
class Base {
public:
    virtual ~Base() {}

    virtual void Function() = 0;
};

class Derived : public Base {
public:
    virtual ~Derived() override {}

    virtual void Function() override;
};

void Derived::Function() {
    std::cout << "In PureAbstrClass::Derived::Function()" << std::endl;
}

}


namespace PureAbstrClassWFR {

// Pure abstract class with abstract virtual function and it's realisation
class Base {
public:
    virtual ~Base() {}

    virtual void Function() = 0;
};

void Base::Function() {
    std::cout << "In PureAbstrClassWFR::Base::Function()" << std::endl;
}

class Derived : public Base {
public:
    virtual ~Derived() override {}

    virtual void Function() override;
};

void Derived::Function() {
    std::cout << "In PureAbstrClassWFR::Derived::Function()" << std::endl;
}

}

void StartAbstractClass() {
    // We can not create object of pure abstract class
    //PureAbstrClass::Base baseObj;

    PureAbstrClass::Derived derivedObj;
    derivedObj.Function();

    // Even if we provide realisation of pure virtual function in
    // pure abstrac class, we still can not create object of such class
    // PureAbstrClassWFR::Base baseWFRObj;

    PureAbstrClassWFR::Derived derivedWFRObj;
    derivedWFRObj.Function();
}

#endif // ABSTRACT_CLASS_HPP
