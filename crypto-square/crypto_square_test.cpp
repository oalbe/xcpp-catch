#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "crypto_square.h"


TEST_CASE("Normalize strange characters", "[answer]") {
    REQUIRE("splunk" == crypto_square::cipher("s#$%^&plunk").normalize_plain_text());
}

TEST_CASE("Normalize numbers", "[answer]") {
    REQUIRE("123go" == crypto_square::cipher("1, 2, 3 GO!").normalize_plain_text());
}

TEST_CASE("Size of small square", "[answer]") {
    REQUIRE(2U == crypto_square::cipher("1234").size());
}

TEST_CASE("Size of slightly larger square", "[answer]") {
    REQUIRE(3U == crypto_square::cipher("123456789").size());
}

TEST_CASE("Size of non perfect square", "[answer]") {
    REQUIRE(4U == crypto_square::cipher("123456789abc").size());
}

TEST_CASE("Plain text segments from phrase", "[answer]") {
    const std::vector<std::string> expected{"neverv", "exthin", "eheart", "withid", "lewoes"};
    const auto actual = crypto_square::cipher("Never vex thine heart with idle woes").plain_text_segments();

    REQUIRE(expected == actual);
}

TEST_CASE("Plain text segments from complex phrase", "[answer]") {
    const std::vector<std::string> expected{"zomg", "zomb", "ies"};
    const auto actual = crypto_square::cipher("ZOMG! ZOMBIES!!!").plain_text_segments();

    REQUIRE(expected == actual);
}

TEST_CASE("Cipher text short phrase", "[answer]") {
    REQUIRE("tasneyinicdsmiohooelntuillibsuuml"
        == crypto_square::cipher("Time is an illusion. Lunchtime doubly so.").cipher_text());
}

TEST_CASE("Cipher text long phrase", "[answer]") {
    REQUIRE("wneiaweoreneawssciliprerlneoidktcms"
        == crypto_square::cipher("We all know interspecies romance is weird.").cipher_text());
}

TEST_CASE("Normalized cipher text1", "[answer]") {
    REQUIRE("msemoa anindn inndla etltsh ui"
        == crypto_square::cipher("Madness, and then illumination.").normalized_cipher_text());
}

TEST_CASE("Normalized cipher text2", "[answer]") {
    REQUIRE("vrela epems etpao oirpo"
        == crypto_square::cipher("Vampires are people too!").normalized_cipher_text());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
