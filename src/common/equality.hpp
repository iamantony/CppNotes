#ifndef UTILS_HPP
#define UTILS_HPP

#include <limits>

template<typename T>
bool equal(const T& left, const T& right)
{
    return left == right;
}

template<>
bool equal<double>(const double& left, const double& right)
{
    return std::fabs(left - right) <= std::numeric_limits<double>::epsilon();
}

#endif // UTILS_HPP

