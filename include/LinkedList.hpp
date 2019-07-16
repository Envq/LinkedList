#pragma once

#include "Node.hpp"

#include <cstddef>      // size_t
#include <iostream>     // std::ostream



namespace list {


//-- CLASS INTERFACE
class LinkedList {
    static size_t _instances;
    size_t _size;
    Node* _first;
    Node* _last;

    public:
        //-- CONSTRUCTORS
        LinkedList();                                   //default constructor
        LinkedList(int count);                          //user-provided constructor
        LinkedList(const LinkedList& obj);              //copy constructor

        //-- METHODS
        static int count_istances();
        size_t size() const;
        void push_back(int value);
        void insert(int value, int index);
        void erase(int index);
        void print() const; 

        //-- OPERATOR OVERLOADING
        int operator[] (int index) const;
        friend std::ostream& operator<< (std::ostream& stream, const LinkedList& list);
        friend LinkedList operator+ (const LinkedList& list1, const LinkedList& list2);

        //-- DESTRUCTOR
        ~LinkedList();

    
    private:
        Node* searchNode(int index) const;
    
};


// AUXILIARY CLASS
class NodeIterator {
    Node* _pointer;

    public:
        //-- CONSTRUCTORS
        NodeIterator(Node* start);                       //user-provided constructor

        //-- METHODS
        int next();    
        bool hasNext();
};





} // namespace list
#include "LinkedList.i.hpp"





