#ifndef TEST_BT_INORDER_TRAVERSAL_HPP
#define TEST_BT_INORDER_TRAVERSAL_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/bt/bt_inorder_traversal.hpp"

BOOST_AUTO_TEST_CASE(test_btinotr_empty_bt)
{
    NodeBT<int>* bt = nullptr;
    const std::vector<int> expected;
    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterative(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterativeMorris(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_btinotr_only_one_node)
{
    NodeBT<int>* bt = CreateBT<int>({10});
    const std::vector<int> expected = {10};
    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterative(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterativeMorris(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_btinotr_valid_bt)
{
    NodeBT<int>* bt = CreateBT<int>({2, 1, 2, 3});
    const std::vector<int> expected = {1, 2, 2, 3};
    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterative(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterativeMorris(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_btinotr_valid_v_shape_bt)
{
    NodeBT<int>* bt = CreateBT<int>({10, 5, 3, 20, 30});
    const std::vector<int> expected = {3, 5, 10, 20, 30};
    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterative(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterativeMorris(bt));

    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_btinotr_valid_full_bt)
{
    NodeBT<int>* bt = CreateBT<int>({10, 5, 4, 6, 20, 15, 30});
    const std::vector<int> expected = {4, 5, 6, 10, 15, 20, 30};
    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderRecursive(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterative(bt));

    BOOST_CHECK(expected ==
                Algo::DS::BT::InorderTraversal::InorderIterativeMorris(bt));

    DeleteBT(&bt);
}

#endif // TEST_BT_INORDER_TRAVERSAL_HPP
