cmake_minimum_required(VERSION 3.0.0)
project(atm VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories($PROJECT_SOURCE_DIR)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11)

add_executable(atm main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
