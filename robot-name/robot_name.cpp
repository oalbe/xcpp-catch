#include "robot_name.h"
#include <random>
#include <cstdio>
#include <unordered_set>


namespace robot_name {
    
namespace {

std::random_device rd;
std::mt19937 gen(rd());

std::string generate_name() {
    std::uniform_int_distribution<> rand_ascii('A', 'Z');
    std::uniform_int_distribution<> rand_digits(0, 999);

    char name_buffer[6]; // 5 chars for the name, 1 char for the null-termination
    std::snprintf(name_buffer, sizeof(name_buffer), "%c%c%.3i", rand_ascii(gen), rand_ascii(gen), rand_digits(gen));
    
    return std::string(name_buffer);
}
    
std::unordered_set<std::string> used_names;

} // unnamed namespace

robot::robot() {
    reset();
}

std::string robot::name() const {
    return __name;
}

void robot::reset() {
    std::string temp_name = generate_name();

    while (used_names.count(temp_name)) {
        used_names.insert(temp_name);
        temp_name = generate_name();
    }
   
    used_names.insert(temp_name);
    __name = temp_name;
}
    
} // namespace robot_name