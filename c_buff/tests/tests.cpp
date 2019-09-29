//
// Created by azari on 19.09.2019.
//


#define TEST 10
#ifdef TEST
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../circular_buffer.h"

TEST_CASE("constructor") {
    SECTION("default") {
        CircularBuffer<int> test1;
        REQUIRE(test1.get_capacity() == 16);
        REQUIRE(test1.get_size() == 0);
        REQUIRE(test1.get_front_index() == -1);
        REQUIRE(test1.get_back_index() == 0);

    }
    SECTION("ONE ARGUE") {
        CircularBuffer<int> test2(15);
        REQUIRE(test2.get_capacity() == 15);
        REQUIRE(test2.get_size() == 0);
        REQUIRE(test2.get_front_index() == -1);
        REQUIRE(test2.get_back_index() == 0);
        REQUIRE_THROWS_AS(CircularBuffer<int>(-2),std::invalid_argument);

    }
    SECTION("TWO ARGUE") {
        CircularBuffer<int> test3(10, 42);
        REQUIRE(test3.get_capacity() == 10);
        REQUIRE(test3.get_size() == 10);
        REQUIRE(test3.get_front_index() == 0);
        REQUIRE(test3.get_back_index() == 9);
        bool check = true;
        for (auto i = 0; i < 10; ++i) {
            if (!test3.check_buffer(i, 42)) {
                check = false;
                break;
            }
        }
        REQUIRE(check);
        REQUIRE_THROWS_AS(CircularBuffer<int>(-2,12),std::invalid_argument);
    }
    SECTION("COPY") {
        CircularBuffer<int> dafaq(5,42);
        const CircularBuffer<int> ffs(dafaq);
        REQUIRE((dafaq == ffs));


    }
}
TEST_CASE("operators"){
    SECTION("=="){
        CircularBuffer<int> item1(5,42);
        CircularBuffer<int> item2(5,42);
        CircularBuffer<int> item3(5,41);
        REQUIRE(item1 == item2);
        REQUIRE(!(item1 == item3));
        CircularBuffer<int> test_1(5);
        for (auto i = 0; i < 5; ++i) {
            test_1.push_front(i + 1);
        }
        CircularBuffer<int> test_2(5);
        for (auto i = 0; i < 5; ++i) {
            test_2.push_front(i + 1);
        }
        test_2.rotate(3);
        REQUIRE((test_1 == test_2));
    }
    SECTION("!="){
        CircularBuffer<int> test_1(5);
        for (int i = 0; i < 5; ++i) {
            test_1.push_front(i + 1);
        }
        CircularBuffer<int> test_2(5);
        for (int i = 0; i < 5; ++i) {
            test_2.push_front(i + 1);
        }
        test_2.rotate(3);
        REQUIRE(!(test_1 !=test_2));
        test_2.pop_back();
        REQUIRE((test_1 !=test_2));
    }
    SECTION("="){
        CircularBuffer<int> test_1(5,42);
        CircularBuffer<int>test_2(2);
        test_2=test_1;
        REQUIRE((test_1 == test_2));

    }

    SECTION("[ ]"){
         CircularBuffer<int> dafaq(6);
    for (int i = 0; i < 3; ++i) {
        dafaq.push_front(i + 1);
    }
    REQUIRE((dafaq[2]) == 1);




    }
    SECTION("at"){
        CircularBuffer<int> dafaq(6);
        for (int i = 0; i < 3; ++i) {
            dafaq.push_front(i + 1);
        }
        REQUIRE((dafaq.at(2)) == 1);
        REQUIRE_THROWS_AS(dafaq.at(42),std::out_of_range);

    }
}
TEST_CASE("ROTATE, Linear, push/pop") {
    SECTION("ROTATE"){
        CircularBuffer<int> dafaq(6);
        for (int i = 0; i < 6; ++i) {
            dafaq.push_back(i + 1);
        }
        dafaq.rotate(3);
        REQUIRE(dafaq.get_front_index() == 3);
        REQUIRE(dafaq.get_front() == 1);
        REQUIRE(dafaq.get_back()==6);
        REQUIRE(dafaq.get_back_index() ==2);
    }
    SECTION("LINEAR"){
        CircularBuffer<int> dafaq(5);
          for (int i = 0; i < 5; ++i) {
            dafaq.push_front(i + 1);
        }
          REQUIRE(!dafaq.is_linearized());
          dafaq.linearize();
          REQUIRE(dafaq.linearize());
          REQUIRE(dafaq.is_linearized());


    }
    SECTION("PUSH_BACK") {
        CircularBuffer<int> dafaq(5);
        for (int i = 0; i < 5; ++i) {
            dafaq.push_back(i + 1);
        }
        REQUIRE(dafaq.get_front() == 1);
        REQUIRE(dafaq.get_front_index() == 0);
        REQUIRE(dafaq.get_back() == 5);
        REQUIRE(dafaq.get_back_index() == 4);
        REQUIRE(dafaq.get_size() == 5);
        bool check = true;
        for (auto i = 0; i < 5; ++i) {
            if (!dafaq.check_buffer(i, i + 1)) {
                check = false;
                break;
            }
        }
        REQUIRE(check);
        ///буфер полный 1 2 3 4 5
        dafaq.push_back(42);
        REQUIRE(dafaq.get_back_index() == 0);
        REQUIRE(dafaq.get_front_index() == 0);
        ///42 2 3 4 5
        REQUIRE(dafaq.get_size() == 5);
    }
    SECTION("push_front") {
        CircularBuffer<int> dafaq(5);
        for (int i = 0; i < 5; ++i) {
            dafaq.push_front(i + 1);
        }
        REQUIRE(dafaq.get_front() == 5);
        REQUIRE(dafaq.get_front_index() == 1);
        REQUIRE(dafaq.get_back() == 1);
        REQUIRE(dafaq.get_back_index() == 0);
        REQUIRE(dafaq.get_size() == 5);
        bool check = true;
        for (auto i = 1; i < 4; ++i) {
            if (!dafaq.check_buffer(i, 6 - i)) {
                check = false;
                break;
            }
        }
        REQUIRE(check);
        ///буфер полный 1 5 4 3 2
        dafaq.push_back(42);
        ///1 42 4 3 2
        REQUIRE(dafaq.get_size() == 5);


    }
    SECTION("pop_back") {
        CircularBuffer<int> dafaq(5, 42);
        dafaq.pop_back();
        REQUIRE(dafaq.get_back_index() == 3);
        REQUIRE(dafaq.get_size() == 4);
        while (!dafaq.empty()) {
            dafaq.pop_back();

        }
        REQUIRE(dafaq.get_back_index() == 0);
        REQUIRE(dafaq.get_size() == 0);
        REQUIRE_THROWS_AS(dafaq.pop_back(), std::underflow_error);
        for (int i = 0; i < 6; ++i) {
            dafaq.push_back(i + 1);
        }
        //// 6 2 3 4 5
        REQUIRE(dafaq.get_back() == 6);
        REQUIRE(dafaq.get_back_index() == 0);

    }
    SECTION("pop_front") {

        CircularBuffer<int> dafaq(5, 42);
        while (dafaq.get_size() != 1) {
            dafaq.pop_front();

        }
        REQUIRE((dafaq.get_front() == 42 && dafaq.get_front_index() == 4));
        dafaq.pop_front();
        REQUIRE(dafaq.get_size() == 0);
        REQUIRE_THROWS_AS(dafaq.pop_back(), std::underflow_error);


    }
    SECTION("front == back") {
        CircularBuffer<int> dafaq(5);
        for (int i = 0; i < 6; ++i) {
            dafaq.push_back(i + 1);
        }
        //// 6 5 4 3 2
        dafaq.pop_front();
        //// _ 5 4 3 2
        REQUIRE(dafaq.get_front_index() == 1);
        REQUIRE(dafaq.get_front() == 2);
        REQUIRE(dafaq.get_back() == 5);
        REQUIRE(dafaq.get_back_index() == 4);

    }
    SECTION("ERASE") {
        CircularBuffer<int> dafaq(6);
        for (int i = 0; i < 6; ++i) {
            dafaq.push_back(i + 1);
        }
        ////1 2 3 4 5 6
        dafaq.erase(4, 5);
        ////1 2 3 4 _ _
        REQUIRE(dafaq.get_front() == 1);
        REQUIRE(dafaq.get_front_index() == 0);
        REQUIRE((dafaq.get_back() = 4));
        REQUIRE(dafaq.get_back_index() == 3);
        REQUIRE(dafaq.get_size() == 4);
        dafaq.erase(1, 2);
        //// 1 _ _ 4_ _ -> 1 4 _ _ _ _
        REQUIRE(dafaq.get_back() == 4);
        REQUIRE(dafaq.get_size() == 2);
        dafaq.clear();
        for (int i = 0; i < 6; ++i) {
            dafaq.push_back(i + 1);
        }
        //// 1 2 3 4 5 6
        dafaq.erase(0, 3);
        /// 5 6 _ _ _ _ _ _
        REQUIRE(dafaq.get_front() == 5);
        REQUIRE(dafaq.get_back() == 6);
        REQUIRE(dafaq.get_size() == 2);
        CircularBuffer<char> dafaq1(5);
        for (int i = 0; i < 5; ++i) {
            dafaq1.push_front(i + 1);
        }
        ////1 5 4 3 2
        dafaq1.erase(1, 3);
        /// _ 5 1 _ _
        REQUIRE(dafaq1.get_front() == 5);
        REQUIRE(dafaq1.get_back() == 1);
        REQUIRE(dafaq1.get_size() == 2);
        dafaq1.clear();
        for (int i = 0; i < 6; ++i) {
            dafaq1.push_front(i + 1);
        }
        //// 6 5 4 3 2
            dafaq1.erase(0, 1);
            REQUIRE(dafaq1.get_front() == 4);
            REQUIRE(dafaq1.get_back() == 2);
            //// 4 3 2 _ _
        REQUIRE_THROWS_AS(dafaq1.erase(-25,2), std::out_of_range);



    }
    SECTION("INSERT"){
        CircularBuffer<int> dafaq(5);
         for(int i = 0; i < 5; ++i){
        dafaq.push_back(i+1);
    }
         //// 1 2 3 4 5
    REQUIRE_THROWS_AS(dafaq.insert(-25,2), std::out_of_range);
    dafaq.insert(0,42);
    //// 42 1 2 3 4
    REQUIRE(dafaq[0] == 42);
    REQUIRE(dafaq.get_back()==4);
    REQUIRE(dafaq.get_size() == 5);
    dafaq.insert(4,21);
    REQUIRE(dafaq[4] == 21);
    ///4 1 2 3 21
    REQUIRE(dafaq.get_front() == 4);





    }

}
TEST_CASE("RESIZE /NEW_CAPACITY"){
    SECTION("RESIZE"){
        CircularBuffer<int> dafaq(5);
    for (int i = 0; i < 5; ++i) {
        dafaq.push_back(i + 1);

    }
    dafaq.resize(3,12);
    REQUIRE(dafaq.get_capacity() == 5);
    REQUIRE(dafaq.get_size() == 3);
    REQUIRE(dafaq.get_back() ==3);
    dafaq.resize(12,42);
     REQUIRE(dafaq.get_capacity() == 12);
    REQUIRE(dafaq.get_size() == 12);
    REQUIRE(dafaq.get_back() ==42);



    }
    SECTION("NEW_capacity"){
        CircularBuffer<int> dafaq(5);
    for (int i = 0; i < 5; ++i) {
        dafaq.push_back(i + 1);

    }
    dafaq.set_capacity(3);
    REQUIRE(dafaq.get_capacity() == 3);
    REQUIRE(dafaq.get_size() == 3);
    REQUIRE(dafaq.get_back() ==3);
    dafaq.set_capacity(15);
    REQUIRE(dafaq.get_capacity()==15);
    REQUIRE_THROWS_AS(dafaq.set_capacity(-2),std::invalid_argument);


    }
}


#endif
