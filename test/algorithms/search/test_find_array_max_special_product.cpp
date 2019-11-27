#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_array_max_special_product.hpp"

BOOST_AUTO_TEST_SUITE(TestFindArrayMaxSpecialProduct)

BOOST_AUTO_TEST_CASE(test)
{
    {
        std::vector<int> nums = {1, 1, 1};
        BOOST_CHECK(0 ==
                    Algo::Search::FindArrayMaxSpecialProduct::Find(nums));
    }

    {
        std::vector<int> nums = {1, 2, 1, 3};
        BOOST_CHECK(3 ==
                    Algo::Search::FindArrayMaxSpecialProduct::Find(nums));
    }

    {
        std::vector<int> nums = {3, 1, 4, 2, 5};
        BOOST_CHECK(8 ==
                    Algo::Search::FindArrayMaxSpecialProduct::Find(nums));
    }
}

BOOST_AUTO_TEST_SUITE_END()
