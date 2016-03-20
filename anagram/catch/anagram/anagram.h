#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>


namespace anagram {

typedef std::map<char, std::size_t> histogram_t;

class anagram {
    // The word against which the program tests candidate anagrams.
    std::string sample;
    std::size_t sample_size;
    
    // A map representation of the `sample` with the frequency of each character.
    histogram_t mapped_sample;
    
    std::string lower(const std::string& input_string) const;
public:
    anagram(const std::string& input);

    bool is_anagram(const std::string& candidate) const;
    std::vector<std::string> matches(const std::vector<std::string>& candidates) const;
};

} // namespace anagram

#endif // ANAGRAM_H