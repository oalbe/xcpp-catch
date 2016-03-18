#include "anagram.h"

std::string anagram::anagram::lower(const std::string& in_str) const {
    std::string output_str = in_str;
    std::transform(output_str.begin(), output_str.end(), output_str.begin(), ::tolower);
    
    return output_str;
}

std::vector<std::string>
anagram::anagram::matches(const std::vector<std::string>& candidates) const {
    std::vector<std::string> __matches;
    
    for (size_t i = 0; i < candidates.size(); ++i) {
        std::string current = lower(candidates[i]);
        if (word == current) {
            continue;
        }

        if (std::is_permutation(current.begin(), current.end(), word.begin())) {
            __matches.push_back(candidates[i]);
        }
    }
    
    return __matches;
}