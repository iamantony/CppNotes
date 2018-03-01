#ifndef TESTBINARYSEARCHTREE2_HPP_
#define TESTBINARYSEARCHTREE2_HPP_

#include <boost/test/unit_test.hpp>

#include "types/ds/binary_search_tree2.hpp"

BOOST_AUTO_TEST_CASE(test_bstree2_create)
{
    DS::BSTree2<int> tree;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_bstree2_add_one_elem)
{
    DS::BSTree2<int> tree;
    BOOST_CHECK(0 == tree.size());

    tree.insert(1);

    BOOST_CHECK(1 == tree.size());
}

BOOST_AUTO_TEST_CASE(test_bstree2_add_elements)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(5 == tree.size());
}

BOOST_AUTO_TEST_CASE(test_bstree2_clear)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(5 == tree.size());

    tree.clear();
    BOOST_CHECK(0 == tree.size());
}

BOOST_AUTO_TEST_CASE(test_bstree2_contains)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(tree.contains(7));
    BOOST_CHECK(false == tree.contains(3));
}

BOOST_AUTO_TEST_CASE(test_bstree2_delete_empty_tree)
{
    DS::BSTree2<int> tree;
    tree.deleteValue(10);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected;
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree2_delete_one_elem_tree)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.deleteValue(1);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected = {10};
    BOOST_CHECK(result == expected);

    tree.deleteValue(10);

    result = tree.printTree();
    expected.clear();
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree2_delete_tree)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    tree.deleteValue(5);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected = {2, 7, 10, 42};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree2_delete_tree_two_same_values)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(5);
    tree.insert(42);

    tree.deleteValue(5);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected = {2, 5, 7, 10, 42};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree2_print_tree)
{
    DS::BSTree2<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected = {2, 5, 7, 10, 42};
    BOOST_CHECK(result == expected);
}

#endif /* TESTBINARYSEARCHTREE2_HPP_ */
