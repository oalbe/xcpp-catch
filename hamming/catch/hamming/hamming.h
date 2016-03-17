#ifndef HAMMING_H
#define HAMMING_H

#include <string>
#include <stdexcept>
#include <numeric>


namespace hamming {
    int compute(const std::string& first_strand, const std::string& second_strand) {
        if (first_strand.size() != second_strand.size()) {
            throw std::domain_error("Strands lengths are different.");
        }
        
        return std::inner_product(first_strand.begin(), first_strand.end(), second_strand.begin(),
            0, std::plus<int>(), std::not_equal_to<int>());
    }
}

#endif // HAMMING_H