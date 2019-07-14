#include "LinkedList.hpp"
#include "Node.hpp"

#include <cstddef>      // size_t


namespace list {

// Initialization counter of instances
size_t LinkedList::_instances = 0;



//-- CONSTRUCTORS

//user-provided constructor                         
LinkedList::LinkedList(int count) {
    _length = count;
    _instances++;
}

//default constructor
LinkedList::LinkedList() {
    LinkedList(0);
}

//initializer-list constructor  
// LinkedList(std::initializer_list<int> init) {}

//copy constructor  
LinkedList::LinkedList(const LinkedList& obj) {

}           



//-- METHODS

int LinkedList::count_istances() {
            return _instances;
}


// void LinkedList::insert(int value, int index);


// void LinkedList::push_back(int value);


size_t LinkedList::size() const {
    return _length;
}


// void LinkedList::erase(int index);


// void LinkedList::print() const; 








} // namespace list