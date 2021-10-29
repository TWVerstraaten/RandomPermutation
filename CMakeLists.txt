cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -Werror -Wall -Wextra")

add_executable(untitled2 main.cpp prm/Permutation.h prm/impl/UniformZeroOneGenerator.cpp prm/impl/UniformZeroOneGenerator.h prm/impl/MallowsBase.h prm/impl/UniformPermutation.h prm/SpeedTest.cpp prm/SpeedTest.h prm/impl/Math.h prm/Tools.cpp prm/Tools.h prm/impl/MallowsQGreaterThanOne.h prm/impl/MallowsQLessThanOne.h)
