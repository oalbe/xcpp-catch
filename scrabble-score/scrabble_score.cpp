#include "scrabble_score.h"
#include <unordered_map>
#include <algorithm>


namespace scrabble_score {

namespace {

std::unordered_map<char, int> points = {
    {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, 
    {'L', 1}, {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1},
    
    {'D', 2}, {'G', 2},
    
    {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
    
    {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
    
    {'K', 5},

    {'J', 8}, {'X', 8},
    
    {'Q', 10}, {'Z', 10}
};

} // unnamed namespace

int score(const std::string& word) {
    if (word.size() == 0) {
        return 0;
    }
    
    std::string upcase_word(word);
    std::transform(upcase_word.begin(), upcase_word.end(), upcase_word.begin(), ::toupper);
    
    int total_score = 0;
    for (const auto character : upcase_word) {
        total_score += points[character];
    }
    
    return total_score;
}

} // namespace scrabble_score