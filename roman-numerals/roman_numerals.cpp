#include "roman_numerals.h"
#include <map>


namespace roman {

namespace {

// weight: { 
//     {class, value}, {class, value}
// }
std::map<int, std::map<int, char>> basic_numbers = {
    {1, {
        {1, 'I'}, {5, 'V'} 
    }},
    {2, {
        {1, 'X'}, {5, 'L'}
    }},
    {3, {
        {1, 'C'}, {5, 'D'}
    }},
    {4, {
        {1, 'M'}
    }}
};

std::string convert_digit(int digit, std::size_t weight) {
    if (!digit) {
        return "";
    }
    
    std::string roman_digit;
    if (3 >= digit) {
        for (std::size_t i = digit; i > 0; --i) {
            roman_digit += basic_numbers[weight].at(1);
        }
    } else if (4 == digit) {
        // NOTE: A trick to concatenate the two `char`s extracted from the `map` into the
        // output string through the ability of accepting initializer-lists by `append()`
        roman_digit.append({basic_numbers[weight].at(1), basic_numbers[weight].at(5)});
    } else if (5 == digit) {
        roman_digit = basic_numbers[weight].at(5);
    } else if (8 >= digit) {
        roman_digit += basic_numbers[weight].at(5);
        
        for (std::size_t i = digit; i > 5; --i) {
            roman_digit += basic_numbers[weight].at(1);
        }
    } else if (9 == digit) {
        roman_digit.append({basic_numbers[weight].at(1), basic_numbers[weight + 1].at(1)});
    }

    return roman_digit;
}

} // unnamed namespace

std::string convert(int number) {
    std::string str_number = std::to_string(number);
    
    std::string roman_number;
    size_t str_number_length = str_number.size();
    for (std::size_t i = 0; i < str_number_length; ++i) {
        std::string converted_digit = convert_digit((str_number[i] - '0'), str_number_length - i);
        
        if (!converted_digit.empty()) {
            roman_number += converted_digit;
        }
    }
    
    return roman_number;
}

} // namespace roman