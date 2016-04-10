#ifndef BOB_H
#define BOB_H
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp> // for boost::trim
#include <regex>


namespace bob {

std::string hey(std::string message) {
    boost::trim(message);
    if (message.empty()) {
        return "Fine. Be that way!";
    }
    
    std::string upperMess = message;
    std::transform(upperMess.begin(), upperMess.end(), upperMess.begin(), ::toupper);
    
    std::regex uppercase_regex("[A-Z]");
    if (std::regex_search(message, uppercase_regex) && (message == upperMess)) {
        return "Whoa, chill out!";
    }
    
    if ('?' == message.back()) {
        return "Sure.";
    }
    
    return "Whatever.";
}

} // namespace bob

#endif // BOB_H