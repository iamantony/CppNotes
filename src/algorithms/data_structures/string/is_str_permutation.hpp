#ifndef ISSTRPERMUTATION_HPP_
#define ISSTRPERMUTATION_HPP_

// Given two strings, write a method to decide if one is a permutation of the
// other

#include <string>
#include <algorithm>
#include <map>

namespace Algo::DS::String {
    bool IsPermutationSort(const std::string& first, const std::string& second) {
        if (first.empty() && second.empty()) { return true; }
        if (first.size() != second.size()) { return false; }

        std::string firstStr = first, secondStr = second;
        std::sort(firstStr.begin(), firstStr.end());
        std::sort(secondStr.begin(), secondStr.end());

        return firstStr == secondStr;
    }

    bool IsPermutationCount(const std::string& first, const std::string& second) {
        if (first.empty() && second.empty()) { return true; }
        if (first.size() != second.size()) { return false; }

        std::map<char, int> stat;
        for (size_t i = 0; i < first.size(); ++i) {
            if (stat.end() == stat.find(first[i])) {
                stat.insert({first[i], 0});
            }

            ++stat[first[i]];
        }

        for (size_t i = 0; i < second.size(); ++i) {
            if (stat.end() == stat.find(second[i])) { return false; }
            if (--stat[second[i]] < 0) { return false; }
        }

        return true;
    }
}

#endif /* ISSTRPERMUTATION_HPP_ */
