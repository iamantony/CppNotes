#ifndef TEST_VECTOR_ITERATOR_HPP
#define TEST_VECTOR_ITERATOR_HPP

#include <iostream>

#include <boost/test/unit_test.hpp>

#include "types/vector_iterator.hpp"

BOOST_AUTO_TEST_CASE(test_veciter_create)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    BOOST_CHECK(1 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_preincrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter;
    BOOST_CHECK(3 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_create_from_other_iter) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter;
    Types::VectorIterator otherIter(iter);
    BOOST_CHECK(3 == *otherIter);
}

BOOST_AUTO_TEST_CASE(test_veciter_assign_from_other_iter) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter, ++iter;
    Types::VectorIterator otherIter(vec);
    otherIter = iter;
    BOOST_CHECK(5 == *otherIter);
}

BOOST_AUTO_TEST_CASE(test_veciter_change_value)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    *iter = 10;
    BOOST_CHECK(10 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_postincrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    Types::VectorIterator prevIter = iter++;
    BOOST_CHECK(1 == *prevIter);
    BOOST_CHECK(3 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_increment_till_end)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec), otherIter(vec);
    for (size_t i = 0; i < 5; ++i) {
        ++iter;
        ++otherIter;
    }

    BOOST_CHECK(otherIter == iter);

    Types::VectorIterator endIter = iter.end();
    BOOST_CHECK(endIter == iter);
    BOOST_CHECK_THROW(*iter, std::out_of_range);
}

BOOST_AUTO_TEST_CASE(test_veciter_predecrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    --iter;
    BOOST_CHECK(1 == *iter);

    ++iter;
    --iter;
    BOOST_CHECK(1 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_postdecrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter, ++iter;

    Types::VectorIterator prevIter = iter--;
    BOOST_CHECK(5 == *prevIter);
    BOOST_CHECK(3 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_decrement_till_begin)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec), otherIter(vec);
    for (size_t i = 0; i < 5; ++i) {
        ++iter;
    }

    for (size_t i = 0; i < 5; ++i) {
        --iter;
    }

    BOOST_CHECK(otherIter == iter);

    Types::VectorIterator beginIter = iter.begin();
    BOOST_CHECK(beginIter == iter);
    BOOST_CHECK(1 == *iter);
}

BOOST_AUTO_TEST_CASE(test_veciter_compare_diff_iters)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec), otherIter(vec);
    ++iter;
    BOOST_CHECK(otherIter != iter);
}

/*

*/

#endif // TEST_VECTOR_ITERATOR_HPP
