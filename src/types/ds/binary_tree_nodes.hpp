#ifndef BINARY_TREE_NODES_HPP
#define BINARY_TREE_NODES_HPP

#include <vector>

namespace Types::DS {
    template<typename T>
    class NodeBT {
    public:
        NodeBT(T x) : value(std::move(x)) {}
        ~NodeBT() {}

        T value;
        NodeBT* left = nullptr;
        NodeBT* right = nullptr;
    };

    template<typename T>
    NodeBT<T>* CreateBST(const std::vector<T>& values) {
        NodeBT<T>* head = nullptr;
        std::for_each(
            values.begin(),
            values.end(),
            [&head](const int& value) {
                if (nullptr == head) {
                    head = new NodeBT<T>(value);
                }
                else {
                    NodeBT<T>* newNode = new NodeBT<T>(value);
                    NodeBT<T>* treeNode = head;
                    while (true) {
                        if (treeNode->value > newNode->value) {
                            if (treeNode->left == nullptr) {
                                treeNode->left = newNode;
                                break;
                            } else {
                                treeNode = treeNode->left;
                            }
                        } else {
                            if (treeNode->right == nullptr) {
                                treeNode->right = newNode;
                                break;
                            } else {
                                treeNode = treeNode->right;
                            }
                        }
                    }
                }
            });

        return head;
    }

    template <typename T>
    NodeBT<T>* CreateBT(const std::vector<std::vector<T>>& values_per_level, const T& null_value) {
        std::vector< NodeBT<T>* > prev_level_nodes;
        for (auto iter = values_per_level.rbegin(); iter != values_per_level.rend(); ++iter) {
            auto& values_vec = *iter;
            std::vector< NodeBT<T>* > level_nodes;
            for (size_t i = 0; i < values_vec.size(); ++i) {
                if (values_vec[i] == null_value) {
                    level_nodes.push_back(nullptr);
                }
                else {
                    auto* new_node = new NodeBT<T>(values_vec[i]);
                    if (auto left_node_pos = i * 2; left_node_pos < prev_level_nodes.size()) {
                        new_node->left = prev_level_nodes[left_node_pos];
                    }

                    if (auto right_node_pos = 1 + i * 2; right_node_pos < prev_level_nodes.size()) {
                        new_node->right = prev_level_nodes[right_node_pos];
                    }

                    level_nodes.push_back(new_node);
                }
            }

            prev_level_nodes = level_nodes;
        }

        return prev_level_nodes.empty() ? nullptr : prev_level_nodes.front();
    }

    template<typename T>
    std::vector<T> ValuesInBT(NodeBT<T>* head)
    {
        std::vector<T> values;
        valuesInBTHelper(head, values);
        return values;
    }

    template<typename T>
    void valuesInBTHelper(NodeBT<T>* head, std::vector<T>& values) {
        if (nullptr == head) {
            return;
        }

        if (nullptr != head->left) {
            valuesInBTHelper(head->left, values);
        }

        values.push_back(head->value);

        if (nullptr != head->right) {
            valuesInBTHelper(head->right, values);
        }
    }

    template<typename T>
    void DeleteBT(NodeBT<T>** head) {
        if (nullptr == head) {
            return;
        }

        deleteBTHelper(*head);
        *head = nullptr;
    }

    template<typename T>
    void deleteBTHelper(NodeBT<T>* head) {
        if (head == nullptr) {
            return;
        }

        deleteBTHelper(head->left);
        deleteBTHelper(head->right);
        delete head;
    }
}

#endif // BINARY_TREE_NODES_HPP
