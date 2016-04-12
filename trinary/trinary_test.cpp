#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "trinary.h"


TEST_CASE("1 yields decimal 1", "[answer]") {
    REQUIRE(1 == trinary::to_decimal("1"));
}

TEST_CASE("2 yields decimal 2", "[answer]") {
    REQUIRE(2 == trinary::to_decimal("2"));
}

TEST_CASE("10 yields decimal 3", "[answer]") {
    REQUIRE(3 == trinary::to_decimal("10"));
}

TEST_CASE("11 yields decimal 4", "[answer]") {
    REQUIRE(4 == trinary::to_decimal("11"));
}

TEST_CASE("100 yields decimal 9", "[answer]") {
    REQUIRE(9 == trinary::to_decimal("100"));
}

TEST_CASE("112 yields decimal 14", "[answer]") {
    REQUIRE(14 == trinary::to_decimal("112"));
}

TEST_CASE("222 yields decimal 26", "[answer]") {
    REQUIRE(26 == trinary::to_decimal("222"));
}

TEST_CASE("1122000120 yields decimal 32091", "[answer]") {
    REQUIRE(32091 == trinary::to_decimal("1122000120"));
}

TEST_CASE("Invalid yields decimal 0", "[answer]") {
    REQUIRE(0 == trinary::to_decimal("carrot"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
