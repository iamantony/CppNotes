#ifndef TEST_DUPLICATES_IN_ARRAY_HPP
#define TEST_DUPLICATES_IN_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/duplicates_in_array.hpp"

BOOST_AUTO_TEST_CASE(test_dia_empty_arr)
{
    std::vector<int> numbers = {};
    BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::containsDuplicates(numbers));
}

BOOST_AUTO_TEST_CASE(test_dia_no_duplicates)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::containsDuplicates(numbers));
}

BOOST_AUTO_TEST_CASE(test_dia_have_duplicates)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 3};
    BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::containsDuplicates(numbers));
}

#endif // TEST_DUPLICATES_IN_ARRAY_HPP
