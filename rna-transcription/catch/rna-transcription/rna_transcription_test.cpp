#include "rna_transcription.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

TEST_CASE("Transcribes cytidine to guanosine", "[answer]") {
    REQUIRE('G' == transcription::to_rna('C'));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Transcribes guanosine to cytidine", "[answer]") {
    REQUIRE('C' == transcription::to_rna('G'));
}

TEST_CASE("Transcribes adenosine to uracil", "[answer]") {
    REQUIRE('U' == transcription::to_rna('A'));
}

TEST_CASE("Transcribes thymidine to adenosine", "[answer]") {
    REQUIRE('A' == transcription::to_rna('T'));
}

TEST_CASE("Transcribes all dna nucleotides to their rna complements", "[answer]") {
    REQUIRE("UGCACCAGAAUU" == transcription::to_rna("ACGTGGTCTTAA"));
}
#endif
