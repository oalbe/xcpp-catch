#ifndef SIEVE_H
#define SIEVE_H
#include <vector>


namespace sieve {

using sieve_t = std::vector<int>;

sieve_t primes(std::size_t limit);

} // namespace sieve

#endif // SIEVE_H