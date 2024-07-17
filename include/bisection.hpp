#pragma once

#include <array>
#include "aux.hpp"

Expect Bisection(
    Func f,
    std::array<std::float64_t, 2> interval,
    std::float64_t tol = 1e-10,
    std::size_t max_iter = 100
);