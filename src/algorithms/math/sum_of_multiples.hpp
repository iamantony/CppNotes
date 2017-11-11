#ifndef SUM_OF_MULTIPLES_OF_3_AND_5_HPP
#define SUM_OF_MULTIPLES_OF_3_AND_5_HPP

// https://projecteuler.net/problem=1
// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
// Answer: 233168

#include <iostream>
#include <vector>
#include <algorithm>

namespace SumOfMultiples {

class Solution {
public:
    unsigned int SumOfMultiples(const unsigned int& first,
                                const unsigned int& second,
                                const unsigned int& limit) {
        unsigned int sumFirst = SumOfNumbersDivisebleByN(first, limit);
        unsigned int sumSecond = SumOfNumbersDivisebleByN(second, limit);
        unsigned int sumMultFirstSecond =
                SumOfNumbersDivisebleByN(first * second, limit);

        return sumFirst + sumSecond - sumMultFirstSecond;
    }

private:
    // Example: 3 and 1000 (non-inclusive)
    // (1000 - 1) / 3 = 333 - number of multiples
    // 3 + 6 + 9 + ... + 999 - 333 numbers
    // 3 + 6 + 9 + ... + 999 == 3 * 333 * (333 + 1) / 2
    unsigned int SumOfNumbersDivisebleByN(const unsigned int& n,
                                          const unsigned int& limit) {
        unsigned int p = (limit -1) / n;
        return (n * p * (p + 1)) / 2;
    }
};

}

#endif // SUM_OF_MULTIPLES_OF_3_AND_5_HPP

