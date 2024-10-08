cmake_minimum_required(VERSION 3.22)

project(MyProject CXX)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-fpermissive)

file(GLOB_RECURSE LIBRARY_SOURCES "src/*.cpp")
list(REMOVE_ITEM LIBRARY_SOURCES "src/main.cpp")

add_library (
    MyLibrary 
    STATIC
        ${LIBRARY_SOURCES}
)

target_include_directories(
    MyLibrary
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    MyLibrary
    PUBLIC
        Eigen3::Eigen
)

set_target_properties( 
    MyLibrary
    PROPERTIES
        ENABLE_EXPORTS ON
        POSITION_INDEPENDENT_CODE ON
)

install (
    TARGETS MyLibrary
    DESTINATION ${CMAKE_BINARY_DIR}/lib
)

# add_executable(
#     MyExecutable
#         "src/main.cpp"
# )



# target_include_directories(
#     MyExecutable
#     PRIVATE
#         ${CMAKE_SOURCE_DIR}/include

# )

# target_link_libraries(
#     MyExecutable
#     PRIVATE
#         MyLibrary
# )

if (CMAKE_BUILD_TYPE STREQUAL "DEBUG" OR enable_tests)
	add_subdirectory(tests/unit-tests)
endif()

