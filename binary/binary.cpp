#include "binary.h"
#include <cmath>


namespace binary {

namespace {

bool is_valid_binary(const std::string& binary_string) {
    for (std::size_t i = 0; i < binary_string.size(); ++i) {
        if (('0' != binary_string[i]) && ('1' != binary_string[i])) {
            return false;
        }
    }
    
    return true;
}

} // unnamed namespace

int convert(const std::string& binary_string) {
    if (!is_valid_binary(binary_string)) {
        return 0;
    }
    
    int decimal = 0;

    for (std::size_t i = binary_string.size(); i-- > 0; ) {
        decimal += (binary_string[i] - '0') * (std::pow(2, (binary_string.size() - 1) - i));
    }

    return decimal;
}

} // namespace binary