#pragma once

#include <cinttypes>
#include <stdfloat>
#include <type_traits>
#include <tuple>
#include <memory>
#include <algorithm>

#include "exception/invalid-dimension.hpp"

// Função para indexar uma matriz em ordem row-major
inline __attribute__((always_inline)) std::size_t RowMajorIndex(std::size_t i, std::size_t j, std::size_t n_columns) {
	return i * n_columns + j;
}



template <typename T>
class Matrix {
	static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

public:
	std::size_t rows_; // Rows
	std::size_t cols_; // Columns
	std::size_t size_; // Rows * Columns

	std::unique_ptr<T[]> data_;

	Matrix(std::size_t m, std::size_t n) {
		if(n == 0) {
			throw InvalidDimensionException("n", n);
		}

		if(n == 0) {
			throw InvalidDimensionException("m", m);
		}

		cols_ = n;
		rows_ = m;
		size_ = cols_ * rows_;
		data_ = std::make_unique<T[]>(size_);
		std::fill(data_.get(), data_.get() + size_, T(0));
	}

	Matrix(const Matrix<T>& A, const Matrix<T>& B) {
		if(A.rows_ != B.rows_) {
			throw std::invalid_argument("Number of rows in both matrices must be the same");
		}

		rows_ = A.rows_;
		cols_ = A.cols_ + B.cols_;
		size_ = rows_ * cols_;
		data_ = std::make_unique<T[]>(size_);

		for(std::size_t i = 0; i < rows_; ++i) {
			std::copy(&A.data_[i * A.cols_], &A.data_[(i + 1) * A.cols_], &data_[i * cols_]);
			std::copy(&B.data_[i * B.cols_], &B.data_[(i + 1) * B.cols_], &data_[i * cols_ + A.cols_]);
		}
	}

	Matrix(std::initializer_list<std::initializer_list<T>> init) {

		rows_ = init.size();
		if(rows_ == 0) {
			throw InvalidDimensionException("m", rows_);
		}

		cols_ = init.begin()->size();
		if(cols_ == 0) {
			throw InvalidDimensionException("n", cols_);
		}

		size_ = rows_ * cols_;
		data_ = std::make_unique<T[]>(size_);

		std::size_t i = 0;
		for(const auto& row : init) {
			if(row.size() != cols_) {
				throw std::invalid_argument("Number of columns does not match");
			}
			std::copy(row.begin(), row.end(), &data_[i * cols_]);
			++i;
		}
	}

	Matrix(std::size_t m, std::size_t n, std::initializer_list<std::initializer_list<T>> init) {
		if(init.size() != m) {
			throw std::invalid_argument("Number of rows does not match");
		}

		std::size_t i = 0;
		for(const auto& row : init) {
			if(row.size() != n) {
				throw std::invalid_argument("Number of columns does not match");
			}
			std::copy(row.begin(), row.end(), &data_[i * n]);
			++i;
		}
	}

	inline __attribute__((always_inline))  std::size_t Size() const {
		return size_;
	}

	inline __attribute__((always_inline)) T Get(std::size_t i, std::size_t j) {
		return data_[RowMajorIndex(i, j, cols_)];
	}

	/*
	* Return a tuple with M and N dims
	*
	*
	*/
	std::tuple<std::size_t, std::size_t> GetDims() const {
		return std::make_tuple(rows_, cols_);
	}

	std::size_t GetNumRows() const {
		return rows_;
	}

	std::size_t GetNumCols() const {
		return cols_;
	}

	Matrix& operator=(std::initializer_list<std::initializer_list<T>> init) {


		if(init.size() != rows_) {
			throw std::invalid_argument("Number of rows does not match");
		}

		std::size_t i = 0;
		for(const auto& row : init) {
			if(row.size() != cols_) {
				throw std::invalid_argument("Number of columns does not match");
			}
			std::copy(row.begin(), row.end(), &data_[i * cols_]);
			++i;
		}
		return *this;
	}

	// Se for usar para indexar muitas vezes não vale a pena, muito custoso
	inline T& operator()(std::size_t row, std::size_t col) const {
		if(row >= rows_ || col >= cols_) {
			throw std::out_of_range("Index out of range");
		}

		// if(is_symmetric) {
		// 	if(row < col) {
		// 		std::swap(row, col);
		// 	}
		// 	return data[RowMajorIndex(row, col)];
		// }

		return data_[RowMajorIndex(row, col, cols_)];
	};

	// Se for usar para indexar muitas vezes não vale a pena, muito custoso
	inline T operator()(std::size_t row, std::size_t col) {
		if(row >= rows_ || col >= cols_) {
			throw std::out_of_range("Index out of range");
		}

		return data_[RowMajorIndex(row, col, cols_)];
	}

	inline __attribute__((always_inline)) T& UnsafeAt(std::size_t row, std::size_t col) noexcept {
		return data_[RowMajorIndex(row, col, cols_)];
	}

	// Versão const da função UnsafeAt
	inline __attribute__((always_inline)) const T& UnsafeAt(std::size_t row, std::size_t col) const noexcept {
		return data_[RowMajorIndex(row, col, cols_)];
	}


	inline __attribute__((always_inline)) void SetUnsafeAt(std::size_t row, std::size_t col, const T& value) noexcept {
		data_[RowMajorIndex(row, col, cols_)] = value;
	}

	inline Matrix operator*(const Matrix& other) const {
		if(cols_ != other.rows_) {
			throw std::invalid_argument("Matrix dimensions do not match for multiplication");
		}

		Matrix result(rows_, other.cols_);
		for(std::size_t i = 0; i < rows_; ++i) {
			for(std::size_t j = 0; j < other.cols_; ++j) {
				T sum = T();
				for(std::size_t k = 0; k < cols_; ++k) {
					sum += UnsafeAt(i, k) * other.UnsafeAt(k, j);
				}
				result.SetUnsafeAt(i, j, sum);
			}
		}

		return result;
	}

	Matrix operator+(const Matrix& other) const {
		if(rows_ != other.rows_ || cols_ != other.cols_) {
			throw std::invalid_argument("Matrix dimensions are not compatible for addition");
		}

		Matrix result(rows_, cols_);
		for(std::size_t i = 0; i < rows_; ++i) {
			for(std::size_t j = 0; j < cols_; ++j) {
				T sum = UnsafeAt(i, j) + other.UnsafeAt(i, j);
				result.SetUnsafeAt(i, j, sum);
			}
		}

		return result;
	}

	Matrix operator-(const Matrix& other) const {
		if(rows_ != other.rows_ || cols_ != other.cols_) {
			throw std::invalid_argument("Matrix dimensions are not compatible for subtraction");
		}

		Matrix result(rows_, cols_);
		for(std::size_t i = 0; i < rows_; ++i) {
			for(std::size_t j = 0; j < cols_; ++j) {
				T sub = UnsafeAt(i, j) - other.UnsafeAt(i, j);
				result.SetUnsafeAt(i, j, sub);
			}
		}

		return result;
	}



};

template <typename T>
bool Equal(const Matrix<T>& A, const Matrix<T>& B, T epsilon = 1e-6) {
	static_assert(std::is_floating_point_v<T> || std::is_integral_v<T>, "T must be an arithmetic type");

	const auto& [num_rows_A, num_cols_A] = A.GetDims();
	const auto& [num_rows_B, num_cols_B] = B.GetDims();
	if(num_rows_A != num_rows_B || num_cols_A != num_cols_B) {
		return false;
	}


	for(std::size_t i = 0; i < num_rows_A; ++i) {
		for(std::size_t j = 0; j < num_cols_A; ++j) {
			if constexpr(std::is_floating_point_v<T>) {
				if(std::abs(A.UnsafeAt(i, j) - B.UnsafeAt(i, j)) > epsilon) {
					return false;
				}
			} else if constexpr(std::is_integral_v<T>) {
				if(A.UnsafeAt(i, j) != B.UnsafeAt(i, j)) {
					return false;
				}
			}
		}
	}

	return true;
}

