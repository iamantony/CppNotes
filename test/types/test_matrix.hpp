#ifndef TEST_MATRIX_HPP_
#define TEST_MATRIX_HPP_

#include <boost/test/unit_test.hpp>

#include "types/matrix.hpp"

BOOST_AUTO_TEST_CASE(test_matrix_add_wrong_dimensions)
{
    DS::Matrix<int> first(2, 2, 0);
    DS::Matrix<int> second(2, 3, 0);

    try
    {
        first += second;
        BOOST_CHECK(false);
    }
    catch(const std::exception& exp) {}

    try
    {
        DS::Matrix<int> result = first + second;
        BOOST_CHECK(false);
    }
    catch(const std::exception& exp) {}

    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_matrix_add)
{
    DS::Matrix<int> first(2, 2, 0);
    first.setRowValues(0, {1, 2});
    first.setRowValues(1, {3, 4});

    DS::Matrix<int> second(2, 2, 0);
    second.setRowValues(0, {5, 6});
    second.setRowValues(1, {7, 8});

    DS::Matrix<int> expected(2, 2, 0);
    expected.setRowValues(0, {6, 8});
    expected.setRowValues(1, {10, 12});

    try
    {
        DS::Matrix<int> result = first + second;
        BOOST_CHECK(expected == result);
    }
    catch(const std::exception& exp)
    {
        BOOST_CHECK(false);
    }

    try
    {
        first += second;
        BOOST_CHECK(expected == first);
    }
    catch(const std::exception& exp)
    {
        BOOST_CHECK(false);
    }
}

BOOST_AUTO_TEST_CASE(test_matrix_substract_wrong_dimensions)
{
    DS::Matrix<int> first(2, 2, 0);
    DS::Matrix<int> second(2, 3, 0);

    try
    {
        first -= second;
        BOOST_CHECK(false);
    }
    catch(const std::exception& exp) {}

    try
    {
        DS::Matrix<int> result = first - second;
        BOOST_CHECK(false);
    }
    catch(const std::exception& exp) {}

    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_matrix_substract)
{
    DS::Matrix<int> first(2, 2, 0);
    first.setRowValues(0, {1, 2});
    first.setRowValues(1, {3, 4});

    DS::Matrix<int> second(2, 2, 0);
    second.setRowValues(0, {5, 6});
    second.setRowValues(1, {7, 8});

    DS::Matrix<int> expected(2, 2, -4);

    try
    {
        DS::Matrix<int> result = first - second;
        BOOST_CHECK(expected == result);
    }
    catch(const std::exception& exp)
    {
        BOOST_CHECK(false);
    }

    try
    {
        first -= second;
        BOOST_CHECK(expected == first);
    }
    catch(const std::exception& exp)
    {
        BOOST_CHECK(false);
    }
}

#endif /* TEST_MATRIX_HPP_ */
