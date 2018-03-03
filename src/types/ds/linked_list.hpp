#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <vector>
#include <stdexcept>

namespace DS {

// Singly linked list

template<typename T>
class LinkedList {
private:

    class Node {
    public:
        Node(const T& value);
        Node(const T& value, Node* next);
        ~Node();

        Node(const LinkedList<T>::Node& other) = delete;
        Node& operator=(const Node& other) = delete;

        void setNext(Node* next);
        Node* getNext() const;

        void setValue(const T& value);
        T getValue() const;

    private:
        T m_value;
        Node* m_next;
    };

    int m_size = 0;
    Node* m_root = nullptr;

public:
    LinkedList() {}
    LinkedList(const size_t& listSize, const T& value = 0);
    LinkedList(const std::vector<T>& values);
    ~LinkedList();

    LinkedList(const LinkedList<T>& other) = delete;
    LinkedList<T>& operator=(const LinkedList<T>& other) = delete;

    size_t size() const;
    bool isEmpty() const;

    T front() const;
    T back() const;
    T at(const size_t& index) const;

    T valueNFromEnd(const size_t& n) const;

    void pushFront(const T& value);
    void pushBack(const T& value);
    void insert(const size_t& index, const T& value);

    void popFront();
    void popBack();
    void deleteItem(const size_t& index);
    void remove(const T& value);
    void removeFirst();
    void removeLast();
    void clear();

    void reverse();

private:
    void clearLast();
    Node* searchNode(const int& index) const;
};

template<typename T>
LinkedList<T>::Node::Node(const T& value) : Node(value, nullptr) { }

template<typename T>
LinkedList<T>::Node::Node(const T& value, Node* next) :
    m_value(value), m_next(next) { }

template<typename T>
LinkedList<T>::Node::~Node() { }

template<typename T>
void LinkedList<T>::Node::setNext(Node* next) {
    m_next = next;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Node::getNext() const {
    return (m_next);
}

template<typename T>
void LinkedList<T>::Node::setValue(const T& value) {
    m_value = value;
}

template<typename T>
T LinkedList<T>::Node::getValue() const {
    return (m_value);
}

template<typename T>
LinkedList<T>::LinkedList(const size_t &listSize, const T& value) {
    for (size_t i = 0; i < listSize; ++i) {
        pushBack(value);
    }
}

template<typename T>
LinkedList(const std::vector<T>& values);

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
T LinkedList<T>::front() const
{
    if (isEmpty())
    {
        throw std::length_error("Linked list is empty");
    }

    return (m_root->getValue());
}

template<typename T>
T LinkedList<T>::back() const
{
    if (isEmpty())
    {
        throw std::length_error("Linked list is empty");
    }

    return (m_last->getValue());
}

template<typename T>
T LinkedList<T>::at(const size_t &index) const
{
    if (isEmpty())
    {
        throw std::length_error("Linked list is empty");
    }
    else if (index < 0 || size() <= index)
    {
        throw std::runtime_error("Invalid index");
    }

    Node* node = searchNode(index);
    if (nullptr == node)
    {
        throw std::runtime_error("Failed to find node");
    }

    return (node->getValue());
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::searchNode(const int& index) const
{
    Node* node = m_root;
    int i = 0;
    while(i != index)
    {
        node = node->getNext();
        ++i;
    }

    return (node);
}

template<typename T>
void LinkedList<T>::pushFront(const T& value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty())
    {
        m_root = m_last = newNode;
    }
    else
    {
        m_root->setPrevious(newNode);
        newNode->setNext(m_root);
        m_root = newNode;
    }

    ++m_size;
}

template<typename T>
void LinkedList<T>::pushBack(const T& value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty())
    {
        m_root = m_last = newNode;
    }
    else
    {
        m_last->setNext(newNode);
        newNode->setPrevious(m_last);
        m_last = newNode;
    }

    ++m_size;
}

template<typename T>
void LinkedList<T>::insert(const size_t &index, const T& value)
{
    if (isEmpty() || index <= 0)
    {
        pushFront(value);
        return;
    }

    if (size() <= index)
    {
        pushBack(value);
        return;
    }

    Node* node = searchNode(index);
    if (nullptr == node)
    {
        throw std::runtime_error("Failed to find node");
    }

    Node* prevNode = node->getPrevious();
    Node* newNode = new Node(value, prevNode, node);
    prevNode->setNext(newNode);
    node->setPrevious(newNode);
    ++m_size;
}

template<typename T>
void LinkedList<T>::deleteItem(const size_t &index)
{
    if (isEmpty() || index < 0 || size() <= index)
    {
        return;
    }

    if (0 == index)
    {
        removeFirst();
    }
    else if (index == size() - 1)
    {
        removeLast();
    }
    else
    {
        Node* node = searchNode(index);
        if (nullptr == node)
        {
            throw std::runtime_error("Failed to find node");
        }

        Node* prevNode = node->getPrevious();
        Node* nextNode = node->getNext();
        if (nullptr != prevNode)
        {
            prevNode->setNext(nextNode);
        }

        if (nullptr != nextNode)
        {
            nextNode->setPrevious(prevNode);
        }

        -- m_size;
        delete node;
    }
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    if (isEmpty())
    {
        return;
    }

    if (m_root == m_last)
    {
        clearLast();
        return;
    }

    Node* firstNode = m_root;
    Node* nextNode = m_root->getNext();
    if (nullptr == nextNode)
    {
        throw std::runtime_error("Invalid next node");
    }

    nextNode->setPrevious(nullptr);
    m_root = nextNode;
    --m_size;
    delete firstNode;
}

template<typename T>
void LinkedList<T>::removeLast()
{
    if (isEmpty())
    {
        return;
    }

    if (m_root == m_last)
    {
        clearLast();
        return;
    }

    Node* lastNode = m_last;
    Node* prevNode = m_last->getPrevious();
    if (nullptr == prevNode)
    {
        throw std::runtime_error("Invalid previous node");
    }

    prevNode->setNext(nullptr);
    m_last = prevNode;
    --m_size;
    delete lastNode;
}

template<typename T>
void LinkedList<T>::clearLast()
{
    Node* node = m_last;
    m_root = m_last = nullptr;
    m_size = 0;
    delete node;
}

template<typename T>
void LinkedList<T>::clear()
{
    while(false == isEmpty())
    {
        removeLast();
    }
}

template<typename T>
size_t LinkedList<T>::size() const
{
    return (m_size);
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return (0 == m_size);
}

}

#endif /* LINKEDLIST_HPP_ */
