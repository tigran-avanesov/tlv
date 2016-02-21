cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

add_subdirectory(googletest)
add_subdirectory(tlvlib)
add_subdirectory(tests)