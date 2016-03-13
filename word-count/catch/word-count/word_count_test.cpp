#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "word_count.h"
#include <map>


TEST_CASE("Counts one word", "[answer]") {
    const std::map<std::string, int> expected{{"word", 1}};
    const auto actual = word_count::words("word");

    REQUIRE(expected == actual);
}

TEST_CASE("Counts one of each", "[answer]") {
    const std::map<std::string, int> expected{{"one", 1}, {"of", 1}, {"each", 1}};
    const auto actual = word_count::words("one of each");

    REQUIRE(expected == actual);
}

TEST_CASE("Counts multiple occurrences", "[answer]") {
    const std::map<std::string, int> expected{
        {"one", 1}, {"fish", 4}, {"two", 1}, {"red", 1}, {"blue", 1}
    };
    const auto actual = word_count::words("one fish two fish red fish blue fish");

    REQUIRE(expected == actual);
}

TEST_CASE("Ignores punctuation", "[answer]") {
    const std::map<std::string, int> expected{
        {"car", 1}, {"carpet", 1}, {"as", 1}, {"java", 1}, {"javascript", 1}
    };
    const auto actual = word_count::words("car : carpet as java : javascript!!&@$%^&");

    REQUIRE(expected == actual);
}

TEST_CASE("Includes numbers", "[answer]") {
    const std::map<std::string, int> expected{{"testing", 2}, {"1", 1}, {"2", 1}};
    const auto actual = word_count::words("testing, 1, 2 testing");

    REQUIRE(expected == actual);
}

TEST_CASE("Normalizes case", "[answer]") {
    const std::map<std::string, int> expected{{"go", 3}};
    const auto actual = word_count::words("go Go GO");

    REQUIRE(expected == actual);
}

TEST_CASE("Counts constructor", "[answer]") {
    const std::map<std::string, int> expected{{"constructor", 2}};
    const auto actual = word_count::words("constructor Constructor");

    REQUIRE(expected == actual);
}

TEST_CASE("Counts multiline", "[answer]") {
    const std::map<std::string, int> expected{{"hello", 1}, {"world", 1}};
    const auto actual = word_count::words("hello\nworld");

    REQUIRE(expected == actual);
}

TEST_CASE("Count everything just once", "[answer]") {
    const std::map<std::string, int> expected{
        {"all", 2}, {"the", 2}, {"kings", 2}, {"horses", 1}, {"and", 1}, {"men", 1}
    };
    const auto actual = word_count::words("all the kings horses and all the kings men");
    
    REQUIRE(expected == actual);
}

TEST_CASE("handles cramped list", "[answer]") {
    const std::map<std::string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};
    const auto actual = word_count::words("one,two,three");

    REQUIRE(expected == actual);
}

TEST_CASE("With apostrophes", "[answer]") {
    const std::map<std::string, int> expected{{"first", 1}, {"don't", 2}, {"laugh", 1}, {"then", 1}, {"cry", 1}};
    const auto actual = word_count::words("First: don't laugh. Then: don't cry.");

    REQUIRE(expected == actual);
}

TEST_CASE("With free standing apostrophes", "[answer]") {
    const std::map<std::string, int> expected{{ "go", 3 }};
    const auto actual = word_count::words("go ' Go '' GO");

    REQUIRE(expected == actual);
}

TEST_CASE("With apostrophes as quotes", "[answer]") {
    const std::map<std::string, int> expected{{"she", 1}, {"said", 1}, {"let's", 1}, {"meet", 1}, {"at", 1}, {"twelve", 1}, {"o'clock", 1}};
    const auto actual = word_count::words("She said, 'let's meet at twelve o'clock'");

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif