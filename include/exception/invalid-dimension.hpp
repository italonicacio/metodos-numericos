#include <exception>
#include <string>

class InvalidDimensionException : public std::exception {
private:
	std::string message;

public:
	InvalidDimensionException(const std::string& dim, std::size_t dim_value) {
		message = "Invalid dimension to dim " + dim + ": " + dim + " = " + std::to_string(dim_value);
	}

	const char* what() const noexcept override {
		return message.c_str();
	}
};
