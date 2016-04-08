#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include "sum_of_multiples.h"

TEST_CASE("Sum to 1 yields 0", "[answer]") {
    REQUIRE(0 == sum_of_multiples::to(0));
}

TEST_CASE("Sum to 4 yields 3", "[answer]") {
    REQUIRE(3 == sum_of_multiples::to(4));
}

TEST_CASE("Sum to 10 yields 23", "[answer]") {
    REQUIRE(23 == sum_of_multiples::to(10));
}

TEST_CASE("Sum to 100", "[answer]") {
    REQUIRE(2318 == sum_of_multiples::to(100));
}

TEST_CASE("Sum to 1000", "[answer]") {
    REQUIRE(233168 == sum_of_multiples::to(1000));
}

TEST_CASE("Sum of 7 13 17 to 20 yields 51", "[answer]") {
    REQUIRE(51 == sum_of_multiples::to({7, 13, 17}, 20));
}

TEST_CASE("Sum of 43 47 to 10000", "[answer]") {
    REQUIRE(2203160 == sum_of_multiples::to({43, 47}, 10000));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
