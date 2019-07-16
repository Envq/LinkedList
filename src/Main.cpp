#include "LinkedList.hpp"

#include <iostream>






int main(int argc, const char** argv) {


    using namespace list;


    LinkedList l {};

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);


    std::cout << l << std::endl;

    LinkedList m {};
    m.push_back(1);
    m.push_back(2);
    LinkedList r {};

    LinkedList q = r + m;

    std::cout << q << std::endl;
    m.erase(1);
    std::cout << q << std::endl;






    return 0;
}