#ifndef CLOCK_H
#define CLOCK_H
#include <string>


namespace date_independent {

namespace {

std::string format_helper(int non_formatted_input) {
    std::string output = std::to_string(non_formatted_input);
    if (output.size() == 1) {
        return "0" + output;
    }
    
    return output;
}

} // unnamed namespace

class clock {
    int __hours;
    int __minutes;
    clock(int hours, int minutes): __hours(hours), __minutes(minutes) {}
public:
    static clock at(int hours, int minutes = 0) {
        return clock(hours, minutes);
    }
    
    // TODO: Fix this, it's too garbled.
    clock& plus(int minutes) {
        int new_hours = (minutes + __minutes) / 60;
        if ((minutes + __minutes) < 0) {
            new_hours = -1 + ((minutes + __minutes) / 60);

            __minutes = 60 + ((minutes + __minutes) % 60);
        } else {
            __minutes = (minutes + __minutes) % 60;
        }

        if ((__hours + new_hours) > 23) {
            __hours = (__hours + new_hours) % 24;
        } else {
            __hours += new_hours;
        }
        
        if (__hours < 0) {
            __hours = 23;
        }
        
        return *this;
    }
    
    clock& minus(int minutes) {
        return plus(-minutes);
    }
    
    operator std::string() const {
        return format_helper(__hours) + ":" + format_helper(__minutes);
    }
    
    bool operator==(const clock& rhs) const {
        return __hours == rhs.__hours && __minutes == rhs.__minutes;
    }
    
    bool operator!=(const clock& rhs) const {
        return !operator==(rhs);
    }
};

} // namespace date_independent

#endif // CLOCK_H