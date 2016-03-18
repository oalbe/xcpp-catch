#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>


namespace anagram {
    class anagram {
        std::string sample;
        std::size_t sample_size;
        
        std::map<char, std::size_t> mapped_sample;
        std::size_t mapped_sample_size;
        
        std::string lower(const std::string& input_string) const;
        std::map<char, std::size_t> map_word(std::string sequence) const;
    public:
        anagram(const std::string input): 
            sample(lower(input)), 
            sample_size(sample.size()),
            mapped_sample(map_word(sample)),
            mapped_sample_size(mapped_sample.size()) {}

        bool is_anagram(std::string candidate) const;
        std::vector<std::string> matches(const std::vector<std::string>& candidates) const;
    };
}

#endif // ANAGRAM_H