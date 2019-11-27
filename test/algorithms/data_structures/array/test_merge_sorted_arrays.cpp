#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/merge_sorted_arrays.hpp"

BOOST_AUTO_TEST_SUITE(TestMergeSortedArrays)

BOOST_AUTO_TEST_CASE(invalid_args)
{
    {
        std::vector<int> first = {};
        std::vector<int> second = {};
        std::vector<int> expected = {};
        int firstSize = -10;
        int secondSize = -1;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }

    {
        std::vector<int> first = {};
        std::vector<int> second = {};
        std::vector<int> expected = {};
        int firstSize = -10;
        int secondSize = 0;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }

    {
        std::vector<int> first = {};
        std::vector<int> second = {};
        std::vector<int> expected = {};
        int firstSize = 0;
        int secondSize = 0;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }
}

BOOST_AUTO_TEST_CASE(one_empty_array)
{
    {
        std::vector<int> first = {0};
        std::vector<int> second = {};
        std::vector<int> expected = {0};
        int firstSize = 1;
        int secondSize = 0;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }

    {
        std::vector<int> first = {0, 0, 0};
        std::vector<int> second = {1, 2, 3};
        std::vector<int> expected = {1, 2, 3};
        int firstSize = 0;
        int secondSize = 3;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }
}

BOOST_AUTO_TEST_CASE(valid_arrays)
{
    {
        std::vector<int> first = {0, 1, 2, 0, 0, 0};
        std::vector<int> second = {0, 1, 2};
        std::vector<int> expected = {0, 0, 1, 1, 2, 2};
        int firstSize = 3;
        int secondSize = 3;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }

    {
        std::vector<int> first = {0, 1, 2, 0, 0, 0};
        std::vector<int> second = {3, 4, 5};
        std::vector<int> expected = {0, 1, 2, 3, 4, 5};
        int firstSize = 3;
        int secondSize = 3;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }

    {
        std::vector<int> first = {0, 1, 10, 0, 0, 0};
        std::vector<int> second = {3, 4, 15};
        std::vector<int> expected = {0, 1, 3, 4, 10, 15};
        int firstSize = 3;
        int secondSize = 3;

        Algo::DS::Array::MergeSortedArrays::Merge(
                    first, firstSize, second, secondSize);

        BOOST_CHECK(expected == first);
    }
}

BOOST_AUTO_TEST_SUITE_END()
