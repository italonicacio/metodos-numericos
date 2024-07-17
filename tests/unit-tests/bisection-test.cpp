#include <gtest/gtest.h>
#include <iostream>

#include "aux-functions-test.hpp"

#include "bisection.hpp"


TEST(BisectionTest, BisectionTest_f4) {
    std::float64_t a = -1.0;
    std::float64_t b = 2.0;

    auto exp = Bisection(f4, {a,b}, 0.0100f64, 100).value();

    EXPECT_NEAR(exp, 1.08008f64, 1e-4);
}

TEST(BisectionTest, BisectionTest_f5) {
    std::float64_t a = 10.0;
    std::float64_t b = 12.0;

    auto exp = Bisection(f5, {a,b}, 0.005f64, 100).value();

    EXPECT_NEAR(exp, 11.74609f64, 1e-4);
}
