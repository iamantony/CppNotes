#include <boost/test/unit_test.hpp>
#include "algorithms/math/sum_of_multiples.hpp"

BOOST_AUTO_TEST_SUITE(TestSumOfMultiples)

BOOST_AUTO_TEST_CASE(test)
{
    SumOfMultiples::Solution solution;
    BOOST_CHECK(solution.SumOfMultiples(3, 5, 1000) == 233168);
}

BOOST_AUTO_TEST_SUITE_END()

