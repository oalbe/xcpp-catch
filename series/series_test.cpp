#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "series.h"
#include <stdexcept>


TEST_CASE("Short digits", "[answer]") {
    const std::vector<int> expected{0, 1, 2, 3, 4, 5};
    const std::vector<int> actual{series::digits("012345")};

    REQUIRE(actual == expected);
}

TEST_CASE("Long digits", "[answer]") {
    const std::vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const std::vector<int> actual{series::digits("0123456789")};

    REQUIRE(actual == expected);
}

TEST_CASE("Keeps the digit order if reversed", "[answer]") {
    const std::vector<int> expected{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    const std::vector<int> actual{series::digits("9876543210")};

    REQUIRE(actual == expected);
}

TEST_CASE("Keeps arbitrary digit order", "[answer]") {
    const std::vector<int> expected{9, 3, 6, 9, 2, 3, 4, 6, 8};
    const std::vector<int> actual{series::digits("936923468")};

    REQUIRE(actual == expected);
}

TEST_CASE("Can slice by 1", "[answer]") {
    const std::vector<std::vector<int>> expected{{0}, {1}, {2}, {3}, {4}};
    const std::vector<std::vector<int>> actual{series::slice("01234", 1)};

    REQUIRE(actual == expected);
}

TEST_CASE("Can slice by 2", "[answer]") {
    const std::vector<std::vector<int>> expected{
        {9, 8}, {8, 2}, {2, 7}, {7, 3}, {3, 4}, {4, 6}, {6, 3}
    };
    const std::vector<std::vector<int>> actual{series::slice("98273463", 2)};

    REQUIRE(actual == expected);
}

TEST_CASE("Can slice by 3", "[answer]") {
    const std::vector<std::vector<int>> expected{{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};
    const std::vector<std::vector<int>> actual{series::slice("01234", 3)};

    REQUIRE(actual == expected);
}

TEST_CASE("Can slice by 3 with duplicate digits", "[answer]") {
    const std::vector<std::vector<int>> expected{{3, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    const std::vector<std::vector<int>> actual{series::slice("31001", 3)};

    REQUIRE(actual == expected);
}

TEST_CASE("Can slice by 4", "[answer]") {
    const std::vector<std::vector<int>> expected{{3, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    const std::vector<std::vector<int>> actual{series::slice("31001", 3)};

    REQUIRE(actual == expected);
}

TEST_CASE("Can slice by 5", "[answer]") {
    const std::vector<std::vector<int>> expected{{8, 1, 2, 2, 8}};
    const std::vector<std::vector<int>> actual{series::slice("81228", 5)};

    REQUIRE(actual == expected);
}

TEST_CASE("Domain error if not enough digits to slice", "[answer]") {
    REQUIRE_THROWS_AS(series::slice("01032987583", 12), std::domain_error);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
