#ifndef SIEVE_H
#define SIEVE_H
#include <vector>


namespace sieve {

namespace {

using sieve_t = std::vector<int>;

} // unnamed namespace

sieve_t primes(std::size_t limit);

} // namespace sieve

#endif // SIEVE_H