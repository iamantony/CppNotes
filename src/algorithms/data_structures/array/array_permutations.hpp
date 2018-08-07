#ifndef ARRAY_PERMUTATIONS_HPP
#define ARRAY_PERMUTATIONS_HPP

/*
https://leetcode.com/problems/permutations/description/
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

https://leetcode.com/problems/permutations-ii/description/
Given a collection of numbers that might contain duplicates, return all
possible unique permutations.

Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {

class ArrayPermutations {
public:
    static std::vector<std::vector<int>> GetAll(std::vector<int> v) {
        std::vector<std::vector<int>> result;
        if (v.empty()) {
            return result;
        }

        CreatePermutation(v, 0, v.size() - 1, result);
        std::sort(result.begin(), result.end());
        return result;
    }

    static std::vector<std::vector<int>> GetUnique(std::vector<int> v) {
        std::vector<std::vector<int>> allPermut = GetAll(v);
        if (allPermut.size() < 2) {
            return allPermut;
        }

        std::sort(allPermut.begin(), allPermut.end());

        std::vector<std::vector<int>> result;
        result.push_back(allPermut[0]);
        for (size_t i = 1; i < allPermut.size(); ++i) {
            if (allPermut[i] != allPermut[i - 1]) {
                result.push_back(allPermut[i]);
            }
        }

        return result;
    }

private:
    static void CreatePermutation(std::vector<int>& v,
                                  const size_t& left, const size_t& right,
                                  std::vector<std::vector<int>>& result) {
        if (left >= right) {
            result.push_back(v);
        }
        else {
            for (size_t i = left; i <= right; ++i) {
                std::swap(v[i], v[left]);

                CreatePermutation(v, left + 1, right, result);

                std::swap(v[i], v[left]);
            }
        }
    }
};

}

#endif // ARRAY_PERMUTATIONS_HPP
