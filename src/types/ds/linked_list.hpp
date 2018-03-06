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
        Node(const T& value, Node* next = nullptr);
        ~Node();

        Node(const LinkedList<T>::Node& other) = delete;
        Node& operator=(const Node& other) = delete;

        void setNext(Node* next);
        Node* getNext() const;

        void setValue(const T& value);
        T getValue() const;

    private:
        T m_value;
        Node* m_next = nullptr;
    };

    size_t m_size = 0;
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
    void clear();

    void reverse();

private:
    Node* searchNode(const size_t& index) const;
    bool checkIndex(const size_t& index) const;
};

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
LinkedList<T>::LinkedList(const std::vector<T>& values) {
    for (const T& value : values) {
        pushBack(value);
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
size_t LinkedList<T>::size() const {
    return (m_size);
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return (0 == m_size);
}

template<typename T>
T LinkedList<T>::front() const {
    return at(0);
}

template<typename T>
T LinkedList<T>::back() const {
    return at(m_size - 1);
}

template<typename T>
T LinkedList<T>::at(const size_t &index) const {
    checkIndex(index);

    Node* node = searchNode(index);
    if (nullptr == node) {
        throw std::runtime_error("Failed to find node");
    }

    return (node->getValue());
}

template<typename T>
bool LinkedList<T>::checkIndex(const size_t& index) const {
    if (isEmpty()) {
        throw std::length_error("Linked list is empty");
    }
    else if (size() <= index) {
        throw std::runtime_error("Invalid index");
    }

    return true;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::searchNode(
        const size_t& index) const {
    if (isEmpty()) {
        throw std::length_error("Linked list is empty");
    }

    // If 'index' is bigger than number of elements in linked list, then
    // return last element
    size_t realIndex = index;
    if (size() <= index) {
        realIndex = size() - 1;
    }

    Node* node = m_root;
    size_t i = 0;
    while(i != realIndex) {
        node = node->getNext();
        ++i;
    }

    return (node);
}

template<typename T>
T LinkedList<T>::valueNFromEnd(const size_t& n) const {
    checkIndex(n);

    Node* forward = m_root;
    size_t counter = 0;
    while(counter < n) {
        forward = forward->getNext();
        if (forward == nullptr) {
            throw std::runtime_error("Linked list is too small");
        }

        ++counter;
    }

    // Move 'forward' and 'secondary' iterators till 'forward' get to the last
    // element in the list. At this time 'secondary' will point to
    // n-from-end node
    Node* secondary = m_root;
    while(true) {
        if (forward->getNext() == nullptr) {
            break;
        }

        forward = forward->getNext();
        secondary = secondary->getNext();
    }

    return secondary->getValue();
}

template<typename T>
void LinkedList<T>::pushFront(const T& value) {
    insert(0, value);
}

template<typename T>
void LinkedList<T>::pushBack(const T& value) {
    insert(m_size, value);
}

template<typename T>
void LinkedList<T>::insert(const size_t &index, const T& value) {
    Node* newNode = new Node(value);

    if (isEmpty() || index == 0) {
        newNode->setNext(m_root);
        m_root = newNode;
    }
    else {
        Node* node = searchNode(index - 1);
        if (nullptr == node) {
            throw std::runtime_error("Failed to find node");
        }

        newNode->setNext(node->getNext());
        node->setNext(newNode);
    }

    ++m_size;
}

template<typename T>
void LinkedList<T>::popFront() {
    deleteItem(0);
}

template<typename T>
void LinkedList<T>::popBack() {
    deleteItem(size() - 1);
}

template<typename T>
void LinkedList<T>::deleteItem(const size_t &index) {
    if (isEmpty() || size() <= index) {
        return;
    }

    Node* node = m_root;
    Node* prev = nullptr;
    size_t i = 0;
    while(i != index) {
        prev = node;
        node = node->getNext();
        ++i;
    }

    // Check if we remove first element
    if (prev == nullptr) {
        m_root = node->getNext();
    }
    else {
        prev->setNext(node->getNext());
    }

    node->setNext(nullptr);
    --m_size;

    delete node;
}

template<typename T>
void LinkedList<T>::remove(const T& value) {
    Node* node = m_root;
    Node* prev = nullptr;

    const size_t maxSize = size();
    size_t i = 0;
    while(i < maxSize) {
        if (node->getValue() == value)
        {
            // Special case when we remove first element
            if (prev == nullptr) {
                m_root = node->getNext();

                node->setNext(nullptr);
                delete node;

                node = m_root;
            }
            else {
                prev->setNext(node->getNext());

                node->setNext(nullptr);
                delete node;

                node = prev->getNext();
            }

            --m_size;
        }
        else {
            prev = node;
            node = node->getNext();
        }

        ++i;
    }
}

template<typename T>
void LinkedList<T>::clear() {
    while(!isEmpty()) {
        deleteItem(0);
    }
}

template<typename T>
void LinkedList<T>::reverse() {
    if (isEmpty()) {
        return;
    }

    Node* current = m_root;
    Node* prev = nullptr;
    while(nullptr != current) {
        Node* next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    m_root = prev;
}

}

#endif /* LINKEDLIST_HPP_ */
