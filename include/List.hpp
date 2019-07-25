#pragma once

#include <cstddef>      // size_t
#include <iostream>

namespace list {


//-- INTERFACE
template <typename T>
struct List {
protected:
    //-- ATTRIBUTES
    static int _instances;

    //-- CONSTRUCTORS
    explicit List();            //default constructor

    //-- DESTRUCTOR
    virtual ~List();


public:
    //-- METHODS
    int x = -7;
    static int count_istances();
    virtual size_t size() const = 0;
    virtual void push_back(int value) = 0;
    virtual void insert(int value, int index) = 0;
    virtual void erase(int index) = 0;
    virtual void print() const = 0;
};


//-- INITIALIZATIONS    -------------------------------------
template <typename T>   
int List<T>::_instances = 0;

//-- CONSTRUCTORS       -------------------------------------
template <typename T>
List<T>::List() {
    _instances++;
    std::cout << "CONSTRUCTOR LIST" << std::endl;
}

//-- DESTRUCTOR
template <typename T>
List<T>::~List() {
    _instances--;
    std::cout << "DESTRUCTOR LIST" << std::endl;
}

//-- METHODS
// template <typename T>
// int List<T>::count_istances() {
//     return -5;
// }


} // namespace list
// #include "implementation/List.i.hpp"
