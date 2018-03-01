#ifndef BINARY_TREE_NODES_HPP
#define BINARY_TREE_NODES_HPP

#include <iostream>
#include <vector>

template<typename T>
class NodeBT {
public:
    NodeBT(T x) : value(x), left(nullptr), right(nullptr) {}
    ~NodeBT()
    {
        std::cout << "Delete BT node with value " << value << std::endl;
    }

    T value;
    NodeBT* left;
    NodeBT* right;
};

template<typename T>
NodeBT<T>* CreateBT(const std::vector<T>& values) {
    NodeBT<T>* head = nullptr;
    std::for_each(values.begin(), values.end(),
                  [&head](const int& value){
        if (nullptr == head) {
            head = new NodeBT<T>(value);
        }
        else {
            NodeBT<T>* newNode = new NodeBT<T>(value);
            NodeBT<T>* treeNode = head;
            while(true)
            {
                if (treeNode->value > newNode->value) {
                    if (treeNode->left == nullptr) {
                        treeNode->left = newNode;
                        break;
                    }
                    else {
                        treeNode = treeNode->left;
                    }
                }
                else {
                    if (treeNode->right == nullptr) {
                        treeNode->right = newNode;
                        break;
                    }
                    else {
                        treeNode = treeNode->right;
                    }
                }
            }
        }
    });

    return head;
}

template<typename T>
std::vector<T> ValuesInBT(NodeBT<T>* head)
{
    std::vector<T> values;
    printNode(head, values);
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

#endif // BINARY_TREE_NODES_HPP
