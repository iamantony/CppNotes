#ifndef USAGE_OF_FUNCTORS_HPP
#define USAGE_OF_FUNCTORS_HPP

#include <algorithm>
#include <vector>
#include <iostream>

/*
https://www.fluentcpp.com/2017/01/23/stl-function-objects-stateless-is-stressless/
https://stackoverflow.com/questions/356950/what-are-c-functors-and-their-uses

Functor - a functor is pretty much just a class which defines the operator().
That lets you create objects which "look like" a function.

Advantages of functors:
- flexibility. Functor could have internal data members that could be used
in operator(). By setting them in functors' constructor, we could change
behavior of operator(). Example: add X to container elements.
- code inside operator() could be inlined into code of STL algorithm (it is not
guaranted, but chances are high). As a result  we would save stack space -
no funciton call, no creation of temp arguments.

Disadvantages of functors:
- it is not recommended to keep state in functor objects. Not all algorithms
guarantee that they will use the same instance of callable along the traversal
of the collection. Instances of callables may then be copied, assigned or
destructed within the execution of an algorithm, making the maintaining of a
state impossible.
Now there is another reason why you should avoid states within function objects:
it makes code more complex. Most of the time there is a better, cleaner and
more expressive way.
*/

class Functor {
    // We could declare class variables, init them in constructor and use in
    // operator().
    int m_value = 0;

public:
    Functor(const int& value) : m_value(value) {}

    // We add 'const' to operator() to be sure that we would not try to modify
    // internal state of the functor
    void operator()(int& element) const {
        element += m_value;
    }
};

void PrintVector(const std::vector<int>& v) {
    for (auto& i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void FunctorStart() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Vector before modification: ";
    PrintVector(v);

    // Call for_each with functor object
    std::for_each(v.begin(), v.end(), Functor(10));

    std::cout << "Vector after modification: ";
    PrintVector(v);
}

#endif // USAGE_OF_FUNCTORS_HPP
