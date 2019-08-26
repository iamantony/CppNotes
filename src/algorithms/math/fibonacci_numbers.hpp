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

    static long long Num(const size_t& num)
    {
        const auto nums = ListOfNums(num);
        return nums[num];
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
