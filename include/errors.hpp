#pragma once 
#include <ostream>
#include <unordered_map>
#include <cinttypes>
#include <string>

#define ERROR_ENUM_VALUES \
    X(MaxIter, 1, "Maximum iterations reached!") \
    X(InternalError, 2, "Internal error ocurred!") \
    X(NoRootFound, 3, "No root found!") \
    X(NonConvergence, 4, "The method did not converged!") \
    X(InvalidInterval, 5, "Interval does not isolate one root or contains several roots") \


enum class Error {
    #define X(name, value, desc) name = value,
    ERROR_ENUM_VALUES
    #undef X
};

inline std::ostream& operator<<(std::ostream& os, Error err) {
    return os << static_cast<std::int32_t>(err);
}

struct ErrorInfo {
    std::string name;
    std::string description;
};

inline std::unordered_map<Error, ErrorInfo> CreateErrorMap() {
    std::unordered_map<Error, ErrorInfo> error_map;

    #define X(name, value, desc) error_map[Error::name] = ErrorInfo{#name, desc};
    ERROR_ENUM_VALUES
    #undef X
    return error_map;
}

inline ErrorInfo GetErrorInfo(const Error err) {
    static auto error_map = CreateErrorMap();
    
    if(error_map.contains(err)) {
        return error_map.at(err);
    }  
        
    return ErrorInfo{"Unknown", "Error not found!"};
}