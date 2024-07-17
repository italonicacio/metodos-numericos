#pragma once 


#include <vector>

#include "aux.hpp"

Expect FixedPoint(Func f, std::float64_t x0, std::float64_t tol = 1e-5, std::size_t max_iter = 70);