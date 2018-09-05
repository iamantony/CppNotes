#ifndef POD_CLASS_HPP
#define POD_CLASS_HPP

/*
http://www.modernescpp.com/index.php/generalized-plain-old-data
Plain Old Data (POD) obeys the C standard layout. Therefore, you directly can
apply the fast C functions memcopy, memmove, memset, or memcmp.

PODs are in classical C++ fundamental types like booleans, integers of floating
point number. The restriction will not hold for C++11. With C++11 even classes
and structs can be PODs. For simplicity reasons I only speak about classes.

Which requirements holds for the C++11 class to be a POD? A class is a POD,
if it's trivial, has a standard layout and all of its non-static members are
PODs.

A class is trivial, if it:
- has a trivial default constructor.
- is trivial copyable.

A trivial copyable class is a class that:
- has no non-trivial copy or move constructor.
- has no non-trivial copy or move assignment operator.
- has a trivial destructor.

Non-trivial means that the mentioned methods are implemented by the developer.
If a method is requested from the compiler via the keyword default or
automatically generated from the compiler, the method is trivial.

The definition of a POD goes on with the standard layout.
A class has a standard layout if it don't has:
- virtual functions.
- virtual base classes.
- references.
- different access specifier (public, protected, and private).
*/

#include <iostream>
#include <type_traits>

namespace Classes::PODClass {

class PODCLass {
public:
    int a;
    bool b;
};

class NonPODClass {
public:
    double i;

private:
    int secret;
};

void Start() {
    std::cout << std::boolalpha << std::endl;

    std::cout << "std::is_pod<PODCLass>::value: " <<
                 std::is_pod<PODCLass>::value << std::endl;

    std::cout << "std::is_pod<NonPODClass>::value: " <<
                 std::is_pod<NonPODClass>::value << std::endl;

    std::cout << std::endl;

    std::cout << "std::is_trivial<NonPODClass>::value: " <<
                 std::is_trivial<NonPODClass>::value << std::endl;

    std::cout << "std::is_standard_layout<NonPODClass>::value: " <<
                 std::is_standard_layout<NonPODClass>::value << std::endl;

    std::cout << std::endl;
}

}

#endif // POD_CLASS_HPP
