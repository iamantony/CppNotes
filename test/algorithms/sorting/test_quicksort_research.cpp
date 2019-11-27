#include <boost/test/unit_test.hpp>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "algorithms/sorting/quicksort_research.hpp"
#include "testcases_for_sorting_algorithms.hpp"

BOOST_AUTO_TEST_SUITE(TestQuickSortResearch)

using namespace TCFSortingAlgo;

BOOST_AUTO_TEST_CASE(empty_container)
{
    std::vector<int> container, expected;
    EmptyContainer(container, expected);
    BOOST_CHECK(expected == QuickSort(container,
                                QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(one_value)
{
    std::vector<int> container, expected;
    ContainerWithOneValue(container, expected);
    std::vector<int> result = QuickSort(container,
                                QuickSortResearch::PivotPosition::FIRST).first;

    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(sorted_container)
{
    std::vector<int> container, expected;
    SortedContainer(container, expected);
    std::vector<int> result = QuickSort(container,
                                QuickSortResearch::PivotPosition::FIRST).first;

    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(min_max_int_values)
{
    std::vector<int> container, expected;
    ContainerWithMinAndMaxValues(container, expected);
    std::vector<int> result = QuickSort(container,
                                QuickSortResearch::PivotPosition::FIRST).first;

    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(unsorted_example)
{
    std::vector<int> container = {3, 8, 2, 5, 1, 4, 7, 6};
    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == QuickSort(container,
            QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(example_10)
{
    // Make sure that working dir is /path/to/build/test
    const auto test_file = std::filesystem::current_path() / "data" / "10.txt";
    std::ifstream file(test_file);
    if (false == file.is_open())
    {
        std::cout << "Failed to open file that contains input data. "
                "Skip test." << std::endl;
        BOOST_CHECK(true);
    }

    std::vector<int> container;
    std::string str;
    while (std::getline(file, str))
    {
        container.push_back(std::stoi(str));
    }

    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    std::pair<std::vector<int>, long long int> qsResultPivotFirst =
            QuickSort(container, QuickSortResearch::PivotPosition::FIRST);

    BOOST_CHECK(result == qsResultPivotFirst.first);
    BOOST_CHECK(25 == qsResultPivotFirst.second);

    std::pair<std::vector<int>, long long int> qsResultPivotLast =
            QuickSort(container, QuickSortResearch::PivotPosition::LAST);

    BOOST_CHECK(result == qsResultPivotLast.first);
    BOOST_CHECK(29 == qsResultPivotLast.second);

    std::pair<std::vector<int>, long long int> qsResultPivotMid =
            QuickSort(container, QuickSortResearch::PivotPosition::MEDIAN_OF_THREE);

    BOOST_CHECK(result == qsResultPivotMid.first);
    BOOST_CHECK(21 == qsResultPivotMid.second);
}

BOOST_AUTO_TEST_CASE(example_100)
{
    const auto test_file = std::filesystem::current_path() / "data" / "100.txt";
    std::ifstream file(test_file);
    if (false == file.is_open())
    {
        std::cout << "Failed to open file that contains input data. "
                "Skip test." << std::endl;
        BOOST_CHECK(true);
    }

    std::vector<int> container;
    std::string str;
    while (std::getline(file, str))
    {
        container.push_back(std::stoi(str));
    }

    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    std::pair<std::vector<int>, long long int> qsResultPivotFirst =
            QuickSort(container, QuickSortResearch::PivotPosition::FIRST);

    BOOST_CHECK(result == qsResultPivotFirst.first);
    BOOST_CHECK(615 == qsResultPivotFirst.second);

    std::pair<std::vector<int>, long long int> qsResultPivotLast =
            QuickSort(container, QuickSortResearch::PivotPosition::LAST);

    BOOST_CHECK(result == qsResultPivotLast.first);
    BOOST_CHECK(587 == qsResultPivotLast.second);

    std::pair<std::vector<int>, long long int> qsResultPivotMid =
        QuickSort(container, QuickSortResearch::PivotPosition::MEDIAN_OF_THREE);

    BOOST_CHECK(result == qsResultPivotMid.first);
    BOOST_CHECK(518 == qsResultPivotMid.second);
}

BOOST_AUTO_TEST_CASE(example_1000)
{
    const auto test_file = std::filesystem::current_path() / "data" / "1000.txt";
    std::ifstream file(test_file);
    if (false == file.is_open())
    {
        std::cout << "Failed to open file that contains input data. "
                     "Skip test." << std::endl;
        BOOST_CHECK(true);
    }

    std::vector<int> container;
    std::string str;
    while (std::getline(file, str))
    {
        container.push_back(std::stoi(str));
    }

    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    std::pair<std::vector<int>, long long int> qsResultPivotFirst =
            QuickSort(container, QuickSortResearch::PivotPosition::FIRST);

    BOOST_CHECK(result == qsResultPivotFirst.first);
    BOOST_CHECK(10297 == qsResultPivotFirst.second);

    std::pair<std::vector<int>, long long int> qsResultPivotLast =
            QuickSort(container, QuickSortResearch::PivotPosition::LAST);

    BOOST_CHECK(result == qsResultPivotLast.first);
    BOOST_CHECK(10184 == qsResultPivotLast.second);

    std::pair<std::vector<int>, long long int> qsResultPivotMid =
        QuickSort(container, QuickSortResearch::PivotPosition::MEDIAN_OF_THREE);

    BOOST_CHECK(result == qsResultPivotMid.first);
    BOOST_CHECK(8921 == qsResultPivotMid.second);
}

BOOST_AUTO_TEST_CASE(example_10000)
{
    const auto test_file = std::filesystem::current_path() / "data" / "10000.txt";
    std::ifstream file(test_file);
    if (false == file.is_open())
    {
        std::cout << "Failed to open file that contains input data. "
                     "Skip test." << std::endl;
        BOOST_CHECK(true);
    }

    std::vector<int> container;
    std::string str;
    while (std::getline(file, str))
    {
        container.push_back(std::stoi(str));
    }

    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    std::pair<std::vector<int>, long long int> qsResultPivotFirst =
            QuickSort(container, QuickSortResearch::PivotPosition::FIRST);

    BOOST_CHECK(result == qsResultPivotFirst.first);
    BOOST_CHECK(162085 == qsResultPivotFirst.second);

    std::pair<std::vector<int>, long long int> qsResultPivotLast =
            QuickSort(container, QuickSortResearch::PivotPosition::LAST);

    BOOST_CHECK(result == qsResultPivotLast.first);
    BOOST_CHECK(164123 == qsResultPivotLast.second);

    std::pair<std::vector<int>, long long int> qsResultPivotMid =
        QuickSort(container, QuickSortResearch::PivotPosition::MEDIAN_OF_THREE);

    BOOST_CHECK(result == qsResultPivotMid.first);
    BOOST_CHECK(138382 == qsResultPivotMid.second);
}

BOOST_AUTO_TEST_SUITE_END()
