#include "LinkedList.hpp"

#include <iostream>






int main(int argc, const char** argv) {


    using namespace list;


    LinkedList l {};
    LinkedList m {};

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    
    std::cout << l << std::endl;
    

    // l.print();



    return 0;
}