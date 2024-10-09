#pragma once

#include <vector>
#include <stdexcept>
#include <cmath>
#include <Eigen/Dense> // For matrix operations

class CurveFitting {
public:
	CurveFitting(const std::vector<double>& x, const std::vector<double>& y) : x_(x), y_(y) {
		if(x.size() != y.size()) {
			throw std::invalid_argument("x and y must have the same size");
		}
	}

	// Fit a polynomial of given degree to the data points
	void fitPolynomial(int degree) {
		if(degree < 0) {
			throw std::invalid_argument("Degree must be non-negative");
		}

		int n = x_.size();
		Eigen::MatrixXd A(n, degree + 1);
		Eigen::VectorXd b(n);

		// Fill the matrix A and vector b
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j <= degree; ++j) {
				A(i, j) = std::pow(x_[i], j);
			}
			b(i) = y_[i];
		}

		// Solve the normal equations A^T * A * coeffs = A^T * b
		Eigen::VectorXd coeffs = (A.transpose() * A).ldlt().solve(A.transpose() * b);
		coefficients_ = std::vector<double>(coeffs.data(), coeffs.data() + coeffs.size());
	}

	// Evaluate the fitted polynomial at a given point
	double evaluatePolynomial(double point) const {
		if(coefficients_.empty()) {
			throw std::runtime_error("Polynomial has not been fitted yet");
		}

		double result = 0.0;
		for(size_t i = 0; i < coefficients_.size(); ++i) {
			result += coefficients_[i] * std::pow(point, i);
		}
		return result;
	}

	// Get the coefficients of the fitted polynomial
	const std::vector<double>& getCoefficients() const {
		return coefficients_;
	}

private:
	std::vector<double> x_;
	std::vector<double> y_;
	std::vector<double> coefficients_;
};
