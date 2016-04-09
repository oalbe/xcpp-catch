#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <stdexcept>


namespace triangle {

namespace {

bool is_legal(double hy, double cg, double cl) {
    return hy < (cg + cl) && cg < (hy + cl) && cl < (hy + cg);
}

} // unnamed namespace

enum triangle_kind {
    equilateral,
    isosceles,
    scalene
};

triangle_kind kind(double hy, double cg, double cl) {
    if (!is_legal(hy, cg, cl)) {
        throw std::domain_error("Numbers don't form a well-made triangle.");
    }
    
    if ((hy <= 0) || (cg <= 0) || (cl <= 0)) {
        throw std::domain_error("No zero sides allowed.");
    }
    
    if ((hy == cg) && (cg == cl)) {
        return equilateral;
    }
    
    if ((hy == cg) || (cg == cl) || (hy == cl)) {
        return isosceles;
    }
    
    return scalene;
}

} // namespace triangle

#endif // TRIANGLE_H