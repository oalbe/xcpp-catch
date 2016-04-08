#include "sum_of_multiples.h"


namespace sum_of_multiples {

namespace {

bool multiple(std::size_t number, std::vector<int> factors) {
    for (std::size_t i = 0; i < factors.size(); ++i) {
        if ((number % factors[i]) == 0) {
            return true;
        }
    }
    
    return false;
}

} // unnamed namespace

long long int to(std::vector<int> factors, std::size_t limit) {
    long long int sum = 0;
    
    for (std::size_t i = 0; i < limit; ++i) {
        if (multiple(i, factors)) {
            sum += i;
        }
    }
    
    return sum;
}

long long int to(std::size_t limit) {
    return to({3, 5}, limit);
}

} // namespace sum_of_multiples