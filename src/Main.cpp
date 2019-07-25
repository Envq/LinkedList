#include "LinkedList.hpp"
// #include "Node.hpp"

#include <iostream>



int main() {
    using namespace list;

    LinkedList <int> l {};
    LinkedList <int> l2 {};

    std::cout << LinkedList<int>::count_istances() << std::endl;

    l.push_back(10);
    l.push_back(11);
    l.push_back(12);

    // std::cout << l << std::endl;




    return 0;
}


/*
NOTE-------
mi piacerebbe accedere al parametro _instances di List da LinkedList ma non
 riesco. C'è un modo migliore di quello che ho fatto io?





 */