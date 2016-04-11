#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "prime_factors.h"


TEST_CASE("1 yields empty", "[answer]") {
    const std::vector<int> expected{};
    const std::vector<int> actual{prime_factors::of(1)};

    REQUIRE(expected == actual);
}

TEST_CASE("2 yields 2", "[answer]") {
    const std::vector<int> expected{2};
    const std::vector<int> actual{prime_factors::of(2)};

    REQUIRE(expected == actual);
}

TEST_CASE("3 yields 3", "[answer]") {
    const std::vector<int> expected{3};
    const std::vector<int> actual{prime_factors::of(3)};

    REQUIRE(expected == actual);
}

TEST_CASE("4 yields 2 2", "[answer]") {
    const std::vector<int> expected{2, 2};
    const std::vector<int> actual{prime_factors::of(4)};

    REQUIRE(expected == actual);
}

TEST_CASE("6 yields 2 3", "[answer]") {
    const std::vector<int> expected{2, 3};
    const std::vector<int> actual{prime_factors::of(6)};

    REQUIRE(expected == actual);
}

TEST_CASE("8 yields 2 2 2", "[answer]") {
    const std::vector<int> expected{2, 2, 2};
    const std::vector<int> actual{prime_factors::of(8)};

    REQUIRE(expected == actual);
}

TEST_CASE("9 yields 3 3", "[answer]") {
    const std::vector<int> expected{3, 3};
    const std::vector<int> actual{prime_factors::of(9)};

    REQUIRE(expected == actual);
}

TEST_CASE("27 yields 3 3 3", "[answer]") {
    const std::vector<int> expected{3, 3, 3};
    const std::vector<int> actual{prime_factors::of(27)};

    REQUIRE(expected == actual);
}

TEST_CASE("625 yields 5 5 5 5", "[answer]") {
    const std::vector<int> expected{5, 5, 5, 5};
    const std::vector<int> actual{prime_factors::of(625)};

    REQUIRE(expected == actual);
}

TEST_CASE("901255 yields 5 17 23 461", "[answer]") {
    const std::vector<int> expected{5, 17, 23, 461};
    const std::vector<int> actual{prime_factors::of(901255)};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
