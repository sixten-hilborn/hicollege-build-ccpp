cmake_minimum_required(VERSION 3.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
project(Arduino)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
# Reset output directories modified by Conan
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY)

generate_arduino_firmware(main
    SRCS main.cpp
    PORT /dev/ttyACM0
    BOARD uno)

target_link_libraries(main CONAN_PKG::LibMorse)

set_target_properties(main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)
