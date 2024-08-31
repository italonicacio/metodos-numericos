#include <gtest/gtest.h>
#include <iostream>
#include <format>

#include <cinttypes>

#include "linalg/matrix.hpp"

TEST(RowMajorIndexTest, MatrixTest) {
	std::size_t i = 0;
	std::size_t j = 0;
	std::size_t n_columns = 3;

	std::size_t index = RowMajorIndex(0, 0, n_columns);

	EXPECT_EQ(index, 0);

	index = RowMajorIndex(0, 1, n_columns);

	EXPECT_EQ(index, 1);

	index = RowMajorIndex(1, 0, n_columns);

	EXPECT_EQ(index, 3);
}

TEST(InitializerListUsedAfterDeclartionOfMatrixTest, MatrixTest) {
	std::size_t m = 2;
	std::size_t n = 3;
	Matrix<std::int32_t> A(m, n);
	A = { {1, 1, 1}, {1, 1, 1} };

	EXPECT_EQ(A.UnsafeAt(0, 0), 1);

}

TEST(PassingInitializerListWithWrongDimensionsTest, MatrixTest) {
	std::size_t m = 3;
	std::size_t n = 3;
	Matrix<std::int32_t> A(m, n);

	auto assign = [&A]() {
		A = {
			{1, 1, 1},
			{1, 1}
		}; // Wrong Dimensions
	};
	EXPECT_ANY_THROW(assign(););
}

TEST(InitializerListConstructorTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1}, {1, 1} };

	EXPECT_EQ(A.UnsafeAt(0, 0), 1);

}

TEST(InitializerListConstructorGetDimensionsTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1}, {1, 1} };

	auto [rows, cols] = A.GetDims();
	EXPECT_EQ(rows, 2);
	EXPECT_EQ(cols, 2);

}

TEST(InitializerListConstructorGetNumRowsTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1}, {1, 1} };

	std::size_t num_rows = A.GetNumRows();
	EXPECT_EQ(num_rows, 2);
}

TEST(InitializerListConstructorGetNumColsTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1}, {1, 1} };

	std::size_t num_cols = A.GetNumCols();
	EXPECT_EQ(num_cols, 2);
}

TEST(SumMatrixTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1, 1}, {1, 1, 1} };
	Matrix<std::int32_t> B = { {1, 1, 1}, {1, 1, 1} };

	Matrix<std::int32_t> C = A + B;

	EXPECT_EQ(C.UnsafeAt(0, 0), 2);

}

TEST(SumWithWrongDimensionMatrixTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	Matrix<std::int32_t> B = { {1, 1, 1}, {1, 1, 1} };

	auto sum = [&A, &B]() {
		Matrix<std::int32_t> C = A + B;
	};

	EXPECT_ANY_THROW(sum(););
}

TEST(SubtractionMatrixTest, MatrixTest) {
	std::size_t m = 2;
	std::size_t n = 2;
	Matrix<std::int32_t> A = { {1, 1}, {1, 1} };
	Matrix<std::int32_t> B = { {1, 1}, {1, 1} };

	Matrix<std::int32_t> C = A - B;

	EXPECT_EQ(C.UnsafeAt(0, 0), 0);

}

TEST(SubtractionWithWrongDimensionMatrixTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1}, {1, 1}, {1, 1} };
	Matrix<std::int32_t> B = { {1, 1}, {1, 1} };

	auto subtract = [&A, &B]() {
		Matrix<std::int32_t> C = A - B;
	};

	EXPECT_ANY_THROW(subtract(););
}

TEST(MultiplicationMatrixTest, MatrixTest) {
	std::size_t m = 2;
	std::size_t n = 2;
	Matrix<std::int32_t> A = { {1, 1}, {1, 1} };
	Matrix<std::int32_t> B = { {1, 1}, {1, 1} };

	Matrix<std::int32_t> C = A * B;

	EXPECT_EQ(C.UnsafeAt(0, 0), 2);
}

TEST(MultiplicationWithWrongDimensionsTest, MatrixTest) {
	Matrix<std::int32_t> A = { {1, 1, 1}, {1, 1, 1}, };
	Matrix<std::int32_t> B = { {1, 1}, {1, 1} };

	auto multiply = [&A, &B]() {
		Matrix<std::int32_t> C = A * B;
	};

	EXPECT_ANY_THROW(multiply(););

}
