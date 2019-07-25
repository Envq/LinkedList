/**
 * @file List.i.hpp
 * @author Enrico Sgarbanti
 * @brief Implementation of methods for managing the number of instances
 * @version 1.0
 * @date 2019-07-25
 * 
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 * 
 */

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
int List<T>::count_instances() {
    return _instances;
}

} // namespace list