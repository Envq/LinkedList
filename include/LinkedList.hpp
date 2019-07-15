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
    int l;

    public:
        //-- CONSTRUCTORS
        LinkedList();                                   //default constructor
        LinkedList(int count);                          //user-provided constructor
        // LinkedList(std::initializer_list<int> init);    //initializer-list constructor
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
        friend LinkedList operator+ (const LinkedList list1, const LinkedList list2);

    
    private:
        Node* searchNode(int index) const;
    
};





} // namespace list
#include "LinkedList.i.hpp"





