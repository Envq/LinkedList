/**
 * @file Test.cpp
 * @author Enrico Sgarbanti
 * @brief Tests for project
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#include "LinkedList.hpp"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#undef CATCH_CONFIG_MAIN

// #include <iomanip>
#include <iostream>

/*
NB: methods to be tested manually:
    push_back()
    print()
    <<
    exception
*/

TEST_CASE("Equals method", "[equals]") {
    using T = int;
    list::LinkedList<T> list1 {};
    list::LinkedList<T> list2 {};

    // both with size=0
    REQUIRE((list1 == list2) == true);

    // size equals and equals value
    list1.push_back(0);
    list2.push_back(0);
    REQUIRE((list1 == list2) == true);

    // size different
    list1.push_back(2);
    REQUIRE((list1 == list2) == false);

    // size equals and different value
    list2.push_back(3);
    REQUIRE((list1 == list2) == false);
}

TEST_CASE("get operator", "get_operator") {
    using T = int;
    list::LinkedList<T> list {};
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    REQUIRE(list[0] == 0);
    REQUIRE(list[1] == 1);
    REQUIRE(list[2] == 2);
    REQUIRE(list[3] == 3);
}

TEST_CASE("insert method", "insert") {
    using T = int;
    list::LinkedList<T> list1 {};
    list::LinkedList<T> list2 {};
    list1.insert(0, 0);     list2.push_back(0);
    list1.insert(1 ,1);     list2.push_back(1);
    list1.insert(2, 2);     list2.push_back(2);
    list1.insert(3, 3);     list2.push_back(3);

    REQUIRE(list1 == list2);
}

TEST_CASE("erase method", "erase") {
    using T = int;
    // equals after erase
    list::LinkedList<T> list1 {};
    list::LinkedList<T> list2 {};
    list1.insert(0, 0);
    list2.push_back(0);
    list1.insert(1,1);
    list1.erase(1);
    REQUIRE(list1 == list2);

    // correct erase position
    list::LinkedList<T> list {};
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // delete on index 2
    // REQUIRE(list[2] == 2); //[0,1,2,3]
    list.erase(2);          
    REQUIRE(list[2] == 3); //[0,1,3]

    // delete on index 0
    list.erase(0);          
    REQUIRE(list[0] == 1); //[1,3]

    // delete on index 0
    list.erase(0);          
    REQUIRE(list[0] == 3); //[3]
}

TEST_CASE("size method", "size") {
    using T = int;
    list::LinkedList<T> list {};

    // size = 0
    REQUIRE(list.size() == 0);

    // size = 1
    list.push_back(1);
    REQUIRE(list.size() == 1);

    // size = 3
    list.push_back(1);
    list.push_back(1);
    REQUIRE(list.size() == 3);
}

TEST_CASE("user-provided Constructor", "up_constructor") {
    using T = int;
    list::LinkedList<T> list1 {};
    list::LinkedList<T> list2 {5};
    list::LinkedList<T> list3 {7};

    REQUIRE(list1.size() == 0);
    REQUIRE(list2.size() == 5);
    REQUIRE(list3.size() == 7);
}

TEST_CASE("copy Constructor", "copy_constructor") {
    using T = int;
    list::LinkedList<T> list1 {};
    list1.push_back(0);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list::LinkedList<T> list2 {list1};

    REQUIRE(list2.size() == list1.size());
    REQUIRE(list2 == list1);
}

TEST_CASE("count_istances Method", "count_istances") {
    using T = int;

    // 1 istances
    list::LinkedList<T> list1 {};
    REQUIRE(list::LinkedList<T>::count_instances() == 1);

    // 2 istances
    list::LinkedList<T> list2 {};
    REQUIRE(list::LinkedList<T>::count_instances() == 2);

    // 4 istances
    list::LinkedList<T> list3 {};
    list::LinkedList<T> list4 {};
    REQUIRE(list::LinkedList<T>::count_instances() == 4);
}

TEST_CASE("contains Method", "contains") {
    using T = int;
    list::LinkedList<T> list {};
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    REQUIRE(list.contains(0) == true);
    REQUIRE(list.contains(3) == true);
    REQUIRE(list.contains(-1) == false);
    REQUIRE(list.contains(10) == false);
}