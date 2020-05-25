#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/validate_bt.hpp"

BOOST_AUTO_TEST_SUITE(ValidateBT)

BOOST_AUTO_TEST_CASE(empty_bt)
{
    Types::DS::NodeBT<int>* bt = nullptr;
    BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
    Types::DS::DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(valid_bt)
{
    {
        Types::DS::NodeBT<int>* bt = Types::DS::CreateBST<int>({2, 1, 2, 3});
        BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
        Types::DS::DeleteBT(&bt);
    }

    {
        Types::DS::NodeBT<int>* bt = Types::DS::CreateBST<int>({1, 1});
        BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
        Types::DS::DeleteBT(&bt);
    }

    {
        Types::DS::NodeBT<int>* bt = Types::DS::CreateBST<int>({1, 0, 1});
        BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
        Types::DS::DeleteBT(&bt);
    }
}

BOOST_AUTO_TEST_CASE(invalid_bt)
{
    {
        Types::DS::NodeBT<int>* bt = Types::DS::CreateBST<int>({2, 1, 2, 3});
        bt->left->value = 100;

        BOOST_CHECK(!Algo::DS::BT::Validate::isValid(bt));
        Types::DS::DeleteBT(&bt);
    }

    {
        Types::DS::NodeBT<int>* bt = Types::DS::CreateBST<int>(
            {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()});

        BOOST_CHECK(!Algo::DS::BT::Validate::isValid(bt));
        Types::DS::DeleteBT(&bt);
    }
}

BOOST_AUTO_TEST_SUITE_END()
