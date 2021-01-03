#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/tree/search_autocomplete_system.hpp"

BOOST_AUTO_TEST_SUITE(TestSearchAutoCompleteSystem)

    BOOST_AUTO_TEST_CASE(empty_initial_dict)
    {
        const std::vector<std::string> input_sentences;
        const std::vector<int> input_times;
        Algo::DS::Tree::SearchAutoCompleteSystem system(input_sentences, input_times);
        BOOST_CHECK(system.input('a').empty());
        BOOST_CHECK(system.input('#').empty());
        BOOST_CHECK(system.input('b').empty());
        BOOST_CHECK(system.input('#').empty());

        {
            const std::vector<std::string> expected = {"a"};
            BOOST_CHECK(system.input('a') == expected);
        }

        BOOST_CHECK(system.input('b').empty());
        BOOST_CHECK(system.input('#').empty());

        {
            const std::vector<std::string> expected = {"a", "ab"};
            BOOST_CHECK(system.input('a') == expected);
        }

        {
            const std::vector<std::string> expected = {"ab"};
            BOOST_CHECK(system.input('b') == expected);
        }

        BOOST_CHECK(system.input('#').empty());

        {
            const std::vector<std::string> expected = {"ab", "a"};
            BOOST_CHECK(system.input('a') == expected);
        }
    }

    BOOST_AUTO_TEST_CASE(initial_dict_from_example)
    {
        const std::vector<std::string> input_sentences =
            {"i love you", "island", "iroman", "i love leetcode"};
        const std::vector<int> input_times = {5,3,2,2};
        Algo::DS::Tree::SearchAutoCompleteSystem system(input_sentences, input_times);

        {
            const std::vector<std::string> expected = {"i love you", "island", "i love leetcode"};
            BOOST_CHECK(system.input('i') == expected);
        }

        {
            const std::vector<std::string> expected = {"i love you", "i love leetcode"};
            BOOST_CHECK(system.input(' ') == expected);
        }

        BOOST_CHECK(system.input('a').empty());
        BOOST_CHECK(system.input('#').empty());
    }

BOOST_AUTO_TEST_SUITE_END()

