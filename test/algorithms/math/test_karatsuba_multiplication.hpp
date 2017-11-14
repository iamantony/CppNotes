#ifndef TESTKARATSUBAMULTIPLICATION_HPP_
#define TESTKARATSUBAMULTIPLICATION_HPP_

#include <boost/test/unit_test.hpp>

#include <string>

#include "algorithms/math/karatsuba_multiplication.hpp"

BOOST_AUTO_TEST_CASE(test_karatsuba_null_numbers)
{
    BOOST_CHECK(0 == KaratsubaMultiplication(0, 0));
    BOOST_CHECK(0 == KaratsubaMultiplication(123, 0));
    BOOST_CHECK(0 == KaratsubaMultiplication(0, 456));
}

BOOST_AUTO_TEST_CASE(test_karatsuba_small_numbers)
{
    BOOST_CHECK(1 == KaratsubaMultiplication(1, 1));
    BOOST_CHECK(20 == KaratsubaMultiplication(10, 2));
    BOOST_CHECK(770 == KaratsubaMultiplication(14, 55));
}

BOOST_AUTO_TEST_CASE(test_karatsuba_big_numbers)
{
    BOOST_CHECK(3085153753124 == KaratsubaMultiplication(895372, 3445667));
    BOOST_CHECK(121932631112635269 ==
            KaratsubaMultiplication(987654321, 123456789));
}

BOOST_AUTO_TEST_CASE(test_karatsuba_numbers_with_sign)
{
    BOOST_CHECK(3085153753124 == KaratsubaMultiplication(-895372, -3445667));
    BOOST_CHECK(-121932631112635269 ==
            KaratsubaMultiplication(-987654321, 123456789));
    BOOST_CHECK(-121932631112635269 ==
            KaratsubaMultiplication(987654321, -123456789));
}

#endif /* TESTKARATSUBAMULTIPLICATION_HPP_ */
