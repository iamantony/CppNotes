#include <boost/test/unit_test.hpp>
#include "types/ds/binary_search_tree.hpp"

BOOST_AUTO_TEST_SUITE(BinarySearchTree)

BOOST_AUTO_TEST_CASE(create)
{
    DS::BSTree<int> tree;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(add_one_elem)
{
    DS::BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(1);

    BOOST_CHECK(false == tree.isEmpty());
    BOOST_CHECK(1 == tree.size());
}

BOOST_AUTO_TEST_CASE(add_elements)
{
    DS::BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(false == tree.isEmpty());
    BOOST_CHECK(5 == tree.size());
}

BOOST_AUTO_TEST_CASE(clear)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(contains)
{
    DS::BSTree<int> tree;
    BOOST_CHECK(tree.isEmpty());

    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(tree.contains(7));
    BOOST_CHECK(false == tree.contains(3));
}

BOOST_AUTO_TEST_CASE(delete_empty_tree)
{
    DS::BSTree<int> tree;
    tree.deleteValue(10);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected;
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(delete_one_elem_tree)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(delete_tree)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(delete_tree_two_same_values)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(max_depth)
{
    DS::BSTree<int> tree;
    BOOST_CHECK(0 == tree.maxDepth());

    tree.insert(10);
    BOOST_CHECK(1 == tree.maxDepth());

    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(3 == tree.maxDepth());
}

BOOST_AUTO_TEST_CASE(min_value)
{
    DS::BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(2 == tree.minValue());
}

BOOST_AUTO_TEST_CASE(max_value)
{
    DS::BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    BOOST_CHECK(42 == tree.maxValue());
}

BOOST_AUTO_TEST_CASE(print_tree)
{
    DS::BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    std::vector<int> result = tree.printTree();
    std::vector<int> expected = {2, 5, 7, 10, 42};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(print_tree_postorder)
{
    DS::BSTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(42);

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected = {2, 7, 5, 42, 10};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(get_paths_empty)
{
    DS::BSTree<int> tree;
    std::vector<std::vector<int>> paths =  tree.getPaths();
    BOOST_CHECK(0 == paths.size());
}

BOOST_AUTO_TEST_CASE(get_paths_one_elem)
{
    DS::BSTree<int> tree;
    tree.insert(10);
    std::vector<std::vector<int>> paths =  tree.getPaths();
    BOOST_CHECK(1 == paths.size());

    std::vector<int> expected = {10};
    BOOST_CHECK(expected == paths[0]);
}

BOOST_AUTO_TEST_CASE(get_paths)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(mirror_empty)
{
    DS::BSTree<int> tree;
    tree.mirror();

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected;
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(mirror_one_elem)
{
    DS::BSTree<int> tree;
    tree.insert(10);
    tree.mirror();

    std::vector<int> result = tree.printTreePostorder();
    std::vector<int> expected = {10};
    BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(mirror)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_CASE(is_equal_empty)
{
    DS::BSTree<int> first, second;
    BOOST_CHECK(first == second);
}

BOOST_AUTO_TEST_CASE(is_equal_one_elem)
{
    DS::BSTree<int> first, second;
    first.insert(10);
    second.insert(10);
    BOOST_CHECK(first == second);
}

BOOST_AUTO_TEST_CASE(is_equal)
{
    DS::BSTree<int> first, second;
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

BOOST_AUTO_TEST_CASE(is_equal_different)
{
    DS::BSTree<int> first, second;
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

BOOST_AUTO_TEST_CASE(get_successor)
{
    DS::BSTree<int> tree;
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

BOOST_AUTO_TEST_SUITE_END()
