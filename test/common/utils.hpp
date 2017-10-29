#ifndef UTILS_HPP
#define UTILS_HPP

#include <limits>

template<typename T>
bool areEqual(const T& left, const T& right)
{
    return std::fabs(left - right) <= std::numeric_limits<T>::epsilon();
}

#endif // UTILS_HPP

