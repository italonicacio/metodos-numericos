#include <gtest/gtest.h>
#include <iostream>

#include "aux-functions-test.hpp"

#include "newton.hpp"


TEST(NewtonTest, NewtonTest_p1) {

    std::float64_t x0 = 4.0;
    std::float64_t epsilon = 1e-5;

    auto exp = Newton(p1, x0, epsilon, 100).value();

    EXPECT_NEAR(exp, 3.00000, epsilon);
}

TEST(NewtonTest, NewtonTest_p1_2) {

    std::float64_t x0 = 0.4;
    std::float64_t epsilon = 1e-5;

    auto exp = Newton(p1, x0, epsilon, 100).value();

    EXPECT_NEAR(exp, 1.11056, epsilon);
}

