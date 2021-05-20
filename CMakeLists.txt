cmake_minimum_required(VERSION 3.17)
project(MarketSimulation)

set(CMAKE_CXX_STANDARD 11)

set(GOOGLETEST_VERSION 1.10.0)

enable_testing()

add_subdirectory(src)

add_subdirectory(tests)

add_subdirectory(lib/googletest)
