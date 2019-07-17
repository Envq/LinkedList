#include "LinkedList.hpp"
#include "Node.hpp"

#include <iostream>


using namespace list;

template <typename T>
struct Box {
    Node<T> n;
    Box (T obj) {
        n.value = obj;
        n.next = nullptr;
        std::cout << obj << std::endl;
    }

    T getObj() {
        return n.value;
    }
};



int main(int argc, const char** argv) {

    Box<int>(3);


    // using namespace list;


    // LinkedList l;

    // l.push_back(0);
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(3);

    // LinkedList m(l);

    // std::cout << l + m << std::endl;






    return 0;
}