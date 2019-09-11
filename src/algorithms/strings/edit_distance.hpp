#ifndef EDIT_DISTANCE_HPP
#define EDIT_DISTANCE_HPP

/*
https://leetcode.com/problems/edit-distance/
The edit distance between two strings is the minimum number of operations
(insertions, deletions, and substitutions of symbols) to transform one string
into another. It is a measure of similarity of two strings. Edit distance has
applications, for example, in computational biology, natural language
processing, and spell checking. Your goal in this problem is to compute the
edit distance between two strings.

Task: The goal of this problem is to implement the algorithm for computing
the edit distance between two strings.

Input Format: Each of the two lines of the input contains a string consisting
of lower case latin letters.

Constraints: The length of both strings is at least 1 and at most 100.
Output Format: Output the edit distance between the given two strings.

Examples:
 - ab, ab -> 0
 - short, ports -> 3
 - editing, distance -> 5
*/

#include <string>
#include <vector>

namespace Algo::Strings {
class EditDistance {
public:
    static uint32_t Calc(const std::string& s1, const std::string& s2) {
        if (s1.empty() && s2.empty()) { return 0; }
        if (s1.empty()) { return static_cast<uint32_t>(s2.size()); }
        if (s2.empty()) { return static_cast<uint32_t>(s1.size()); }

        const auto rowsNum = s1.size() + 1;
        const auto colsNum = s2.size() + 1;
        std::vector<uint32_t> rowsVec(colsNum, 0);
        std::vector<std::vector<uint32_t>> table(rowsNum, rowsVec);

        for (size_t r = 0, c = 0; c < colsNum; ++c) {
            table[r][c] = static_cast<uint32_t>(c);
        }

        for (size_t r = 0, c = 0; r < rowsNum; ++r) {
            table[r][c] = static_cast<uint32_t>(r);
        }

        for (size_t c = 1; c < colsNum; ++c) {
            for (size_t r = 1; r < rowsNum; ++r) {
                const auto insertion = table[r][c - 1] + 1;
                const auto deletion = table[r - 1][c] + 1;
                const auto match = table[r - 1][c - 1];
                const auto mismatch = table[r - 1][c - 1] + 1;

                const auto insDelMin = std::min(insertion, deletion);
                if (s1[r - 1] == s2[c - 1]) {
                    table[r][c] = std::min(insDelMin, match);
                }
                else {
                    table[r][c] = std::min(insDelMin, mismatch);
                }
            }
        }

        return table[rowsNum - 1][colsNum - 1];
    }
};
}

#endif // EDIT_DISTANCE_HPP
