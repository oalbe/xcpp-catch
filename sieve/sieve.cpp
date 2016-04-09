#include "sieve.h"
#include <cmath>


namespace sieve {

namespace {

// Takes care of initializing the sieve with all `false` values
std::vector<bool> initialize_sieve(std::size_t limit) {
    std::vector<bool> empty_sequence(limit, false);
    
    empty_sequence[0] = true;
    empty_sequence[1] = true;

    return empty_sequence;
}

sieve_t vector_convert_helper(std::vector<bool> sequence) {
    sieve_t output;
    
    for (std::size_t i = 0; i < sequence.size(); ++i) {
        if (false == sequence[i]) {
            output.push_back(i);
        }
    }
    
    return output;
}

} // unnamed namespace

sieve_t primes(std::size_t limit) {
    std::vector<bool> primes_sequence = initialize_sieve(limit);
    
    for (std::size_t i = 2; i <= std::sqrt(limit); ++i) {
        if (true == primes_sequence[i]) {
            continue;
        }
        
        for (std::size_t j = i * i; j <= limit; j += i) {
            primes_sequence[j] = true;
        }
    }
    
    return vector_convert_helper(primes_sequence);
}

} // namespace sieve