#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/hashmap/count_visits_to_subdomains.hpp"

BOOST_AUTO_TEST_SUITE(TestCountVisitsToSubdomains)

    BOOST_AUTO_TEST_CASE(empty_input)
    {
        BOOST_CHECK(Algo::DS::HashMap::CountVisitsToSubdomains::count({}).empty());
    }

    BOOST_AUTO_TEST_CASE(invalid_entries_in_input)
    {
        const std::vector<std::string> input = {
            "abcd",
            "ab.cd.eg",
            "123",
            "123 ",
            ".a.b.c",
        };

        BOOST_CHECK(Algo::DS::HashMap::CountVisitsToSubdomains::count(input).empty());
    }

    BOOST_AUTO_TEST_CASE(valid_input)
    {
        const std::vector<std::string> input = {
            "1 org",
            "2 ya.ru",
            "3 wiki.org",
            "4 test.google.ru",
            "0 this.s.long.domain",
        };

        std::vector<std::string> expected = {
            "4 org",
            "6 ru",
            "2 ya.ru",
            "3 wiki.org",
            "4 google.ru",
            "4 test.google.ru"
        };

        auto result = Algo::DS::HashMap::CountVisitsToSubdomains::count(input);

        std::sort(expected.begin(), expected.end());
        std::sort(result.begin(), result.end());
        BOOST_CHECK(result == expected);
    }

BOOST_AUTO_TEST_SUITE_END()
