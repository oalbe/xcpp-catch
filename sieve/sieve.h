#ifndef SIEVE_H
#define SIEVE_H
#include <vector>


namespace sieve {

using primes_t = std::vector<int>;
using sieve_t = std::vector<char>;

primes_t primes(std::size_t limit);

} // namespace sieve

#endif // SIEVE_H