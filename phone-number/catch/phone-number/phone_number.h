#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H
#include <string>
#include <regex>

#include <iostream>


class phone_number {
    std::string __number;
public:
    phone_number(std::string input): __number(input) {}
    
    std::string number() const {
        std::regex symbols_re("[\(\)\-\.\ ]", std::regex::ECMAScript);
        std::string clean_number = std::regex_replace(__number, symbols_re, "");
        
        std::size_t clean_number_len = clean_number.size();
        if (10 == clean_number_len) {
            return clean_number;
        } else if ((11 == clean_number_len) && ('1' == clean_number[0])) {
            return clean_number.substr(1);
        }
        
        return "0000000000";
    }
    
    std::string area_code() const {
        return number().substr(0, 3);
    }
    
    operator std::string() const {
        return "(" + __number.substr(0, 3) + ") " + __number.substr(3, 3) + "-" + 
           __number.substr(6);
    } 
};

#endif // PHONE_NUMBER_H