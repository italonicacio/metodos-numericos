#pragma once
#include <vector>

namespace Interpolation {

	std::vector<double> DividedDifferences(const std::vector<double>& x, const std::vector<double>& y) {
		std::size_t n = x.size();
		std::vector<double> coef(y);
		for (std::size_t j = 1; j < n; ++j) {
			for (std::size_t i = n - 1; i >= j; --i) {
				coef[i] = (coef[i] - coef[i - j]) / (x[i] - x[i - j]);
			}
		}
		return coef;
	}

	double NewtonInterpolation(const std::vector<double>& x, const std::vector<double>& coef, double value) {
		double result = coef.back();
		for (std::size_t i = coef.size() - 1; i > 0; --i) {
			result = result * (value - x[i - 1]) + coef[i - 1];
		}
		return result;
	}

}
