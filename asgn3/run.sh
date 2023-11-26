#!/bin/bash

# Compile the source files
# g++ -std=c++11 -c BaseClass.cpp
# g++ -std=c++11 -c LinearProbing.cpp
g++ -o test  BaseClass.h  LinearProbing.cpp QuadraticProbing.cpp Chaining.cpp CubicProbing.cpp Comp.cpp test.cpp

# Run the compiled program
./test

# Clean up compiled object files and executable
rm -f test BaseClass.o LinearProbing.o
