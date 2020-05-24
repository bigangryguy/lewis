# CMakeList.txt : CMake project for Lewis, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(lewis)

# Add source to this project's executable.
add_executable (Lewis "main.cpp" "ppmwriter.cpp" ray.cpp ray.h)

# TODO: Add tests and install targets if needed.
