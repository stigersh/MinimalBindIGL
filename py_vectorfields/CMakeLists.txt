cmake_minimum_required(VERSION 3.16)#2.8.12)
project(py_vectorfields)
set(CMAKE_CXX_STANDARD 17)
# add_definitions(-w)# suppress warnings
set(CMAKE_BUILD_TYPE Debug)
# -DCMAKE_BUILD_TYPE=Debug//can be release!
cmake_policy(SET CMP0114 NEW)
# pybind11 path - output of python -c "import pybind11; print(pybind11.get_cmake_dir())"
# set(pybind11_DIR "/Users/annashtengel/anaconda3/lib/python3.9/site-packages/pybind11/share/cmake/pybind11") 

#python -c "from sysconfig import get_paths; print(get_paths()['include'])"
set(PYTHON_INCLUDE_DIR "/Users/annashtengel/anaconda3/include/python3.9")
include_directories(${PYTHON_INCLUDE_DIR})

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


find_package( PkgConfig )
pkg_check_modules( EIGEN3 REQUIRED eigen3 )
include_directories( ${EIGEN3_INCLUDE_DIRS} )


option(LIBIGL_GLFW "Build target igl::glfw" OFF)
option(LIBIGL_IMGUI "Build target igl::imgui" OFF)
option(LIBIGL_PNG "Build target igl::png" OFF)
option(LIBIGL_COPYLEFT_CGAL "Build target igl_copyleft::cgal" OFF)
option(LIBIGL_RESTRICTED_MATLAB "Build target igl_restricted::matlab" OFF)


include(libigl)

#----------------------------
# add source code
# add source code


#----------------------------

# main CPP
# Add the executable for the main file
# uses classes
add_executable(main_pymesh_app main_pymesh_app.cpp)
# Link the main executable to igl
target_link_libraries(main_pymesh_app PUBLIC igl::core)

# wrapping cpp to python

# add_subdirectory(pybind11)

include(pybind11)
pybind11_add_module(py_vectorfields SHARED py_mesh_app.cpp)

find_package(OpenMP)

message(STATUS CMAKE_C_FLAGS": ${CMAKE_C_FLAGS}")
message(STATUS OpenMP_C_FLAGS": ${OpenMP_C_FLAGS}")


if(OpenMP_CXX_FOUND)
    target_link_libraries(py_vectorfields PUBLIC igl::core OpenMP::OpenMP_CXX)
else()
    target_link_libraries(py_vectorfields PUBLIC igl::core )
endif()

