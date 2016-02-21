cmake_minimum_required (VERSION 2.8.11)

project (tlv)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*) 

if (NOT DEFINED TAG_TYPE)
    set(TAG_TYPE uint16_t)
endif()

if (NOT DEFINED SIZE_TYPE)
    set(SIZE_TYPE uint16_t)
endif()

configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp.in
                ${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp)

add_library(${PROJECT_NAME} ${SRC})

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
