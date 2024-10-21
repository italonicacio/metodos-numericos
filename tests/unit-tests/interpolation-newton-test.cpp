#include <gtest/gtest.h>
#include "interpolation/newton.hpp"

TEST(NewtonInterpolationTest, LinearInterpolation) {
	std::vector<double> x = { 1.0, 2.0 };
	std::vector<double> y = { 2.0, 3.0 };
	std::vector<double> coef = Interpolation::DividedDifferences(x, y);

	double value = 1.5;
	double expected = 2.5;
	double result = Interpolation::NewtonInterpolation(x, coef, value);

	EXPECT_NEAR(result, expected, 1e-6);
}

TEST(NewtonInterpolationTest, QuadraticInterpolation) {
	std::vector<double> x = { 1.0, 2.0, 3.0 };
	std::vector<double> y = { 1.0, 4.0, 9.0 };
	std::vector<double> coef = Interpolation::DividedDifferences(x, y);

	double value = 1.5;
	double expected = 2.0;
	double result = Interpolation::NewtonInterpolation(x, coef, value);

	EXPECT_NEAR(result, expected, 1e-6);
}

TEST(NewtonInterpolationTest, CubicInterpolation) {
	std::vector<double> x = { 1.0, 2.0, 3.0, 4.0 };
	std::vector<double> y = { 1.0, 8.0, 27.0, 64.0 };
	std::vector<double> coef = Interpolation::DividedDifferences(x, y);

	double value = 2.5;
	double expected = 16.5;
	double result = Interpolation::NewtonInterpolation(x, coef, value);

	EXPECT_NEAR(result, expected, 1e-6);
}
