/*
 * matrix.cpp
 *
 *  Created on: Jan 23, 2014
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <sstream>
#include "matrix.h"

template <class T>
void Matrix<T>::Clear()
{
	m_width = 0;
	m_height = 0;
	m_matrix.clear();
}

template <class T>
bool Matrix<T>::SetData(const int &t_width,
						const int &t_height,
						const std::string &t_str,
						const char &t_delimiter)
{
	if ( (t_width <= 0) ||
		 (t_height <= 0) ||
		 (true == t_str.empty()) )
	{
		return false;
	}

	std::vector<std::string> parsedStr = Split(t_str, t_delimiter);
	if ( t_width * t_height != parsedStr.size() )
	{
		std::cout << "SetData(): Error - invalid arguments" << std::endl;
		return false;
	}

	m_width = t_width;
	m_height = t_height;
	FillMatrix(parsedStr);

	return true;
}

template <class T>
std::vector<std::string> Matrix<T>::Split(const std::string &t_str,
										  const char &t_delimiter) const
{
	std::stringstream strStream(t_str);
	std::string item;
	std::vector<std::string> result;
	while(std::getline(strStream, item, t_delimiter))
	{
		result.push_back(item);
	}

	return result;
}

template <>
void Matrix<int>::FillMatrix(const std::vector<std::string> &t_elements)
{
	const int numOfElemetns = t_elements.size();
	m_matrix.clear();
	m_matrix.reserve(numOfElemetns);
	for ( int elem = 0; elem < numOfElemetns; ++elem  )
	{
		int num = std::stoi(t_elements[elem]);
		m_matrix.push_back(num);
	}
}

template <class T>
T Matrix<T>::At(const int &t_width, const int &t_height) const
{
	if ( false == ValidatePosition(t_width, t_height) )
	{
		return -1;
	}

	int index = t_height * m_width + t_width;
	return m_matrix[index];
}

template <class T>
bool Matrix<T>::ValidatePosition(const int &t_width, const int &t_height) const
{
	if ( (t_width < m_width) && (t_height < m_height) )
	{
		return true;
	}

	return false;
}

template <class T>
int Matrix<T>::GetWidth() const
{
	return m_width;
}

template <class T>
int Matrix<T>::GetHeight() const
{
	return m_height;
}

template class Matrix<int>;
