set(CMAKE_SYSTEM_NAME Darwin)

set(PROJECT_NAME "va_exception")

if(${PROJECT_NAME} STREQUAL "Sample Project Name")
	message(AUTHOR_WARNING "No project name is set")
endif()

project(${PROJECT_NAME})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_BUILD_TYPE debug)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-std=c++14 -Werror -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

file(GLOB_RECURSE SOURCES "src/*.cpp")

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/res COMMAND ln -s ${CMAKE_BINARY_DIR}/res ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# add_library(${PROJECT_NAME} STATIC ${SOURCES})
# add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC "/usr/local/include") 
 