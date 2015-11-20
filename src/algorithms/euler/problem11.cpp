/*
 * problem11.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

#include "problem11.h"

void Problem11::DoSolve()
{
	std::cout << "Problem 11" << std::endl;

	std::string initNumbers;
	initNumbers.append("08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 ");
	initNumbers.append("49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 ");
	initNumbers.append("81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 ");
	initNumbers.append("52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 ");
	initNumbers.append("22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 ");
	initNumbers.append("24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 ");
	initNumbers.append("32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 ");
	initNumbers.append("67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 ");
	initNumbers.append("24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 ");
	initNumbers.append("21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 ");
	initNumbers.append("78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 ");
	initNumbers.append("16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 ");
	initNumbers.append("86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 ");
	initNumbers.append("19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 ");
	initNumbers.append("04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 ");
	initNumbers.append("88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 ");
	initNumbers.append("04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 ");
	initNumbers.append("20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 ");
	initNumbers.append("20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 ");
	initNumbers.append("01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48");

	Matrix<int> matrix;
	bool isMatrixSet = matrix.SetData(20, 20, initNumbers, ' ');
	if ( false == isMatrixSet )
	{
		std::cout << "Problem11: Error - failed to initialize matrix" << std::endl;
		return;
	}

	const int biggestValue = std::numeric_limits<int>::max();
	std::vector< std::pair<int, int> > maxElements = FindMaxElements(matrix,
																biggestValue);

	int product = FindMaxProduct(matrix, maxElements);

	const int maxValue = matrix.At(maxElements[0].first, maxElements[0].second);
	const int limit = maxValue / 2;
	for ( int i = maxValue; i >= limit; --i )
	{
		std::vector< std::pair<int, int> > elements = FindMaxElements(matrix, i);
		int newProduct = FindMaxProduct(matrix, elements);
		product = std::max(product, newProduct);
	}

	std::cout << "Answer = " << product << std::endl;
}

std::vector< std::pair<int, int> > Problem11::FindMaxElements(const Matrix<int> &t_matrix,
														const int &t_maxValue)
{
	std::vector< std::pair<int, int> > foundElements;
	int max = std::numeric_limits<int>::min();
	int width = t_matrix.GetWidth();
	int height = t_matrix.GetHeight();

	for ( int w = 0; w < width; ++w )
	{
		for ( int h = 0; h < height; ++h )
		{
			int value = t_matrix.At(w, h);
			if ( t_maxValue <= value )
			{
				continue;
			}

			if ( max < value )
			{
				foundElements.clear();
				max = value;
			}

			if ( max == value )
			{
				std::pair<int, int> coord(w, h);
				foundElements.push_back(coord);
			}
		}
	}

	return foundElements;
}

int Problem11::FindMaxProduct(const Matrix<int> &t_matrix,
						const std::vector< std::pair<int, int> > &t_elements)
{
	int maxProduct = 0;

	for ( unsigned int elem = 0; elem < t_elements.size(); ++elem )
	{
		maxProduct = std::max(maxProduct,
						FindMaxHorizontalProduct(t_matrix, t_elements[elem]));

		maxProduct = std::max(maxProduct,
							FindMaxVerticalProduct(t_matrix, t_elements[elem]));

		maxProduct = std::max(maxProduct,
					FindMaxUpLeftDiagonalProduct(t_matrix, t_elements[elem]));

		maxProduct = std::max(maxProduct,
					FindMaxDownLeftDiagonalProduct(t_matrix, t_elements[elem]));
	}

	return maxProduct;
}

int Problem11::FindMaxHorizontalProduct(const Matrix<int> &t_matrix,
										const std::pair<int, int> &t_element)
{
	int startWdt = std::max(0, t_element.first - 3);
	int maxWdt = std::min(t_matrix.GetWidth() - 1, t_element.first + 3);
	if ( (maxWdt - startWdt) < 4 )
	{
		return 0;
	}

	int stopWdt = maxWdt - 3;

	int maxProduct = 0;
	for ( int wdt = startWdt; wdt <= stopWdt; ++wdt )
	{
		int product = t_matrix.At(wdt, t_element.second) *
					  t_matrix.At(wdt + 1, t_element.second) *
					  t_matrix.At(wdt + 2, t_element.second) *
					  t_matrix.At(wdt + 3, t_element.second);

		maxProduct = std::max(maxProduct, product);
	}

	return maxProduct;
}

int Problem11::FindMaxVerticalProduct(const Matrix<int> &t_matrix,
										const std::pair<int, int> &t_element)
{
	int startHgt = std::max(0, t_element.second - 3);
	int maxHgt = std::min(t_matrix.GetHeight() - 1, t_element.second + 3);
	if ( (maxHgt - startHgt) < 4 )
	{
		return 0;
	}

	int stopHgt = maxHgt - 3;

	int maxProduct = 0;
	for ( int hgt = startHgt; hgt <= stopHgt; ++hgt )
	{
		int product = t_matrix.At(t_element.first, hgt) *
					  t_matrix.At(t_element.first, hgt + 1) *
					  t_matrix.At(t_element.first, hgt + 2) *
					  t_matrix.At(t_element.first, hgt + 3);

		maxProduct = std::max(maxProduct, product);
	}

	return maxProduct;
}

int Problem11::FindMaxUpLeftDiagonalProduct(const Matrix<int> &t_matrix,
										const std::pair<int, int> &t_element)
{
	int startWdt = t_element.first;
	int startHgt = t_element.second;
	int shiftCounter = 0;
	while( (0 < startWdt) &&
		   (0 < startHgt) &&
		   (shiftCounter < 3) )
	{
		--startWdt;
		--startHgt;
		++shiftCounter;
	}

	int stopWdt = startWdt;
	int stopHgt = startHgt;
	shiftCounter = 0;
	while( (stopWdt < t_element.first) &&
		   (stopWdt + 3 < t_matrix.GetWidth()) &&
		   (stopHgt < t_element.second) &&
		   (stopHgt + 3 < t_matrix.GetHeight()) )
	{
		++stopWdt;
		++stopHgt;
	}

	if ( shiftCounter < 1 )
	{
		return 0;
	}

	int maxProduct = 0;
	for ( int wdt = startWdt, hgt = startHgt; wdt <= stopWdt || hgt <= stopHgt; ++wdt, ++hgt )
	{
		int product = t_matrix.At(wdt, hgt) *
					  t_matrix.At(wdt + 1, hgt + 1) *
					  t_matrix.At(wdt + 2, hgt + 2) *
					  t_matrix.At(wdt + 3, hgt + 3);

		maxProduct = std::max(maxProduct, product);
	}

	return maxProduct;
}

int Problem11::FindMaxDownLeftDiagonalProduct(const Matrix<int> &t_matrix,
										const std::pair<int, int> &t_element)
{
	int startWdt = t_element.first;
	int startHgt = t_element.second;
	int shiftCounter = 0;
	while( (0 < startWdt) &&
		   (startHgt < t_matrix.GetHeight()) &&
		   (shiftCounter < 3) )
	{
		--startWdt;
		++startHgt;
		++shiftCounter;
	}

	int stopWdt = startWdt;
	int stopHgt = startHgt;
	shiftCounter = 0;
	while( (stopWdt < t_element.first) &&
		   (stopWdt + 3 < t_matrix.GetWidth()) &&
		   (t_element.second < stopHgt) &&
		   (0 < stopHgt - 3))
	{
		++stopWdt;
		--stopHgt;
		++shiftCounter;
	}

	if ( shiftCounter < 1 )
	{
		return 0;
	}

	int maxProduct = 0;
	for ( int wdt = startWdt, hgt = startHgt; wdt <= stopWdt || stopHgt <= hgt; ++wdt, --hgt )
	{
		int product = t_matrix.At(wdt, hgt) *
					  t_matrix.At(wdt + 1, hgt - 1) *
					  t_matrix.At(wdt + 2, hgt - 2) *
					  t_matrix.At(wdt + 3, hgt - 3);

		maxProduct = std::max(maxProduct, product);
	}

	return maxProduct;
}
