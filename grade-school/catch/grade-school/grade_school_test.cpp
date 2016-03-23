#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>
#include "grade_school.h"


struct school_fixture {
    grade_school::school school_;
};

TEST_CASE_METHOD(school_fixture, "A new school has an empty roster", "[answer]") {
    REQUIRE(school_.roster().empty());
}

TEST_CASE_METHOD(school_fixture, "Adding a student adds them to the roster for the given grade", "[answer]") {
    school_.add("Aimee", 2);

    const auto actual = school_.roster();

    const std::map<int, std::vector<std::string>> expected {{2, {"Aimee"}}};
    REQUIRE(expected == actual);
}

TEST_CASE_METHOD(school_fixture, "Adding more students to the same grade adds them to the roster", "[answer]") {
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);

    const auto actual = school_.roster();

    const std::map<int, std::vector<std::string>> expected {{2, {"Blair", "James", "Paul"}}};
    REQUIRE(expected == actual);
}

TEST_CASE_METHOD(school_fixture, "Adding students to different grades adds them to the roster", "[answer]") {
    school_.add("Chelsea", 3);
    school_.add("Logan", 7);

    const auto actual = school_.roster();

    const std::map<int, std::vector<std::string>> expected {{3, {"Chelsea"}}, {7, {"Logan"}}};
    REQUIRE(expected == actual);
}

TEST_CASE_METHOD(school_fixture, "Grade returns the students in that grade in alphabetical order", "[answer]") {
    school_.add("Franklin", 5);
    school_.add("Bradley", 5);
    school_.add("Jeff", 1);

    const auto actual = school_.grade(5);

    const std::vector<std::string> expected {"Bradley", "Franklin"};
    REQUIRE(expected == actual);
}

TEST_CASE_METHOD(school_fixture, "Grade returns an empty array if there are no students in that grade", "[answer]") {
    const auto actual = school_.grade(1);

    REQUIRE(actual.empty());
}

TEST_CASE_METHOD(school_fixture, "The student names in each grade in the roster are sorted", "[answer]") {
    school_.add("Jennifer", 4);
    school_.add("Kareem", 6);
    school_.add("Christopher", 4);
    school_.add("Kyle", 3);

    const auto actual = school_.roster();

    const std::map<int, std::vector<std::string>> expected {
        {3, {"Kyle"}},
        {4, {"Christopher", "Jennifer"}},
        {6, {"Kareem"}}
    };
    
    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
