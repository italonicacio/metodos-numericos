#pragma once 


#include <vector>

#include "aux.hpp"

Expect Newton(
    Func f, 
    std::float64_t x0, 
    std::float64_t tol = 1e-10, 
    std::size_t max_iter = 100
);

Expect Newton(
    Func f, 
    std::float64_t x0, 
    std::array<std::float64_t, 2> interval,
    std::float64_t tol = 1e-10, 
    std::size_t max_iter = 100
);