cmake_minimum_required (VERSION 2.8.11)

project (test-tlv)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/*) 

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/tlvlib/include)
target_link_libraries (${PROJECT_NAME} gtest tlv)
