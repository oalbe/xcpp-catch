#include "robot_name.h"
#include <random>
#include <algorithm>

// #include <iostream>


namespace robot_name {
    
namespace {

std::string generate_name() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rand_ascii(65, 90);
    std::uniform_int_distribution<> rand_digit(0, 999);
    
    char first_letter = rand_ascii(gen);
    char second_letter = rand_ascii(gen);
    int digits = rand_digit(gen);

    std::string str_digits = std::to_string(digits);
    if (100 > digits) {
        str_digits = (2 == str_digits.size()) ? ("0" + str_digits) : ("00" + str_digits);
    }

    return first_letter + (second_letter + str_digits);
}
    
std::vector<std::string> used_names;

} // unnamed namespace

robot::robot() {
    reset();
}

std::string robot::name() const {
    return __name;
}

void robot::reset() {
    std::string temp_name = generate_name();

    if (used_names.size() > 0) {
        while (
            std::find(used_names.begin(), used_names.end(), temp_name) != std::end(used_names)) {
            used_names.push_back(temp_name);
            temp_name = generate_name();
        }
    }
   
    used_names.push_back(temp_name);
    __name = temp_name;
}
    
} // namespace robot_name