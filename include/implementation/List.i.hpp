#pragma once

namespace list {

//-- INITIALIZATIONS    -------------------------------------
template <typename T>   
int List<T>::_instances = 0;

//-- CONSTRUCTORS       -------------------------------------
template <typename T>
List<T>::List() {
    _instances++;
}

//-- DESTRUCTOR         -------------------------------------
template <typename T>
List<T>::~List() {
    _instances--;
}

//-- METHODS
template <typename T>
int List<T>::count_istances() {
    return _instances;
}

} // namespace list