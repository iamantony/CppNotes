#include <boost/test/unit_test.hpp>
#include <iostream>
#include <vector>
#include "algorithms/math/primes.hpp"

BOOST_AUTO_TEST_SUITE(TestPrimesGeneration)

BOOST_AUTO_TEST_CASE(naive_invalid)
{
    BOOST_CHECK(std::vector<int>() == GetPrimesNaive<int>(-10));
    BOOST_CHECK(std::vector<int>() == GetPrimesNaive<int>(0));
    BOOST_CHECK(std::vector<int>() == GetPrimesNaive<int>(1));
}

BOOST_AUTO_TEST_CASE(naive_min)
{
    std::vector<int> expected = {2};
    BOOST_CHECK(expected == GetPrimesNaive<int>(2));
}

BOOST_AUTO_TEST_CASE(naive)
{
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
            41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    BOOST_CHECK(expected == GetPrimesNaive<int>(100));
}

BOOST_AUTO_TEST_CASE(improved_invalid)
{
    BOOST_CHECK(std::vector<int>() == GetPrimesImproved<int>(-10));
    BOOST_CHECK(std::vector<int>() == GetPrimesImproved<int>(0));
    BOOST_CHECK(std::vector<int>() == GetPrimesImproved<int>(1));
}

BOOST_AUTO_TEST_CASE(improved_min)
{
    std::vector<int> expected = {2};
    BOOST_CHECK(expected == GetPrimesImproved<int>(2));
}

BOOST_AUTO_TEST_CASE(improved)
{
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
            41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    BOOST_CHECK(expected == GetPrimesImproved<int>(100));
}

BOOST_AUTO_TEST_CASE(seive_invalid)
{
    BOOST_CHECK(std::vector<int>() == GetPrimesSeive<int>(-10));
    BOOST_CHECK(std::vector<int>() == GetPrimesSeive<int>(0));
    BOOST_CHECK(std::vector<int>() == GetPrimesSeive<int>(1));
}

BOOST_AUTO_TEST_CASE(seive_min)
{
    std::vector<int> expected = {2};
    BOOST_CHECK(expected == GetPrimesSeive<int>(2));
}

BOOST_AUTO_TEST_CASE(seive)
{
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
            41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    BOOST_CHECK(expected == GetPrimesSeive<int>(100));
}

BOOST_AUTO_TEST_SUITE_END()
