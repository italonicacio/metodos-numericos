#include <cmath>

#include "errors.hpp"
#include "fixed_point.hpp"

Expect FixedPoint(Func f, std::float64_t x0, std::float64_t tol, std::size_t max_iter) {
    std::float64_t x = x0;
    std::float64_t e = std::numeric_limits<std::float64_t>::max();
    // std::vector<std::float64_t> xp(20);

    for(std::size_t iter = 0; iter < max_iter; ++iter) {

        std::float64_t p = f(x);
        e = std::abs(x - p);
        if(e < tol) {
            return Expect(p);
        }
        
        x = p;
        
    }

    return std::unexpected(Error::MaxIter);
}