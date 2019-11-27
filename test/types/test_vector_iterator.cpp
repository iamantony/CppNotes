#include <boost/test/unit_test.hpp>
#include <iostream>
#include "types/vector_iterator.hpp"

BOOST_AUTO_TEST_SUITE(VectorIterator)

BOOST_AUTO_TEST_CASE(create)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    BOOST_CHECK(1 == *iter);
}

BOOST_AUTO_TEST_CASE(preincrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter;
    BOOST_CHECK(3 == *iter);
}

BOOST_AUTO_TEST_CASE(create_from_other_iter) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter;
    Types::VectorIterator otherIter(iter);
    BOOST_CHECK(3 == *otherIter);
}

BOOST_AUTO_TEST_CASE(assign_from_other_iter) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter, ++iter;
    Types::VectorIterator otherIter(vec);
    otherIter = iter;
    BOOST_CHECK(5 == *otherIter);
}

BOOST_AUTO_TEST_CASE(change_value)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    *iter = 10;
    BOOST_CHECK(10 == *iter);
}

BOOST_AUTO_TEST_CASE(postincrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    Types::VectorIterator prevIter = iter++;
    BOOST_CHECK(1 == *prevIter);
    BOOST_CHECK(3 == *iter);
}

BOOST_AUTO_TEST_CASE(increment_till_end)
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

BOOST_AUTO_TEST_CASE(predecrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    --iter;
    BOOST_CHECK(1 == *iter);

    ++iter;
    --iter;
    BOOST_CHECK(1 == *iter);
}

BOOST_AUTO_TEST_CASE(postdecrement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec);
    ++iter, ++iter;

    Types::VectorIterator prevIter = iter--;
    BOOST_CHECK(5 == *prevIter);
    BOOST_CHECK(3 == *iter);
}

BOOST_AUTO_TEST_CASE(decrement_till_begin)
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

BOOST_AUTO_TEST_CASE(compare_diff_iters)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Types::VectorIterator iter(vec), otherIter(vec);
    ++iter;
    BOOST_CHECK(otherIter != iter);
}

BOOST_AUTO_TEST_SUITE_END()
