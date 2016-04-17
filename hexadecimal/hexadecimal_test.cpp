#define CATCH_CONFIG_MAIN
#include "hexadecimal.h"
#include "catch.hpp"


TEST_CASE("Hex 1 is decimal 1", "[answer]") {
    REQUIRE(0x1 == hexadecimal::convert("1"));
}

TEST_CASE("Hex c is decimal 12", "[answer]") {
    REQUIRE(0xc == hexadecimal::convert("c"));
}

TEST_CASE("Hex 10 is decimal 16", "[answer]") {
    REQUIRE(0x10 == hexadecimal::convert("10"));
}

TEST_CASE("Hex af is decimal 175", "[answer]") {
    REQUIRE(0xaf == hexadecimal::convert("af"));
}

TEST_CASE("Hex 100 is decimal 256", "[answer]") {
    REQUIRE(0x100 == hexadecimal::convert("100"));
}

TEST_CASE("Hex 19ace is decimal 105166", "[answer]") {
    REQUIRE(0x19ace == hexadecimal::convert("19ace"));
}

TEST_CASE("Invalid hex is decimal 0", "[answer]") {
    REQUIRE(0 == hexadecimal::convert("carrot"));
}

TEST_CASE("Black", "[answer]") {
    REQUIRE(0x000000 == hexadecimal::convert("000000"));
}

TEST_CASE("White", "[answer]") {
    REQUIRE(0xffffff == hexadecimal::convert("ffffff"));
}

TEST_CASE("Yellow", "[answer]") {
    REQUIRE(0xffff00 == hexadecimal::convert("ffff00"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
