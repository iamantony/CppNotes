#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/search_insert_position.hpp"

BOOST_AUTO_TEST_SUITE(TestSearchInsertPosition)

BOOST_AUTO_TEST_CASE(empty_vector)
{
    std::vector<int> v;
    std::sort(v.begin(), v.end());
    int value = 0;
    size_t expectedPos = 0;
    BOOST_CHECK(expectedPos ==
                Algo::DS::Array::SearchInsertPos::Search(v, value));
}

BOOST_AUTO_TEST_CASE(one_value_vector)
{
    {
        std::vector<int> v = {0};
        std::sort(v.begin(), v.end());
        int value = 0;
        size_t expectedPos = 0;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {0};
        std::sort(v.begin(), v.end());
        int value = 1;
        size_t expectedPos = 1;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {5};
        std::sort(v.begin(), v.end());
        int value = 0;
        size_t expectedPos = 0;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }
}

BOOST_AUTO_TEST_CASE(vector_with_many_values)
{
    {
        std::vector<int> v = {1, 3, 5, 6};
        std::sort(v.begin(), v.end());
        int value = 5;
        size_t expectedPos = 2;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3, 5, 6};
        std::sort(v.begin(), v.end());
        int value = 2;
        size_t expectedPos = 1;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3, 5, 6};
        std::sort(v.begin(), v.end());
        int value = 7;
        size_t expectedPos = 4;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3, 5, 6};
        std::sort(v.begin(), v.end());
        int value = 0;
        size_t expectedPos = 0;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3};
        std::sort(v.begin(), v.end());
        int value = 0;
        size_t expectedPos = 0;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3};
        std::sort(v.begin(), v.end());
        int value = 2;
        size_t expectedPos = 1;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3};
        std::sort(v.begin(), v.end());
        int value = 4;
        size_t expectedPos = 2;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {1, 3, 5};
        std::sort(v.begin(), v.end());
        int value = 4;
        size_t expectedPos = 2;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }

    {
        std::vector<int> v = {3, 6, 7, 8, 10};
        std::sort(v.begin(), v.end());
        int value = 5;
        size_t expectedPos = 1;
        BOOST_CHECK(expectedPos ==
                    Algo::DS::Array::SearchInsertPos::Search(v, value));
    }
}

BOOST_AUTO_TEST_SUITE_END()
