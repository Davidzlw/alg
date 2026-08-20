cmake_minimum_required(VERSION 3.22)
project(test)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

file(GLOB CPP_SOURCES CONFIGURE_DEPENDS "*.cpp" "graph/*.cpp")

add_executable(cf ${CPP_SOURCES})
target_include_directories(cf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/graph)
