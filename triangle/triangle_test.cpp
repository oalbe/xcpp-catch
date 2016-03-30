#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include "triangle.h"
#include <stdexcept>


TEST_CASE("Equilateral triangles have equal sides", "[answer]") {
    REQUIRE(triangle::equilateral == triangle::kind(2, 2, 2));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Larger equilateral triangles also have equal sides", "[answer]") {
    REQUIRE(triangle::equilateral == triangle::kind(10, 10, 10));
}

TEST_CASE("Isosceles triangles have last two sides equal", "[answer]") {
    REQUIRE(triangle::isosceles == triangle::kind(3, 4, 4));
}

TEST_CASE("Isosceles triangles have first and last sides equal", "[answer]") {
    REQUIRE(triangle::isosceles == triangle::kind(4, 3, 4));
}

TEST_CASE("Isosceles triangles have first two sides equal", "[answer]") {
    REQUIRE(triangle::isosceles == triangle::kind(4, 4, 3));
}

TEST_CASE("Isosceles triangles have in fact exactly two sides equal", "[answer]") {
    REQUIRE(triangle::isosceles == triangle::kind(10, 10, 2));
}

TEST_CASE("Scalene triangles have no equal sides", "[answer]") {
    REQUIRE(triangle::scalene == triangle::kind(3, 4, 5));
}

TEST_CASE("Scalene triangles have no equal sides at a larger scale too", "[answer]") {
    REQUIRE(triangle::scalene == triangle::kind(10, 11, 12));
}

TEST_CASE("Scalene triangles have no equal sides in descending order either", "[answer]") {
    REQUIRE(triangle::scalene == triangle::kind(5, 4, 2));
}

TEST_CASE("Very small triangles are legal", "[answer]") {
    REQUIRE(triangle::scalene == triangle::kind(0.4, 0.6, 0.3));
}

// TEST_CASE("Triangles with no size are illegal", "[answer]") {
//     REQUIRE_THROW ==(triangle::kind(0, 0, 0), std::domain_error);
// }

// TEST_CASE("Triangles with negative sides are illegal", "[answer]") {
//     REQUIRE_THROW ==(triangle::kind(3, 4, -5), std::domain_error);
// }

// TEST_CASE("Triangles violating triangle inequality are illegal", "[answer]") {
//     REQUIRE_THROW ==(triangle::kind(1, 1, 3), std::domain_error);
// }

// TEST_CASE("Medium triangles violating triangle inequality are illegal", "[answer]") {
//     REQUIRE_THROW ==(triangle::kind(2, 4, 2), std::domain_error);
// }

// TEST_CASE("Larger triangles violating triangle inequality are illegal", "[answer]") {
//     REQUIRE_THROW ==(triangle::kind(7, 3, 2), std::domain_error);
// }
#endif
