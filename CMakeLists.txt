cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -Werror -Wall -Wextra")

add_executable(untitled2 main.cpp prm/UniformPermutation.h prm/impl/UniformZeroOneGenerator.cpp prm/impl/UniformZeroOneGenerator.h prm/impl/CopyIntoContainer.h prm/impl/UniformPermutationImpl.h prm/extra/SpeedTest.cpp prm/extra/SpeedTest.h prm/impl/Math.h prm/extra/Tools.cpp prm/extra/Tools.h prm/impl/MallowsPermutationImpl.h prm/impl/MallowsQGreaterThenOneBase.cpp prm/impl/MallowsQGreaterThenOneBase.h prm/impl/MallowsBase.cpp prm/impl/MallowsBase.h prm/impl/MallowsQLessThanOneBase.cpp prm/impl/MallowsQLessThanOneBase.h prm/impl/EwensPermutationImpl.h prm/MallowsPermutation.h prm/EwensPermutation.h prm/impl/Con.cpp prm/impl/Con.h)
