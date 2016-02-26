cmake_minimum_required (VERSION 2.8.11)

project("tlvlib")

# project version
set(VERSION_MAJOR 0 CACHE STRING "Project major version number.")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 1 CACHE STRING "Project patch version number.")

include(CPack)
include(TestBigEndian)

# enable c++11 for different compilers
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.0")
        message(FATAL_ERROR "Insufficient gcc version")
    else()
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.0")
        message(FATAL_ERROR "Insufficient clang version")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
    endif()
endif()

# enable all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

# endianness detection
test_big_endian(CPU_IS_BIGENDIAN)

# enable doxygen
find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_INPUT "${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf")
    set(DOXYGEN_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/doc")
    configure_file(
        ${CMAKE_SOURCE_DIR}/doxygen.conf.in
        ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
    add_custom_command(
        OUTPUT ${DOXYGEN_OUTPUT}
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${DOXYGEN_INPUT})
    add_custom_target(apidoc ALL DEPENDS ${DOXYGEN_OUTPUT})
else (DOXYGEN_FOUND)
    message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif (DOXYGEN_FOUND)

# add project tree
add_subdirectory(googletest)
add_subdirectory(tlvlib)
add_subdirectory(tests)

