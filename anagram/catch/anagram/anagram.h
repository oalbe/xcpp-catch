#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


namespace anagram {

typedef std::unordered_map<char, std::size_t> histogram_t;
typedef std::vector<std::string> words_t;

class anagram {
    // The word against which the program tests candidate anagrams.
    std::string sample;
    std::size_t sample_size;
    
    // A map representation of the `sample` with the frequency of each character.
    histogram_t mapped_sample;
public:
    anagram(const std::string& input);

    bool is_anagram(const std::string& candidate) const;
    words_t matches(const std::vector<std::string>& candidates) const;
};

} // namespace anagram

namespace {
    std::string lower(const std::string& input_string);
} // unnamed namespace

#endif // ANAGRAM_H