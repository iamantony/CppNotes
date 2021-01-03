#ifndef CPPNOTESMAIN_SERIALIZE_N_ARY_TREE_HPP
#define CPPNOTESMAIN_SERIALIZE_N_ARY_TREE_HPP

/*
https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/
Serialization is the process of converting a data structure or object into a sequence of bits so
that it can be stored in a file or memory buffer, or transmitted across a network connection link
to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree
in which each node has no more than N children. There is no restriction on how your
 serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree
can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree
                             1
                          /  |  \
                        3    2   4
                      /   \
                     5     6


as "[1 [3[5 6] 2 4]]" or as "1,null,3,2,4,null,5,6,null,null,null"

Constraints:
* The number of nodes in the tree is in the range [0, 10^].
* 0 <= Node.val <= 10^4
* The height of the n-ary tree is less than or equal to 1000
* Do not use class member/global/static variables to store states. Your encode and decode
algorithms should be stateless.
*/

#include "types/ds/n_ary_tree_nodes.hpp"
#include <string>
#include <vector>

namespace Algo::DS::Tree {
    template <typename T>
    class SerializeNAryTree {
        static const std::string lvl_end = "n";
        static const std::string sep = ",";

        static Types::DS::NAryTreeNode<T>* get_node(const std::string& s, size_t& pos) {
            auto* n = new Types::DS::NAryTreeNode<T>(0);
            for (; s[pos] >= '0' && s[pos] <= '9'; ++pos) {
                n->val *= 10;
                n->val += static_cast<int>(s[pos] - '0');
            }

            return n;
        }

    public:
        static std::string serialize(Types::DS::NAryTreeNode<T>* root) {
            if (root == nullptr) { return {}; }

            std::string res;
            std::vector<std::vector<Types::DS::NAryTreeNode<T>*>> lvl;
            lvl.push_back({root});
            while (!lvl.empty()) {
                std::vector<std::vector<Types::DS::NAryTreeNode<T>*>> next_lvl;
                for (const auto& nodes : lvl) {
                    for (auto* n : nodes) {
                        if (n == nullptr) {
                            res += lvl_end;
                        }
                        else {
                            res += std::to_string(n->val);
                            next_lvl.push_back(n->children);
                        }

                        res += sep;
                    }

                    res += lvl_end + sep;
                }

                lvl = next_lvl;
            }

            res.resize(res.size() - 1);
            return res;
        }

        // Input: 1,n, 3,2,4,n, 5,6,n, n, 7,n ,n ,n, 8,n
        Types::DS::NAryTreeNode<T>* deserialize(std::string data) {
            if (data.empty()) { return nullptr; }

            size_t pos = 0;
            auto* root = get_node(data, pos);
            if (data.size() <= pos+2 || data[pos] != sep[0] || data[pos+1] != lvl_end[0]) {
                return nullptr;
            }

            pos += 2;
            if (pos++ >= data.size()) { return root; }

            std::vector<Types::DS::NAryTreeNode<T>*> lvl;
            lvl.push_back(root);
            while (pos <= data.size() && !lvl.empty()) {
                std::vector<Types::DS::NAryTreeNode<T>*> next_lvl;
                for (auto* p : lvl) {
                    while (pos < data.size()) {
                        if (data[pos] == lvl_end[0]) {
                            pos += 2;
                            break;
                        }
                        else {
                            p->children.push_back(get_node(data, pos));
                            next_lvl.push_back(*(p->children.rbegin()));
                            if (data[pos] != sep[0]) { break; }

                            ++pos;
                        }
                    }
                }

                lvl = next_lvl;
            }

            return root;
        }
    };
}

#endif //CPPNOTESMAIN_SERIALIZE_N_ARY_TREE_HPP
