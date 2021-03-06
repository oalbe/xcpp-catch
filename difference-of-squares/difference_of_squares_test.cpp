#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "difference_of_squares.h"


TEST_CASE("Up to 5", "[answer]") {
    REQUIRE(225 == squares::square_of_sums(5));
    REQUIRE(55 == squares::sum_of_squares(5));
    REQUIRE(170 == squares::difference(5));
}

TEST_CASE("Up to 10", "[answer]") {
    REQUIRE(3025 == squares::square_of_sums(10));
    REQUIRE(385 == squares::sum_of_squares(10));
    REQUIRE(2640 == squares::difference(10));
}

TEST_CASE("Up to 100", "[answer]") {
    REQUIRE(25502500 == squares::square_of_sums(100));
    REQUIRE(338350 == squares::sum_of_squares(100));
    REQUIRE(25164150 == squares::difference(100));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
