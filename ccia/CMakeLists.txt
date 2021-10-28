cmake_minimum_required(VERSION 3.0.0)
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

project(threadsafeMap VERSION 0.1.0)

include(CTest)
enable_testing()
# c++11
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11)
# import boost
# find_path(BOOST_DIR NAMES boost PATHS /Users/Duke-mac/OpenSource/vcpkg/installed/x64-osx/include)
# include_directories(${BOOST_DIR})
# link_directories(/Users/Duke-mac/OpenSource/vcpkg/installed/x64-osx/lib)
find_package(Boost)
include_directories(/Users/Duke-mac/OpenSource/vcpkg/installed/x64-osx/include)
link_directories(${Boost_LIBRARY_DIRS})
add_executable(threadsafeMap threadsafeMap.cpp)

target_link_libraries(${PROJECT_NAME} boost_thread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
