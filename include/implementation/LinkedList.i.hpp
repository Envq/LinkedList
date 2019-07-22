#include "Util.hpp"     // error



namespace list {


//-- INITIALIZATIONS    -------------------------------------

template <typename T>   
size_t LinkedList<T>::_instances = 0;


//-- CONSTRUCTORS       -------------------------------------

// user-provided constructor
template <typename T>                         
LinkedList<T>::LinkedList(int count) {
    _instances++;
    _size = 0;
    _head = nullptr;
    _tail = _head;

    // init list
    for (int i = 0; i < count; i++) {
        push_back(0);
    }
}

// default constructor
template <typename T>
LinkedList<T>::LinkedList() : LinkedList(0) {}

// copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& obj) : LinkedList(0) {
    NodeIterator<T> ptr {obj._head};               //init ptr to node
    while (ptr.hasNext()) {
        push_back(ptr.next());
    }
}  


//-- METHODS PUBLIC     -------------------------------------

template <typename T>
int LinkedList<T>::count_istances() {
    return _instances;
}

template <typename T>
size_t LinkedList<T>::size() const {
    return _size;
}

template <typename T>
void LinkedList<T>::push_back(int value) {
    Node<T>* node = new Node<T>();                  //create new node
    node->value = value;
    node->next = nullptr;
    
    if (_size == 0)                                 //init _head
        _head = node;
    else
        _tail->next = node;                         //connect to the previous node
    
    _tail = node;                                   //connect _tail to the new last node
    _size++;                                        //update size
}

template <typename T>
void LinkedList<T>::insert(int value, int index) {    
    if (index > _size || index < 0)                 // check if the operation is valid
        error("Insert");

    Node<T>* node = new Node<T>();                  //create new node
    _size++;                                        //update _size
    node->value = value;

    if (index == 0) {                               //check if is the first
        node->next = _head;
        _head = node;                              //update _head

    } else if (index == _size) {                    //check if is the last
        node->next = nullptr;
        _tail->next = node;
        _tail = node;                               //update _tail

    } else {
        Node<T>* previous = searchNode(index - 1);  //find previous node
        node->next = previous->next;
        previous->next = node;                      //connect previous node
    }
}

template <typename T>
void LinkedList<T>::erase(int index) {    
    if (index >= _size || index < 0)                // check if the operation is valid
        error("Erase");
        
    if (index == 0) {                               //check if is the first
        auto to_delete = _head;
        _head = _head->next;                        //update _head
        delete to_delete;
    
    } else {
        auto previous = searchNode(index - 1);      //find previous node
        auto to_delete = previous->next;
        previous->next = to_delete->next;
        delete to_delete;

        if (index == _size -1)                      //check if is the last
            _tail = previous;
    }
}

template <typename T>
void LinkedList<T>::print() const {
    NodeIterator<T> ptr {_head};                   //init ptr to node
    while (ptr.hasNext()) {
        std::cout << ptr.next() << std::endl;
    }
}


//-- OPERATOR OVERLOADING------------------------------------

template <typename T>
T LinkedList<T>::operator[] (int index) const {
    // check control is implicit in searchNode
    return searchNode(index)->value;
}

template <typename R>
std::ostream& operator<< (std::ostream& stream, const LinkedList<R>& list) {
    if (list._head == nullptr)                 //exit if _head is nullptr
        return stream << "[]";

    Node<R>* ptr = list._head;

    stream << "[";
    while (ptr->next != nullptr) {              //stop at the penultimum
        stream << ptr->value << ", ";
        ptr = ptr->next;
    }
    stream << ptr->value << "]";
    
    return stream;
}

template <typename R>
LinkedList<R> operator+ (const LinkedList<R>& list1, const LinkedList<R>& list2) {
    if (list1._size == 0 && list2._size == 0)   //case list1 and list2 empty
        return {};

    if (list1._size == 0)                       //case only list1 empty
        return list2;

    if (list2._size == 0)                       //case only list2 empty
        return list1;

    LinkedList list {list1};                    //case list1 and list2 not empty
    NodeIterator<R> ptr {list2._head};         //init ptr to node
    while (ptr.hasNext()) {
        list.push_back(ptr.next());
    }

    return list;
}


//-- DESTRUCTOR
template <typename T>
LinkedList<T>::~LinkedList() {
    Node <T>* to_delete = nullptr;

    while (_head != nullptr) {
        to_delete = _head;                      // update ptr
        _head = _head->next;                    // update _head
        delete to_delete;                       // delete node
    }
}


//-- PRIVATE METHODS    -------------------------------------

template <typename T>
Node<T>* LinkedList<T>::searchNode(int index) const {
    if (index >= _size || index < 0)                    // check if the operation is valid
        error("SearchNode");

    Node<T>* ptr = _head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr;
}


//-- AUXILIARY CLASS    -------------------------------------

template <typename T>                 
NodeIterator<T>::NodeIterator(Node<T>* start) {
    _pointer = start;
}

template <typename T>
int NodeIterator<T>::next() {
    int ret = _pointer->value;              //get return value
    _pointer = _pointer->next;              //update pointer

    return ret;
}

template <typename T>
bool NodeIterator<T>::hasNext() {
    return _pointer != nullptr;
}


} // namespace list