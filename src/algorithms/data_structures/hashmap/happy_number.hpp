#ifndef HAPPY_NUMBER_HPP
#define HAPPY_NUMBER_HPP

/*
https://leetcode.com/problems/happy-number/
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
replace the number by the sum of the squares of its digits, and repeat the process until the number
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example:
Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <unordered_set>

namespace Algo::DS::HashMap {
    class HappyNumber {
    public:
        static bool check(int n) {
            if (n < 1) { return false; }
            if (n == 1) { return true; }

            uint64_t number = static_cast<uint64_t>(n);
            std::unordered_set<uint64_t> known_values;
            while (true) {
                uint64_t sum = 0;
                while (number > 0) {
                    const auto modulo = number % 10;
                    sum += modulo * modulo;
                    number /= 10;
                }

                if (sum == 1) { return true; }
                if (known_values.count(sum) > 0) { return false; }

                known_values.insert(sum);
                number = sum;
            }
        }
    };
}

#endif //HAPPY_NUMBER_HPP
