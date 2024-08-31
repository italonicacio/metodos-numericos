#pragma once

#include "tridiagonal-matrix.hpp"

// thomas algorithm trabalha com matrizes tridiagonais, então a diagonal a, b e c estão contadias na matriz A
// É necessario que a matriz A seja quadrada e que a matriz b tenha o mesmo número de linhas que a matriz A

template <typename T>
std::vector<T> ThomasAlgorithm(const TridiagonalMatrix<T>& A, const std::vector<T>& b) {
	std::size_t n = b.size();
	if(n != A.size_) {
		throw std::invalid_argument("Vector size must match the size of the matrix");
	}
	std::vector<T> c(n - 1);
	std::vector<T> x(n);

	// Forward elimination
	c[0] = A.upper_[0] / A.main_[0];
	x[0] = b[0] / A.main_[0];

	for(std::size_t i = 1; i < n - 1; ++i) {
		T denom = A.main_[i] - A.lower_[i - 1] * c[i - 1];
		c[i] = A.upper_[i] / denom;
		x[i] = (b[i] - A.lower_[i - 1] * x[i - 1]) / denom;
	}

	x[n - 1] = (b[n - 1] - A.lower_[n - 2] * x[n - 2]) / (A.main_[n - 1] - A.lower_[n - 2] * c[n - 2]);

	// Back substitution
	x[n - 1] = x[n - 1];
	for(std::size_t i = n - 1; i-- > 0;) {
		x[i] -= c[i] * x[i + 1];
	}

	return x;
}
