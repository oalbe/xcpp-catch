#include "difference_of_squares.h"
#include <cstddef> // for size_t


namespace squares {

long long int square_of_sums(int limit) {
    long long int sum = 0;
    for (std::size_t i = 1; i <= limit; ++i) {
        sum += i;
    }
    
    return sum * sum;
}

long long int sum_of_squares(int limit) {
    long long int sum = 0;
    for (std::size_t i = 1; i <= limit; ++i) {
        sum += i * i;
    }
    
    return sum;
}

long long int difference(int limit) {
    return square_of_sums(limit) - sum_of_squares(limit);
}

} // namespace squares