#pragma once

#include <cstddef>      // size_t

namespace list {


//-- INTERFACE
template <typename T>
struct List {
private:
    //-- ATTRIBUTES
    static int _instances;


protected:
    //-- CONSTRUCTORS
    explicit List();            //default constructor

    //-- DESTRUCTOR
    virtual ~List();

    //-- GETTER _instances
    static int count_istances();


public:
    //-- METHODS
    virtual size_t size() const = 0;
    virtual void push_back(int value) = 0;
    virtual void insert(int value, int index) = 0;
    virtual void erase(int index) = 0;
    virtual void print() const = 0;
};


} // namespace list
#include "implementation/List.i.hpp"
