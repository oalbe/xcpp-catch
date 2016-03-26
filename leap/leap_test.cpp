#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>
#include "leap.h"


TEST_CASE("A known leap year", "[answer]") {
    REQUIRE(leap::is_leap_year(1996));
}

TEST_CASE("Any old year", "[answer]") {
    REQUIRE(!leap::is_leap_year(1997));
}

TEST_CASE("Turn of the 20th century", "[answer]") {
    REQUIRE(!leap::is_leap_year(1900));
}

TEST_CASE("Turn of the 21st century", "[answer]") {
    REQUIRE(leap::is_leap_year(2000));
}

TEST_CASE("Turn of the 25th century", "[answer]") {
    REQUIRE(leap::is_leap_year(2400));;
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
