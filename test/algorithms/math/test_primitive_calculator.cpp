#include <boost/test/unit_test.hpp>
#include "algorithms/math/primitive_calculator.hpp"

BOOST_AUTO_TEST_SUITE(TestPrimitiveCalculator)

BOOST_AUTO_TEST_CASE(test_primcalc_input) {
    {
        const uint32_t value = 1;
        const std::vector<uint32_t> result = {1};
        BOOST_CHECK(Algo::Math::PrimitiveCalculator::Calc(value) == result);
    }

    {
        const uint32_t value = 5;
        const std::vector<uint32_t> result = {1, 2, 4, 5};
        BOOST_CHECK(Algo::Math::PrimitiveCalculator::Calc(value) == result);
    }

    {
        const uint32_t value = 96234;
        const std::vector<uint32_t> result = {1, 3, 9, 10, 11, 22, 66, 198, 594,
                                        1782, 5346, 16038, 16039, 32078, 96234};
        BOOST_CHECK(Algo::Math::PrimitiveCalculator::Calc(value) == result);
    }
}

BOOST_AUTO_TEST_SUITE_END()
