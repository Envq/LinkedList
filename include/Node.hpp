/**
 * @file Node.hpp
 * @author Enrico Sgarbanti
 * @brief Structure of Node
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#pragma once

/// @brief Namespace for list
namespace list {

/**
 * @brief Definition of Node
 *
 * @tparam T
 */
template<typename T>
struct Node {
    T value;
    Node<T> *next;
};

} // namespace list