#pragma once

#include <utility>

#include "matrix.hpp"

// LU Decomposition
// Return a pair matrices, L and U 
template<typename T>
std::pair<Matrix<T>, Matrix<T>> LUDecomposition(const Matrix<T>& A) {
	if(A.rows_ != A.cols_) {
		throw std::invalid_argument("Matrix A must be square");
	}

	std::size_t num_rows = A.GetNumRows();

	Matrix<T> L(num_rows, num_rows);
	Matrix<T> U(num_rows, num_rows);

	for(std::size_t i = 0; i < num_rows; ++i) {
		L.UnsafeAt(i, i) = static_cast<T>(1);
	}

	for(std::size_t i = 0; i < num_rows; ++i) {
		for(std::size_t j = i; j < num_rows; ++j) {
			T sum = static_cast<T>(0.0);

			for(std::size_t k = 0; k < i; ++k) {
				sum += L.UnsafeAt(i, k) * U.UnsafeAt(k, j);
			}
			U.UnsafeAt(i, j) = A.UnsafeAt(i, j) - sum;
		}

		for(std::size_t j = i + 1; j < num_rows; ++j) {
			T sum = static_cast<T>(0.0);
			for(std::size_t k = 0; k < i; ++k) {
				sum += L.UnsafeAt(j, k) * U.UnsafeAt(k, i);
			}
			L.UnsafeAt(j, i) = (A.UnsafeAt(j, i) - sum) / U.UnsafeAt(i, i);
		}
	}

	return std::make_pair(std::move(L), std::move(U));
}
