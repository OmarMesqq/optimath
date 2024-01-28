#!/bin/sh

# Build optimath
mkdir -p build && cd build
cmake ..
make -j$(nproc)

# Organize final compiled files
cd .. 
mkdir out
cp build/liboptimath_shared.so out/
cp build/liboptimath_static.a out/
cp build/optimath_tests out/
