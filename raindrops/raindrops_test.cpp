#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "raindrops.h"


TEST_CASE("One yields itself", "[answer]") {
    REQUIRE("1" == raindrops::convert(1));
}

TEST_CASE("Three yields pling", "[answer]") {
    REQUIRE("Pling" == raindrops::convert(3));
}

TEST_CASE("Five yields plang", "[answer]") {
    REQUIRE("Plang" == raindrops::convert(5));
}

TEST_CASE("Seven yields plong", "[answer]") {
    REQUIRE("Plong" == raindrops::convert(7));
}

TEST_CASE("Six yields pling", "[answer]") {
    REQUIRE("Pling" == raindrops::convert(6));
}

TEST_CASE("Nine yields pling", "[answer]") {
    REQUIRE("Pling" == raindrops::convert(9));
}

TEST_CASE("Ten yields plang", "[answer]") {
    REQUIRE("Plang" == raindrops::convert(10));
}

TEST_CASE("Fourteen yields plong", "[answer]") {
    REQUIRE("Plong" == raindrops::convert(14));
}

TEST_CASE("Fifteen yields plingplang", "[answer]") {
    REQUIRE("PlingPlang" == raindrops::convert(15));
}

TEST_CASE("Twenty one yields plingplong", "[answer]") {
    REQUIRE("PlingPlong" == raindrops::convert(21));
}

TEST_CASE("Twenty five yields plang", "[answer]") {
    REQUIRE("Plang" == raindrops::convert(25));
}

TEST_CASE("Thirty five yields plangplong", "[answer]") {
    REQUIRE("PlangPlong" == raindrops::convert(35));
}

TEST_CASE("Forty nine yields plong", "[answer]") {
    REQUIRE("Plong" == raindrops::convert(49));
}

TEST_CASE("Fifty two yields itself", "[answer]") {
    REQUIRE("52" == raindrops::convert(52));
}

TEST_CASE("One hundred five yields plingplangplong", "[answer]") {
    REQUIRE("PlingPlangPlong" == raindrops::convert(105));
}

TEST_CASE("Big prime yields itself", "[answer]") {
    REQUIRE("12121" == raindrops::convert(12121));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
