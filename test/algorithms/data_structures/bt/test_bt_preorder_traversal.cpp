#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/bt_preorder_traversal.hpp"

BOOST_AUTO_TEST_SUITE(BTPreorderTraversal)

BOOST_AUTO_TEST_CASE(empty_bt)
{
    NodeBT<int>* bt = nullptr;
    const std::vector<int> expected;
    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderIterative(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(only_one_node)
{
    NodeBT<int>* bt = CreateBT<int>({10});
    const std::vector<int> expected = {10};
    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderIterative(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(valid_bt)
{
    NodeBT<int>* bt = CreateBT<int>({2, 1, 2, 3});
    const std::vector<int> expected = {2, 1, 2, 3};
    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderIterative(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(valid_v_shape_bt)
{
    NodeBT<int>* bt = CreateBT<int>({10, 5, 3, 20, 30});
    const std::vector<int> expected = {10, 5, 3, 20, 30};
    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderIterative(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(valid_full_bt)
{
    NodeBT<int>* bt = CreateBT<int>({10, 5, 4, 6, 20, 15, 30});
    const std::vector<int> expected = {10, 5, 4, 6, 20, 15, 30};
    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::PreorderTraversal::PreorderIterative(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_SUITE_END()
