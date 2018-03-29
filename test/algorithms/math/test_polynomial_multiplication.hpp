#ifndef TEST_POLYNOMIAL_MULTIPLICATION_HPP
#define TEST_POLYNOMIAL_MULTIPLICATION_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/polynomial_multiplication.hpp"

BOOST_AUTO_TEST_CASE(test_polmul_zero_polynomials)
{
    PolMult::Solution solution;
    std::vector<int> pol1;
    std::vector<int> pol2;
    std::vector<int> expected;

    BOOST_CHECK(expected == solution.PolynomialMultNaive(0, pol1, pol2));
}

BOOST_AUTO_TEST_CASE(test_polmul_invalid_polynomials)
{
    PolMult::Solution solution;
    std::vector<int> pol1 = {0, 1, 2};
    std::vector<int> pol2 = {12};
    std::vector<int> expected;

    BOOST_CHECK(expected == solution.PolynomialMultNaive(
                    pol1.size(), pol1, pol2));
}

BOOST_AUTO_TEST_CASE(test_polmul_simple_polynomials)
{
    PolMult::Solution solution;
    std::vector<int> pol1 = {1, 2};
    std::vector<int> pol2 = {3, 4};
    std::vector<int> expected = {3, 10, 8};

    BOOST_CHECK(expected == solution.PolynomialMultNaive(
                    pol1.size(), pol1, pol2));
}

BOOST_AUTO_TEST_CASE(test_polmul_polynomials)
{
    PolMult::Solution solution;
    std::vector<int> pol1 = {3, 2, 5};
    std::vector<int> pol2 = {5, 1, 2};
    std::vector<int> expected = {15, 13, 33, 9, 10};

    BOOST_CHECK(expected == solution.PolynomialMultNaive(
                    pol1.size(), pol1, pol2));
}

#endif // TEST_POLYNOMIAL_MULTIPLICATION_HPP

