#ifndef EQUALITY_HPP
#define EQUALITY_HPP

#include <limits>
#include <cstdlib>

template<typename T>
bool equal(const T& left, const T& right) {
    return left == right;
}

template<>
inline bool equal<double>(const double& left, const double& right) {
    return std::fabs(left - right) <= std::numeric_limits<double>::epsilon();
}

inline bool equalDoubles(const double& left, const double& right, const double& epsilon) {
    return std::fabs(left - right) <= epsilon;
}

#endif // EQUALITY_HPP

