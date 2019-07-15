#include "LinkedList.hpp"
#include "Node.hpp"

#include <cstddef>      // size_t
#include <iostream>     // cout


namespace list {

// Initialization counter of instances
size_t LinkedList::_instances = 0;



//-- CONSTRUCTORS

//user-provided constructor                         
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

//default constructor
LinkedList::LinkedList() : LinkedList(0) {}

//initializer-list constructor  
// LinkedList(std::initializer_list<int> init) {}

//copy constructor  
LinkedList::LinkedList(const LinkedList& obj) {

}           



//-- METHODS PUBLIC

int LinkedList::count_istances() {
    return _instances;
}


size_t LinkedList::size() const {
    return _size;
}


void LinkedList::push_back(int value) {
    Node *node = new Node();            //create new node
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

    Node *node = new Node();                    //create new node
    node->value = value;

    if (index == 0) {                           //check if is the first
        node->next = _first;
        _first = node;                          //update _first

    } else if (index == _size) {                //check if is the last
        node->next = nullptr;
        _last->next = node;
        _last = node;                           //update _last

    } else {
        Node* previous = searchNode(index - 1); //find previous node
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
        Node* new_first = _first->next;
        delete _first;
        _first = new_first;                     //update _first
    
    } else {
        Node* previous = searchNode(index - 1); //find previous node
        Node* to_delete = previous->next;
        previous->next = to_delete->next;
        delete to_delete;

        if (index == _size -1)                  //check if is the last
            _last = previous;
    }
}


void LinkedList::print() const {
    Node* ptr = _first;

    while (ptr != nullptr) {
        std::cout << ptr->value << std::endl;
        ptr = ptr->next;
    }

    // std::cout << _last->value << std::endl;
}



//-- OPERATOR OVERLOADING
int LinkedList::operator[] (int index) const {
    return searchNode(index)->value;              
}


// std::ostream& LinkedList::operator<< (std::ostream& stream, const LinkedList& list) {
//     Node* ptr = _first;

//     stream << std::endl;
//     while (ptr != nullptr) {
//         std::cout << ptr->value 
//         stream << ptr->value
//         ptr = ptr->next;
//     }
//     stream << std::endl;
// }


// std::ostream& operator << (std::ostream& stream, const LinkedList& list) {

// }




//-- PRIVATE METHODS

Node* LinkedList::searchNode(int index) const {
    Node *ptr = _first;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr;                     // no check index -> risk segmentation fault
}








} // namespace list