#include "anagram.h"


anagram::anagram::anagram(const std::string input) {
    sample = input;
    sample_size = sample.size();
    
    std::string lower_sample = lower(sample);
    for (char character : lower_sample) {
        if (mapped_sample.count(character)) {
            mapped_sample[character] += 1;
        } else {
            mapped_sample[character] = 1;
            zero_mapped_sample[character] = 0;
        }
    }
}

bool anagram::anagram::is_anagram(const std::string candidate) const {
    if (sample_size != candidate.size()) {
        return false;
    }
    
    std::map<char, std::size_t> mapped_sample_copy(mapped_sample);
    for (char character : candidate) {
        mapped_sample_copy[character] -= 1;
    }

    return zero_mapped_sample == mapped_sample_copy;
}

std::vector<std::string>
anagram::anagram::matches(const std::vector<std::string>& candidates) const {
    std::vector<std::string> __matches;
    
    std::string lower_sample = lower(sample);
    for (std::string candidate : candidates) {
        std::string current = lower(candidate);
        
        if (lower_sample == current) {
            continue;
        }
        
        if (is_anagram(current)) {
            __matches.push_back(candidate);
        }
    }
    
    return __matches;
}

std::string anagram::anagram::lower(const std::string& input_string) const {
    std::string output_str = input_string;
    std::transform(output_str.begin(), output_str.end(), output_str.begin(), ::tolower);
    
    return output_str;
}