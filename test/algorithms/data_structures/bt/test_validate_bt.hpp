#ifndef TEST_VALIDATE_BT_HPP
#define TEST_VALIDATE_BT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/bt/validate_bt.hpp"

BOOST_AUTO_TEST_CASE(test_valbt_empty_bt)
{
    NodeBT<int>* bt = nullptr;
    BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
    DeleteBT(&bt);
}

BOOST_AUTO_TEST_CASE(test_valbt_valid_bt)
{
    {
        NodeBT<int>* bt = CreateBT<int>({2, 1, 2, 3});
        BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
        DeleteBT(&bt);
    }

    {
        NodeBT<int>* bt = CreateBT<int>({1, 1});
        BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
        DeleteBT(&bt);
    }

    {
        NodeBT<int>* bt = CreateBT<int>({1, 0, 1});
        BOOST_CHECK(Algo::DS::BT::Validate::isValid(bt));
        DeleteBT(&bt);
    }
}

BOOST_AUTO_TEST_CASE(test_valbt_invalid_bt)
{
    {
        NodeBT<int>* bt = CreateBT<int>({2, 1, 2, 3});
        bt->left->value = 100;

        BOOST_CHECK(!Algo::DS::BT::Validate::isValid(bt));
        DeleteBT(&bt);
    }

    {
        NodeBT<int>* bt = CreateBT<int>({std::numeric_limits<int>::max(),
                                         std::numeric_limits<int>::max()});

        BOOST_CHECK(!Algo::DS::BT::Validate::isValid(bt));
        DeleteBT(&bt);
    }
}

#endif // TEST_VALIDATE_BT_HPP
