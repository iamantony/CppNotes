#ifndef CPPNOTESMAIN_FIND_TWO_SUM_DS_HPP
#define CPPNOTESMAIN_FIND_TWO_SUM_DS_HPP

/*
https://leetcode.com/problems/two-sum-iii-data-structure-design/
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

Example 2:
add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/

#include <unordered_set>

namespace Algo::DS::Array {
    class TwoSumDS {
        std::unordered_multiset<int> m_values;
    public:
        void add(const int number) {
            m_values.insert(number);
        }

        bool find(const int value) {
            if (m_values.size() < 2) { return false; }
            for (const auto& num : m_values) {
                const auto search_num = value - num;
                const auto count = m_values.count(search_num);
                if ((search_num == num && count > 1) || ((search_num != num && count > 0))) {
                    return true;
                }
            }

            return false;
        }
    };
}

#endif //CPPNOTESMAIN_FIND_TWO_SUM_DS_HPP
