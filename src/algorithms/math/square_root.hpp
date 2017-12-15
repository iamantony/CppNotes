#ifndef SQUARE_ROOT_HPP
#define SQUARE_ROOT_HPP

namespace SquareRoot {

// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Rough_estimation
// When we work in binary numerical system we could express
// S = a * (2^2n)
// where S is a value for which square root we want to find

// So: sqrt(S) = sqrt(a) * (2^n) = 2^n
int RoughSR(const int& value) {
    if (value <= 0) {
        return -1;
    }
    else if (value == 1) {
        return 0;
    }
    else if (value == 2) {
        return 1;
    }

    int lastOneBitPos = 0;
    int temp = value;
    while(temp > 0) {
        temp >>= 1;
        ++lastOneBitPos;
    }

    int power = lastOneBitPos / 2 ;
    int root = 1 << power;
    return root;
}

}

#endif // SQUARE_ROOT_HPP
