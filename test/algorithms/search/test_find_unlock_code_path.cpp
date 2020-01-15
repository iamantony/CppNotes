#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_unlock_code_path.hpp"

BOOST_AUTO_TEST_SUITE(TestUnlockCodePath)

BOOST_AUTO_TEST_CASE(invalid_target)
{
    BOOST_CHECK(-1 == Algo::Search::UnlockCodePath::find_dfs({}, {}));
}

BOOST_AUTO_TEST_CASE(target_in_deadend)
{
    BOOST_CHECK(-1 == Algo::Search::UnlockCodePath::find_dfs({"0205", "9561"}, "9561"));
}

BOOST_AUTO_TEST_CASE(start_pos_in_deadend)
{
    BOOST_CHECK(-1 == Algo::Search::UnlockCodePath::find_dfs({"0205", "9561", "0000"}, "9001"));
}

BOOST_AUTO_TEST_CASE(all_start_pos_neighbors_in_deadend)
{
    const std::vector<std::string> deadends = {
        "1000", "0100", "0010", "0001",
        "9000", "0900", "0090", "0009"};

    BOOST_CHECK(-1 == Algo::Search::UnlockCodePath::find_dfs(deadends, "1234"));
}

BOOST_AUTO_TEST_CASE(no_deadends_target_is_first_neighbor)
{
    BOOST_CHECK(1 == Algo::Search::UnlockCodePath::find_dfs({}, "0900"));
    BOOST_CHECK(1 == Algo::Search::UnlockCodePath::find_dfs({}, "0010"));
}

BOOST_AUTO_TEST_CASE(leetcode_test_case_1)
{
    const std::vector<std::string> deadends = {"0201","0101","0102","1212","2002"};
    BOOST_CHECK(6 == Algo::Search::UnlockCodePath::find_dfs(deadends, "0202"));
}

BOOST_AUTO_TEST_CASE(leetcode_test_case_2)
{
    const std::vector<std::string> deadends = {"8888"};
    BOOST_CHECK(1 == Algo::Search::UnlockCodePath::find_dfs(deadends, "0009"));
}

BOOST_AUTO_TEST_CASE(leetcode_test_case_3)
{
    const std::vector<std::string> deadends =
        {"8887","8889","8878","8898","8788","8988","7888","9888"};

    BOOST_CHECK(-1 == Algo::Search::UnlockCodePath::find_dfs(deadends, "8888"));
}

BOOST_AUTO_TEST_SUITE_END()
