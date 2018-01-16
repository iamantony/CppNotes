#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <stdexcept>

namespace DS {

template<typename T>
class LinkedList
{
    // == DATA ==
private:
    class Node
    {
    public:
        Node(T value, Node* previous, Node* next) : m_value(value),
            m_prev(previous), m_next(next) {}
        ~Node();

        Node(const LinkedList<T>::Node& other) = delete;
        Node& operator=(const Node& other) = delete;

        void setPrevious(Node* previous);
        Node* getPrevious() const;
        void setNext(Node* next);
        Node* getNext() const;
        void setValue(const T& value);
        T getValue() const;

    private:
        T m_value;
        Node* m_prev;
        Node* m_next;
    };

    int m_size = 0;
    Node* m_first = nullptr;
    Node* m_last = nullptr;

    // == METHODS ==
public:
    LinkedList() {}
    LinkedList(const int& listSize, const T& value = 0);
    ~LinkedList();

    LinkedList(const LinkedList<T>& other) = delete;
    LinkedList<T>& operator=(const LinkedList<T>& other) = delete;

    T first() const;
    T last() const;
    T at(const int& index) const;
    void addFirst(const T& value);
    void addLast(const T& value);
    void insert(const int& index, const T& value);
    void remove(const int& index);
    void removeFirst();
    void removeLast();
    void clear();
    int size() const;
    bool isEmpty() const;

private:
    void clearLast();
    Node* searchNode(const int& index) const;
};

template<typename T>
LinkedList<T>::Node::~Node()
{
    if (nullptr != m_prev)
    {
        m_prev->setNext(m_next);
        if (nullptr != m_next)
        {
            m_next->setPrevious(m_prev);
        }
    }
}

template<typename T>
void LinkedList<T>::Node::setPrevious(Node* previous)
{
    m_prev = previous;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Node::getPrevious() const
{
    return (m_prev);
}

template<typename T>
void LinkedList<T>::Node::setNext(Node* next)
{
    m_next = next;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Node::getNext() const
{
    return (m_next);
}

template<typename T>
void LinkedList<T>::Node::setValue(const T& value)
{
    m_value = value;
}

template<typename T>
T LinkedList<T>::Node::getValue() const
{
    return (m_value);
}

template<typename T>
LinkedList<T>::LinkedList(const int& listSize, const T& value)
{
    for (int i = 0; i < listSize; ++i)
    {
        addLast(value);
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
T LinkedList<T>::first() const
{
    if (isEmpty())
    {
        throw std::length_error("Linked list is empty");
    }

    return (m_first->getValue());
}

template<typename T>
T LinkedList<T>::last() const
{
    if (isEmpty())
    {
        throw std::length_error("Linked list is empty");
    }

    return (m_last->getValue());
}

template<typename T>
T LinkedList<T>::at(const int& index) const
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
    Node* node = m_first;
    int i = 0;
    while(i != index)
    {
        node = node->getNext();
        ++i;
    }

    return (node);
}

template<typename T>
void LinkedList<T>::addFirst(const T& value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty())
    {
        m_first = m_last = newNode;
    }
    else
    {
        m_first->setPrevious(newNode);
        newNode->setNext(m_first);
        m_first = newNode;
    }

    ++m_size;
}

template<typename T>
void LinkedList<T>::addLast(const T& value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty())
    {
        m_first = m_last = newNode;
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
void LinkedList<T>::insert(const int& index, const T& value)
{
    if (isEmpty() || index <= 0)
    {
        addFirst(value);
        return;
    }

    if (size() <= index)
    {
        addLast(value);
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
void LinkedList<T>::remove(const int& index)
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

    if (m_first == m_last)
    {
        clearLast();
        return;
    }

    Node* firstNode = m_first;
    Node* nextNode = m_first->getNext();
    if (nullptr == nextNode)
    {
        throw std::runtime_error("Invalid next node");
    }

    nextNode->setPrevious(nullptr);
    m_first = nextNode;
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

    if (m_first == m_last)
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
    m_first = m_last = nullptr;
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
int LinkedList<T>::size() const
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
