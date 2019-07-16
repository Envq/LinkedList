#include "LinkedList.hpp"

#include <iostream>

template <typename T>
struct Box {
    T obj;
    Box (T obj) : obj(obj) {
        std::cout << obj << std::endl;
    }
};



int main(int argc, const char** argv) {


    // using namespace list;


    // LinkedList l;

    // l.push_back(0);
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(3);

    // LinkedList m(l);

    // std::cout << l + m << std::endl;


    Box<int>* b = new Box(3);




    return 0;
}