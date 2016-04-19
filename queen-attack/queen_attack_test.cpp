#define CATCH_CONFIG_MAIN

#include "queen_attack.h"
#include "catch.hpp"


TEST_CASE("Queens in default positions", "[answer]") {
    const queen_attack::chess_board board;

    REQUIRE(std::make_pair(0, 3) == board.white());
    REQUIRE(std::make_pair(7, 3) == board.black());
}

TEST_CASE("Initialized with specific positions", "[answer]") {
    const auto white = std::make_pair(3, 7);
    const auto black = std::make_pair(6, 1);
    const queen_attack::chess_board board{white, black};

    REQUIRE(white == board.white());
    REQUIRE(black == board.black());
}

TEST_CASE("Queen positions must be distinct", "[answer]") {
    const auto pos = std::make_pair(3, 7);
    REQUIRE_THROWS_AS((queen_attack::chess_board{pos, pos}), std::domain_error);
}

TEST_CASE("String representation", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(2, 4), std::make_pair(6, 6)};

    const std::string expected{
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ W _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ B _\n"
        "_ _ _ _ _ _ _ _\n"};
    REQUIRE(expected == static_cast<std::string>(board));
}

TEST_CASE("Queens cannot attack", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(2, 3), std::make_pair(4, 7)};

    REQUIRE(!board.can_attack());
}

TEST_CASE("Queens can attack when they are on the same row", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(2, 4), std::make_pair(2, 7)};

    REQUIRE(board.can_attack());
}

TEST_CASE("Queens can attack when they are on the same column", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(5, 4), std::make_pair(2, 4)};

    REQUIRE(board.can_attack());
}

TEST_CASE("Queens can attack diagonally", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(1, 1), std::make_pair(6, 6)};

    REQUIRE(board.can_attack());
}

TEST_CASE("Queens can attack another diagonally", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(0, 6), std::make_pair(1, 7)};

    REQUIRE(board.can_attack());
}

TEST_CASE("Queens can attack yet another diagonally", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(4, 1), std::make_pair(6, 3)};

    REQUIRE(board.can_attack());
}

TEST_CASE("Queens can attack on the nw so diagonal", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(1, 6), std::make_pair(6, 1)};

    REQUIRE(board.can_attack());
}

TEST_CASE("Queens cannot attack if not on same row column or diagonal", "[answer]") {
    const queen_attack::chess_board board{std::make_pair(1, 1), std::make_pair(3, 7)};

    REQUIRE(!board.can_attack());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
