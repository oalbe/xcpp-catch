#include "crypto_square.h"
#include <regex>
#include <cmath>


namespace crypto_square {

namespace {
    std::string lower(std::string input_string) {
        std::transform(input_string.begin(), input_string.end(), input_string.begin(), ::tolower);
        
        return input_string;
    }
} // unnamed namespace

std::string cipher::normalize_text_helper() {
    std::regex symbols_re("[,\.!&@#$%\^:\ ]+", std::regex::ECMAScript);
    std::string no_symbols = std::regex_replace(__plain_text, symbols_re, "");
    
    __normalized_text = lower(no_symbols);
    return lower(no_symbols);
}

cipher::cipher(std::string input):
    __plain_text(input), __normalized_text(normalize_text_helper()) {}

std::string cipher::normalize_plain_text() const {
    return __normalized_text;
}

std::size_t cipher::size() const {
    return static_cast<std::size_t>(std::ceil(std::sqrt(normalize_plain_text().size())));
}

std::vector<std::string> cipher::plain_text_segments() const {
    std::vector<std::string> segmented_text;
    
    float nts = static_cast<float>(__normalized_text.size());
    float s = static_cast<float>(size());
    
    std::size_t loops = static_cast<std::size_t>(std::ceil(nts / s));
    for (std::size_t i = 0; i < loops; ++i) {
        std::size_t begin = i * size();
        
        segmented_text.push_back(__normalized_text.substr(begin, size()));
    }
    
    return segmented_text;
}

std::string cipher::normalized_cipher_text() const {
    std::string normalized_encrypted_text;
    std::string encrypted_text = cipher_text();
    
    float nts = static_cast<float>(encrypted_text.size());
    float s = static_cast<float>(size());
    
    std::size_t loops = static_cast<std::size_t>(std::ceil(nts / s));
    for (std::size_t i = 0; i < loops; ++i) {
        std::size_t begin = i * size();
        
        normalized_encrypted_text += encrypted_text.substr(begin, size()) + ' ';
    }
    
    return normalized_encrypted_text.erase(normalized_encrypted_text.size() - 1, 1);
}

std::string cipher::cipher_text() const {
    std::string encrypted_text;
    std::vector<std::string> plain_segments = plain_text_segments();
    
    std::size_t segment_len = plain_segments[0].size();
    for (std::size_t j = 0; j < segment_len; ++j) {
        for (std::size_t i = 0; i < plain_segments.size(); ++i) {
            if (j < plain_segments[i].size()) {
                encrypted_text += plain_segments[i][j];
            }
        }
    }

    return encrypted_text;
}

} // namespace crypto_square