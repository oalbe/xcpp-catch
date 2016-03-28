#ifndef SPACE_AGE_H
#define SPACE_AGE_H
#include <string>


namespace space_age {

class space_age {
    unsigned long long int __seconds;
    
    double convert_helper(std::string) const;
public:
    space_age(unsigned long long int age_in_seconds);
    
    unsigned long long int seconds() const;
    
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;
};

} 

#endif // SPACE_AGE_H