#include <boost/test/unit_test.hpp>
#include "types/ds/fenwick_tree.hpp"

BOOST_AUTO_TEST_SUITE(TestFenwickTree)

    BOOST_AUTO_TEST_CASE(empty_ft)
    {
        Types::DS::FenwickTree<int> ft(1);
    }

    BOOST_AUTO_TEST_CASE(init_ft_with_values)
    {
        Types::DS::FenwickTree<int> ft({1, 2, 3, 4});
        BOOST_CHECK(ft.get(0) == 1);
        BOOST_CHECK(ft.get(1) == 2);
        BOOST_CHECK(ft.get(2) == 3);
        BOOST_CHECK(ft.get(3) == 4);
    }

    BOOST_AUTO_TEST_CASE(fill_ft)
    {
        Types::DS::FenwickTree<int> ft(6);
        ft.add(0, 3);
        ft.add(1, 4);
        ft.add(2, 5);
        ft.add(3, 6);
        ft.add(4, 7);
        ft.add(5, 8);

        BOOST_CHECK(ft.get(0) == 3);
        BOOST_CHECK(ft.get(1) == 4);
        BOOST_CHECK(ft.get(2) == 5);
        BOOST_CHECK(ft.get(3) == 6);
        BOOST_CHECK(ft.get(4) == 7);
        BOOST_CHECK(ft.get(5) == 8);
    }

    BOOST_AUTO_TEST_CASE(prefix_sum)
    {
        Types::DS::FenwickTree<int> ft(6);
        ft.add(0, 3);
        ft.add(1, 4);
        ft.add(2, 5);
        ft.add(3, 6);
        ft.add(4, 7);
        ft.add(5, 8);
        ft.add(3, 1);

        BOOST_CHECK(ft.prefix_sum(0) == 3);
        BOOST_CHECK(ft.prefix_sum(3) == 19);
        BOOST_CHECK(ft.prefix_sum(5) == 34);
    }

    BOOST_AUTO_TEST_CASE(set)
    {
        Types::DS::FenwickTree<int> ft({1, 2, 3, 4});
        ft.set(1, 10);

        BOOST_CHECK(ft.get(0) == 1);
        BOOST_CHECK(ft.get(1) == 10);
        BOOST_CHECK(ft.get(2) == 3);
        BOOST_CHECK(ft.get(3) == 4);
    }

BOOST_AUTO_TEST_SUITE_END()
