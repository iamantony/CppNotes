#ifndef LEAST_COMMON_MULTIPLE_HPP
#define LEAST_COMMON_MULTIPLE_HPP

/*
The least common multiple of two positive integers a and b is the least positive
integer m that is divisible by both a and b.
*/

#include <algorithm>

namespace Algo::Math {
class LeastCommonMultiple {
public:
    static uint64_t Find(uint64_t first, uint64_t second) {
        const auto check_value = std::min(first, second);
        const auto largest_value = std::max(first, second);

        const auto largest_common_multiple = first * second;
        for (auto multiple = largest_value;
             multiple < largest_common_multiple;
             multiple += largest_value)
        {
            if (multiple % check_value == 0) {
                return multiple;
            }
        }

        return largest_common_multiple;
    }

    static uint64_t FindNaive(uint64_t first, uint64_t second) {
      for (uint64_t l = 1; l <= first * second; ++l) {
        if (l % first == 0 && l % second == 0) {
          return l;
        }
      }

      return first * second;
    }
};
}

#endif // LEAST_COMMON_MULTIPLE_HPP
