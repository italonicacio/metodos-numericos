#pragma once

#include <expected>
#include <stdfloat> 
#include <cinttypes>

#include "errors.hpp"

using Func = std::float64_t(*)(std::float64_t);
// using Expect = std::expected<std::tuple<std::float64_t, std::vector<std::float64_t>>, Error>;
using Expect = std::expected<std::float64_t, Error>;
