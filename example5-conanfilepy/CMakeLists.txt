cmake_minimum_required(VERSION 3.4)
project(BoostExample)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(Main main.cpp)
target_link_libraries(Main CONAN_PKG::libhiq)

set_target_properties(Main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)
