add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(TJRayTracer)

target_include_directories(${PROJECT_NAME} PUBLIC TJRayTracer)

target_link_directories(${PROJECT_NAME} PRIVATE TJRayTracer)

target_link_libraries(${PROJECT_NAME} vec4)