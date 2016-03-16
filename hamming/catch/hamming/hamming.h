#include <string>
#include <stdexcept>


namespace hamming {
    std::size_t compute(const std::string& first_strand, const std::string& second_strand) {
        if (first_strand.size() != second_strand.size()) {
            throw std::domain_error("Strands lengths are different.");
        }
        
        if (first_strand == second_strand) {
            return 0;
        }
        
        std::size_t difference = 0;
        std::size_t strands_len = first_strand.size();
        for (std::size_t i = 0; i < strands_len; ++i) {
            if (first_strand[i] != second_strand[i]) {
                ++difference;
            }
        }
        
        return difference;
    }
}