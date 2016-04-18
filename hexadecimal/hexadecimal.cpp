#include "hexadecimal.h"
#include <regex>
#include <cmath>
#include <algorithm>


namespace hexadecimal {

namespace {

std::string lower(std::string input_string) {
    std::transform(input_string.begin(), input_string.end(), input_string.begin(), ::tolower);
    
    return input_string;
}

bool is_legal_hex(const std::string& hex_string) {
    std::regex allowed_symbols("[0-9a-f]+", std::regex::ECMAScript);

    return std::regex_match(lower(hex_string), allowed_symbols);
}

int parse_hex_digit(char digit) {
    if (('0' <= digit) && (digit <= '9')) {
        return digit - '0';
    }
    
    return digit - 'a' + 10;
}

} // unnamed namespace

int convert(const std::string& hex_string) {
    if (!is_legal_hex(hex_string)) {
        return 0;
    }
    
    int decimal = 0;

    for (std::size_t i = hex_string.size(); i-- > 0; ) {
        decimal += parse_hex_digit(hex_string[i]) * (std::pow(16, (hex_string.size() - 1) - i));
    }

    return decimal;
}

} // namespace hexadecimal
