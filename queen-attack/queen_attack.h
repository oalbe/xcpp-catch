#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H
#include <utility>
#include <stdexcept>
#include <string>


namespace queen_attack {

using square_t = std::pair<int, int>;

class chess_board {
    square_t __white;
    square_t __black;
public:
    chess_board(): __white(std::make_pair(0, 3)), __black(std::make_pair(7, 3)) {}
    chess_board(square_t white_queen, square_t black_queen) {
        if (white_queen == black_queen) {
            throw std::domain_error("You can't place both queens on the same square.");
        }
        __white = white_queen;
        __black = black_queen;
    }
    
    square_t white() const {
        return __white;
    }
    
    square_t black() const {
        return __black;
    }
    
    operator std::string() const {
        std::string stringified_board;
        for (std::size_t i = 0; i < 8; ++i) {
            stringified_board += "_ _ _ _ _ _ _ _\n";
        }
        
        // REVIEW: Chose which one's best to use.
        // std::size_t white_position = ((white().first + 1) * 16) - (16 - (white().second * 2));
        // std::size_t white_position = (white().first * 16) + (white().second * 2);
        std::size_t white_position = 2 * ((white().first * 8) + white().second);
        std::size_t black_position = ((black().first + 1) * 16) - (16 - (black().second * 2));
        
        stringified_board[white_position] = 'W';
        stringified_board[black_position] = 'B';
        
        return stringified_board;
    }
    
    bool can_attack() const {
        if (white().first == black().first) {
            return true;
        }
        
        if (white().second == black().second) {
            return true;
        }
        
        // Check if they are in the same diagonal
        std::size_t deltax = white().first - black().first;
        std::size_t deltay = white().second - black().second;

        return (deltay == deltax) || (deltay == -deltax);
    }
};

} // namespace queen_attack

#endif // QUEEN_ATTACK_H
