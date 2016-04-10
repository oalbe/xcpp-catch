#ifndef SERIES_H
#define SERIES_H
#include <vector>
#include <string>


namespace series {

namespace {

using slices_t = std::vector<std::vector<int>>;

} // unnamed namespace

std::vector<int> digits(const std::string& digits_string);
slices_t slice(const std::string& digits_string, const std::size_t slice_size);

} // namespace series

#endif // SERIES_H