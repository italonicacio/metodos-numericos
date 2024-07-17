#include "newton.hpp"
#include "derivate.hpp"


Expect Newton(
    Func f,
    std::float64_t x0, 
    std::float64_t tol, 
    std::size_t max_iter
) {
    std::float64_t fx = f(x0);
    std::float64_t dfx = Derivate(f, x0);
    std::float64_t x = x0;

    for(std::size_t iter = 0; iter < max_iter; ++iter) {
        std::float64_t delta_x = -fx/dfx;
        x = x + delta_x;

        fx = f(x);
        dfx = Derivate(f, x);
        

        if(dfx <= tol) {
            return Expect(x);
        }



        if(std::abs(delta_x) <= tol && std::abs(fx) <= tol) {
            return Expect(x);
        }



    }

    return std::unexpected(Error::MaxIter);
}

Expect Newton(
    Func f,
    std::float64_t x0,
    std::array<std::float64_t, 2> interval,
    std::float64_t tol, 
    std::size_t max_iter
) {
    std::float64_t a = interval[0];
    std::float64_t b = interval[1];

    std::float64_t fx = f(x0);
    std::float64_t dfx = Derivate(f, x0);
    std::float64_t x = x0;

    if(x < a || x > b) {
        return std::unexpected(Error::InvalidInterval);
    }


    for(std::size_t iter = 0; iter < max_iter; ++iter) {
        std::float64_t delta_x = -fx/dfx;
        x = x + delta_x;
        fx = f(x);
        dfx = Derivate(f, x);

        if(dfx <= tol) {
            return Expect(x);
        }


        if(std::abs(delta_x) <= tol && std::abs(fx) <= tol) {
            return Expect(x);
        }

    }

    return std::unexpected(Error::MaxIter);
}
