#ifndef CPPNOTESMAIN_PARTITION_LABELS_HPP
#define CPPNOTESMAIN_PARTITION_LABELS_HPP

/*
https://leetcode.com/problems/partition-labels/
A string S of lowercase English letters is given. We want to partition this string into as many
parts as possible so that each letter appears in at most one part, and return a list of integers
representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:
- S will have length in range [1, 500].
- S will consist of lowercase English letters ('a' to 'z') only.
*/

#include <string>
#include <vector>
#include <unordered_map>

namespace Algo::Greedy {
    class PartitionLabels {
    public:
        static std::vector<int> partition(const std::string& s) {
            if (s.empty()) { return {}; }

            std::unordered_map<char, size_t> last_pos;
            for (size_t i = 0; i < s.size(); ++i) {
                last_pos[s[i]] = i;
            }

            std::vector<int> result;
            size_t start_pos = 0;
            size_t max_pos = last_pos[s.front()];
            for (size_t i = 0; i < s.size(); ++i) {
                if (max_pos == i) {
                    result.push_back(static_cast<int>(max_pos - start_pos + 1));

                    if (i + 1 < s.size()) {
                        start_pos = i + 1;
                        max_pos = last_pos[s[i + 1]];
                    }
                }
                else {
                    max_pos = std::max(max_pos, last_pos[s[i]]);
                }
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_PARTITION_LABELS_HPP
