#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "nucleotide_count.h"
#include <stdexcept>


TEST_CASE("Has no nucleotides", "[answer]") {
    const dna::counter dna("");
    const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

TEST_CASE("Has no adenosine", "[answer]") {
    const dna::counter dna("");

    REQUIRE(0 == dna.count('A'));
}

TEST_CASE("Repetitive cytidine gets counts", "[answer]") {
    const dna::counter dna("CCCCC");

    REQUIRE(5 == dna.count('C'));
}

TEST_CASE("Repetitive sequence has only guanosine", "[answer]") {
    const dna::counter dna("GGGGGGGG");
    const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 8} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

TEST_CASE("Counts only thymidine", "[answer]") {
    const dna::counter dna("GGGGTAACCCGG");

    REQUIRE(1 == dna.count('T'));
}

TEST_CASE("Counts a nucleotide only once", "[answer]") {
    const dna::counter dna("GGTTGG");

    dna.count('T');

    REQUIRE(2 == dna.count('T'));
}

TEST_CASE("Validates nucleotides", "[answer]") {
    const dna::counter dna("GGTTGG");

    REQUIRE_THROWS_AS(dna.count('X'), std::invalid_argument);
}

TEST_CASE("Counts all nucleotides", "[answer]") {
    const dna::counter dna("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");
    std::map<char, int> expected{ {'A', 20}, {'T', 21}, {'G', 17}, {'C', 12} };

    auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
