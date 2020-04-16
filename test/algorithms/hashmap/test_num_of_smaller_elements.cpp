#include <boost/test/unit_test.hpp>
#include "algorithms/hashmap/num_of_smaller_elements.hpp"

BOOST_AUTO_TEST_SUITE(TestNumOfSmallerElements)

    BOOST_AUTO_TEST_CASE(empty_input_array)
    {
        Algo::HashMap::NumOfSmallerElements obj;
        const std::vector<int> input = {};
        const std::vector<int> expected = {};
        BOOST_CHECK(expected == obj.count(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_one_elem)
    {
        Algo::HashMap::NumOfSmallerElements obj;
        const std::vector<int> input = {1};
        const std::vector<int> expected = {0};
        BOOST_CHECK(expected == obj.count(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_all_equal_elements)
    {
        Algo::HashMap::NumOfSmallerElements obj;
        const std::vector<int> input = {3, 3, 3, 3};
        const std::vector<int> expected = {0, 0, 0, 0};
        BOOST_CHECK(expected == obj.count(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_two_diff_elements)
    {
        Algo::HashMap::NumOfSmallerElements obj;
        const std::vector<int> input = {4, 3};
        const std::vector<int> expected = {1, 0};
        BOOST_CHECK(expected == obj.count(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_several_diff_elements)
    {
        Algo::HashMap::NumOfSmallerElements obj;
        const std::vector<int> input = {8, 1, 2, 2, 3};
        const std::vector<int> expected = {4, 0, 1, 1, 3};
        BOOST_CHECK(expected == obj.count(input));
    }


BOOST_AUTO_TEST_SUITE_END()
