#ifndef CLASS_DESTRUCTOR_HPP
#define CLASS_DESTRUCTOR_HPP

#include <iostream>

// ==== 1. Function and object destruction
// https://www.geeksforgeeks.org/playing-with-destructors-in-c/

int globalVariable;

class DestructingClass {
public:
    ~DestructingClass() {
        std::cout << "Destructor of DestructingClass" << std::endl;
        ::globalVariable = 10;
    }
};

int functionThatChangeGlobaVar() {
    globalVariable = 3;
    DestructingClass obj;
    return globalVariable;
}

int functionThatChangeGlobaVarFix() {
    globalVariable = 3;

    {
        DestructingClass obj;
    }

    return globalVariable;
}

void FunctionAndDestructionOfObjects() {
    /*
    What we will get from functionThatChangeGlobaVar()?
    Answer: 3. Why?
    While returning from a function, destructor is the last method to be
    executed. The destructor for the object “ob” is called after the value of
    globalVariable is copied to the return value of the function.
    */

    std::cout << "FunctionAndDestructionOfObjects: globalVariable = " <<
                 functionThatChangeGlobaVar() << std::endl;

    /*
    How to fix that? One of the solutions is to guarantee that destruction
    of object will be called before return statement
    */

    std::cout << "FunctionAndDestructionOfObjects: globalVariable = " <<
                 functionThatChangeGlobaVarFix() << std::endl;
}


// ==== 2. Class with private destructor

class ClassWithPrivateDestructor {
private:
    ~ClassWithPrivateDestructor() {}

public:
    // Friend function is able to access private functions of class
    friend void destructObject(ClassWithPrivateDestructor *obj);
};

// Function that could destruct objects via pointer
void destructObject(ClassWithPrivateDestructor* obj) {
    delete obj;
}

void HowToCallPrivateDestructor() {
    // Error: we will not be able to destruc object
    // ClassWithPrivateDestructor obj;

    ClassWithPrivateDestructor *obj = new ClassWithPrivateDestructor;
    destructObject(obj);
}

#endif // CLASS_DESTRUCTOR_HPP

