#ifndef ARRAY_PERMUTATIONS_HPP
#define ARRAY_PERMUTATIONS_HPP

/*

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
