#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "binary.h"


TEST_CASE("B1 is decimal 1", "[answer]") {
    REQUIRE(1 == binary::convert("1"));
}

TEST_CASE("B10 is decimal 2", "[answer]") {
    REQUIRE(2 == binary::convert("10"));
}

TEST_CASE("B11 is decimal 3", "[answer]") {
    REQUIRE(3 == binary::convert("11"));
}

TEST_CASE("B100 is decimal 4", "[answer]") {
    REQUIRE(4 == binary::convert("100"));
}

TEST_CASE("B1001 is decimal 9", "[answer]") {
    REQUIRE(9 == binary::convert("1001"));
}

TEST_CASE("B11010 is decimal 26", "[answer]") {
    REQUIRE(26 == binary::convert("11010"));
}

TEST_CASE("B10001101000 is decimal 1128", "[answer]") {
    REQUIRE(1128 == binary::convert("10001101000"));
}

TEST_CASE("Carrot is decimal 0", "[answer]") {
    REQUIRE(0 == binary::convert("convert"));
}

TEST_CASE("X1100101b is decimal 0", "[answer]") {
    REQUIRE(0 == binary::convert("1100101b"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
