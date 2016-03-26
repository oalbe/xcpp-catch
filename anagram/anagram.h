#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>
#include <unordered_map>


namespace anagram {

using histogram_t = std::unordered_map<char, std::size_t>;
using words_t = std::vector<std::string>;

class anagram {
    // The word against which the program tests candidate anagrams.
    std::string sample;
    
    // A map representation of the `sample` with the frequency of each character.
    histogram_t mapped_sample;
public:
    anagram(const std::string& input);

    bool is_anagram(const std::string& candidate) const;
    words_t matches(const words_t& candidates) const;
};

} // namespace anagram


#endif // ANAGRAM_H