#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/find_duplicate_subtrees.hpp"
#include <limits>

using Types::DS::NodeBT;
using Algo::DS::BT::FindDuplicateSubtrees;

std::string traverse(NodeBT<int>* head, const int& null_value) {
    if (head == nullptr) { return std::to_string(null_value); }

    auto pattern = traverse(head->left, null_value);
    pattern += std::to_string(head->value);
    pattern += traverse(head->right, null_value);
    return pattern;
}

BOOST_AUTO_TEST_SUITE(BTFindDuplicateSubtrees)

    BOOST_AUTO_TEST_CASE(empty_bt)
    {
        NodeBT<int>* bt = nullptr;
        const std::vector<NodeBT<int>*> expected;
        FindDuplicateSubtrees finder;
        BOOST_CHECK(expected == finder.find(bt));
        DeleteBT(&bt);
    }

    BOOST_AUTO_TEST_CASE(bt_with_one_node)
    {
        NodeBT<int>* bt = Types::DS::CreateBT({{5}}, std::numeric_limits<int>::min());
        const std::vector<NodeBT<int>*> expected;
        FindDuplicateSubtrees finder;
        BOOST_CHECK(expected == finder.find(bt));
        DeleteBT(&bt);
    }

    BOOST_AUTO_TEST_CASE(bt_default_test_case)
    {
        const auto nv = 0;
        const std::vector<std::vector<int>> tree_levels = {
            {1},
            {2, 3},
            {4, nv, 2, 4},
            {nv, nv, nv, nv, 4, nv, nv, nv}
        };

        NodeBT<int>* bt = Types::DS::CreateBT(tree_levels, nv);
        FindDuplicateSubtrees finder;
        const auto result = finder.find(bt);

        std::vector<std::string> result_patterns;
        for (const auto& node : result) {
            result_patterns.push_back(traverse(node, nv));
        }

        std::vector<std::string> expected_patterns = {"040", "04020"};

        std::sort(result_patterns.begin(), result_patterns.end());
        std::sort(expected_patterns.begin(), expected_patterns.end());
        BOOST_CHECK(expected_patterns == result_patterns);
        DeleteBT(&bt);
    }

    BOOST_AUTO_TEST_CASE(bt_3_level_tree_no_duplicates)
    {
        const auto nv = 0;
        const std::vector<std::vector<int>> tree_levels = {
            {1},
            {2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11, 12, 13, 14, 15}
        };

        NodeBT<int>* bt = Types::DS::CreateBT(tree_levels, nv);
        FindDuplicateSubtrees finder;
        BOOST_CHECK(finder.find(bt).empty());
        DeleteBT(&bt);
    }

    BOOST_AUTO_TEST_CASE(bt_test_case_140)
    {
        // [0,0,0,0,null,null,0,null,null,null,0]
        const auto nv = -1;
        const std::vector<std::vector<int>> tree_levels = {
            {0},
            {0, 0},
            {0, nv, nv, 0},
            {nv, nv, nv, nv, nv, nv, nv, 0}
        };

        NodeBT<int>* bt = Types::DS::CreateBT(tree_levels, nv);
        FindDuplicateSubtrees finder;
        const auto result = finder.find(bt);

        std::vector<std::string> result_patterns;
        for (const auto& node : result) {
            result_patterns.push_back(traverse(node, nv));
        }

        std::vector<std::string> expected_patterns = {"-10-1"};

        std::sort(result_patterns.begin(), result_patterns.end());
        std::sort(expected_patterns.begin(), expected_patterns.end());
        BOOST_CHECK(expected_patterns == result_patterns);
        DeleteBT(&bt);
    }

BOOST_AUTO_TEST_SUITE_END()

