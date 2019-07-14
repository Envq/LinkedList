#pragma once

#include "Node.hpp"

#include <cstddef>      // size_t




namespace list {


//-- CLASS INTERFACE
class LinkedList {
    size_t _length;
    Node _first;
    static size_t _instances;

    public:
        //-- CONSTRUCTORS
        LinkedList();                                   //default constructor
        LinkedList(int count);                          //user-provided constructor
        // LinkedList(std::initializer_list<int> init);    //initializer-list constructor
        LinkedList(const LinkedList& obj);              //copy constructor

        //-- METHODS
        static int count_istances();
        void insert(int value, int index);
        void push_back(int value);
        size_t size() const;
        void erase(int index);
        void print() const; 

        
        // operator << -> print()
        // operator [] -> accesso
        // operator + -> merge di due liste

};







} // namespace list
#include "LinkedList.i.hpp"