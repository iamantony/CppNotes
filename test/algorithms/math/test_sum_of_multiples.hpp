#ifndef TEST_SUM_OF_MULTIPLES_HPP
#define TEST_SUM_OF_MULTIPLES_HPP

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <memory>

#include "algorithms/math/sum_of_multiples.hpp"

BOOST_AUTO_TEST_CASE(test_som_3_and_5_lim_1000)
{
    SumOfMultiples::Solution solution;
    BOOST_CHECK(solution.SumOfMultiples(3, 5, 1000) == 233168);
}

#endif // TEST_SUM_OF_MULTIPLES_HPP

