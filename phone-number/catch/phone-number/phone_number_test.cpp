#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>
#include "phone_number.h"


TEST_CASE("Cleans_parens_dashes_and_spaces_from_the_number", "[answer]") {
    const phone_number phone("(123) 456-7890");

    REQUIRE("1234567890", phone.number());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Cleans_numbers_with_dots", "[answer]") {
    const phone_number phone("123.456.7890");

    REQUIRE("1234567890", phone.number());
}

TEST_CASE("Valid_when_11_digits_and_first_digit_is_1", "[answer]") {
    const phone_number phone("11234567890");

    REQUIRE("1234567890", phone.number());
}

TEST_CASE("Invalid_when_11_digits", "[answer]") {
    const phone_number phone("21234567890");

    REQUIRE("0000000000", phone.number());
}

TEST_CASE("Invalid_when_9_digits", "[answer]") {
    const phone_number phone("123456789");

    REQUIRE("0000000000", phone.number());
}

TEST_CASE("Has_an_area_code", "[answer]") {
    const phone_number phone("1234567890");

    REQUIRE("123", phone.area_code());
}

TEST_CASE("Formats_a_number", "[answer]") {
    const phone_number phone("1234567890");

    REQUIRE("(123) 456-7890", std::string(phone));
}
#endif
