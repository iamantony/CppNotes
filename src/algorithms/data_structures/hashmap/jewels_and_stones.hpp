#ifndef JEWELS_AND_STONES_HPP
#define JEWELS_AND_STONES_HPP

#include <string>
#include <array>
#include <algorithm>
#include <limits>

/*
https://leetcode.com/problems/jewels-and-stones/
You're given strings J representing the types of stones that are jewels, and S representing the
stones you have.  Each character in S is a type of stone you have.  You want to know how many
of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are
case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0

Note:
- S and J will consist of letters and have length at most 50.
- The characters in J are distinct.
*/

namespace Algo::DS::HashMap {
    class JewelsAndStones {
    public:
        static size_t CountJewels(const std::string& jewels, const std::string& stones) {
            if (jewels.empty() || stones.empty()) { return 0; }

            std::array<bool, 256> jset;
            jset.fill(false);

            const auto shift = -1 * std::numeric_limits<char>::min();
            std::for_each(
                jewels.begin(),
                jewels.end(),
                [&jset](const auto& c) {
                    const auto index = static_cast<size_t>(c + shift);
                    jset[index] = true;
                });

            return std::count_if(
                stones.begin(),
                stones.end(),
                [&jset](const auto& c) {
                    const auto index = static_cast<size_t>(c + shift);
                    return jset[index];
                });
        }
    };
}

#endif //JEWELS_AND_STONES_HPP
