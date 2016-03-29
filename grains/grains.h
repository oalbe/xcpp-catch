#ifndef GRAINS_H
#define GRAINS_H
#include <cmath>

namespace grains {

unsigned long long int square(std::size_t square_number) {
    return std::pow(2, square_number - 1);
}

unsigned long long int total() {
    unsigned long long int total_grains = 0;
    for (std::size_t i = 1; i < 65; ++i) {
        total_grains += square(i);
    }
    
    return total_grains;
}

} // namespace grains

#endif // GRAINS_H