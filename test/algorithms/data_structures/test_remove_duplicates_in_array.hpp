#ifndef TEST_REMOVE_DUPLICATES_IN_ARRAY_HPP
#define TEST_REMOVE_DUPLICATES_IN_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/remove_duplicates_in_array.hpp"

BOOST_AUTO_TEST_CASE(test_rdia_empty_vector) {
    std::vector<int> v;

    RDIA::Solution solution;
    BOOST_CHECK(0 == solution.removeDuplicates(v));
}

BOOST_AUTO_TEST_CASE(test_rdia_one_elem) {
    std::vector<int> v = {0};
    std::vector<int> expected = {0};

    RDIA::Solution solution;
    BOOST_CHECK(1 == solution.removeDuplicates(v));
    BOOST_CHECK(expected == v);
}

BOOST_AUTO_TEST_CASE(test_rdia_base_case) {
    std::vector<int> v = {1, 1, 2};
    std::vector<int> expected = {1, 2};

    RDIA::Solution solution;
    BOOST_CHECK(expected.size() == solution.removeDuplicates(v));

    v.resize(expected.size());
    BOOST_CHECK(expected == v);
}

BOOST_AUTO_TEST_CASE(test_rdia_no_duplicates) {
    std::vector<int> v = {1, 2, 3, 4};
    std::vector<int> expected = {1, 2, 3, 4};

    RDIA::Solution solution;
    BOOST_CHECK(expected.size() == solution.removeDuplicates(v));

    v.resize(expected.size());
    BOOST_CHECK(expected == v);
}

BOOST_AUTO_TEST_CASE(test_rdia_many_duplicates) {
    std::vector<int> v = {0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4};
    std::vector<int> expected = {0, 1, 2, 3, 4};

    RDIA::Solution solution;
    BOOST_CHECK(expected.size() == solution.removeDuplicates(v));

    v.resize(expected.size());
    BOOST_CHECK(expected == v);
}

BOOST_AUTO_TEST_CASE(test_rdia_same_element) {
    std::vector<int> v = {0, 0, 0, 0, 0};
    std::vector<int> expected = {0};

    RDIA::Solution solution;
    BOOST_CHECK(expected.size() == solution.removeDuplicates(v));

    v.resize(expected.size());
    BOOST_CHECK(expected == v);
}

#endif // TEST_REMOVE_DUPLICATES_IN_ARRAY_HPP
