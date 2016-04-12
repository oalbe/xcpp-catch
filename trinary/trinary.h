#ifndef TRINARY_H
#define TRINARY_H
#include <string>


namespace trinary {

namespace {

bool is_legal_trinary(std::string trinary_string) {
    for (std::size_t i = 0; i < trinary_string.size(); ++i) {
        if (('0' != trinary_string[i]) && ('1' != trinary_string[i]) && ('2' != trinary_string[i])) {
            return false;
        }
    }
    
    return true;
}

} // unnamed namespace

int to_decimal(std::string trinary_string) {
    if (!is_legal_trinary(trinary_string)) {
        return 0;
    }
    
    int decimal = 0;

    for (std::size_t i = trinary_string.size(); i-- > 0; ) {
        decimal += (trinary_string[i] - '0') * (std::pow(3, (trinary_string.size() - 1) - i));
    }

    return decimal;
}

} // namespace trinary

#endif // TRINARY_H