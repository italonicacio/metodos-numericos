#include "secant.hpp"

Expect Secant(
    Func f,
    std::array<std::float64_t, 2> interval,
    std::float64_t tol,
    std::size_t max_iter 
) {
    std::float64_t a = interval[0];
    std::float64_t b = interval[1];

    std::float64_t fa = f(a);
    std::float64_t fb = f(b);

    if(std::abs(fa) < std::abs(fb)) {
        std::swap(a, b);
        std::swap(fa, fb);
    }

    std::float64_t x = b;
    std::float64_t fx = fb;

    for(std::size_t iter = 0; iter < max_iter; ++iter) {
        std::float64_t delta_x = -fx/(fb - fa) * (b - a);
        x = x + delta_x;
        fx = f(x);
 


        if(std::abs(delta_x) <= tol && std::abs(fx) <= tol) {
            return Expect(x);
        }

        
        a = b;
        fa = fb;
        b = x;
        fb = fx;
    }

    return std::unexpected(Error::MaxIter);
}