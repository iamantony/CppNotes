#ifndef FIBONACCI_NUMBERS_HPP
#define FIBONACCI_NUMBERS_HPP

/*
 * Fibonacci numbers:
 * F[n] = F[n - 1] + F[n - 2]
 *
 * 0: 0
 * 1: 1
 * 2: 1 + 0 = 1
 * 3: 1 + 1 = 2
 * 4: 2 + 1 = 3
 * 5: 3 + 2 = 5
 * ......
 */

#include <vector>

namespace Algo::Math {
class FibonacciNumbers {
public:
    static std::vector<long long> ListOfNums(const size_t& num) {
        std::vector<long long> result;
        result.push_back(0);

        if (num == 0) {
            return result;
        }

        result.push_back(1);
        if (num == 1) {
            return result;
        }

        for (size_t i = 2; i <= num; ++i) {
            result.push_back( result[i - 1] + result[i - 2] );
        }

        return result;
    }

    /*
    https://leetcode.com/problems/fibonacci-number/
    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
    Fibonacci sequence, such that each number is the sum of the two preceding
    ones, starting from 0 and 1. That is,

    F(0) = 0,   F(1) = 1
    F(N) = F(N - 1) + F(N - 2), for N > 1.
    Given N, calculate F(N).
    */
    static uint64_t Num(const size_t& num)
    {
        std::vector<uint64_t> buffer = {0, 1};
        if (num == 0) { return buffer[num]; }

        for (size_t i = 2; i <= num; ++i) {
            const auto nextFibNum = buffer[0] + buffer[1];
            buffer[0] = buffer[1];
            buffer[1] = nextFibNum;
        }

        return buffer[1];
    }

    static unsigned char LastDigitOfNum(const size_t& num)
    {
        std::vector<unsigned char> buffer = {0, 1};
        if (num == 0) { return buffer[num]; }

        for (size_t i = 2; i <= num; ++i) {
            const auto sum = buffer[0] + buffer[1];
            auto lastDigit = static_cast<unsigned char>(sum % 10);
            buffer[0] = buffer[1];
            buffer[1] = lastDigit;
        }

        return buffer[1];
    }
};

}

#endif // FIBONACCI_NUMBERS_HPP
