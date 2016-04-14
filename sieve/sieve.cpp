#include "sieve.h"
#include <cmath>


namespace sieve {

namespace {

// Takes care of initializing the sieve with all `false` values
std::vector<char> initialize_sieve(std::size_t limit) {
    std::vector<char> empty_sequence(limit, 0);
    
    empty_sequence[0] = 1;
    empty_sequence[1] = 1;

    return empty_sequence;
}

// REVIEW: Should the `vector` here be passed by const reference?
sieve_t vector_convert_helper(std::vector<char> sequence) {
    sieve_t output;
    
    for (std::size_t i = 0; i < sequence.size(); ++i) {
        if (0 == sequence[i]) {
            output.push_back(i);
        }
    }
    
    return output;
}

} // unnamed namespace

sieve_t primes(std::size_t limit) {
    std::vector<char> primes_sequence = initialize_sieve(limit);
    
    // for (std::size_t i = 2; i <= std::sqrt(limit); ++i) {
    for (std::size_t i = 2; i * i <= limit; ++i) {
        if (1 == primes_sequence[i]) {
            continue;
        }
        
        for (std::size_t j = i * i; j <= limit; j += i) {
            primes_sequence[j] = 1;
        }
    }

    sieve_t converted_vector = vector_convert_helper(primes_sequence);
    
    return converted_vector;
}

} // namespace sieve