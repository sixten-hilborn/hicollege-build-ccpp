#!/bin/bash
set -ex

cmake -DCMAKE_TOOLCHAIN_FILE=~/emsdk/emsdk_portable/emscripten/master/cmake/Modules/Platform/Emscripten.cmake \
    "$(dirname "$0")"
