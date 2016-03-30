#ifndef RAINDROPS_H
#define RAINDROPS_H
#include <string>


namespace raindrops {

std::string convert(int number) {
    if (1 == number) {
        return "1";
    }
    
    std::string output;
    if ((number % 3) == 0) {
        output += "Pling";
    }
    
    if ((number % 5) == 0) {
        output += "Plang";
    }
    
    if ((number % 7) == 0) {
        output += "Plong";
    }
    
    if (output.empty()) {
        return std::to_string(number);
    }
    
    return output;
}

} // namespace raindrops

#endif // RAINDROPS_H