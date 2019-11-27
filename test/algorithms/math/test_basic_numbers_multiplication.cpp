#include <boost/test/unit_test.hpp>
#include "algorithms/math/basic_numbers_multiplication.hpp"

BOOST_AUTO_TEST_SUITE(TestBasicNumbersMultiplication)

BOOST_AUTO_TEST_CASE(null_numbers)
{
    BOOST_CHECK(0 == BasicNumbersMultiplication(0, 0));
    BOOST_CHECK(0 == BasicNumbersMultiplication(123, 0));
    BOOST_CHECK(0 == BasicNumbersMultiplication(0, 456));
}

BOOST_AUTO_TEST_CASE(small_numbers)
{
    BOOST_CHECK(1 == BasicNumbersMultiplication(1, 1));
    BOOST_CHECK(20 == BasicNumbersMultiplication(10, 2));
    BOOST_CHECK(770 == BasicNumbersMultiplication(14, 55));
}

BOOST_AUTO_TEST_CASE(big_numbers)
{
    BOOST_CHECK(3085153753124 == BasicNumbersMultiplication(895372, 3445667));
    BOOST_CHECK(121932631112635269 ==
            BasicNumbersMultiplication(987654321, 123456789));
}

BOOST_AUTO_TEST_CASE(numbers_with_sign)
{
    BOOST_CHECK(3085153753124 == BasicNumbersMultiplication(-895372, -3445667));
    BOOST_CHECK(-121932631112635269 ==
            BasicNumbersMultiplication(-987654321, 123456789));
    BOOST_CHECK(-121932631112635269 ==
                    BasicNumbersMultiplication(987654321, -123456789));
}

BOOST_AUTO_TEST_SUITE_END()
