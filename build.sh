#!/bin/sh

# Clone Catch2
if [ ! -d "Catch2" ]; then
    git clone https://github.com/catchorg/Catch2.git
else
    echo "Catch2 directory exists, skipping clone."
fi

echo "---------------------------"
## Build optimath
mkdir -p build && cd build
cmake ..
make -j$(nproc)

