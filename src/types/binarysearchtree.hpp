#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include <iostream>
#include <algorithm>
#include <stdexcept>

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
    int size() const;
    bool isEmpty() const;
    void insert(const T& value);
    bool contains(const T& value) const;
    int maxDepth() const;
    T minValue() const;
    T maxValue() const;
    void printTree() const;
    void printTreePostorder() const;

private:
    int calcSize(const Node* node) const;
    void insertValue(Node* node, const T& value);
    bool containsValue(Node* node, const T& value) const;
    int calcMaxDepth(const Node* node) const;
    void printNode(const Node* node) const;
    void printNodePostorder(const Node* node) const;
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
typename BSTree<T>::Node* BSTree<T>::Node::getLeftNode() const
{
    return m_left;
}

template<typename T>
void BSTree<T>::Node::setRightNode(Node* right)
{
    m_right = right;
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::Node::getRightNode() const
{
    return m_right;
}

template<typename T>
void BSTree<T>::Node::setValue(const T& value)
{
    m_value = value;
}

template<typename T>
T BSTree<T>::Node::getValue() const
{
    return m_value;
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
int BSTree<T>::size() const
{
    return calcSize(root);
}

template<typename T>
int BSTree<T>::calcSize(const Node* node) const
{
    if (nullptr == node)
    {
        return 0;
    }

    return 1 + calcSize(node->getLeftNode()) + calcSize(node->getRightNode());
}

template<typename T>
bool BSTree<T>::isEmpty() const
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
        throw std::runtime_error("Can't insert to null node");
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
            node->setRightNode(rightNode);
        }
        else
        {
            insertValue(node->getRightNode(), value);
        }
    }
}

template<typename T>
bool BSTree<T>::contains(const T& value) const
{
    return containsValue(root, value);
}

template<typename T>
bool BSTree<T>::containsValue(Node* node, const T& value) const
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

template<typename T>
int BSTree<T>::maxDepth() const
{
    return calcMaxDepth(root);
}

template<typename T>
int BSTree<T>::calcMaxDepth(const Node* node) const
{
    if (nullptr == node)
    {
        return 0;
    }

    int leftDepth = calcMaxDepth(node->getLeftNode());
    int rightDepth = calcMaxDepth(node->getRightNode());
    return 1 + std::max(leftDepth, rightDepth);
}

template<typename T>
T BSTree<T>::minValue() const
{
    if (nullptr == root)
    {
        return T();
    }

    Node* node = root;
    while(node->getLeftNode() != nullptr)
    {
        node = node->getLeftNode();
    }

    return node->getValue();
}

template<typename T>
T BSTree<T>::maxValue() const
{
    if (nullptr == root)
    {
        return T();
    }

    Node* node = root;
    while(node->getRightNode() != nullptr)
    {
        node = node->getRightNode();
    }

    return node->getValue();
}

template<typename T>
void BSTree<T>::printTree() const
{
    printNode(root);
    std::cout << std::endl;
}

template<typename T>
void BSTree<T>::printNode(const Node* node) const
{
    if (nullptr == node)
    {
        return;
    }

    if (nullptr != node->getLeftNode())
    {
        printNode(node->getLeftNode());
    }

    std::cout << node->getValue() << " ";

    if (nullptr != node->getRightNode())
    {
        printNode(node->getRightNode());
    }
}

template<typename T>
void BSTree<T>::printTreePostorder() const
{
    printNodePostorder(root);
    std::cout << std::endl;
}

template<typename T>
void BSTree<T>::printNodePostorder(const Node* node) const
{
    if (nullptr == node)
    {
        return;
    }

    if (nullptr != node->getLeftNode())
    {
        printNodePostorder(node->getLeftNode());
    }

    if (nullptr != node->getRightNode())
    {
        printNodePostorder(node->getRightNode());
    }

    std::cout << node->getValue() << " ";
}

#endif /* BINARYSEARCHTREE_HPP_ */
