#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/max_depth_of_bt.hpp"

BOOST_AUTO_TEST_SUITE(MaxDepthOfBT)

BOOST_AUTO_TEST_CASE(empty_bt)
{
    Types::DS::NodeBT<int>* bt = nullptr;
    BOOST_CHECK(0 == Algo::DS::BT::MaxDepth::Depth(bt));
    Types::DS::DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(valid_bt)
{
    {
        Types::DS::NodeBT<int>* bt = Types::DS::CreateBST<int>({2, 1, 2, 3});
        BOOST_CHECK(3 == Algo::DS::BT::MaxDepth::Depth(bt));
        Types::DS::DeleteBT(&bt);
    }
}

BOOST_AUTO_TEST_SUITE_END()
