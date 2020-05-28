#ifndef COUNT_VISITS_TO_SUBDOMAINS_HPP
#define COUNT_VISITS_TO_SUBDOMAINS_HPP

/*
https://leetcode.com/problems/subdomain-visit-count/
A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level,
we have "com", at the next level, we have "leetcode.com", and at the lowest level,
"discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit
the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain
received), followed by a space, followed by the address. An example of a count-paired domain might
be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains,
(in the same format as the input, and in any order), that explicitly counts the number of visits
to each subdomain.

Example 1:
Input:
["9001 discuss.leetcode.com"]
Output:
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation:
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain
"leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input:
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output:
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation:
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and
"wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times,
"com" 900 + 50 + 1 = 951 times, and "org" 5 times.

Notes:
The length of cpdomains will not exceed 100.
The length of each domain name will not exceed 100.
Each address will have either 1 or 2 "." characters.
The input count in any count-paired domain will not exceed 10000.
The answer output can be returned in any order.
*/

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <limits>

namespace Algo::DS::HashMap {
    class CountVisitsToSubdomains {
        static bool convert_to_num(const std::string_view& str, size_t& num) {
            char** end = nullptr;
            const auto result = std::strtoull(str.data(), end, 10);
            if (result == std::numeric_limits<unsigned long long>::max()) {
                return false;
            }

            num = result;
            return true;
        }

        static std::tuple<bool, size_t, std::vector<std::string_view>> split_count_domains_string(
            const std::string_view& str) {
            const auto space_pos = str.find(' ');
            if (space_pos == std::string::npos) { return {false, 0, {}}; }

            size_t count = 0;
            if (!convert_to_num(str.substr(0, space_pos), count) || count == 0) {
                return {false, 0, {}};
            }

            std::vector<std::string_view> domains;
            for (size_t i = space_pos + 1; i < str.size(); ++i) {
                const auto pos = str.find('.', i);
                const auto dot_pos = pos == std::string_view::npos ? str.size() : pos;
                domains.push_back(str.substr(i));
                i = dot_pos;
            }

            if (domains.empty()) { return {false, 0, {}}; }

            return {true, count, domains};
        }

    public:
        static std::vector<std::string> count(const std::vector<std::string>& count_domains) {
            std::unordered_map<std::string_view, size_t> count_map;
            for (const auto& str : count_domains) {
                const auto [is_ok, count, domains] = split_count_domains_string(str);
                if (!is_ok) { continue; }

                for (const auto& domain : domains) {
                    count_map[domain] += count;
                }
            }

            std::vector<std::string> result;
            for (const auto& [str, count] : count_map) {
                result.push_back(std::to_string(count) + ' ' + std::string(str));
            }

            return result;
        }
    };
}

#endif //COUNT_VISITS_TO_SUBDOMAINS_HPP
