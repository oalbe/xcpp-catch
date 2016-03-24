#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "anagram.h"

TEST_CASE("No matches", "[answer]") {
    auto subject = anagram::anagram("diaper");
    auto matches = subject.matches({"hello", "world", "zombies", "pants"});
    std::vector<std::string> expected;
    
    REQUIRE(matches == expected);
}

TEST_CASE("Detects simple anagram", "[answer]") {
    auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"tan", "stand", "at"});
    std::vector<std::string> expected{"tan"};

    REQUIRE(matches == expected);
}

TEST_CASE("Does not detect false positives", "[answer]") {
    auto subject = anagram::anagram("galea");
    auto matches = subject.matches({"eagle"});
    std::vector<std::string> expected;

    REQUIRE(matches == expected);
}

TEST_CASE("Detects multiple anagrams", "[answer]") {
    auto subject = anagram::anagram("master");
    auto matches = subject.matches({"stream", "pigeon", "maters"});
    std::vector<std::string> expected{"stream", "maters"};

    REQUIRE(matches == expected);
}

TEST_CASE("Does not detect anagram subsets", "[answer]") {
    auto subject = anagram::anagram("good");
    auto matches = subject.matches({"dog", "goody"});
    std::vector<std::string> expected;

    REQUIRE(matches == expected);
}

TEST_CASE("Detects anagram", "[answer]") {
    auto subject = anagram::anagram("listen");
    auto matches = subject.matches({"enlists", "google", "inlets", "banana"});
    std::vector<std::string> expected{"inlets"};

    REQUIRE(matches == expected);
}

TEST_CASE("Detects multiple anagrams2", "[answer]") {
    auto subject = anagram::anagram("allergy");
    auto matches = subject.matches(
        {"gallery", "ballerina", "regally", "clergy", "largely", "leading"}
    );
    std::vector<std::string> expected{"gallery", "regally", "largely"};

    REQUIRE(matches == expected);
}

TEST_CASE("Detects anagrams case insensitively", "[answer]") {
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});
    std::vector<std::string> expected{"Carthorse"};

    REQUIRE(matches == expected);
}

TEST_CASE("Does not detect a word as its own anagram", "[answer]") {
    auto subject = anagram::anagram("banana");
    auto matches = subject.matches({"Banana"});
    std::vector<std::string> expected;

    REQUIRE(matches == expected);
}

TEST_CASE("Matches accepts std::string arguments", "[answer]") {
    auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"stand", "tan", "at"});
    std::vector<std::string> expected{"tan"};

    REQUIRE(matches == expected);
}

// #if defined(EXERCISM_RUN_ALL_TESTS)
// #endif
