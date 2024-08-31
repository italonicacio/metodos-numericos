#include <gtest/gtest.h>
#include <iostream>
#include <format>

#include "linalg/thomas-algorithm.hpp"

TEST(ThomasAlgorithm1Test, ThomasAlgorithmTest) {
	TridiagonalMatrix<std::float64_t> A = {
		{1.0, 1.0},  // Diagonal inferior
		{4.0, 4.0, 4.0},  // Diagonal principal
		{1.0, 1.0}   // Diagonal superior
	};

	std::vector<std::float64_t> b = { 5.0, 5.0, 5.0 };


	std::vector<std::float64_t> x = ThomasAlgorithm(A, b);

	std::vector<std::float64_t> result = A.multiply(x);

	std::float64_t epsilon = 1e-6;
	// EXPECT_TRUE(compare_vectors(b, result, epsilon));
	EXPECT_NEAR(b[0], result[0], epsilon);
	EXPECT_NEAR(b[1], result[1], epsilon);
	EXPECT_NEAR(b[2], result[2], epsilon);

}

TEST(ThomasAlgorithm2Test, ThomasAlgorithmTest) {
	TridiagonalMatrix<std::float64_t> A = {
		{2.0, 3.0},  // Diagonal inferior
		{5.0, 6.0, 7.0},  // Diagonal principal
		{1.0, 2.0}   // Diagonal superior
	};

	std::vector<std::float64_t> b = { 8.0, 9.0, 10.0 };

	std::vector<std::float64_t> x = ThomasAlgorithm(A, b);

	std::vector<std::float64_t> result = A.multiply(x);
	std::float64_t epsilon = 1e-6;

	// EXPECT_TRUE(compare_vectors(b, result, epsilon));
	EXPECT_NEAR(b[0], result[0], epsilon);
	EXPECT_NEAR(b[1], result[1], epsilon);
	EXPECT_NEAR(b[2], result[2], epsilon);

}


