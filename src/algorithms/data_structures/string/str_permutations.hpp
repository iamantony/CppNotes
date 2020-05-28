#ifndef STRPERMUTATIONS_HPP_
#define STRPERMUTATIONS_HPP_

#include <string>
#include <vector>

namespace Algo::DS::String {
    void StrSwap(std::string& str, const size_t& first, const size_t& second) {
        char buff = str[first];
        str[first] = str[second];
        str[second] = buff;
    }

    void DoPermutations(
        std::string& str,
        const size_t& start,
        const size_t& end,
        std::vector<std::string>& result)
    {
        if (start == end) {
            result.push_back(str);
        }
        else {
            for (size_t i = start; i <= end; ++i) {
                StrSwap(str, start, i);
                DoPermutations(str, start + 1, end, result);
                StrSwap(str, start, i);
            }
        }
    }

    std::vector<std::string> GetStrPermutations(const std::string& str) {
        if (str.empty()) { return {}; }

        std::string string(str);
        std::vector<std::string> permutations;
        DoPermutations(string, 0, string.size() -1, permutations);

        return permutations;
    }
}

#endif /* STRPERMUTATIONS_HPP_ */
