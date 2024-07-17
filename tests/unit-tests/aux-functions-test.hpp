#pragma once 

#include <stdfloat>
#include <cinttypes>
#include <cmath>

// f(x) = x^2 - 2
inline std::float64_t f1(std::float64_t x) {
    return x * x - 2;
}

// f(x) = sqrt(2 + x)
inline std::float64_t f2(std::float64_t x) {
    return std::sqrt(2.0 + x);
}

// f(x) = sqrt(2 + x)
inline std::float64_t f3(std::float64_t x) {
    return std::sqrt(2.0 + x);
}

// f(x) = 2x^3 - cos(x+1) - 3
inline std::float64_t f4(std::float64_t x) {
    return 2 * pow(x, 3) - cos(x + 1) - 3;
}

// f(x) = 0.05x^3 - 0.4x^2 + 3sin(x)x
inline std::float64_t f5(std::float64_t x) {
    return 0.05 * pow(x,3) - 0.4 * pow(x,2) + 3 * sin(x) * x;
}

// P(x) = x^4 + 2x^3 - 13x^2 - 14x + 24
inline std::float64_t p1(std::float64_t x) {
    return pow(x, 4) + 2.0 * pow(x, 3) - 13.0 * pow(x,2) - 14.0 * x + 24.0;
}
