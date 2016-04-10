#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "clock.h"


TEST_CASE("Prints the hour", "[answer]") {
    REQUIRE("08:00" == std::string(date_independent::clock::at(8)));
    REQUIRE("09:00" == std::string(date_independent::clock::at(9)));
}

TEST_CASE("Prints past the hour", "[answer]") {
    REQUIRE("11:09" == std::string(date_independent::clock::at(11, 9)));
    REQUIRE("11:19" == std::string(date_independent::clock::at(11, 19)));
}

TEST_CASE("Can add minutes", "[answer]") {
    const auto clock = date_independent::clock::at(10).plus(3);

    REQUIRE("10:03" == std::string(clock));
}

TEST_CASE("Can add over an hour", "[answer]") {
    const auto clock = date_independent::clock::at(10).plus(61);

    REQUIRE("11:01" == std::string(clock));
}

TEST_CASE("Wraps around midnight", "[answer]") {
    const auto clock = date_independent::clock::at(23, 59).plus(2);

    REQUIRE("00:01" == std::string(clock));
}

TEST_CASE("Can subtract minutes", "[answer]") {
    const auto clock = date_independent::clock::at(10, 3).minus(3);

    REQUIRE("10:00" == std::string(clock));
}

TEST_CASE("Can subtract to previous hour", "[answer]") {
    const auto clock = date_independent::clock::at(10, 3).minus(30);

    REQUIRE("09:33" == std::string(clock));
}

TEST_CASE("Can subtract over an hour", "[answer]") {
    const auto clock = date_independent::clock::at(10, 3).minus(70);

    REQUIRE("08:53" == std::string(clock));
}

TEST_CASE("Can know if its equal to another clock", "[answer]") {
    const auto clock1 = date_independent::clock::at(10, 3);
    const auto clock2 = date_independent::clock::at(10, 3);

    REQUIRE(clock1 == clock2);
}

TEST_CASE("Can know if its not equal to another clock", "[answer]") {
    const auto clock1 = date_independent::clock::at(10, 3);
    const auto clock2 = date_independent::clock::at(10, 4);

    REQUIRE(clock1 != clock2);
}

TEST_CASE("Wraps around midnight backwards", "[answer]") {
    const auto clock = date_independent::clock::at(0, 3).minus(4);

    REQUIRE("23:59" == std::string(clock));
}

// #if defined(EXERCISM_RUN_ALL_TESTS)
// #endif
