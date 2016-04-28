#include "queen_attack.h"
#include <stdexcept>


namespace queen_attack {

chess_board::chess_board():
    __white(std::make_pair(0, 3)), __black(std::make_pair(7, 3)) {}

chess_board::chess_board(square_t white_queen, square_t black_queen) {
    if (white_queen == black_queen) {
        throw std::domain_error("You can't place both queens on the same square.");
    }
    
    __white = white_queen;
    __black = black_queen;
}

square_t chess_board::white() const { return __white; }
square_t chess_board::black() const { return __black; }

chess_board::operator std::string() const {
    std::string stringified_board;
    for (std::size_t i = 0; i < 8; ++i) {
        stringified_board += "_ _ _ _ _ _ _ _\n";
    }
    
    std::size_t white_position = 2 * ((white().first * 8) + white().second);
    std::size_t black_position = 2 * ((black().first * 8) + black().second);
    
    stringified_board[white_position] = 'W';
    stringified_board[black_position] = 'B';
    
    return stringified_board;
}

bool chess_board::can_attack() const {
    if (white().first == black().first) {
        return true;
    }
    
    if (white().second == black().second) {
        return true;
    }
    
    // Check if they are in the same diagonal
    std::size_t deltax = white().first - black().first;
    std::size_t deltay = white().second - black().second;

    // REVIEW: This can be split into two `if`s, but is it worth it?
    return (deltay == deltax) || (deltay == -deltax);
}

} // namespace queen_attack