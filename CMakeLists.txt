cmake_minimum_required(VERSION 3.16)
project(TJRayTracerExec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(TESTING_ENABLED 0)

if ({TESTING_ENABLED})
	enable_testing()
	add_subdirectory(tests)
endif()

add_subdirectory(src)
