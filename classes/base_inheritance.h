/*
 * base_inheritance.h
 *
 *  Created on: Oct 8, 2014
 *      Author: Antony Cherepanov
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

class Base
{
public:
	int public_data;

protected:
	int protected_data;

public:
	// Construct Base class object and initialize class members
	Base() : public_data(0), protected_data(1)
	{
		std::cout << "In Base constructor: public_data = " << public_data <<
				", protected_data = " << protected_data << std::endl;
	};

	~Base()
	{
		std::cout << "In Base destructor" << std::endl;
	};
};

class Derived : public Base
{
public:
	// We have access to public and protected members of Base class
	// and we can change them
	Derived()
	{
		public_data = 42;
		protected_data++;
		std::cout << "In Derived constructor: public_data = " << public_data <<
				", protected_data = " << protected_data << std::endl;
	};

	~Derived()
	{
		std::cout << "In Derived destructor" << std::endl;
	};
};

void Start()
{
	std::cout << "base_inheritance" << std::endl << std::endl;

	std::cout << "Create Base class object:" << std::endl;
	Base *baseObject = new Base();

	std::cout << "Create Derived class object:" << std::endl;
	// First of all will be created constructor of parent class and then
	// constructor of Derived class will be called.
	Derived *derivedObject = new Derived();

	std::cout << "Delete Base class object:" << std::endl;
	delete baseObject;

	std::cout << "Delete Derived class object:" << std::endl;
	// Call child (Derived destructor), in the end call parent class
	// destructor (Base destructor)
	delete derivedObject;
}

#endif /* BASE_H_ */
