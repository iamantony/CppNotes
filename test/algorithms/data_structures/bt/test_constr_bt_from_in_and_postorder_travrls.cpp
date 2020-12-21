#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/constr_bt_from_in_and_post_order_travrls.hpp"

using Types::DS::NodeBT;
using Algo::DS::BT::ConstructBTFromInorderAndPostorderTraversals;

BOOST_AUTO_TEST_SUITE(TestConstructBTFromInorderAndPostorderTraversals)

    BOOST_AUTO_TEST_CASE(empty_traversals)
    {
        const std::vector<int> inorder;
        const std::vector<int> postorder;
        ConstructBTFromInorderAndPostorderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

    BOOST_AUTO_TEST_CASE(bt_with_one_node)
    {
        const std::vector<int> inorder{1};
        const std::vector<int> postorder{1};
        ConstructBTFromInorderAndPostorderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative(inorder, postorder);
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
        const std::vector<int> inorder{2, 5, 3};
        const std::vector<int> postorder{2,3,5};
        ConstructBTFromInorderAndPostorderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative(inorder, postorder);
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
        const std::vector<int> inorder{8,2,5};
        const std::vector<int> postorder{8,2,5};
        ConstructBTFromInorderAndPostorderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative(inorder, postorder);
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
        const std::vector<int> inorder{8,4,2,1,15,9,5};
        const std::vector<int> postorder{4,8,1,9,15,2,5};
        ConstructBTFromInorderAndPostorderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative(inorder, postorder);
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
        const std::vector<int> inorder{2,15,9,5,8,7,1};
        const std::vector<int> postorder{9,15,2,1,7,8,5};
        ConstructBTFromInorderAndPostorderTraversals<int> constructor;

        {
            auto* result_bt = constructor.construct_recursive(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }

        {
            auto* result_bt = constructor.construct_iterative(inorder, postorder);
            const auto result_inorder = Types::DS::ValuesInBT(result_bt);
            BOOST_CHECK(result_inorder == inorder);
            DeleteBT(&result_bt);
        }
    }

BOOST_AUTO_TEST_SUITE_END()
