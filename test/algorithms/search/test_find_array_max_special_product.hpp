#ifndef TEST_FIND_ARRAY_MAX_SPECIAL_PRODUCT_HPP
#define TEST_FIND_ARRAY_MAX_SPECIAL_PRODUCT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/search/find_array_max_special_product.hpp"

BOOST_AUTO_TEST_CASE(test_famso_data)
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

#endif // TEST_FIND_ARRAY_MAX_SPECIAL_PRODUCT_HPP
