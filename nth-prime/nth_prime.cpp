#include "nth_prime.h"
#include <cmath>
#include <stdexcept>


namespace prime {

namespace {

bool is_prime(uint_fast64_t test) {
    uint_fast64_t limit = static_cast<uint_fast64_t>(std::sqrt(test) + 1);
    
    for (std::size_t i = 3; i < limit; i += 2) {
        if ((test % i) == 0) {
            return false;
        }
    }
    
    return true;
}

} // unnamed namespace

uint_fast64_t nth(std::size_t index) {
    if (0 == index) {
        throw std::domain_error("Seriously? You want the zero-th prime?");
    }
    
    if (1 == index) {
        return 2;
    }
    
    uint_fast64_t possible_prime = 3;

    std::size_t i = 1;
    while (i < index) {
        if (is_prime(possible_prime)) {
            ++i;
        }
        
        possible_prime += 2;
    }

    return possible_prime - 2;
}

} // namespace prime
