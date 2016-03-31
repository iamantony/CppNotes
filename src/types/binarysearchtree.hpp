#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include <algorithm>
#include <stdexcept>
#include <vector>

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

    template <typename U>
    friend bool operator==(BSTree<U>& left, BSTree<U>& right);

    template <typename U>
    friend bool operator!=(BSTree<U>& left, BSTree<U>& right);

    void clear();
    int size() const;
    bool isEmpty() const;
    void insert(const T& value);
    bool contains(const T& value) const;
    int maxDepth() const;
    T minValue() const;
    T maxValue() const;
    std::vector<T> printTree() const;
    std::vector<T> printTreePostorder() const;
    std::vector<std::vector<T>> getPaths() const;
    void mirror();

private:
    int calcSize(const Node* node) const;
    void insertValue(Node* node, const T& value);
    bool containsValue(Node* node, const T& value) const;
    int calcMaxDepth(const Node* node) const;
    void printNode(const Node* node, std::vector<T>& values) const;
    void printNodePostorder(const Node* node, std::vector<T>& values) const;
    std::vector<std::vector<T>> getNodePaths(const Node* node) const;
    void mirrorNode(Node* node);
    bool isSameNodes(Node* lh, Node* rh);
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
std::vector<T> BSTree<T>::printTree() const
{
    std::vector<T> values;
    printNode(root, values);

    return values;
}

template<typename T>
void BSTree<T>::printNode(const Node* node, std::vector<T>& values) const
{
    if (nullptr == node)
    {
        return;
    }

    if (nullptr != node->getLeftNode())
    {
        printNode(node->getLeftNode(), values);
    }

    values.push_back(node->getValue());

    if (nullptr != node->getRightNode())
    {
        printNode(node->getRightNode(), values);
    }
}

template<typename T>
std::vector<T> BSTree<T>::printTreePostorder() const
{
    std::vector<T> values;
    printNodePostorder(root, values);

    return values;
}

template<typename T>
void BSTree<T>::printNodePostorder(const Node* node,
        std::vector<T>& values) const
{
    if (nullptr == node)
    {
        return;
    }

    if (nullptr != node->getLeftNode())
    {
        printNodePostorder(node->getLeftNode(), values);
    }

    if (nullptr != node->getRightNode())
    {
        printNodePostorder(node->getRightNode(), values);
    }

    values.push_back(node->getValue());
}

template<typename T>
std::vector<std::vector<T>> BSTree<T>::getPaths() const
{
    std::vector<std::vector<T>> paths = getNodePaths(root);
    auto func = [](std::vector<T>& vec){std::reverse(vec.begin(), vec.end());};
    std::for_each(paths.begin(), paths.end(), func);

    return paths;
}

template<typename T>
std::vector<std::vector<T>> BSTree<T>::getNodePaths(const Node* node) const
{
    if (nullptr == node)
    {
        return std::vector<std::vector<T>>();
    }

    std::vector<std::vector<T>> leftPaths, rightPaths;
    if (nullptr != node->getLeftNode())
    {
        leftPaths = getNodePaths(node->getLeftNode());
    }

    if (nullptr != node->getRightNode())
    {
        rightPaths = getNodePaths(node->getRightNode());
    }

    std::vector<std::vector<T>> result;
    std::copy(leftPaths.begin(), leftPaths.end(), std::back_inserter(result));
    std::copy(rightPaths.begin(), rightPaths.end(), std::back_inserter(result));
    if (result.empty())
    {
        result.push_back(std::vector<T>());
    }

    const T nodeValue = node->getValue();
    auto func = [&nodeValue](std::vector<T>& vec){vec.push_back(nodeValue);};
    std::for_each(result.begin(), result.end(), func);

    return result;
}

template<typename T>
void BSTree<T>::mirror()
{
    mirrorNode(root);
}

template<typename T>
void BSTree<T>::mirrorNode(Node* node)
{
    if (nullptr == node)
    {
        return;
    }

    Node* left = node->getLeftNode();
    Node* right = node->getRightNode();
    mirrorNode(left);
    mirrorNode(right);

    node->setLeftNode(right);
    node->setRightNode(left);
}

template<typename U>
bool operator==(BSTree<U>& left, BSTree<U>& right)
{
    return left.isSameNodes(left.root, right.root);
}

template<typename U>
bool operator!=(BSTree<U>& left, BSTree<U>& right)
{
    return !(left == right);
}

template<typename T>
bool BSTree<T>::isSameNodes(Node* lh, Node* rh)
{
    if (nullptr == lh)
    {
        return nullptr == rh ? true : false;
    }
    else if (nullptr == rh)
    {
        return false;
    }

    if (lh->getValue() == rh->getValue() &&
            isSameNodes(lh->getLeftNode(), rh->getLeftNode()) &&
            isSameNodes(lh->getRightNode(), rh->getRightNode()))
    {
        return true;
    }

    return false;
}

#endif /* BINARYSEARCHTREE_HPP_ */
