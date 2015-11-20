/*
 * problem.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <chrono>

#include "problem.h"

Problem::Problem()
{

}

Problem::~Problem()
{

}

void Problem::Solve()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	DoSolve();

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> secElapsed = end - start;
	std::cout << "Elapsed time: " << secElapsed.count() << " s" << std::endl;
}
