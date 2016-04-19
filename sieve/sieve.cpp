#include "sieve.h"


namespace sieve {

namespace {

// Takes care of initializing the sieve with all `0` values
sieve_t initialize_sieve(std::size_t limit) {
    sieve_t empty_sieve(limit, 0);
    
    empty_sieve[0] = 1;
    empty_sieve[1] = 1;

    return empty_sieve;
}

primes_t vector_convert_helper(const sieve_t& sieve) {
    primes_t output;
    
    for (std::size_t i = 0; i < sieve.size(); ++i) {
        if (0 == sieve[i]) {
            output.push_back(i);
        }
    }
    
    return output;
}

} // unnamed namespace

primes_t primes(std::size_t limit) {
    sieve_t sieve = initialize_sieve(limit);

    for (std::size_t i = 2; i * i <= limit; ++i) {
        if (1 == sieve[i]) {
            continue;
        }
        
        for (std::size_t j = i * i; j < limit; j += i) {
            sieve[j] = 1;
        }
    }
    
    return vector_convert_helper(sieve);
}

} // namespace sieve