#ifndef PRIME_FACTORS_H
#define PRIME_FACTORS_H


namespace prime_factors {

std::vector<int> of(int number) {
    std::vector<int> factors;
    for (std::size_t i = 2; i <= number; ++i) {
        if (0 == (number % i)) {
            factors.push_back(i);
            
            number /= i;
            i = 1;
        }
    }
    
    return factors;
}

} // namespace prime_factors

#endif // PRIME_FACTORS_H