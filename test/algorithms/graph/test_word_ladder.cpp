#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/graph/word_ladder.hpp"

BOOST_AUTO_TEST_SUITE(TestWordLadder)

    BOOST_AUTO_TEST_CASE(naive_impl_default_test_data)
    {
        {
            const std::string begin_word = "hit";
            const std::string end_word = "cog";
            const std::vector<std::string> words_dict = {"hot","dot","dog","lot","log","cog"};
            const int expected = 5;
            const auto result = Algo::DS::Graph::WordLadder::find_min_steps_naive(
                begin_word, end_word, words_dict);
            BOOST_CHECK(expected == result);
        }

        {
            const std::string begin_word = "hit";
            const std::string end_word = "cog";
            const std::vector<std::string> words_dict = {"hot","dot","dog","lot","log"};
            const int expected = 0;
            const auto result = Algo::DS::Graph::WordLadder::find_min_steps_naive(
                begin_word, end_word, words_dict);
            BOOST_CHECK(expected == result);
        }
    }

BOOST_AUTO_TEST_SUITE_END()
