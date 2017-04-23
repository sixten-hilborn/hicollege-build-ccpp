cmake_minimum_required(VERSION 3.4)
project(Example2)

add_executable(Example2 hello_sdl.cpp)
if(EMSCRIPTEN)
    target_compile_options(Example2 PUBLIC -s USE_SDL=2 -o hello_sdl.html --preload-file image.bmp)
else()
    target_link_libraries(Example2 PUBLIC SDL2)
endif()

set_target_properties(Example2 PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRE ON
    CXX_EXTENSIONS OFF)
#find_package(SDL2 REQUIRED)

set_property(TARGET Example2 PROPERTY OUTPUT_NAME Example2$<$<CONFIG:Debug>:d>)
