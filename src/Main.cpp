#include "LinkedList.hpp"
#include "Node.hpp"

#include <iostream>





int main(int argc, const char** argv) {


    using namespace list;

    LinkedList <int> l {};                                      // OK

    l.push_back(10);                                            // OK
    l.push_back(11);
    l.push_back(12);

    std::cout << l << std::endl;

    // l.print();                                               // OK

    // l.insert(-1, 0); l.print();                              // OK
    // l.insert(-1, 1); l.print();                              // OK
    // l.insert(-1, 2); l.print();                              // OK
    // l.insert(-1, 3); l.print();                              // OK
    // l.insert(-1, 4); l.print();                              // OK

    // l.erase(0); l.print();                                   // OK
    // l.erase(1); l.print();                                   // OK
    // l.erase(2); l.print();                                   // OK
    // l.erase(3); l.print();                                   // OK

    // std::cout << "size: " << l.size() << std::endl;          // OK
    
    // LinkedList <int> m {3}; m.print();                       // OK
    // LinkedList <int> n {l}; n.print();                       // OK
    // std::cout << "I: " << l.count_istances() << std::endl;   // OK


    // std::cout << "l[0]: " << l[0] << std::endl;              // OK
    // std::cout << l << std::endl;                            // OK


    // Node<int>* n  = new Node<int>();
    // Node<int>* n1 = new Node<int>();
    // Node<int>* n2 = new Node<int>();
    // n1->value = 1;
    // n1->next = n2;
    // n2->value = 2;
    // n2->next = nullptr;
    // n = n1;

    // std::cout << n1->value << std::endl;
    // std::cout << n2->value << std::endl;
    // std::cout << n1->next->value << std::endl;

    // std::cout << n->value << std::endl;
    // delete n;
    // n = n2;
    // std::cout << n->value << std::endl;

    return 0;
}