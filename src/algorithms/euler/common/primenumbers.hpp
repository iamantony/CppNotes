/*
 * primalnumbers.h
 *
 *  Created on: Dec 30, 2013
 *      Author: Antony Cherepanov
 */

#ifndef PRIMALNUMBERS_H_
#define PRIMALNUMBERS_H_

#include <vector>

class PrimeNumbers
{
	// == DATA ==

	// == METHODS ==
public:
	std::vector<long int> GetPrimeNumbers(const long int &t_limit);
};

#endif /* PRIMALNUMBERS_H_ */
