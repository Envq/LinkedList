#include "LinkedList.hpp"
#include "Node.hpp"

#include <cstddef>      // size_t
#include <iostream>     // cout





namespace list {



// INITIALIZIZATIONS
size_t LinkedList::_instances = 0;



//-- CONSTRUCTORS

// user-provided constructor                         
LinkedList::LinkedList(int count) {
    _instances++;
    _size = 0;
    _first = nullptr;
    _last = _first;

    // init list
    for (int i = 0; i < count; i++) {
        push_back(0);
    }
}


// default constructor
LinkedList::LinkedList() : LinkedList(0) {}


// copy constructor  
LinkedList::LinkedList(const LinkedList& obj) : LinkedList(0) {
    NodeIterator<int> ptr {obj._first};               //init ptr to node
    while (ptr.hasNext()) {
        push_back(ptr.next());
    }
}           



//-- METHODS PUBLIC

int LinkedList::count_istances() {
    return _instances;
}


size_t LinkedList::size() const {
    return _size;
}


void LinkedList::push_back(int value) {
    Node<int>* node = new Node<int>();            //create new node
    node->value = value;
    node->next = nullptr;
    
    if (_size == 0)                     //init _first
        _first = node;
    else
        _last->next = node;             //connect to the previous node
    
    _last = node;                       //connect _last to the new last node
    _size++;                            //update size
}


void LinkedList::insert(int value, int index) {
    // check if the operation is valid
    if (index > _size || index < 0) {
        std::cout << "ERROR: insert" << std::endl;
        return;
    }

    Node<int>* node = new Node<int>();                    //create new node
    node->value = value;

    if (index == 0) {                           //check if is the first
        node->next = _first;
        _first = node;                          //update _first

    } else if (index == _size) {                //check if is the last
        node->next = nullptr;
        _last->next = node;
        _last = node;                           //update _last

    } else {
        Node<int>* previous = searchNode(index - 1); //find previous node
        node->next = previous->next;
        previous->next = node;                  //connect previous node
    }
}


void LinkedList::erase(int index) {
    // check if the operation is valid
    if (index >= _size || index < 0) {
        std::cout << "ERROR: erase" << std::endl;
        return;
    }

    if (index == 0) {                           //check if is the first
        Node<int>* new_first = _first->next;
        delete _first;
        _first = new_first;                     //update _first
    
    } else {
        Node<int>* previous = searchNode(index - 1); //find previous node
        Node<int>* to_delete = previous->next;
        previous->next = to_delete->next;
        delete to_delete;

        if (index == _size -1)                  //check if is the last
            _last = previous;
    }
}


void LinkedList::print() const {
    Node<int>* ptr = _first;

    while (ptr != nullptr) {
        std::cout << ptr->value << std::endl;
        ptr = ptr->next;
    }
}



//-- OPERATOR OVERLOADING
int LinkedList::operator[] (int index) const {
    return searchNode(index)->value;
}


std::ostream& operator<< (std::ostream& stream, const LinkedList& list) {
    if (list._first == nullptr)                 //exit if _first is nullptr
        return stream << "[]";

    Node<int>* ptr = list._first;

    stream << "[";
    while (ptr->next != nullptr) {              //stop at the penultimum
        stream << ptr->value << ", ";
        ptr = ptr->next;
    }
    stream << ptr->value << "]";
    
    return stream;
}



LinkedList operator+ (const LinkedList& list1, const LinkedList& list2) {
    if (list1._size == 0 && list2._size == 0)   //case list1 and list2 empty
        return {};

    if (list1._size == 0)                       //case only list1 empty
        return list2;

    if (list2._size == 0)                       //case only list2 empty
        return list1;

    LinkedList list {list1};                    //case list1 and list2 not empty
    NodeIterator<int> ptr {list2._first};            //init ptr to node
    while (ptr.hasNext()) {
        list.push_back(ptr.next());
    }



    return list;
}



//-- DESTRUCTOR
LinkedList::~LinkedList() {
    Node<int>* ptr = _first;
    for (int i = 0; i < _size; i++) {
        _first = _first->next;
        delete ptr;
        ptr = _first;
    }
}





//-- PRIVATE METHODS
Node<int>* LinkedList::searchNode(int index) const {
    // check if the operation is valid
    if (index >= _size || index < 0) {
        std::cout << "ERROR: searchNode" << std::endl;
        return nullptr;
    }

    Node<int>* ptr = _first;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr;
}




//-- AUXILIARY CLASS
template <typename T>                 
NodeIterator<T>::NodeIterator(Node<T>* start) {
    _pointer = start;
}

template <typename T>
int NodeIterator<T>::next() {
    int ret = _pointer->value;              //get return value
    _pointer = _pointer->next;              //update pointer

    return ret;
}

template <typename T>
bool NodeIterator<T>::hasNext() {
    return _pointer != nullptr;
}







} // namespace list