#include <string>
#include <stdexcept>


namespace hamming {
    std::size_t compute(std::string first_strand, std::string second_strand) {
        std::size_t difference = 0;
        
        if (first_strand.size() != second_strand.size()) {
            throw std::domain_error("Stands length is different.");
        }
        
        std::size_t strands_len = first_strand.size();
        for (std::size_t i = 0; i < strands_len; ++i) {
            if (first_strand[i] != second_strand[i]) {
                ++difference;
            }
        }
        
        return difference;
    }
}