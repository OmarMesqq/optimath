#!/bin/sh

# Clone and build Catch2
if [ ! -d "Catch2" ]; then
    git clone https://github.com/catchorg/Catch2.git
else
    echo "Catch2 directory exists, skipping clone."
fi


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