#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "bob.h"


TEST_CASE("Stating something", "[answer]") {
    REQUIRE("Whatever." == bob::hey("Tom-ay-to, tom-aaaah-to."));
}

TEST_CASE("Shouting", "[answer]") {
    REQUIRE("Whoa, chill out!" == bob::hey("WATCH OUT!"));
}

TEST_CASE("Asking a question", "[answer]") {
    REQUIRE("Sure." == bob::hey("Does this cryogenic chamber make me look fat?"));
}

TEST_CASE("Talking forcefully", "[answer]") {
    REQUIRE("Whatever." == bob::hey("Let's go make out behind the gym!"));
}

TEST_CASE("Using acronyms in regular speech", "[answer]") {
    REQUIRE("Whatever." == bob::hey("It's OK if you don't want to go to the DMV."));
}

TEST_CASE("Forceful questions", "[answer]") {
    REQUIRE("Whoa, chill out!" == bob::hey("WHAT THE HELL WERE YOU THINKING?"));
}

TEST_CASE("Shouting numbers", "[answer]") {
    REQUIRE("Whoa, chill out!" == bob::hey("1, 2, 3 GO!"));
}

TEST_CASE("only_numbers", "[answer]") {
    REQUIRE("Whatever." == bob::hey("1, 2, 3"));
}

TEST_CASE("Question with only numbers", "[answer]") {
    REQUIRE("Sure." == bob::hey("4?"));
}

TEST_CASE("Shouting with special characters", "[answer]") {
    REQUIRE("Whoa, chill out!" == bob::hey("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!"));
}

TEST_CASE("Shouting with no exclamation mark", "[answer]") {
    REQUIRE("Whoa, chill out!" == bob::hey("I HATE YOU"));
}

TEST_CASE("Statement containing question mark", "[answer]") {
    REQUIRE("Whatever." == bob::hey("Ending with a ? means a question."));
}

TEST_CASE("Prattling on", "[answer]") {
    REQUIRE("Sure." == bob::hey("Wait! Hang on.  Are you going to be OK?"));
}

TEST_CASE("Question with trailing whitespace", "[answer]") {
    REQUIRE("Sure." == bob::hey("Are you ok? "));
}

TEST_CASE("Silence", "[answer]") {
    REQUIRE("Fine. Be that way!" == bob::hey(""));
}

TEST_CASE("Prolonged silence", "[answer]") {
    REQUIRE("Fine. Be that way!" == bob::hey("   "));
}

TEST_CASE("Not all silence", "[answer]") {
    REQUIRE("Whatever." == bob::hey(" A bit of silence can be nice.  "));                           
}