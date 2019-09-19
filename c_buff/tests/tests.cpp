//
// Created by azari on 19.09.2019.
//



///#define TEST 10
#ifdef TEST
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../circular_buffer.h"

TEST_CASE("work with front and back"){
    CircularBuffer <int> dafaq(5);
    SECTION("push"){
        for (size_t i = 0; i < 5; ++i){
        dafaq.push_front(i+1);
    }
        REQUIRE(dafaq.get_front() == 5 &&  dafaq.get_size == 5);

        dafaq.clear;
        for (size_t i = 0; i <= 6; ++i){
        dafaq.push_back(i+1);
    }
        REQUIRE(dafaq.get_back() == 7 && size == 5)
    }
    dafaq.push_front(1);
    dafaq.push_back(0);
    dafaq.push_front(3);
    dafaq.push_front(5);
    dafaq.push_back(2);
    dafaq.push_front(7);
    dafaq.push_front(42);
       REQUIRE(dafaq.get_front() == 42)
    SECTION("pop"){
         for (size_t i = 0; i < 6; ++i) {
        dafaq.push_back(i + 1);
    }
    dafaq.pop_front();
    dafaq.pop_front();
    dafaq.pop_front();
    dafaq.pop_front();
    dafaq.pop_front();
    REQUIRE(dafaq.get_size == 0)
    dafaq.clear()
     CircularBuffer<int> dafaq(5);
    for (size_t i = 0; i < 6; ++i) {
        dafaq.push_back(i + 1);
    }
    dafaq.pop_back();
    dafaq.pop_back();
    REQUIRE(dafaq.get_back == 4)
    }



    }
}

#endif
