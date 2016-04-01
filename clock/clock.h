#ifndef CLOCK_H
#define CLOCK_H
#include <string>


namespace date_independent {

class clock {
    int __hours;
    int __minutes;
    clock(int hours, int minutes);
public:
    static clock at(int hours, int minutes = 0);
    clock& plus(int minutes);
    clock& minus(int minutes);

    operator std::string() const;    
    bool operator==(const clock& rhs) const;
    bool operator!=(const clock& rhs) const;
};

} // namespace date_independent

#endif // CLOCK_H