/**
 * @file LinkedList.hpp
 * @author Enrico Sgarbanti
 * @brief LinkedList Interface
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#pragma once

#include "List.hpp"
#include "Node.hpp"

#include <cstddef>  // size_t
#include <iostream> // std::ostream, cout

/// @brief Namespace for list
namespace list {

/**
 * @brief Interface of LinkedList
 *
 * @tparam T
 */
template<typename T>
class LinkedList : public List<T> {
  private:
    /// @brief Size of LinkedList
    size_t _size;
    /// @brief Pointer to head of LinkedList
    Node<T> *_head;
    /// @brief Pointer to tail of LinkedList
    Node<T> *_tail;

    /**
     * @brief Get the Node to an index
     *
     * @param index: Index where to get Node
     * @return Pointer to the Node
     */
    Node<T> *getNode(int index) const;

  public:
    /**
     * @brief Construct a new Linked List object
     *
     * @details Default constructor
     *
     */
    explicit LinkedList();

    /**
     * @brief Construct a new Linked List object
     *
     * @details User-provided constructor
     *
     * @param count: Number of Nodes to create
     */
    explicit LinkedList(int count);

    /**
     * @brief Construct a new Linked List object
     *
     * @details Copy constructor
     *
     * @param obj: Object (LinkedList) to initialize this LinkedList
     */
    explicit LinkedList(const LinkedList<T> &obj);

    /**
     * @brief Destroy the LinkedList object
     *
     * @details Destructor
     */
    ~LinkedList() override;

    /**
     * @brief Count the istances of List
     *
     * @return Number of istances
     */
    static int count_instances() {
        return List<int>::count_instances(); //???
    }

    // METHODS OVERRIDEDED
    size_t size() const override;
    void push_back(int value) override;
    void insert(int value, int index) override;
    void erase(int index) override;
    void print() const override;
    bool contains(T value) const override;

    //-- UNARY OPERATOR OVERLOADING
    /**
     * @brief Return the value of Node to an index
     *
     * @param index: Index where to get Node
     * @return Constant Reference to value
     */
    const T &operator[](size_t index) const;

    /**
     * @brief Return the value of Node to an index
     *
     * @param index: Index where to get Node
     * @return Reference to value
     */
    T &operator[](size_t index);

    //-- BINARY OPERATOR OVERLOADING
    /**
     * @brief Return the stream Of LinkedList
     *
     * @tparam R
     * @param stream: Stream software
     * @param list: LinkedList to stream
     * @return Stream with LinkedList
     */
    template<typename R>
    friend std::ostream &operator<<(std::ostream &stream,
                                    const LinkedList<R> &list);
    /**
     * @brief Return a LinkedList with is the sum of two LinkedList
     *
     * @tparam R
     * @param list1: First LinkedList
     * @param list2: Second LinkedList
     * @return LinkedList containing both LinkedLists
     */
    template<typename R>
    friend LinkedList<R> operator+(const LinkedList<R> &list1,
                                   const LinkedList<R> &list2);
    /**
     * @brief Compare two lists
     * 
     * @tparam R 
     * @param list1: First LinkedList
     * @param list2: Secondo LinkedList
     * @return true if the lists are equals
     * @return false if the lists are different
     */
    template<typename R>
    friend bool operator==(const LinkedList<R> &list1,
                           const LinkedList<R> &list2);
};

// AUXILIARY CLASS
/**
 * @brief Node Iterator
 *
 * @details This auxilary class allows you to iterate between nodes
 *
 * @tparam T
 */
template<typename T>
class NodeIterator {
  private:
    /// @brief Pointer to a Node
    Node<T> *_pointer;

  public:
    /**
     * @brief Construct a new Node Iterator object
     *
     * @details User-provided constructor
     *
     * @param start: First Node to iterate
     */
    explicit NodeIterator(Node<T> *start);

    /**
     * @brief Go to the next Node
     *
     * @return Return the value of pointend Node
     */
    int next();

    /**
     * @brief Check if exist next Node
     *
     * @return true if the next Node exist
     * @return false if the next Node not exist
     */
    bool hasNext();
};

} // namespace list
#include "implementation/LinkedList.i.hpp"