#include <gtest/gtest.h>
#include <iostream>

#include "aux-functions-test.hpp"

#include "secant.hpp"


TEST(SecantTest, SecantTest_f4) {
    std::float64_t a = -1.0;
    std::float64_t b = 2.0;

    auto exp = Secant(f4, {a,b}, 0.0100f64, 100).value();

    EXPECT_NEAR(exp, 1.07881, 1e-5);
}

TEST(SecantTest, SecantTest_f5) {
    std::float64_t a = 9.0;
    std::float64_t b = 11.0;
    std::float64_t epsilon = 0.005; //tol

    auto exp = Secant(f5, {a,b}, epsilon, 100).value();

    EXPECT_NEAR(exp, 9.70384, epsilon);
}

