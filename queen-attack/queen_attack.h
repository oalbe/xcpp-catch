#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H
#include <utility>
#include <string>


namespace queen_attack {

// REVIEW: Should this alias be defined inside the class? Can that actually be done?
using square_t = std::pair<int, int>;

class chess_board {
    square_t __white;
    square_t __black;
public:
    chess_board();
    chess_board(square_t white_queen, square_t black_queen);
    
    square_t white() const;
    square_t black() const;
    bool can_attack() const;
    operator std::string() const;
};

} // namespace queen_attack

#endif // QUEEN_ATTACK_H
