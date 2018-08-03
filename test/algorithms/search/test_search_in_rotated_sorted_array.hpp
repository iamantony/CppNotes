#ifndef TEST_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
#define TEST_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/search/search_in_rotated_sorted_array.hpp"

BOOST_AUTO_TEST_CASE(test_sirsa_empty_container)
{
    std::vector<int> container;
    int value = 0;
    size_t position;
    bool expectedIsFound = false;
    BOOST_CHECK(expectedIsFound == Algo::Search::SearchInRotatedArray::Search(
                    container, value, position));
}

BOOST_AUTO_TEST_CASE(test_sirsa_container_with_one_elem)
{
    {
        std::vector<int> container = {0};
        int value = 0;
        size_t position;
        size_t expectedPosition = 0;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {1};
        int value = 0;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }
}

BOOST_AUTO_TEST_CASE(test_sirsa_sorted_container_with_two_elems)
{
    {
        std::vector<int> container = {0, 1};
        int value = 1;
        size_t position;
        size_t expectedPosition = 1;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {1, 2};
        int value = 0;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }
}

BOOST_AUTO_TEST_CASE(test_sirsa_unsorted_container_with_two_elems)
{
    {
        std::vector<int> container = {5, 1};
        int value = 1;
        size_t position;
        size_t expectedPosition = 1;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {2, 1};
        int value = 0;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }
}

BOOST_AUTO_TEST_CASE(test_sirsa_sorted_container_with_many_elems)
{
    {
        std::vector<int> container = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8};
        int value = 3;
        size_t position;
        size_t expectedPosition = 3;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8};
        int value = 10;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }
}

/*
rotated container of size 5 with pivot on left with value
rotated container of size 5 with pivot on right without value
*/

BOOST_AUTO_TEST_CASE(test_sirsa_rotated_container_with_4_elems)
{
    {
        std::vector<int> container = {4, 1, 2, 3};
        int value = 3;
        size_t position;
        size_t expectedPosition = 3;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {4, 1, 2, 3};
        int value = 4;
        size_t position;
        size_t expectedPosition = 0;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {4, 1, 2, 3};
        int value = 15;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }

    {
        std::vector<int> container = {2, 3, 4, 1};
        int value = 2;
        size_t position;
        size_t expectedPosition = 0;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {2, 3, 4, 1};
        int value = 10;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }
}

BOOST_AUTO_TEST_CASE(test_sirsa_rotated_container_with_5_elems)
{
    {
        std::vector<int> container = {4, 5, 1, 2, 3};
        int value = 5;
        size_t position;
        size_t expectedPosition = 1;
        bool expectedIsFound = true;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
        BOOST_CHECK(expectedPosition == position);
    }

    {
        std::vector<int> container = {4, 5, 1, 2, 3};
        int value = 14;
        size_t position;
        bool expectedIsFound = false;
        BOOST_CHECK(expectedIsFound ==
                    Algo::Search::SearchInRotatedArray::Search(
                        container, value, position));
    }
}

#endif // TEST_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
