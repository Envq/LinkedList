#pragma once


namespace list {



//-- STRUCTURE
template <typename T>
struct Node {
    T value;
    Node<T>* next;
};


} // namespace list
#include "implementation/Node.i.hpp"