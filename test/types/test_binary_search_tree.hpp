#ifndef TEST_BINARYSEARCHTREE_H_
#define TEST_BINARYSEARCHTREE_H_

#include <boost/test/unit_test.hpp>

#include "types/binary_search_tree.hpp"

BOOST_AUTO_TEST_CASE(test_bstree_create)
{
    BSTree<int> tree;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_bstree_add_one_elem)
{
    BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(1);

    BOOST_CHECK(false == tree.isEmpty());
    BOOST_CHECK(1 == tree.size());
}

BOOST_AUTO_TEST_CASE(test_bstree_add_elements)
{
    BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(false == tree.isEmpty());
    BOOST_CHECK(5 == tree.size());
}

BOOST_AUTO_TEST_CASE(test_bstree_clear)
{
    BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(5 == tree.size());

    tree.clear();
    BOOST_CHECK(0 == tree.size());
}

BOOST_AUTO_TEST_CASE(test_bstree_contains)
{
    BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(tree.contains(7));
    BOOST_CHECK(false == tree.contains(3));
}

BOOST_AUTO_TEST_CASE(test_bstree_delete_empty_tree)
{
    BSTree<int> tree;
    tree.deleteValue(10);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected;
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree_delete_one_elem_tree)
{
    BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(test_bstree_delete_tree)
{
    BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(test_bstree_delete_tree_two_same_values)
{
    BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(test_bstree_max_depth)
{
    BSTree<int> tree;
    BOOST_CHECK(0 == tree.maxDepth());

    tree.insert(10);
    BOOST_CHECK(1 == tree.maxDepth());

    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(3 == tree.maxDepth());
}

BOOST_AUTO_TEST_CASE(test_bstree_min_value)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(2 == tree.minValue());
}

BOOST_AUTO_TEST_CASE(test_bstree_max_value)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(42 == tree.maxValue());
}

BOOST_AUTO_TEST_CASE(test_bstree_print_tree)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected = {2, 5, 7, 10, 42};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree_print_tree_postorder)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected = {2, 7, 5, 42, 10};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree_get_paths_empty)
{
    BSTree<int> tree;
    std::vector<std::vector<int>> paths =  tree.getPaths();
    BOOST_CHECK(0 == paths.size());
}

BOOST_AUTO_TEST_CASE(test_bstree_get_paths_one_elem)
{
    BSTree<int> tree;
    tree.insert(10);
    std::vector<std::vector<int>> paths =  tree.getPaths();
    BOOST_CHECK(1 == paths.size());

    std::vector<int> expected = {10};
    BOOST_CHECK(expected == paths[0]);
}

BOOST_AUTO_TEST_CASE(test_bstree_get_paths)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);
    tree.insert(40);

    std::vector<std::vector<int>> paths =  tree.getPaths();
    BOOST_CHECK(3 == paths.size());

    std::vector<int> expectedFirst = {10, 5, 2};
    std::vector<int> expectedSecond = {10, 5, 7};
    std::vector<int> expectedThird = {10, 42, 40};

    BOOST_CHECK(expectedFirst == paths[0]);
    BOOST_CHECK(expectedSecond == paths[1]);
    BOOST_CHECK(expectedThird == paths[2]);
}

BOOST_AUTO_TEST_CASE(test_bstree_mirror_empty)
{
    BSTree<int> tree;
    tree.mirror();

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected;
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree_mirror_one_elem)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.mirror();

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected = {10};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree_mirror)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);
    tree.insert(40);

    tree.mirror();

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected = {40, 42, 7, 2, 5, 10};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(test_bstree_is_equal_empty)
{
    BSTree<int> first, second;
    BOOST_CHECK(first == second);
}

BOOST_AUTO_TEST_CASE(test_bstree_is_equal_one_elem)
{
    BSTree<int> first, second;
    first.insert(10);
    second.insert(10);
    BOOST_CHECK(first == second);
}

BOOST_AUTO_TEST_CASE(test_bstree_is_equal)
{
    BSTree<int> first, second;
    first.insert(10);
    first.insert(5);
    first.insert(2);
    first.insert(7);
    first.insert(42);
    first.insert(40);

    second.insert(10);
    second.insert(5);
    second.insert(2);
    second.insert(7);
    second.insert(42);
    second.insert(40);

    BOOST_CHECK(first == second);
}

BOOST_AUTO_TEST_CASE(test_bstree_is_equal_different)
{
    BSTree<int> first, second;
    first.insert(10);
    first.insert(5);
    first.insert(2);
    first.insert(7);
    first.insert(42);
    first.insert(40);

    second.insert(10);
    second.insert(5);
    second.insert(2);
    second.insert(42);
    second.insert(40);

    BOOST_CHECK(first != second);
}

BOOST_AUTO_TEST_CASE(test_bstree_get_successor)
{
    BSTree<int> tree;
    tree.insert(20);
    tree.insert(8);
    tree.insert(22);
    tree.insert(4);
    tree.insert(12);
    tree.insert(10);
    tree.insert(14);

    BOOST_CHECK(tree.getSuccessorOfValue(20) == 22);
    BOOST_CHECK(tree.getSuccessorOfValue(14) == 20);
    BOOST_CHECK(tree.getSuccessorOfValue(11) == 12);
}

#endif /* TEST_BINARYSEARCHTREE_H_ */
