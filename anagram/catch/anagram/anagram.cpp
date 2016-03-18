#include "anagram.h"

std::string anagram::anagram::lower(const std::string& input_string) const {
    std::string output_str = input_string;
    std::transform(output_str.begin(), output_str.end(), output_str.begin(), ::tolower);
    
    return output_str;
}

std::map<char, std::size_t> anagram::anagram::map_word(std::string sequence) const {
    std::map<char, std::size_t> mapped_sequence;
    
    std::size_t sequence_size = sequence.size();
    for (std::size_t i = 0; i < sequence_size; ++i) {
        if (mapped_sequence.count(sequence[i])) {
            mapped_sequence[sequence[i]] += 1;
        } else {
            mapped_sequence[sequence[i]] = 1;
        }
    }
    
    return mapped_sequence;
}

bool anagram::anagram::is_anagram(std::string candidate) const {
    if (sample_size != candidate.size()) {
        return false;
    }

    return map_word(candidate) == mapped_sample;
}

std::vector<std::string>
anagram::anagram::matches(const std::vector<std::string>& candidates) const {
    std::vector<std::string> __matches;
    
    std::size_t candidates_size = candidates.size();
    for (size_t i = 0; i < candidates_size; ++i) {
        std::string current = lower(candidates[i]);
        if (sample == current) {
            continue;
        }
        
        if (is_anagram(current)) {
            __matches.push_back(candidates[i]);
        }
    }
    
    return __matches;
}