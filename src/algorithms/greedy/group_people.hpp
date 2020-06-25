#ifndef CPPNOTESMAIN_GROUP_PEOPLE_HPP
#define CPPNOTESMAIN_GROUP_PEOPLE_HPP

/*
https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group.
Given the array groupSizes of length n telling the group size each person belongs to, return
the groups there are and the people's IDs each group includes.

You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that
there exists at least one solution.

Example 1:
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation:
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Example 2:
Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]

Constraints:
- groupSizes.length == n
- 1 <= n <= 500
- 1 <= groupSizes[i] <= n
*/

#include <vector>

namespace Algo::Greedy {
    class GroupPeople {
    public:
        static std::vector<std::vector<int>> group(const std::vector<int>& groupSizes) {
            std::vector<std::vector<std::vector<int>>> groups;
            for (size_t people_id = 0; people_id < groupSizes.size(); ++people_id) {
                const auto group_size = static_cast<size_t>(groupSizes[people_id]);
                const auto group_index = group_size - 1;

                groups.resize(std::max(groups.size(), group_index + 1));

                if (groups.at(group_index).empty()) {
                    groups.at(group_index).push_back({});
                }

                if (groups.at(group_index).back().size() == group_size) {
                    groups.at(group_index).push_back({});
                }

                groups.at(group_index).back().push_back(people_id);
            }

            std::vector<std::vector<int>> result;
            for (const auto& group_section : groups) {
                result.insert(result.end(), group_section.begin(), group_section.end());
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_GROUP_PEOPLE_HPP
