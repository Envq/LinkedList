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
        // friend std::ostream& operator<< (std::ostream& stream, const LinkedList& list) {
        //     stream << _size;
        //     return stream;
        // }
        // operator + -> merge di due liste

    
    private:
        Node* searchNode(int index) const;
    
};

// class Point {
//     int x,y;

//     friend std::ostream& operator<<(std::ostream& stream, const Point& point) {
//         stream << "(" << point.x << "," << point.y << ")";
//         return stream;
//     }
// };




} // namespace list
#include "LinkedList.i.hpp"





