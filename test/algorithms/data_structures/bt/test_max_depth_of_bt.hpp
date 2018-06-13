#ifndef TEST_MAX_DEPTH_OF_BT_HPP
#define TEST_MAX_DEPTH_OF_BT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/bt/max_depth_of_bt.hpp"

BOOST_AUTO_TEST_CASE(test_mdobt_empty_bt)
{
    NodeBT<int>* bt = nullptr;
    BOOST_CHECK(0 == Algo::DS::BT::MaxDepth::Depth(bt));
    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_mdobt_valid_bt)
{
    {
        NodeBT<int>* bt = CreateBT<int>({2, 1, 2, 3});
        BOOST_CHECK(3 == Algo::DS::BT::MaxDepth::Depth(bt));
        DeleteBT(&bt);
    }
}

#endif // TEST_MAX_DEPTH_OF_BT_HPP
