#ifndef TEST_QUICKSORT_RESEARCH_HPP_
#define TEST_QUICKSORT_RESEARCH_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <vector>
#include <limits>
#include <iostream>
#include <fstream>

#include "algorithms/sorting/quicksort_research.hpp"

BOOST_AUTO_TEST_CASE(test_qsr_empty_container)
{
    BOOST_CHECK(std::vector<int>() == QuickSort(std::vector<int>(),
            QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(test_qsr_one_value)
{
    std::vector<int> container;
    container.push_back(42);

    BOOST_CHECK(container == QuickSort(container,
            QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(test_qsr_sorted_container)
{
    std::vector<int> container = {0, 42, 43, 100};
    BOOST_CHECK(container == QuickSort(container,
            QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(test_qsr_min_max_int_values)
{
    std::vector<int> container;
    container.push_back(42);
    container.push_back(10);
    container.push_back(1);
    container.push_back(std::numeric_limits<int>::min());
    container.push_back(std::numeric_limits<int>::max());

    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == QuickSort(container,
            QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(test_qsr_unsorted_example)
{
    std::vector<int> container = {3, 8, 2, 5, 1, 4, 7, 6};
    std::vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == QuickSort(container,
            QuickSortResearch::PivotPosition::FIRST).first);
}

BOOST_AUTO_TEST_CASE(test_qsr_example_10)
{
//    How to find out what is current path of the executable:
//    boost::filesystem::path full_path( boost::filesystem::current_path() );
//    std::cout << full_path << std::endl;

    std::ifstream file("./test/data/10.txt");
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

BOOST_AUTO_TEST_CASE(test_qsr_example_100)
{
    std::ifstream file("./test/data/100.txt");
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

BOOST_AUTO_TEST_CASE(test_qsr_example_1000)
{
    std::ifstream file("./test/data/1000.txt");
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

BOOST_AUTO_TEST_CASE(test_qsr_example_10000)
{
    std::ifstream file("./test/data/10000.txt");
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

#endif /* TEST_QUICKSORT_RESEARCH_HPP_ */
