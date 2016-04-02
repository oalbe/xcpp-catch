#include "difference_of_squares.h"
#include <cstddef> // for size_t


namespace squares {

namespace {

using lli_t = long long int;

} // unnamed namespace

lli_t square_of_sums(int limit) {
    lli_t sum = 0;
    for (std::size_t i = 1; i <= limit; ++i) {
        sum += i;
    }
    
    return sum * sum;
}

lli_t sum_of_squares(int limit) {
    lli_t sum = 0;
    for (std::size_t i = 1; i <= limit; ++i) {
        sum += i * i;
    }
    
    return sum;
}

lli_t difference(int limit) {
    return square_of_sums(limit) - sum_of_squares(limit);
}

} // namespace squares