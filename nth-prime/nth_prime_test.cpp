#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include "nth_prime.h"
#include <stdexcept>
#include <chrono>
#include <iostream>


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
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();
    
    REQUIRE(104743 == prime::nth(10001));
    
    auto end = clock::now();
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
}

TEST_CASE("Even bigger prime", "[answer]") {
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();

    REQUIRE(15485863 == prime::nth(1000000));
    
    auto end = clock::now();
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
}

TEST_CASE("Weird case", "[answer]") {
    REQUIRE_THROWS_AS(prime::nth(0), std::domain_error);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
