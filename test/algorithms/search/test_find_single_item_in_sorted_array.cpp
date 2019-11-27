#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_single_item_in_sorted_array.hpp"

BOOST_AUTO_TEST_SUITE(TestFindSingleItemInSortedArray)

BOOST_AUTO_TEST_CASE(vector_empty)
{
    BOOST_CHECK(0 == Algo::Search::FindSingleItemInSortedArr<int>::FindBS(
                    std::vector<int>()));

    BOOST_CHECK(0 == Algo::Search::FindSingleItemInSortedArr<int>::FindLinear(
                    std::vector<int>()));
}

BOOST_AUTO_TEST_CASE(one_elem)
{
    BOOST_CHECK(1 == Algo::Search::FindSingleItemInSortedArr<int>::FindBS({1}));
    BOOST_CHECK(1 ==
                Algo::Search::FindSingleItemInSortedArr<int>::FindLinear({1}));
}

BOOST_AUTO_TEST_CASE(two_elements)
{
    BOOST_CHECK(0 ==
                Algo::Search::FindSingleItemInSortedArr<int>::FindBS({1, 1}));

    BOOST_CHECK(0 ==
             Algo::Search::FindSingleItemInSortedArr<int>::FindLinear({1, 1}));
}

BOOST_AUTO_TEST_CASE(several_elements)
{
    {
        const std::vector<int> v({1, 1, 2, 2, 3, 4, 4});
        BOOST_CHECK(3 ==
                    Algo::Search::FindSingleItemInSortedArr<int>::FindBS(v));
        BOOST_CHECK(3 ==
                    Algo::Search::FindSingleItemInSortedArr<int>::FindLinear(v));
    }

    {
        const std::vector<int> v({1, 2, 2, 3, 3, 4, 4});
        BOOST_CHECK(1 ==
                    Algo::Search::FindSingleItemInSortedArr<int>::FindBS(v));
        BOOST_CHECK(1 ==
                    Algo::Search::FindSingleItemInSortedArr<int>::FindLinear(v));
    }

    {
        const std::vector<int> v({1, 1, 2, 2, 3, 3, 4, 4, 5});
        BOOST_CHECK(5 ==
                    Algo::Search::FindSingleItemInSortedArr<int>::FindBS(v));
        BOOST_CHECK(5 ==
                    Algo::Search::FindSingleItemInSortedArr<int>::FindLinear(v));
    }
}

BOOST_AUTO_TEST_SUITE_END()
