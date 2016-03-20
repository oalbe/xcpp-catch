#include "anagram.h"


namespace anagram {

anagram::anagram(const std::string& input) {
    sample = input;
    sample_size = sample.size();
    
    std::string lower_sample = lower(sample);
    for (char character : lower_sample) {
        ++mapped_sample[character];
    }
}

bool anagram::is_anagram(const std::string& candidate) const {
    if (sample_size != candidate.size()) {
        return false;
    }
    
    histogram_t mapped_sample_copy(mapped_sample);
    for (char character : candidate) {
        mapped_sample_copy[character] -= 1;
    }

    for (auto& pair : mapped_sample_copy) {
        if (pair.second) {
            return false;
        }
    }

    return true;
}

std::vector<std::string>
anagram::matches(const std::vector<std::string>& candidates) const {
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

std::string anagram::lower(const std::string& input_string) const {
    std::string output_str = input_string;
    std::transform(output_str.begin(), output_str.end(), output_str.begin(), ::tolower);
    
    return output_str;
}

} // namespace anagram