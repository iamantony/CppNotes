#ifndef ISOMORPHIC_STRINGS_HPP
#define ISOMORPHIC_STRINGS_HPP


#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>

namespace Algo::HashMap {
    class IsomorphicStrings {
    public:
        static bool check_with_maps(const std::string& s1, const std::sttring& s2) {
            if (s1.size() != s2.size()) { return false; }

            std::unordered_map<char, char> change_map;
            std::unordered_set<char> fixed_chars;
            for (size_t i = 0; i < s1.size(); ++i) {
                const auto iter = change_map.find(s1[i]);
                if (iter == change_map.end()) {
                    if (fixed_chars.count(s2[i]) > 0) { return false; }

                    change_map[s1[i]] = s2[i];
                    fixed_chars.insert(s2[i]);
                }
                else if (s2[i] != iter->second) {
                    return false;
                }
            }

            return true;
        }

        static bool check_with_vectors(const std::string& s1, const std::sttring& s2) {
            if (s1.size() != s2.size()) { return false; }

            const auto max_value = std::numeric_limits<char>::max();
            std::vector<char> s1_map(max_value, -1), s2_map(max_value, -1);
            for (size_t i = 0; i < s1.size(); ++i) {
                const auto s1_ind = static_cast<size_t>(s1[i]);
                const auto s2_ind = static_cast<size_t>(s2[i]);
                if (s1_map[s1_ind] != s2_map[s2_ind]) { return false; }

                s1_map[s1_ind] = s2_map[s2_ind] = i;
            }

            return true;
        }
    };

}

#endif //ISOMORPHIC_STRINGS_HPP
