#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/constr_bt_from_pre_and_inorder_travrls.hpp"
#include <limits>

using Types::DS::NodeBT;
using Algo::DS::BT::ConstructBTFromInAndPreOrderTraversals;

BOOST_AUTO_TEST_SUITE(TestConstrBTFromInAndPreOrderTraversals)

    BOOST_AUTO_TEST_CASE(empty_traversals)
    {
        const std::vector<int> preorder;
        const std::vector<int> inorder;
        ConstructBTFromInAndPreOrderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_my(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_fast(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

    BOOST_AUTO_TEST_CASE(bt_with_one_node)
    {
        const std::vector<int> preorder{1};
        const std::vector<int> inorder{1};
        ConstructBTFromInAndPreOrderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_my(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_fast(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

    BOOST_AUTO_TEST_CASE(bt_with_two_childs)
    {
        /*
               5
             /   \
            2     3
        */
        const std::vector<int> preorder{5, 2, 3};
        const std::vector<int> inorder{2, 5, 3};
        ConstructBTFromInAndPreOrderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_my(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_fast(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

    BOOST_AUTO_TEST_CASE(bt_with_only_left_part)
    {
        /*
                 5
               /
              2
             /
            8
       */
        const std::vector<int> preorder{5,2,8};
        const std::vector<int> inorder{8,2,5};
        ConstructBTFromInAndPreOrderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_my(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_fast(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

    BOOST_AUTO_TEST_CASE(bt_with_only_left_part_and_right_childs)
    {
        /*
                  5
                 /
                2
             /    \
            8      15
             \    /  \
              4  1    9
       */
        const std::vector<int> preorder{5,2,8,4,15,1,9};
        const std::vector<int> inorder{8,4,2,1,15,9,5};
        ConstructBTFromInAndPreOrderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_my(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_fast(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

    BOOST_AUTO_TEST_CASE(bt_with_left_and_right_parts_only_right_childs)
    {
        /*
           5
          / \
         2   8
          \   \
           15  7
             \   \
              9   1
       */
        const std::vector<int> preorder{5,2,15,9,8,7,1};
        const std::vector<int> inorder{2,15,9,5,8,7,1};
        ConstructBTFromInAndPreOrderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_my(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative_fast(preorder, inorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

BOOST_AUTO_TEST_SUITE_END()

