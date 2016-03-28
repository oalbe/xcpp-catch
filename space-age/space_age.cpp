#include "space_age.h"
#include <map>
#include <string>


namespace space_age {

namespace {
    std::map<std::string, double> orbital_periods = {
        {"earth", 31557600},
        {"mercury", 7600543.81992},
        {"venus", 19414149.052176},
        {"mars", 59354032.69008},
        {"jupiter", 374355659.124},
        {"saturn", 929292362.8848},
        {"uranus", 2651370019.3296},
        {"neptune", 5200418560.032}
    };
}

space_age::space_age(unsigned long long int age_in_seconds): __seconds(age_in_seconds) {}

double space_age::convert_helper(std::string planet) const {
    return seconds() / orbital_periods[planet];
}

unsigned long long int space_age::seconds() const {
    return __seconds;
}

double space_age::on_earth() const   { return convert_helper("earth"); }
double space_age::on_mercury() const { return convert_helper("mercury"); }
double space_age::on_venus() const   { return convert_helper("venus"); }
double space_age::on_mars() const    { return convert_helper("mars"); }
double space_age::on_jupiter() const { return convert_helper("jupiter"); }
double space_age::on_saturn() const  { return convert_helper("saturn"); }
double space_age::on_uranus() const  { return convert_helper("uranus"); }
double space_age::on_neptune() const { return convert_helper("neptune"); }

} // namespace space_age