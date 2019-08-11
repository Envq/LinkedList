/**
 * @file LinkedList.i.hpp
 * @author Enrico Sgarbanti
 * @brief Implementation of methods for LinkedList
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#pragma once

#include "Util.hpp" // error

/// @brief Namespace for list
namespace list {

//-- CONSTRUCTORS       -------------------------------------
// user-provided constructor
template<typename T>
LinkedList<T>::LinkedList(int count) {
    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    // init list
    for (int i = 0; i < count; i++) {
        push_back(0);
    }
}

// default constructor
template<typename T>
LinkedList<T>::LinkedList() : LinkedList(0) {
}

// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList &obj) : LinkedList(0) {
    NodeIterator<T> ptr{obj._head}; // init ptr to node
    while (ptr.hasNext()) {
        push_back(ptr.next());
    }
}

//-- DESTRUCTOR
template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *to_delete = nullptr;

    while (_head != nullptr) {
        to_delete = _head;   // update ptr
        _head = _head->next; // update _head
        delete to_delete;    // delete node
    }
}

//-- METHODS PUBLIC     -------------------------------------
template<typename T>
size_t LinkedList<T>::size() const {
    return _size;
}

template<typename T>
void LinkedList<T>::push_back(int value) {
    auto node = new Node<T>(); // create new node
    node->value = value;
    node->next = nullptr;

    if (_size == 0) { // init _head
        _head = node;
    } else {
        _tail->next = node; // connect to the previous node
    }

    _tail = node; // connect _tail to the new last node
    _size++;      // update size
}

template<typename T>
void LinkedList<T>::insert(int value, int index) {
    if (index < 0 || static_cast<size_t>(index) > _size) // check if the operation is valid
        error("Insert");

    auto node = new Node<T>(); // create new node
    _size++;                   // update _size
    node->value = value;

    if (index == 0) { // check if is the first
        node->next = _head;
        _head = node; // update _head

    } else if (static_cast<size_t>(index) == _size) { // check if is the last
        node->next = nullptr;
        _tail->next = node;
        _tail = node; // update _tail

    } else {
        auto previous = getNode(index - 1); // find previous node
        node->next = previous->next;
        previous->next = node; // connect previous node
    }
}

template<typename T>
void LinkedList<T>::erase(int index) {
    if (index < 0 || static_cast<size_t>(index) >= _size) // check if the operation is valid
        error("Erase");

    if (index == 0) { // check if is the first
        auto to_delete = _head;
        _head = _head->next; // update _head
        delete to_delete;

    } else {
        auto previous = getNode(index - 1); // find previous node
        auto to_delete = previous->next;
        previous->next = to_delete->next;
        delete to_delete;

        if (static_cast<size_t>(index) == _size - 1) // check if is the last
            _tail = previous;
    }
    _size--; // update _size
}

template<typename T>
void LinkedList<T>::print() const {
    NodeIterator<T> ptr{_head}; // init ptr to node
    while (ptr.hasNext()) {
        std::cout << ptr.next() << std::endl;
    }
}

template<typename T>
bool LinkedList<T>::contains(T value) const {
    NodeIterator<T> ptr{_head}; // init ptr to node
    while (ptr.hasNext()) {
        if (ptr.next() == value) {
            return true;
        }
    }
    return false;
}

//-- UNARY OPERATOR OVERLOADING------------------------------
template<typename T>
const T &LinkedList<T>::operator[](size_t index) const {
    // check control is implicit in getNode
    return getNode(index)->value;
}

template<typename T>
T &LinkedList<T>::operator[](size_t index) {
    // check control is implicit in getNode
    return getNode(index)->value;
}

//-- BINARY OPERATOR OVERLOADING-----------------------------
template<typename R>
std::ostream &operator<<(std::ostream &stream, const LinkedList<R> &list) {
    if (list._head == nullptr) // exit if _head is nullptr
        return stream << "[]";

    auto ptr = list._head;

    stream << "[";
    while (ptr->next != nullptr) { // stop at the penultimum
        stream << ptr->value << ", ";
        ptr = ptr->next;
    }
    stream << ptr->value << "]";

    return stream;
}

template<typename R>
LinkedList<R> operator+(const LinkedList<R> &list1,
                        const LinkedList<R> &list2) {
    if (list1._size == 0 && list2._size == 0) // case list1 and list2 empty
        return {};

    if (list1._size == 0) // case only list1 empty
        return list2;

    if (list2._size == 0) // case only list2 empty
        return list1;

    LinkedList list{list1};           // case list1 and list2 not empty
    NodeIterator<R> ptr{list2._head}; // init ptr to node
    while (ptr.hasNext()) {
        list.push_back(ptr.next());
    }

    return list;
}

template<typename R>
bool operator==(const LinkedList<R> &list1, const LinkedList<R> &list2) {
    if (list1._size != list2._size) // case list1 and list2 have different size
        return false;

    NodeIterator<R> ptr1{list1._head}; // init ptr to list1
    NodeIterator<R> ptr2{list2._head}; // init ptr to list2
    while (ptr1.hasNext()) {
        if (ptr1.next() != ptr2.next()) {
            return false; // exit if Node.value is different
        }
    }

    return true; // case in which all the nodes are equal
}

//-- PRIVATE METHODS    -------------------------------------
template<typename T>
Node<T> *LinkedList<T>::getNode(int index) const {
    if (index < 0 || static_cast<size_t>(index) >= _size) // check if the operation is valid
        error("getNode");

    auto ptr = _head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr;
}

//-- AUXILIARY CLASS    -------------------------------------
template<typename T>
NodeIterator<T>::NodeIterator(Node<T> *start) {
    _pointer = start;
}

template<typename T>
int NodeIterator<T>::next() {
    int ret = _pointer->value; // get return value
    _pointer = _pointer->next; // update pointer

    return ret;
}

template<typename T>
bool NodeIterator<T>::hasNext() {
    return _pointer != nullptr;
}

} // namespace list