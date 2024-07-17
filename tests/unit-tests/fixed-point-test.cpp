#include <gtest/gtest.h>
#include <iostream>

#include "aux-functions-test.hpp"

#include "fixed_point.hpp"


TEST(FixedPointTest, FixedPointTest_f1) {
    std::float64_t x0 = 2.5;
    auto exp = FixedPoint(f1, x0);

    EXPECT_FALSE(exp.has_value());
}

TEST(FixedPointTest, FixedPointTest_f2) {
    std::float64_t x0 = 2.5;
    auto exp = FixedPoint(f2, x0);

    EXPECT_NEAR(exp.value(), 2.0, 1e-5);
}

TEST(FixedPointTest, FixedPointTest_f3) {
    std::float64_t x0 = 2.5;
    auto exp = FixedPoint(f3, x0);

    EXPECT_NEAR(exp.value(), 2.0, 1e-5);
}