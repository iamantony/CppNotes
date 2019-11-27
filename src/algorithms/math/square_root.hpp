#ifndef SQUARE_ROOT_HPP
#define SQUARE_ROOT_HPP

#include <cmath>

namespace SquareRoot {

// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Rough_estimation
// When we work in binary numerical system we could express
// S = a * (2^2n)
// where S is a value for which square root we want to find

// So: sqrt(S) = sqrt(a) * (2^n) = 2^n
inline int RoughSR(int value) {
    if (value <= 0) {
        return -1;
    }
    else if (value == 1 || value == 2) {
        return 1;
    }

    int lastOneBitPos = 0;
    while(value > 0) {
        value >>= 1;
        ++lastOneBitPos;
    }

    int power = lastOneBitPos / 2 ;
    int root = 1 << power;
    return root;
}

// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
inline double BabylonialSR(int value, const double& error = 0.0001) {
    if (value <= 0 || error <= 0.0) {
        return 0.0;
    }

    double root = RoughSR(value);
    while(true) {
        double newRoot = (root + value/root) / 2.0;
        double diff = (root > newRoot) ? root - newRoot : newRoot - root;
        root = newRoot;
        if (diff <= error) {
            break;
        }
    }

    return root;
}

// https://leetcode.com/problems/sqrtx/description/
// Implement int sqrt(int x).
// Compute and return the square root of x.
// x is guaranteed to be a non-negative integer.
class Solution {
public:
    int mySqrt(int x) {
        double root = BabylonialSR(x, 0.1);
        return static_cast<int>(std::floor(root));
    }
};

}

#endif // SQUARE_ROOT_HPP
