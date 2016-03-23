#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>
#include "phone_number.h"


TEST_CASE("Cleans parens dashes and spaces from the number", "[answer]") {
    const phone_number phone("(123) 456-7890");

    REQUIRE("1234567890" == phone.number());
}

TEST_CASE("Cleans numbers with dots", "[answer]") {
    const phone_number phone("123.456.7890");

    REQUIRE("1234567890" == phone.number());
}

TEST_CASE("Valid when 11 digits and first digit is 1", "[answer]") {
    const phone_number phone("11234567890");

    REQUIRE("1234567890" == phone.number());
}

TEST_CASE("Invalid when 11 digits", "[answer]") {
    const phone_number phone("21234567890");

    REQUIRE("0000000000" == phone.number());
}

TEST_CASE("Invalid when 9 digits", "[answer]") {
    const phone_number phone("123456789");

    REQUIRE("0000000000" == phone.number());
}

TEST_CASE("Has an area code", "[answer]") {
    const phone_number phone("1234567890");

    REQUIRE("123" == phone.area_code());
}

TEST_CASE("Formats a number", "[answer]") {
    const phone_number phone("1234567890");

    REQUIRE("(123) 456-7890" == std::string(phone));
}

// #if defined(EXERCISM_RUN_ALL_TESTS)
// #endif
