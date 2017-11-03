#include <iostream>
#include <limits>
#include <ios>

#ifndef INTTYPE_H_
#define INTTYPE_H_

void IntTypes()
{
	std::cout << "IntTypes()" << std::endl;

	std::cout << "int: " << std::endl;
	std::cout << "int size: " << sizeof(int) << std::endl;
	std::cout << "min int = " <<
				std::numeric_limits<int>::min() << std::endl;
	std::cout << "max int = " <<
				std::numeric_limits<int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<int>::is_signed) << std::endl;
	std::cout << std::endl;

	std::cout << "signed int: " << std::endl;
	std::cout << "signed int size: " << sizeof(signed int) << std::endl;
	std::cout << "min signed int = " <<
				std::numeric_limits<signed int>::min() << std::endl;
	std::cout << "max signed int = " <<
				std::numeric_limits<signed int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<signed int>::is_signed) << std::endl;
	std::cout << std::endl;

	std::cout << "unsigned int: " << std::endl;
	std::cout << "unsigned int size: " << sizeof(unsigned int) << std::endl;
	std::cout << "min unsigned int = " <<
				std::numeric_limits<unsigned int>::min() << std::endl;
	std::cout << "max unsigned int = " <<
				std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<unsigned int>::is_signed) << std::endl;
	std::cout << std::endl;

	std::cout << "long int: " << std::endl;
	std::cout << "long int size: " << sizeof(long int) << std::endl;
	std::cout << "min long int = " <<
				std::numeric_limits<long int>::min() << std::endl;
	std::cout << "max long int = " <<
				std::numeric_limits<long int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<long int>::is_signed) << std::endl;
	std::cout << std::endl;

	std::cout << "unsigned long int: " << std::endl;
	std::cout << "unsigned long int size: " << sizeof(unsigned long int) << std::endl;
	std::cout << "min unsigned long int = " <<
				std::numeric_limits<unsigned long int>::min() << std::endl;
	std::cout << "max unsigned long int = " <<
				std::numeric_limits<unsigned long int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<unsigned long int>::is_signed) << std::endl;
	std::cout << std::endl;

	std::cout << "long long int: " << std::endl;
	std::cout << "long long int size: " << sizeof(long long int) << std::endl;
	std::cout << "min long long int = " <<
				std::numeric_limits<long long int>::min() << std::endl;
	std::cout << "max long long int = " <<
				std::numeric_limits<long long int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<long long int>::is_signed) << std::endl;
	std::cout << std::endl;

	std::cout << "unsigned long long int: " << std::endl;
	std::cout << "unsigned long long int size: " << sizeof(unsigned long long int) << std::endl;
	std::cout << "min unsigned long long int = " <<
				std::numeric_limits<unsigned long long int>::min() << std::endl;
	std::cout << "max unsigned long long int = " <<
				std::numeric_limits<unsigned long long int>::max() << std::endl;
	std::cout << "is signed: " << std::boolalpha <<
			bool(std::numeric_limits<unsigned long long int>::is_signed) << std::endl;
	std::cout << std::endl;
}

void Start()
{
	IntTypes();
}

#endif /* INTTYPE_H_ */
