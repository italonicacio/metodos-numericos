#include <gtest/gtest.h>
#include <iostream>
#include <format>

#include "linalg/gauss-elimination.hpp"

TEST(GaussElimination1Test, GaussEliminationTest) {
	Matrix<std::float32_t> A = { {2, 1, -3}, {-1, 3, 2}, {3, 1, -3} };
	Matrix<std::float32_t> b = { {-1}, {12}, {0} };

	Matrix<std::float32_t> x = GaussElimination(A, b);

	Matrix<std::float32_t> result = A * x;
	std::float32_t epsilon = 1e-6f;

	EXPECT_NEAR(b.UnsafeAt(0, 0), result.UnsafeAt(0, 0), epsilon);
	EXPECT_NEAR(b.UnsafeAt(1, 0), result.UnsafeAt(1, 0), epsilon);
	EXPECT_NEAR(b.UnsafeAt(2, 0), result.UnsafeAt(2, 0), epsilon);
}

TEST(GaussElimination2Test, GaussEliminationTest) {
	Matrix<std::float32_t> A = { {1, -3, 2}, {-2, 8, -1}, {4, -6, 5} };
	Matrix<std::float32_t> b = { {11}, {-15}, {29} };

	Matrix<std::float32_t> x = GaussElimination(A, b);

	Matrix<std::float32_t> result = A * x;
	std::float32_t epsilon = 1e-6f;

	EXPECT_NEAR(b.UnsafeAt(0, 0), result.UnsafeAt(0, 0), epsilon);
	EXPECT_NEAR(b.UnsafeAt(1, 0), result.UnsafeAt(1, 0), epsilon);
	EXPECT_NEAR(b.UnsafeAt(2, 0), result.UnsafeAt(2, 0), epsilon);
}
