#include "LinkedList.hpp"

#include <iostream>






int main(int argc, const char** argv) {


    using namespace list;


    LinkedList l {};

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    LinkedList m{l};

    std::cout << l + m << std::endl;






    return 0;
}