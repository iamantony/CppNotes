#include <random>
#include <limits>
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "algorithms/math/least_common_multiple.hpp"

BOOST_AUTO_TEST_SUITE(TestLeastCommonMultiple)

BOOST_AUTO_TEST_CASE(numbers) {
    BOOST_CHECK(Algo::Math::LeastCommonMultiple::Find(1, 1) == 1);
    BOOST_CHECK(Algo::Math::LeastCommonMultiple::Find(5, 1) == 5);
    BOOST_CHECK(Algo::Math::LeastCommonMultiple::Find(5, 15) == 15);
    BOOST_CHECK(Algo::Math::LeastCommonMultiple::Find(6, 8) == 24);
    BOOST_CHECK(Algo::Math::LeastCommonMultiple::Find(761457, 614573) == 467970912861);
}

BOOST_AUTO_TEST_CASE(random_numbers) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> valuesDist(1, 100);
    for (int i = 0; i < 100; ++i) {
        const uint64_t first = static_cast<uint64_t>(valuesDist(gen));
        const uint64_t second = static_cast<uint64_t>(valuesDist(gen));

        const auto result = Algo::Math::LeastCommonMultiple::Find(first, second);
        const auto resultNaive =
                Algo::Math::LeastCommonMultiple::FindNaive(first, second);

        if (result != resultNaive)
        {
            std::cout << first << " and " << second << ": " <<
                         result << " vs " << resultNaive << std::endl;
            BOOST_FAIL("Different results!");
            return;
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
