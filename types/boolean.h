/*
 * boolean.h
 *
 *  Created on: Nov 6, 2014
 *      Author: Antony Cherepanov
 */

#ifndef BOOLEAN_H_
#define BOOLEAN_H_

#include <iostream>
#include <ios>

void BoolValues()
{
	std::cout << "BoolValues()" << std::endl;

	// False == 0, True == 1 (or !0)
	std::cout << "True as int = " << int(true) << std::endl;
	std::cout << "False as int = " << int(false) << std::endl;
	std::cout << "0 as bool = " << std::boolalpha <<  bool(0) << std::endl;
	std::cout << "1 as bool = " << std::boolalpha << bool(1) << std::endl;
	std::cout << "123456 as bool = " << std::boolalpha << bool(123456) <<
			std::endl;
	std::cout << std::endl;
}

void BoolArithmetics()
{
	std::cout << "BoolArithmetics()" << std::endl;

	std::cout.setf(std::ios::boolalpha);
	std::cout << "true + true = " << bool(true + true) << std::endl;
	std::cout << "true - true = " << bool(true - true) << std::endl;
	std::cout << "true + false = " << bool(true + false) << std::endl;
	std::cout << "true - false = " << bool(true - false) << std::endl;
	std::cout << "false + false = " << bool(false + false) << std::endl;
	std::cout << "false - false = " << bool(false - false) << std::endl;
	std::cout << std::endl;
}

void BoolLogicOperations()
{
	std::cout << "BoolLogicOperations()" << std::endl;

	std::cout.setf(std::ios::boolalpha);
	std::cout << "AND:" << std::endl;
	std::cout << "true && true = " << bool(true && true) << std::endl;
	std::cout << "true && false = " << bool(true && false) << std::endl;
	std::cout << "false && true = " << bool(false && true) << std::endl;
	std::cout << "false && false = " << bool(false && false) << std::endl;
	std::cout << std::endl;

	std::cout << "OR:" << std::endl;
	std::cout << "true || true = " << bool(true || true) << std::endl;
	std::cout << "true || false = " << bool(true || false) << std::endl;
	std::cout << "false || true = " << bool(false || true) << std::endl;
	std::cout << "false || false = " << bool(false || false) << std::endl;
	std::cout << std::endl;

	std::cout << "NOT:" << std::endl;
	std::cout << "!true = " << bool(!true) << std::endl;
	std::cout << "!false = " << bool(!false) << std::endl;
	std::cout << std::endl;

	std::cout << "XOR:" << std::endl;
	std::cout << "true ^ true = " << bool(true ^ true) << std::endl;
	std::cout << "true ^ false = " << bool(true ^ false) << std::endl;
	std::cout << "false ^ true = " << bool(false ^ true) << std::endl;
	std::cout << "false ^ false = " << bool(false ^ false) << std::endl;
	std::cout << std::endl;
}

void Start()
{
	BoolValues();
	BoolArithmetics();
	BoolLogicOperations();
}

#endif /* BOOLEAN_H_ */
