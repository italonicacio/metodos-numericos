#include <cmath>

#include "bisection.hpp"

Expect Bisection(
    Func f,
    std::array<std::float64_t, 2> interval,
    std::float64_t tol,
    std::size_t max_iter
) {
    std::float64_t a = interval[0];
    std::float64_t b = interval[1];
    
    std::float64_t fa = f(a);
    if(std::abs(fa) < tol) return Expect(a);
    std::float64_t fb = f(b);
    if(std::abs(fb) < tol) return Expect(b);

    if(fa*fb > tol) return std::unexpected(Error::InvalidInterval);

    std::float64_t delta_x = std::abs(b-a) * 0.5;

    for(std::size_t iter = 0; iter < max_iter; ++iter) {
        std::float64_t x = (a + b) * 0.5;
        std::float64_t fx = f(x);
        
        if( (delta_x <= tol) || (std::abs(fx) <= tol)) {
            return Expect(x);
        }

        if(fa*fx > 0.0f64) {
            a = x;
            fa = fx;
        } else {
            b = x;
        }

        delta_x = delta_x * 0.5;

    }

    return std::unexpected(Error::MaxIter);

}