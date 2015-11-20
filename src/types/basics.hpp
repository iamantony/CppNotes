#ifndef TYPES_BASICS_H_
#define TYPES_BASICS_H_

#include <iostream>
#include <limits>
#include <typeinfo>

void Introduction()
{
	std::cout << "Introduction()" << std::endl;

	// Every name and every expression has a type that determines the
	// operations that may be performed on it.
	// A declaration is a statement that introduces a name into the program.
	// It specifies a type for the named entity:
	// - A type defines a set of possible values and a set of operations
	// (for an object).
	// - An object is some memory that holds a value of some type.
	// - A value is a set of bits interpreted according to a type.
	// - A variable is a named object.

	// Fundamental types:
	// 1. bool. True (!0) or False (0)
	std::cout << "Boolean type: bool. Size: " << sizeof(bool) << std::endl;
	std::cout << std::endl;

	// 2. char. Type for integer values
	std::cout << "Integers type: char. Size: " << sizeof(char) << std::endl;
	std::cout << "min char = " <<
			static_cast<int>(std::numeric_limits<char>::min()) <<
			std::endl;
	std::cout << "max char = " <<
			static_cast<int>(std::numeric_limits<char>::max()) <<
			std::endl;
	std::cout << std::endl;

	// 3. int. Type for integer values
	std::cout << "Integers type: int. Size: " << sizeof(int) << std::endl;
	std::cout << "min int = " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "max int = " << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::endl;

	// 4. long int. Type for integer values
	std::cout << "Integers type: long int. Size: " <<
			sizeof(long int) << std::endl;
	std::cout << "min long int = " <<
			std::numeric_limits<long int>::min() << std::endl;
	std::cout << "max long int = " <<
			std::numeric_limits<long int>::max() << std::endl;
	std::cout << std::endl;

	// 5. long long int. Type for big integer values
	std::cout << "Integers type: long long int. Size: " <<
			sizeof(long long int) << std::endl;
	std::cout << "min long long int = " <<
			std::numeric_limits<long long int>::min() << std::endl;
	std::cout << "max long long int = " <<
			std::numeric_limits<long long int>::max() << std::endl;
	std::cout << std::endl;

	// 6. float. Type for small floating numbers.
	std::cout << "Floating numbers type: float. Size: " <<
			sizeof(float) << std::endl;
	std::cout << "min float = " <<
			std::numeric_limits<float>::min() << std::endl;
	std::cout << "max float = " <<
			std::numeric_limits<float>::max() << std::endl;
	std::cout << "epsilon float = " <<
			std::numeric_limits<float>::epsilon() << std::endl;
	std::cout << std::endl;

	// 7. double. Type for floating numbers.
	std::cout << "Floating numbers type: double. Size: " <<
			sizeof(double) << std::endl;
	std::cout << "min double = " <<
			std::numeric_limits<double>::min() << std::endl;
	std::cout << "max double = " <<
			std::numeric_limits<double>::max() << std::endl;
	std::cout << "epsilon double = " <<
			std::numeric_limits<double>::epsilon() << std::endl;
	std::cout << std::endl;

	// 8. long double. Type for big floating numbers.
	std::cout << "Floating numbers type: long double. Size: " <<
			sizeof(long double) << std::endl;
	std::cout << "min long double = " <<
			std::numeric_limits<long double>::min() << std::endl;
	std::cout << "max long double = " <<
			std::numeric_limits<long double>::max() << std::endl;
	std::cout << "epsilon long double = " <<
			std::numeric_limits<long double>::epsilon() << std::endl;
	std::cout << std::endl;
}

void Initialization()
{
	std::cout << "Initialization()" << std::endl;

	// C++ offers a variety of notations for expressing initialization,
	// such as the = used above, and a universal form based on
	// curly-brace-delimited initializer lists.

	int integer = 1;
	std::cout << "Initialization via =: " << integer << std::endl;

	double double_val {2.3};
	std::cout << "Initialization via {}: " << double_val << std::endl;

	// If we initialize "short" value by "long" value (for example,
	// int = double), then value will be converted with lose of information
	int convertion_int = static_cast<int>(7.5);
	std::cout << "Lost of information: int value = double value 7.5: " <<
			convertion_int << std::endl;

	// When defining a variable, you don’t actually need to state its type
	// explicitly when it can be deduced from the initializer.
	auto auto_val = 90.887;
	std::cout << "Auto value initialized by " << auto_val << std::endl;
	std::cout << "and its' type is " << typeid(auto_val).name() << std::endl;

	std::cout << std::endl;
}

void Declaration()
{
	// Every name (identifier) in a C++ program has a type associated with it.
	// This type determines what operations can be applied to the name
	// (that is, to the entity referred to by the name) and how such
	// operations are interpreted.

	// y is integer value
	// int y;
	// c is char values
	// char c;

	// func is a function that get as argument integer value and return
	// floating-point value
	float func(int t);
}

void Start()
{
	Introduction();
	Initialization();
	Declaration();
}

#endif /* TYPES_BASICS_H_ */
