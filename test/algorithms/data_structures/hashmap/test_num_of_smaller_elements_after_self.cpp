#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/hashmap/num_of_smaller_elements_after_self.hpp"
#include <random>
#include <chrono>
#include <iostream>

BOOST_AUTO_TEST_SUITE(TestNumOfSmallerElementsAfterSelf)

    BOOST_AUTO_TEST_CASE(empty_input_array)
    {
        Algo::DS::HashMap::NumOfSmallerElementsAfterSelf obj;
        const std::vector<int> input = {};
        const std::vector<int> expected = {};
        BOOST_CHECK(expected == obj.count_with_map(input));
        BOOST_CHECK(expected == obj.count_with_sorting(input));
        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_one_elem)
    {
        Algo::DS::HashMap::NumOfSmallerElementsAfterSelf obj;
        const std::vector<int> input = {1};
        const std::vector<int> expected = {0};
        BOOST_CHECK(expected == obj.count_with_map(input));
        BOOST_CHECK(expected == obj.count_with_sorting(input));
        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_all_equal_elements)
    {
        Algo::DS::HashMap::NumOfSmallerElementsAfterSelf obj;
        const std::vector<int> input = {3, 3, 3, 3};
        const std::vector<int> expected = {0, 0, 0, 0};
        BOOST_CHECK(expected == obj.count_with_map(input));
        BOOST_CHECK(expected == obj.count_with_sorting(input));
        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_two_diff_elements)
    {
        Algo::DS::HashMap::NumOfSmallerElementsAfterSelf obj;
        const std::vector<int> input = {4, 3};
        const std::vector<int> expected = {1, 0};
        BOOST_CHECK(expected == obj.count_with_map(input));
        BOOST_CHECK(expected == obj.count_with_sorting(input));
        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_several_diff_elements)
    {
        Algo::DS::HashMap::NumOfSmallerElementsAfterSelf obj;
        const std::vector<int> input = {8, 1, 2, 2, 3};
        const std::vector<int> expected = {4, 0, 0, 0, 0};
        BOOST_CHECK(expected == obj.count_with_map(input));
        BOOST_CHECK(expected == obj.count_with_sorting(input));
        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
    }

    BOOST_AUTO_TEST_CASE(array_with_several_diff_elements2)
    {
        Algo::DS::HashMap::NumOfSmallerElementsAfterSelf obj;
        const std::vector<int> input = {8, 1, 4, 10, 11, 3, 4, 0};
        const std::vector<int> expected = {5, 1, 2, 3, 3, 1, 1, 0};
        BOOST_CHECK(expected == obj.count_with_map(input));
        BOOST_CHECK(expected == obj.count_with_sorting(input));
        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
    }

//    BOOST_AUTO_TEST_CASE(array_with_rand_elements)
//    {
//        std::random_device rd;
//        std::mt19937 mt(rd());
//        std::uniform_int_distribution<> dis(-10000, 10000);
//
//        std::vector<int> input(22100);
//        std::generate(input.begin(), input.end(), std::bind(dis, std::ref(mt)));
//
//        Algo::HashMap::NumOfSmallerElementsAfterSelf obj;
//        const auto expected = obj.count_with_map(input);
//
//        auto start = std::chrono::high_resolution_clock::now();
//        BOOST_CHECK(expected == obj.count_with_map(input));
//        auto stop = std::chrono::high_resolution_clock::now();
//        std::cout << "First method: " << std::chrono::duration<double>(stop - start).count() <<
//            std::endl;
//
//        start = std::chrono::high_resolution_clock::now();
//        BOOST_CHECK(expected == obj.count_with_sorting(input));
//        stop = std::chrono::high_resolution_clock::now();
//        std::cout << "Second method: " << std::chrono::duration<double>(stop - start).count() <<
//                  std::endl;
//
//        start = std::chrono::high_resolution_clock::now();
//        BOOST_CHECK(expected == obj.count_with_fenwick_tree(input));
//        stop = std::chrono::high_resolution_clock::now();
//        std::cout << "Third method: " << std::chrono::duration<double>(stop - start).count() <<
//                  std::endl;
//    }

BOOST_AUTO_TEST_SUITE_END()
