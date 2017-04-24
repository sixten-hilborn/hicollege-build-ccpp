cmake_minimum_required(VERSION 3.4)
project(Example2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

add_executable(Example2 hello_sdl.cpp)
target_link_libraries(Example2 PUBLIC SDL2::core)

set_target_properties(Example2 PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRE ON
    CXX_EXTENSIONS OFF)

if(EMSCRIPTEN)
    target_compile_options(Example2 PRIVATE --preload-file ${CMAKE_SOURCE_DIR}/image.bmp)
    set_target_properties(Example2 PROPERTIES LINK_FLAGS "-o Example2.html -s USE_SDL=2")
endif()
