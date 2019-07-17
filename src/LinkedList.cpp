#include "LinkedList.hpp"
#include "Node.hpp"

#include <cstddef>      // size_t
#include <iostream>     // cout





namespace list {



// INITIALIZIZATIONS
template <typename T>   
size_t LinkedList<T>::_instances = 0;



//-- CONSTRUCTORS

// user-provided constructor
// template <typename T>                         
// LinkedList<T>::LinkedList(int count) {
//     _instances++;
//     _size = 0;
//     _first = nullptr;
//     _last = _first;

//     // init list
//     for (int i = 0; i < count; i++) {
//         // push_back(0);
//     }
// }


// default constructor
template <typename T>
LinkedList<T>::LinkedList() /*: LinkedList(0)*/ {}


// // copy constructor
// template <typename T>
// LinkedList<T>::LinkedList(const LinkedList& obj) : LinkedList(0) {
//     NodeIterator<T> ptr {obj._first};               //init ptr to node
//     while (ptr.hasNext()) {
//         push_back(ptr.next());
//     }
// }           



// //-- METHODS PUBLIC

// template <typename T>
// int LinkedList<T>::count_istances() {
//     return _instances;
// }


// template <typename T>
// size_t LinkedList<T>::size() const {
//     return _size;
// }


// template <typename T>
// void LinkedList<T>::push_back(int value) {
//     Node<T>* node = new Node<T>();            //create new node
//     node->value = value;
//     node->next = nullptr;
    
//     if (_size == 0)                     //init _first
//         _first = node;
//     else
//         _last->next = node;             //connect to the previous node
    
//     _last = node;                       //connect _last to the new last node
//     _size++;                            //update size
// }


// template <typename T>
// void LinkedList<T>::insert(int value, int index) {
//     // check if the operation is valid
//     if (index > _size || index < 0) {
//         std::cout << "ERROR: insert" << std::endl;
//         return;
//     }

//     Node<T>* node = new Node<T>();                    //create new node
//     node->value = value;

//     if (index == 0) {                           //check if is the first
//         node->next = _first;
//         _first = node;                          //update _first

//     } else if (index == _size) {                //check if is the last
//         node->next = nullptr;
//         _last->next = node;
//         _last = node;                           //update _last

//     } else {
//         Node<T>* previous = searchNode(index - 1); //find previous node
//         node->next = previous->next;
//         previous->next = node;                  //connect previous node
//     }
// }


// template <typename T>
// void LinkedList<T>::erase(int index) {
//     // check if the operation is valid
//     if (index >= _size || index < 0) {
//         std::cout << "ERROR: erase" << std::endl;
//         return;
//     }

//     if (index == 0) {                           //check if is the first
//         Node<T>* new_first = _first->next;
//         delete _first;
//         _first = new_first;                     //update _first
    
//     } else {
//         Node<T>* previous = searchNode(index - 1); //find previous node
//         Node<T>* to_delete = previous->next;
//         previous->next = to_delete->next;
//         delete to_delete;

//         if (index == _size -1)                  //check if is the last
//             _last = previous;
//     }
// }


// template <typename T>
// void LinkedList<T>::print() const {
//     Node<T>* ptr = _first;

//     while (ptr != nullptr) {
//         std::cout << ptr->value << std::endl;
//         ptr = ptr->next;
//     }
// }



// //-- OPERATOR OVERLOADING

// template <typename T>
// T LinkedList<T>::operator[] (int index) const {
//     return searchNode(index)->value;
// }


// template <typename T>
// std::ostream& operator<< (std::ostream& stream, const LinkedList<T>& list) {
//     if (list._first == nullptr)                 //exit if _first is nullptr
//         return stream << "[]";

//     Node<T>* ptr = list._first;

//     stream << "[";
//     while (ptr->next != nullptr) {              //stop at the penultimum
//         stream << ptr->value << ", ";
//         ptr = ptr->next;
//     }
//     stream << ptr->value << "]";
    
//     return stream;
// }


// template <typename T>
// LinkedList<T> operator+ (const LinkedList<T>& list1, const LinkedList<T>& list2) {
//     if (list1._size == 0 && list2._size == 0)   //case list1 and list2 empty
//         return {};

//     if (list1._size == 0)                       //case only list1 empty
//         return list2;

//     if (list2._size == 0)                       //case only list2 empty
//         return list1;

//     LinkedList list {list1};                    //case list1 and list2 not empty
//     NodeIterator<T> ptr {list2._first};            //init ptr to node
//     while (ptr.hasNext()) {
//         list.push_back(ptr.next());
//     }



//     return list;
// }



// //-- DESTRUCTOR
// template <typename T>
// LinkedList<T>::~LinkedList() {
//     Node<T>* ptr = _first;
//     for (int i = 0; i < _size; i++) {
//         _first = _first->next;
//         delete ptr;
//         ptr = _first;
//     }
// }





// //-- PRIVATE METHODS
// template <typename T>
// Node<T>* LinkedList<T>::searchNode(int index) const {
//     // check if the operation is valid
//     if (index >= _size || index < 0) {
//         std::cout << "ERROR: searchNode" << std::endl;
//         return nullptr;
//     }

//     Node<T>* ptr = _first;
//     for (int i = 0; i < index; i++) {
//         ptr = ptr->next;
//     }
//     return ptr;
// }




// //-- AUXILIARY CLASS
// template <typename T>                 
// NodeIterator<T>::NodeIterator(Node<T>* start) {
//     _pointer = start;
// }

// template <typename T>
// int NodeIterator<T>::next() {
//     int ret = _pointer->value;              //get return value
//     _pointer = _pointer->next;              //update pointer

//     return ret;
// }

// template <typename T>
// bool NodeIterator<T>::hasNext() {
//     return _pointer != nullptr;
// }







} // namespace list