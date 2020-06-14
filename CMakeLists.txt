# CMakeList.txt : CMake project for Lewis, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(lewis)

set(SOURCE_CODE
        main.cpp
        ppmwriter.cpp
        vec3.h
        ray.cpp
        ray.h
        hitable.h
        sphere.cpp
        sphere.h
        hitablelist.cpp
        hitablelist.h
        camera.cpp
        camera.h)

# Add source to this project's executable.
add_executable (Lewis ${SOURCE_CODE})
