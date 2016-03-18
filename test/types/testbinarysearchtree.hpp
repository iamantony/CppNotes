#ifndef TEST_BINARYSEARCHTREE_H_
#define TEST_BINARYSEARCHTREE_H_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "types/binarysearchtree.hpp"

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

    tree.printTree();
}

BOOST_AUTO_TEST_CASE(test_bstree_print_tree_postorder)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    tree.printTreePostorder();
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
    tree.printTreePostorder();
}

BOOST_AUTO_TEST_CASE(test_bstree_mirror_one_elem)
{
    BSTree<int> tree;
    tree.insert(10);
    tree.mirror();
    tree.printTreePostorder();
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
    tree.printTreePostorder();
}

#endif /* TEST_BINARYSEARCHTREE_H_ */
