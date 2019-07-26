/**
 * @file List.hpp
 * @author Enrico Sgarbanti
 * @brief List interface
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#pragma once

#include <cstddef> // size_t

/// @brief Namespace for list
namespace list {

/**
 * @brief Interface of List
 *
 * @tparam T
 */
template<typename T>
struct List {
  private:
    /// @brief Number of instances
    static int _instances;

  protected:
    /**
     * @brief Construct a new List object
     *
     * @details Default constructor
     */
    explicit List();

    /**
     * @brief Destroy the List object
     *
     * @details Destructor
     */
    virtual ~List();

    /**
     * @brief Count the istances of List
     *
     * @return Number of istances
     */
    static int count_instances();

  public:
    /**
     * @brief Return the size of List
     *
     * @return Size of list
     */
    virtual size_t size() const = 0;

    /**
     * @brief Push a value in the List
     *
     * @param value: Value to push
     */
    virtual void push_back(int value) = 0;

    /**
     * @brief Insert a value to an index
     *
     * @param value: Value to insert
     * @param index: Index where to insert
     */
    virtual void insert(int value, int index) = 0;

    /**
     * @brief Erase a value to an index
     *
     * @param index: Index where to erase
     */
    virtual void erase(int index) = 0;

    /**
     * @brief Print the values of the List
     *
     */
    virtual void print() const = 0;

    /**
     * @brief Check if the list contains "value"
     * 
     * @param value: Value to check
     * @return true if value is contained
     * @return false if value is not contained
     */
    virtual bool contains(T value) const = 0;
};

} // namespace list
#include "implementation/List.i.hpp"