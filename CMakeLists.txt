cmake_minimum_required (VERSION 2.8.11)

INCLUDE(CPack)
INCLUDE(TestBigEndian)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.0")
        message(FATAL_ERROR "Insufficient gcc version")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.0")
        message(FATAL_ERROR "Insufficient clang version")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
    endif()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

TEST_BIG_ENDIAN(CPU_IS_BIGENDIAN)

add_subdirectory(googletest)
add_subdirectory(tlvlib)
add_subdirectory(tests)

