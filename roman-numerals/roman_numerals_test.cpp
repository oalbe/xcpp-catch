#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "roman_numerals.h"


TEST_CASE("One yields I", "[answer]") {
    REQUIRE("I" == roman::convert(1));
}

TEST_CASE("Two yields II", "[answer]") {
    REQUIRE("II" == roman::convert(2));
}

TEST_CASE("Three yields III", "[answer]") {
    REQUIRE("III" == roman::convert(3));
}

TEST_CASE("Four yields IV", "[answer]") {
    REQUIRE("IV" == roman::convert(4));
}

TEST_CASE("Five yields V", "[answer]") {
    REQUIRE("V" == roman::convert(5));
}

TEST_CASE("Six yields VI", "[answer]") {
    REQUIRE("VI" == roman::convert(6));
}

TEST_CASE("Nine yields IX", "[answer]") {
    REQUIRE("IX" == roman::convert(9));
}

TEST_CASE("Twenty seven yields XXVII", "[answer]") {
    REQUIRE("XXVII" == roman::convert(27));
}

TEST_CASE("Forty eight yields XLVIII", "[answer]") {
    REQUIRE("XLVIII" == roman::convert(48));
}

TEST_CASE("Fifty nine yields LIX", "[answer]") {
    REQUIRE("LIX" == roman::convert(59));
}

TEST_CASE("Ninety three yields XCIII", "[answer]") {
    REQUIRE("XCIII" == roman::convert(93));
}

TEST_CASE("One hundred forty one yields CXLI", "[answer]") {
    REQUIRE("CXLI" == roman::convert(141));
}

TEST_CASE("One hundred sixty three yields CLXIII", "[answer]") {
    REQUIRE("CLXIII" == roman::convert(163));
}

TEST_CASE("Four hundred two yields CDII", "[answer]") {
    REQUIRE("CDII" == roman::convert(402));
}

TEST_CASE("Five hundred seventy five yields DLXXV", "[answer]") {
    REQUIRE("DLXXV" == roman::convert(575));
}

TEST_CASE("Nine hundred eleven yields CMXI", "[answer]") {
    REQUIRE("CMXI" == roman::convert(911));
}

TEST_CASE("One thousand twenty four yields MXXIV", "[answer]") {
    REQUIRE("MXXIV" == roman::convert(1024));
}

TEST_CASE("Three thousand yields MMM", "[answer]") {
    REQUIRE("MMM" == roman::convert(3000));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
