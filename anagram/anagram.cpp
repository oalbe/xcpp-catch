#include "anagram.h"
#include <algorithm>


namespace anagram {

namespace {
    std::string lower(std::string input_string) {
        std::transform(input_string.begin(), input_string.end(), input_string.begin(), ::tolower);
        
        return input_string;
    }
} // unnamed namespace

anagram::anagram(const std::string& input): sample(lower(input)) {
    for (char character : sample) {
        ++mapped_sample[character];
    }
}

bool anagram::is_anagram(const std::string& candidate) const {
    if (sample.size() != candidate.size()) {
        return false;
    }
    
    histogram_t mapped_sample_copy(mapped_sample);
    for (char character : candidate) {
        --mapped_sample_copy[character];
    }

    for (auto& pair : mapped_sample_copy) {
        if (pair.second) {
            return false;
        }
    }

    return true;
}

words_t anagram::matches(const words_t& candidates) const {
    words_t __matches;

    auto copy_lambda = [this](const std::string& s) {
        std::string low_s = lower(s);
        return (this->sample != low_s) ? this->is_anagram(low_s) : false;
    };

    std::copy_if(candidates.begin(), candidates.end(), std::back_inserter(__matches), copy_lambda);
    
    return __matches;
}

} // namespace anagram
