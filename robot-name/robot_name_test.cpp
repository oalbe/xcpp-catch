#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "robot_name.h"
#include <regex>


namespace {
    
const std::regex name_pattern{R"name(^[[:alpha:]]{2}\d{3}$)name"};

}

TEST_CASE("Has a name", "[answer]") {
    const robot_name::robot robot;

    REQUIRE(std::regex_match(robot.name(), name_pattern));
}

TEST_CASE("Name is the same each time", "[answer]") {
    const robot_name::robot robot;

    REQUIRE(robot.name() == robot.name());
}

TEST_CASE("Different robots have different names", "[answer]") {
    const robot_name::robot robot_one;
    const robot_name::robot robot_two;

    REQUIRE(robot_one.name() != robot_two.name());
}

TEST_CASE("Is able to reset name", "[answer]") {
    robot_name::robot robot;
    const auto original_name = robot.name();

    robot.reset();

    REQUIRE(original_name != robot.name());
}

TEST_CASE("Exhausting digits yields different names", "[answer]") {
    robot_name::robot robot;
    auto last_name = robot.name();
    
    for (int i = 0; i < 1000; ++i) {
        robot.reset();
        REQUIRE(last_name != robot.name());
        REQUIRE(std::regex_match(robot.name(), name_pattern));
    }
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
