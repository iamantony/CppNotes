#ifndef TEST_MAX_DEPTH_OF_BT_HPP
#define TEST_MAX_DEPTH_OF_BT_HPP

#include <boost/test/unit_test.hpp>

#include "types/binary_tree_nodes.hpp"
#include "algorithms/data_structures/max_depth_of_bt.hpp"

BOOST_AUTO_TEST_CASE(test_mdobt_empty_bt)
{
    NodeBT<int>* bt = nullptr;
    MaxDepthBT::Solution solution;
    BOOST_CHECK(0 == solution.maxDepth(bt));
    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_mdobt_valid_bt)
{
    {
        NodeBT<int>* bt = CreateBT<int>({2, 1, 2, 3});
        MaxDepthBT::Solution solution;
        BOOST_CHECK(3 == solution.maxDepth(bt));
        DeleteBT(&bt);
    }
}

#endif // TEST_MAX_DEPTH_OF_BT_HPP
