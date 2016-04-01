#ifndef BINARYSEARCHTREE2_HPP_
#define BINARYSEARCHTREE2_HPP_

#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class BSTree2
{
private:
    class Node
    {
    public:
        T m_value;
        std::unique_ptr<Node> m_left, m_right;

        Node(T value) : m_value(value), m_left(nullptr), m_right(nullptr) {}
        ~Node()
        {
//            std::cout << "Delete node with value " << m_value << std::endl;
        }

        Node(const BSTree2<T>::Node& other) = delete;
        Node& operator=(const Node& other) = delete;
    };

    std::unique_ptr<Node> m_root;
    unsigned int m_size;

public:
    BSTree2() : m_root(nullptr), m_size(0) {}
    ~BSTree2() {}

    BSTree2(const BSTree2<T>& other) = delete;
    BSTree2<T>& operator=(const BSTree2<T>& other) = delete;

    void clear()
    {
        m_root.reset();
        m_size = 0;
    }

    unsigned int size()
    {
        return m_size;
    }

    void insert(const T& value)
    {
        std::unique_ptr<Node> node(new Node(value));
        if (m_root.get() == nullptr)
        {
            m_root = std::move(node);
        }
        else
        {
            Node* temp = m_root.get();
            Node* prev = m_root.get();
            while (temp != nullptr)
            {
                prev = temp;
                if (value < temp->m_value)
                {
                    temp = temp->m_left.get();
                }
                else
                {
                    temp = temp->m_right.get();
                }
            }

            if (value < prev->m_value)
            {
                prev->m_left = std::move(node);
            }
            else
            {
                prev->m_right = std::move(node);
            }
        }

        ++m_size;
    }

    bool contains(const T& value) const
    {
        if (m_root.get() == nullptr)
        {
            return false;
        }

        Node* temp = m_root.get();
        while (temp != nullptr)
        {
            if (value == temp->m_value)
            {
                return true;
            }
            else if (value < temp->m_value)
            {
                temp = temp->m_left.get();
            }
            else
            {
                temp = temp->m_right.get();
            }
        }

        return false;
    }

    void deleteValue(const T& value)
    {
        m_root = std::move(deleteValueNode(m_root, value));
    }

    std::vector<T> printTree() const
    {
        std::vector<T> values;
        printNode(m_root, values);
        return values;
    }

private:
    void printNode(
            const std::unique_ptr<Node>& node, std::vector<T>& values) const
    {
        if (nullptr == node.get())
        {
            return;
        }

        if (nullptr != node->m_left.get())
        {
            printNode(node->m_left, values);
        }

        values.push_back(node->m_value);

        if (nullptr != node->m_right.get())
        {
            printNode(node->m_right, values);
        }
    }

    std::unique_ptr<Node> deleteValueNode(
            std::unique_ptr<Node>& node, const T& value)
    {
        if (nullptr == node.get())
        {
            return std::move(node);
        }

        if (value < node->m_value)
        {
            node->m_left = std::move(deleteValueNode(node->m_left, value));
        }
        else if (node->m_value < value)
        {
            node->m_right = std::move(deleteValueNode(node->m_right, value));
        }
        else
        {
            if (nullptr == node->m_left.get())
            {
                return std::move(node->m_right);
            }
            else if (nullptr == node->m_right.get())
            {
                return std::move(node->m_left);
            }

            // node with two children: get the inorder successor (smallest
            // in the right subtree)
            T minValue = minValueNode(node->m_right);
            node->m_value = minValue;

            // Delete the inorder successor
            node->m_right =
                    std::move(deleteValueNode(node->m_right, node->m_value));
        }

        return std::move(node);
    }

    T minValueNode(const std::unique_ptr<Node>& node) const
    {
        if (nullptr == node.get())
        {
            return T();
        }

        Node* iNode = node.get();
        while(iNode->m_left.get() != nullptr)
        {
            iNode = iNode->m_left.get();
        }

        return iNode->m_value;
    }
};

#endif /* BINARYSEARCHTREE2_HPP_ */
