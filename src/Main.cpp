#include "LinkedList.hpp"
// #include "Node.hpp"

#include <iostream>



int main() {
    using namespace list;

    LinkedList <int> l {};

    std::cout << l.foo() << std::endl;

    l.push_back(10);
    l.push_back(11);
    l.push_back(12);

    // std::cout << l << std::endl;




    return 0;
}


/*
NOTE-------
#include "impl/list.i.hpp" non funziona




 */