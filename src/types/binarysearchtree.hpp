#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include <iostream>

template <typename T>
class BSTree
{
    // == DATA ==
private:
    class Node
    {
    public:
        Node(T value) : m_value(value), m_left(nullptr), m_right(nullptr) {}
        ~Node();

        Node(const BSTree<T>::Node& other) = delete;
        Node& operator=(const Node& other) = delete;

        void setLeftNode(Node* left);
        Node* getLeftNode() const;
        void setRightNode(Node* right);
        Node* getRightNode() const;
        void setValue(const T& value);
        T getValue() const;

    private:
        T m_value;
        Node* m_left;
        Node* m_right;
    };

    Node* root;

    // == METHODS ==
public:
    BSTree() : root(nullptr) {}
    ~BSTree();

    BSTree(const BSTree<T>& other) = delete;
    BSTree<T>& operator=(const BSTree<T>& other) = delete;

    void clear();
    int size();
    bool isEmpty();
    void insert(const T& value);
    bool contains(const T& value);

private:
    int calcSize(const Node* node);
    void insertValue(Node* node, const T& value);
    bool containsValue(Node* node, const T& value);
};

template<typename T>
BSTree<T>::Node::~Node()
{
    if (nullptr != m_left)
    {
        delete m_left;
        m_left = nullptr;
    }

    if (nullptr != m_right)
    {
        delete m_right;
        m_right = nullptr;
    }
}

template<typename T>
void BSTree<T>::Node::setLeftNode(Node* left)
{
    m_left = left;
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::Node::getLeftNode()
{
    return (m_left);
}

template<typename T>
void BSTree<T>::Node::setRightNode(Node* right)
{
    m_right = right;
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::Node::getRightNode()
{
    return (m_right);
}

template<typename T>
void BSTree<T>::Node::setValue(const T& value)
{
    m_value = value;
}

template<typename T>
T BSTree<T>::Node::getValue()
{
    return (m_value);
}

template<typename T>
BSTree<T>::~BSTree()
{
    clear();
}

template<typename T>
void BSTree<T>::clear()
{
    if (nullptr != root)
    {
        delete root;
        root = nullptr;
    }
}

template<typename T>
int BSTree<T>::size()
{
    return calcSize(root);
}

template<typename T>
int BSTree<T>::calcSize(const Node* node)
{
    if (nullptr == node)
    {
        return 0;
    }

    return 1 + calcSize(node->getLeftNode()) + calcSize(node->getRightNode());
}

template<typename T>
bool BSTree<T>::isEmpty()
{
    return (nullptr == root);
}

template<typename T>
void BSTree<T>::insert(const T& value)
{
    if (nullptr == root)
    {
        root = new Node(value);
    }
    else
    {
        insertValue(root, value);
    }
}

template<typename T>
void BSTree<T>::insertValue(Node* node, const T& value)
{
    if (nullptr == node)
    {
        std::cout << "Error - can't insert value with null node" << std::endl;
        return;
    }

    if (value < node->getValue())
    {
        if (nullptr == node->getLeftNode())
        {
            Node* leftNode = new Node(value);
            node->setLeftNode(leftNode);
        }
        else
        {
            insertValue(node->getLeftNode(), value);
        }
    }
    else
    {
        if (nullptr == node->getRightNode())
        {
            Node* rightNode = new Node(value);
            node->setRightNode(leftNode);
        }
        else
        {
            insertValue(node->getRightNode(), value);
        }
    }
}

template<typename T>
bool BSTree<T>::contains(const T& value)
{
    return containsValue(root, value);
}

template<typename T>
bool BSTree<T>::containsValue(Node* node, const T& value)
{
    if (nullptr == node)
    {
        return false;
    }

    if (value == node->getValue())
    {
        return true;
    }
    else if (value < node->getValue())
    {
        return containsValue(node->getLeftNode(), value);
    }

    return containsValue(node->getRightNode(), value);
}

#endif /* BINARYSEARCHTREE_HPP_ */
