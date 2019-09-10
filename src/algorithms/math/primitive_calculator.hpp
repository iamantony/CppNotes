#ifndef PRIMITIVE_CALCULATOR_HPP
#define PRIMITIVE_CALCULATOR_HPP

/*
You are given a primitive calculator that can perform the following three
operations with the current number x: multiply x by 2, multiply x by 3, or
add 1 to x. Your goal is given a positive integer n, find the minimum number
of operations needed to obtain the number n starting from the number 1.
*/

#include <algorithm>
#include <vector>

namespace Algo::Math {
class PrimitiveCalculator {
public:
    static std::vector<uint32_t> Calc(const uint32_t value) {
        if (value == 0) { return {}; }

        std::vector<uint32_t> table(static_cast<size_t>(value + 1), 0);
        table[1] = 1;

        auto applyOperation =
                [&table](const uint32_t num, const uint32_t nextNum) {
            if (nextNum < table.size() &&
                    (table[nextNum] == 0 || table[nextNum] > table[num] + 1)) {
                table[nextNum] = table[num] + 1;
            }
        };

        for (uint32_t num = 1; num <= value; ++num) {
            if (table[num] == 0) { continue; }

            applyOperation(num, num + 1);
            applyOperation(num, num * 2);
            applyOperation(num, num * 3);
        }

        std::vector<uint32_t> result;
        for (uint32_t num = value; num > 0; ) {
            result.push_back(num);
            if (num % 3 == 0 && table[num / 3] == table[num] - 1) {
                num /= 3;
            }
            else if (num % 2 == 0 && table[num / 2] == table[num] - 1) {
                num /= 2;
            }
            else if (table[num - 1] == table[num] - 1) {
                num -= 1;
            }
        }

        if (*(result.rbegin()) != 1) { result.push_back(1); }

        std::reverse(std::begin(result), std::end(result));
        return result;
    }
};
}

#endif // PRIMITIVE_CALCULATOR_HPP
