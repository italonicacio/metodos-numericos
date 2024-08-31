#pragma once

#include "matrix.hpp"


#include "gauss-elimination.hpp"

template <typename T>
Matrix<T> GaussElimination(const Matrix<T>& A, const Matrix<T>& b) {
	Matrix<T> Ab = { A, b };
	const auto [num_rows, num_cols] = Ab.GetDims();

	for(std::size_t i = 0; i < num_rows; ++i) {

		// Find pivot
		std::size_t pivot = i;
		for(std::size_t j = i + 1; j < num_rows; ++j) {
			if(std::abs(Ab.UnsafeAt(j, i)) > std::abs(Ab.UnsafeAt(pivot, i))) {
				pivot = j;
			}
		}


		// Swap rows
		if(pivot != i) {
			for(std::size_t j = 0; j < num_cols; ++j) {
				std::swap(Ab.UnsafeAt(i, j), Ab.UnsafeAt(pivot, j));
			}
		}


		// Eliminate
		for(std::size_t j = i + 1; j < num_rows; ++j) {
			T factor = Ab.UnsafeAt(j, i) / Ab.UnsafeAt(i, i);

			for(std::size_t k = i; k < num_cols; ++k) {
				Ab.UnsafeAt(j, k) -= factor * Ab.UnsafeAt(i, k);
			}
		}
	}

	// Back substitution
	Matrix<T> x(num_rows, 1);
	for(std::size_t i = num_rows; i-- > 0;) {
		x.UnsafeAt(i, 0) = Ab.UnsafeAt(i, num_cols - 1);
		for(std::size_t j = i + 1; j < num_cols - 1; ++j) {
			x.UnsafeAt(i, 0) -= Ab.UnsafeAt(i, j) * x.UnsafeAt(j, 0);
		}
		x.UnsafeAt(i, 0) /= Ab.UnsafeAt(i, i);
	}

	return x;
}

