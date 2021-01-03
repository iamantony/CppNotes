#ifndef CPPNOTESMAIN_N_ARY_TREE_NODES_HPP
#define CPPNOTESMAIN_N_ARY_TREE_NODES_HPP

#include <vector>

namespace Types::DS {
    template <typename T>
    struct NAryTreeNode {
        T value;
        std::vector<NAryTreeNode<T>*> children;

        NAryTreeNode() = default;
        NAryTreeNode(T val) : value(val) {}
        ~NAryTreeNode() {
            for (auto iter = children.begin(); iter != children.end(); ++iter) {
                delete *iter;
            }
        }
    };
}

#endif //CPPNOTESMAIN_N_ARY_TREE_NODES_HPP
