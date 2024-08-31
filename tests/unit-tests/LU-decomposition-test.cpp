#include <gtest/gtest.h>
#include <iostream>
#include <format>

#include "linalg/matrix.hpp"
#include "linalg/LU-decomposition.hpp"

TEST(LUDecomposition1Test, LUDecompositionTest) {
	Matrix<std::float32_t> A = { {2, 1, -3}, {-1, 3, 2}, {3, 1, -3} };
	Matrix<std::float32_t> b = { {-1}, {12}, {0} };

	const auto& [L, U] = LUDecomposition(A);

	const Matrix<std::float32_t> result = L * U;


	std::float32_t epsilon = 1e-6f;
	EXPECT_TRUE(Equal(A, result, epsilon));

}
