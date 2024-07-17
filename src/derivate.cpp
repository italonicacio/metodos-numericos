#include <cmath>
#include <algorithm>
#include <limits>

#include "derivate.hpp"

std::float64_t Derivate(Func f, std::float64_t x) {
    std::float64_t absx = std::abs(x);
    std::float64_t h = std::cbrt(std::numeric_limits<std::float64_t>::epsilon()) * std::max(std::float64_t(1.0), absx);;
    
    return (f(x + h) - f(x - h)) / (2.0 * h);
}


