#pragma once

#include "Node.hpp"

#include <cstddef>      // size_t
#include <iostream>     // std::ostream, cout



namespace list {


//-- CLASS INTERFACE
template <typename T>
class LinkedList {
    static size_t _instances;
    size_t _size;
    Node<T>* _first;
    Node<T>* _last;

    public:
        //-- CONSTRUCTORS
        LinkedList();                                   //default constructor
        LinkedList(int count);                          //user-provided constructor
        LinkedList(const LinkedList<T>& obj);           //copy constructor

        //-- METHODS
        static int count_istances();
        size_t size() const;
        void push_back(int value);
        void insert(int value, int index);
        void erase(int index);
        void print() const; 

        //-- OPERATOR OVERLOADING
        T (operator[]) (int index) const;
        template <typename R>
            friend std::ostream& operator<< (std::ostream& stream, const LinkedList<R>& list);
        template <typename R>
             friend LinkedList<R> operator+ (const LinkedList<R>& list1, const LinkedList<R>& list2);

        //-- DESTRUCTOR
        ~LinkedList();

    
        // private:
        Node<T>* searchNode(int index) const;
};


// AUXILIARY CLASS
template <typename T>
class NodeIterator {
    Node<T>* _pointer;
    public:
        //-- CONSTRUCTORS
        NodeIterator(Node<T>* start);              //user-provided constructor

        //-- METHODS
        int next();    
        bool hasNext();
};


} // namespace list
#include "implementation/LinkedList.i.hpp"