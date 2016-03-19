#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>


namespace anagram {
    class anagram {
        // The word against which the program tests candidate anagrams.
        std::string sample;
        std::size_t sample_size;
        
        // A map representation of the `sample` with the frequency of each character.
        std::map<char, std::size_t> mapped_sample;
        
        // A map representation of the `sample`, but with zeros instead of characters' frequencies.
        std::map<char, std::size_t> zero_mapped_sample;
        
        std::string lower(const std::string& input_string) const;
    public:
        anagram(const std::string input);

        bool is_anagram(const std::string candidate) const;
        std::vector<std::string> matches(const std::vector<std::string>& candidates) const;
    };
}

#endif // ANAGRAM_H