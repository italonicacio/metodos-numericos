#pragma once

#include <cinttypes>
#include <stdfloat> 
#include <cinttypes>
#include <vector>
#include <utility>

template <typename T>
class Lagrange {
public:
	std::vector<T> x;
	std::vector<T> y;
	std::vector<T> coefficients;

	Lagrange(const std::vector<T>& x, const std::vector<T>& y) : x(x), y(y) {

		if(x.size() != y.size()) {
			throw std::invalid_argument("x and y must have the same size");
		}

		if(!is_sorted(x)) {
			throw std::invalid_argument("x must be sorted");
		}
		Precalculate();
	}

	void Precalculate() {
		coefficients.resize(x.size());
		for(size_t i = 0; i < x.size(); i++) {
			T denominator = 1;
			for(size_t j = 0; j < x.size(); j++) {
				if(i == j) {
					continue;
				}
				denominator *= x[i] - x[j];
			}
			coefficients[i] = y[i] / denominator;
		}
	}

	T operator()(T point) const {
		T result = 0;
		size_t n = x.size();

		for(size_t i = 0; i < n; ++i) {
			T term = coefficients[i];
			for(size_t j = 0; j < n; ++j) {
				if(i != j) {
					term *= (point - x[j]);
				}
			}
			result += term;
		}

		return result;
	}

	bool is_sorted(const std::vector<T>& vec) const {
		return std::adjacent_find(vec.begin(), vec.end(), std::greater<T>()) == vec.end();
	}

};
