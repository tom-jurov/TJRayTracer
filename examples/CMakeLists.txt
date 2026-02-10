add_executable(raytracer_example main.cpp)

target_link_libraries(raytracer_example
    PRIVATE TJRayTracer::RayTracer
)
