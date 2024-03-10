#!/bin/sh

# Build optimath
mkdir -p build && cd build
cmake ..
make -j$(nproc)

cd .. 
mkdir -p out
cp build/examples out
cp build/optimath_tests out/
