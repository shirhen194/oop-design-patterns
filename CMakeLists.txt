cmake_minimum_required(VERSION 3.21)
project(generic_c___implementations)

set(CMAKE_CXX_STANDARD 14)

add_executable(generic_c___implementations main.cpp Builder.cpp Adapter.cpp)
