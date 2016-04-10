#include "series.h"
#include <stdexcept>


namespace series {

std::vector<int> digits(const std::string& digits_string) {
    std::vector<int> serialized;
    for (std::size_t i = 0; i < digits_string.size(); ++i) {
        serialized.push_back(digits_string[i] - '0');
    }
    
    return serialized;
}

slices_t slice(const std::string& digits_string, const std::size_t slice_size) {
    if (slice_size > digits_string.size()) {
        throw std::domain_error("Nope, note doable.");
    }
    
    slices_t slices;
    std::size_t limit = digits_string.size() - (slice_size - 1);
    for (std::size_t i = 0; i < limit; ++i) {
        std::vector<int> slice;
        for (std::size_t j = 0; j < slice_size; ++j) {
            slice.push_back(digits_string[i + j] - '0');
        }
        
        slices.push_back(slice);
        slice.clear();
    }
    
    return slices;
}

} // namespace series