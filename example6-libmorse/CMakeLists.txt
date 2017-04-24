cmake_minimum_required(VERSION 2.8)
project(conanlibmorse)

include(conanbuildinfo.cmake)
conan_basic_setup()

set(source_dir "./LibMorse-b1b05e16a8e74f3859838b82dbe817b06cc44c90")

add_library(morse ${source_dir}/libmorse.c)

install(TARGETS morse
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES ${source_dir}/libmorse.h DESTINATION include)
