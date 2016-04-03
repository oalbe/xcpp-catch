#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include "nth_prime.h"
#include <stdexcept>


TEST_CASE("First", "[answer]") {
    REQUIRE(2 == prime::nth(1));
}

TEST_CASE("Second", "[answer]") {
    REQUIRE(3 == prime::nth(2));
}

TEST_CASE("Sixth", "[answer]") {
    REQUIRE(13 == prime::nth(6));
}

TEST_CASE("Big prime", "[answer]") {
    REQUIRE(104743 == prime::nth(10001));
}

TEST_CASE("Weird case", "[answer]") {
    REQUIRE_THROWS_AS(prime::nth(0), std::domain_error);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
