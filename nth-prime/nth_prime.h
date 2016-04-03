#ifndef NTH_PRIME_H
#define NTH_PRIME_H
#include <cmath>
// #include <stdexcept>


namespace prime {

namespace {

using lli_t = long long int;

bool is_prime(lli_t test) {
    lli_t limit = static_cast<lli_t>(std::sqrt(test) + 1);
    
    for (std::size_t i = 3; i < limit; i += 2) {
        if ((test % i) == 0) {
            return false;
        }
    }
    
    return true;
}

} // unnamed namespace

lli_t nth(lli_t index) {
    if (0 == index) {
        throw std::domain_error("Seriously? You want the zero-th prime?");
    }
    
    if (1 == index) {
        return 2;
    }
    
    lli_t possible_prime = 3;

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

#endif // NTH_PRIME_H