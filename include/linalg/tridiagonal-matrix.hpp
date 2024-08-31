#include <vector>

#include <cinttypes>
#include <stdfloat>

template<typename T>
class TridiagonalMatrix {
public:
	std::size_t size_;
	std::vector<T> lower_;
	std::vector<T> main_;
	std::vector<T> upper_;
	TridiagonalMatrix(size_t size)
		: size_(size), lower_(size - 1, T()), main_(size, T()), upper_(size - 1, T()) {
	}

	TridiagonalMatrix(std::initializer_list<T> lower, std::initializer_list<T> main, std::initializer_list<T> upper)
		: size_(main.size()), lower_(lower), main_(main), upper_(upper) {
	}

	inline std::size_t offset(std::size_t i) const {
		return i * size_;
	}

	T at(std::size_t i, std::size_t j) const {
		if(i == j) {
			return main_[i];
		} else if(i == j + 1) {
			return lower_[j];
		} else if(i + 1 == j) {
			return upper_[i];
		} else {
			throw std::out_of_range("Invalid index for tridiagonal matrix");
		}
	}

	T& at(std::size_t i, std::size_t j) {
		if(i == j) {
			return main_[i];
		} else if(i == j + 1) {
			return lower_[j];
		} else if(i + 1 == j) {
			return upper_[i];
		} else {
			throw std::out_of_range("Invalid index for tridiagonal matrix");
		}
	}

	std::vector<T> multiply(const std::vector<T>& x) const {
		if(x.size() != size_) {
			throw std::invalid_argument("Vector size must match the size of the matrix");
		}

		std::vector<T> result(size_, T());

		for(std::size_t i = 0; i < size_; ++i) {
			result[i] = main_[i] * x[i];
			if(i > 0) {
				result[i] += lower_[i - 1] * x[i - 1];
			}
			if(i < size_ - 1) {
				result[i] += upper_[i] * x[i + 1];
			}
		}

		return result;
	}

};

template<typename T>
bool compare_vectors(const std::vector<T>& vec1, const std::vector<T>& vec2, T epsilon) {
	if(vec1.size() != vec2.size()) {
		return false;
	}

	if(std::is_integral<T>::value) {
		for(std::size_t i = 0; i < vec1.size(); ++i) {
			if(vec1[i] != vec2[i]) {
				return false;
			}
		}
	} else {
		for(std::size_t i = 0; i < vec1.size(); ++i) {
			if(std::abs(vec1[i] - vec2[i]) >= epsilon) {
				return false;
			}
		}
	}

	return true;
}
