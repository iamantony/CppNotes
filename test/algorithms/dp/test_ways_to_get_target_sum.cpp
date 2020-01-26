#include <boost/test/unit_test.hpp>
#include "algorithms/dp/ways_to_get_target_sum.hpp"

BOOST_AUTO_TEST_SUITE(TestWaysToGetTargetSum)

BOOST_AUTO_TEST_CASE(empty_vector)
{
    const std::vector<int> values;
    const int targetSum = 0;
    const int expected = 0;
    BOOST_CHECK(expected == Algo::DP::WaysToGetTargetSum::calc(values, targetSum));
}

BOOST_AUTO_TEST_CASE(vector_wih_one_element_valid_target)
{
    const std::vector<int> values = {1};
    const int targetSum = 1;
    const int expected = 1;
    BOOST_CHECK(expected == Algo::DP::WaysToGetTargetSum::calc(values, targetSum));
}

BOOST_AUTO_TEST_CASE(vector_wih_one_element_invalid_target)
{
    const std::vector<int> values = {10};
    const int targetSum = 1;
    const int expected = 0;
    BOOST_CHECK(expected == Algo::DP::WaysToGetTargetSum::calc(values, targetSum));
}

// TODO fix
//BOOST_AUTO_TEST_CASE(vector_wih_several_element_valid_target)
//{
//    const std::vector<int> values = {1, 1, 1, 1, 1};
//    const int targetSum = 3;
//    const int expected = 5;
//    BOOST_CHECK(expected == Algo::DP::WaysToGetTargetSum::calc(values, targetSum));
//}
//
//BOOST_AUTO_TEST_CASE(vector_wih_several_element_invalid_target)
//{
//    const std::vector<int> values = {1, 1, 1, 1, 1};
//    const int targetSum = 80;
//    const int expected = 0;
//    BOOST_CHECK(expected == Algo::DP::WaysToGetTargetSum::calc(values, targetSum));
//}

BOOST_AUTO_TEST_SUITE_END()
