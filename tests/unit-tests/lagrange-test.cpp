#include <gtest/gtest.h>
#include <iostream>

#include "interpolation/lagrange.hpp"




TEST(Lagrange1Test, InterpolationTest) {
	std::vector<std::float64_t> x = { 0.84, 3.46, 6, 9 };
	std::vector<std::float64_t> y = { 0.64, 3.2, -1, 4 };

	Lagrange<std::float64_t> lagrange(x, y);

	EXPECT_NEAR(lagrange(0.84), 0.64, 1e-10);
	EXPECT_NEAR(lagrange(3.46), 3.2, 1e-10);
	EXPECT_NEAR(lagrange(6), -1, 1e-10);
	EXPECT_NEAR(lagrange(9), 4, 1e-10);

	EXPECT_NEAR(lagrange(5), 0.5678817, 1e-6);
}

TEST(Lagrange2Test, InterpolationTest) {
	std::vector<std::float64_t> x = { 9.0, 34.2, 79.1, 145.8, 235.9, 350.7 };
	std::vector<std::float64_t> y = { 2.9, 4.7, 6.5, 8.3, 10.1, 11.9 };

	Lagrange<std::float64_t> lagrange(x, y);

	for(std::size_t i = 0; i < x.size(); i++) {
		EXPECT_NEAR(lagrange(x[i]), y[i], 1e-10);
	}

	// This lagrange evaluate to 7.258..., so we expect 7.3
	// This is a good example of the error that can be introduced by the lagrange interpolation
	EXPECT_NEAR(lagrange(106.05), 7.3, 1e-1);


}
