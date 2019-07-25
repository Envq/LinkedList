#pragma once

#include "List.hpp"
#include "Node.hpp"

#include <cstddef>      // size_t
#include <iostream>     // std::ostream, cout



namespace list {


//-- CLASS
template <typename T>
class LinkedList : public List<T> {
private:
    //-- ATTRIBUTES
    size_t _size;
    Node<T>* _head;
    Node<T>* _tail;

    //-- PRIVATE METHODS
    Node<T>* searchNode(int index) const;


public:
    //-- CONSTRUCTORS
    explicit LinkedList();                                   //default constructor
    explicit LinkedList(int count);                          //user-provided constructor
    explicit LinkedList(const LinkedList<T>& obj);           //copy constructor

    //-- DESTRUCTOR
    ~LinkedList() override;

    //-- METHODS
    static int count_istances() {
        return List<int>::count_istances();                 //???
    }

    size_t size() const override;
    void push_back(int value) override;
    void insert(int value, int index) override;
    void erase(int index) override;
    void print() const override; 

    //-- UNARY OPERATOR OVERLOADING
    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);

    //-- BINARY OPERATOR OVERLOADING
    template <typename R>
        friend std::ostream& operator<< (std::ostream& stream, const LinkedList<R>& list);
    template <typename R>
        friend LinkedList<R> operator+ (const LinkedList<R>& list1, const LinkedList<R>& list2);

};



// AUXILIARY CLASS
template <typename T>
class NodeIterator {
private:
    //-- ATTRIBUTES
    Node<T>* _pointer;

public:
    //-- CONSTRUCTORS
    explicit NodeIterator(Node<T>* start);                   //user-provided constructor

    //-- METHODS
    int next();    
    bool hasNext();
};


} // namespace list
#include "implementation/LinkedList.i.hpp"