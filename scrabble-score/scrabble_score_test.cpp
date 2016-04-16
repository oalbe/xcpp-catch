#define CATCH_CONFIG_MAIN
#include "scrabble_score.h"
#include "catch.hpp"


TEST_CASE("Scores an empty word as zero", "[answer]") {
    REQUIRE(0 == scrabble_score::score(""));
}

TEST_CASE("Scores a very short word", "[answer]") {
    REQUIRE(1 == scrabble_score::score("a"));
}

TEST_CASE("Scores the word by the number of letters", "[answer]") {
    REQUIRE(6 == scrabble_score::score("street"));
}

TEST_CASE("Scores more complicated words with more", "[answer]") {
    REQUIRE(22 == scrabble_score::score("quirky"));
}

TEST_CASE("Scores case insensitive words", "[answer]") {
    REQUIRE(20 == scrabble_score::score("MULTIBILLIONAIRE"));
}

TEST_CASE("Scores z word", "[answer]") {
    REQUIRE(12 == scrabble_score::score("zoo"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
