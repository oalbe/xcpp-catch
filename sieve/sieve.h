#ifndef SIEVE_H
#define SIEVE_H
#include <vector>


namespace sieve {

namespace {

using sieve_t = std::vector<int>;

// Takes care of initializing the sieve with all `false` values
std::vector<bool> initialize_sieve(std::size_t limit) {
    std::vector<bool> empty_sequence;
    for (std::size_t i = 0; i <= limit; ++i) {
        empty_sequence.push_back(false);
    }
    
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
    
    for (std::size_t i = 2; i <= limit; ++i) {
        if (true == primes_sequence[i]) {
            continue;
        }
        
        for (std::size_t j = i + 1; j <= limit; ++j) {
            if ((j % i) == 0) {
                primes_sequence[j] = true;
            }
        }
    }
    
    return vector_convert_helper(primes_sequence);
}

} // namespace sieve

#endif // SIEVE_H