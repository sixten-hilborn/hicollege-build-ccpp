cmake_minimum_required(VERSION 3.4)
project(SDL_App)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

add_executable(SDL_App main.c)
target_link_libraries(SDL_App PUBLIC SDL2::core)
configure_file(image.bmp image.bmp COPYONLY)

if(EMSCRIPTEN)
    set_target_properties(SDL_App PROPERTIES LINK_FLAGS "--preload-file image.bmp -o SDL_App.html -s USE_SDL=2")
endif()
