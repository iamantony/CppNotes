#ifndef POLYNOMIAL_MULTIPLICATION_HPP
#define POLYNOMIAL_MULTIPLICATION_HPP

// https://www.geeksforgeeks.org/multiply-two-polynomials-2/
// Given two polynomials represented by two arrays, write a function that
// multiplies given two polynomials.

// Example:

// Input:  A[] = {5, 0, 10, 6}
//         B[] = {1, 2, 4}
// Output: prod[] = {5, 10, 30, 26, 52, 24}

// The first input array represents "5x^3 + 0x^2 + 10x^1 + 6x^0"
// The second array represents "1x^2 + 2x^1 + 4x^0"
// And Output is "5x^5 + 10x^4 + 30x^3 + 26x^2 + 52x^1 + 24x^0"

// Time complexity: O(n^2)

// There exist more optimal solution that is based on divide-and-conqure
// and Karatsuba Multiplication that runs in O(n^1.58)

#include <vector>

namespace PolMult {

class Solution {
public:
    std::vector<int> PolynomialMultNaive(const size_t& n,
                    const std::vector<int> pol1, const std::vector<int> pol2) {
        if (n == 0) {
            return std::vector<int>();
        }

        if (pol1.size() != n || pol2.size() != n) {
            return std::vector<int>();
        }

        std::vector<int> result(2*n - 1, 0);
        for (size_t i = 0; i < pol1.size(); ++i) {
            for(size_t j = 0; j < pol2.size(); ++j) {
                result[i + j] += pol1[i] * pol2[j];
            }
        }

        return result;
    }
};

}

#endif // POLYNOMIAL_MULTIPLICATION_HPP

