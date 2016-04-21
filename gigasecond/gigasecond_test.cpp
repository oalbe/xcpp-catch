#define CATCH_CONFIG_MAIN

#include "gigasecond.h"
#include "catch.hpp"


// See <http://www.boost.org/doc/libs/1_55_0/doc/html/date_time.html>
// for documentation on boost::gregorian::date

TEST_CASE("Test 1", "[answer]") {
    const auto actual = gigasecond::advance(boost::gregorian::date(2011, 4, 26));

    const boost::gregorian::date expected(2043, 1, 2);
    REQUIRE(expected == actual);
}

TEST_CASE("Test 2", "[answer]") {
    const auto actual = gigasecond::advance(boost::gregorian::date(1977, 6, 14));

    const boost::gregorian::date expected(2009, 2, 20);
    REQUIRE(expected == actual);
}

TEST_CASE("Test 3", "[answer]") {
    const auto actual = gigasecond::advance(boost::gregorian::date(1959, 7, 20));

    const boost::gregorian::date expected(1991, 3, 28);
    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
