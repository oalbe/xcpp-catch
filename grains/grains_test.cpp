#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "grains.h"


TEST_CASE("Square 1", "[answer]") {
    REQUIRE(1ULL == grains::square(1));
}

TEST_CASE("Square 2", "[answer]") {
    REQUIRE(2ULL == grains::square(2));
}

TEST_CASE("Square 3", "[answer]") {
    REQUIRE(4ULL == grains::square(3));
}

TEST_CASE("Square 4", "[answer]") {
    REQUIRE(8ULL == grains::square(4));
}

TEST_CASE("Square 16", "[answer]") {
    REQUIRE(32768ULL == grains::square(16));
}

TEST_CASE("Square 32", "[answer]") {
    REQUIRE(2147483648ULL == grains::square(32));
}

TEST_CASE("Square 64", "[answer]") {
    REQUIRE(9223372036854775808ULL == grains::square(64));
}

TEST_CASE("Total", "[answer]") {
    REQUIRE(18446744073709551615ULL == grains::total());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
