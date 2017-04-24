#!/bin/bash
set -ex

cmake -DCMAKE_TOOLCHAIN_FILE=/home/sixten/emsdk/emsdk_portable/emscripten/master/cmake/Modules/Platform/Emscripten.cmake \
    "$(dirname "$0")"
