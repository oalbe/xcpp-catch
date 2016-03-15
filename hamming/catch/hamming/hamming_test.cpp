#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "hamming.h"
#include <stdexcept>

TEST_CASE("No difference between identical strands", "[answer]") {
    REQUIRE(0 == hamming::compute("A", "A"));
}

TEST_CASE("Complete hamming distance for single nucleotide strand", "[answer]") {
    REQUIRE(1 == hamming::compute("A", "G"));
}

TEST_CASE("Complete hamming distance for small strand", "[answer]") {
    REQUIRE(2 == hamming::compute("AG", "CT"));
}

TEST_CASE("Small hamming distance", "[answer]") {
    REQUIRE(1 == hamming::compute("AT", "CT"));
}

TEST_CASE("Small hamming distance in longer strand", "[answer]") {
    REQUIRE(1 == hamming::compute("GGACG", "GGTCG"));
}

TEST_CASE("Domain error when first string is longer", "[answer]") {
    REQUIRE_THROWS_AS(hamming::compute("AAAG", "AAA"), std::domain_error);
}

TEST_CASE("Domain error when second string is longer", "[answer]") {
    REQUIRE_THROWS_AS(hamming::compute("AAA", "AAAG"), std::domain_error);
}

TEST_CASE("Large hamming distance", "[answer]") {
    REQUIRE(4 == hamming::compute("GATACA", "GCATAA"));
}

TEST_CASE("Hamming distance in very long strand", "[answer]") {
    REQUIRE(9 == hamming::compute("GGACGGATTCTG", "AGGACGGATTCT"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
