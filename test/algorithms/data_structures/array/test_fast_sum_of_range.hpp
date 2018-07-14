#ifndef TEST_FAST_SUM_OF_RANGE_HPP
#define TEST_FAST_SUM_OF_RANGE_HPP

#include <limits>
#include <random>

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/fast_sum_of_range.hpp"

BOOST_AUTO_TEST_CASE(test_fsor_invalid_args)
{
    {
        Algo::DS::Array::NumArray array({});
        BOOST_CHECK(0 == array.sumRange(1, 2));
        BOOST_CHECK(0 == array.sumRange(0, 0));
    }

    {
        Algo::DS::Array::NumArray array({1, 2, 3});
        BOOST_CHECK(0 == array.sumRange(-1, -2));
        BOOST_CHECK(0 == array.sumRange(-1, 0));
        BOOST_CHECK(0 == array.sumRange(3, 1));
        BOOST_CHECK(0 == array.sumRange(3, 4));
    }
}

BOOST_AUTO_TEST_CASE(test_fsor_rand_tests) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> sizeDist(
                1, 1000000);

    std::uniform_int_distribution<int> valuesDist(
                std::numeric_limits<int>::min(),
                std::numeric_limits<int>::max());

    for (size_t i = 0; i < 10; ++i) {
        std::vector<int> container(sizeDist(gen), 0);
        for (size_t j = 0; j < container.size(); ++j) {
            container[j] = valuesDist(gen);
        }

        Algo::DS::Array::NumArray array(container);

        std::uniform_int_distribution<int> indexesDist(
                    0, static_cast<int>(container.size() - 1));

        for (size_t j = 0; j < 100; ++j) {
            int iInd = indexesDist(gen);

            std::uniform_int_distribution<int> secondIndexDist(
                        iInd, static_cast<int>(container.size() - 1));

            int jInd = secondIndexDist(gen);

            int expected = 0;
            for (size_t k = static_cast<size_t>(iInd);
                 k <= static_cast<size_t>(jInd);
                 ++k)
            {
                expected += container[k];
            }

            BOOST_CHECK(expected == array.sumRange(iInd, jInd));
        }
    }
}

#endif // TEST_FAST_SUM_OF_RANGE_HPP
