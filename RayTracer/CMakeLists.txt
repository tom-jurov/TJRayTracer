set(SOURCES 
    src/Color.cpp
    src/Canvas.cpp
    src/Pixel.cpp
    src/TF.cpp
    src/Ray.cpp
    src/Sphere.cpp
    src/BaseObject.cpp
    src/Intersection.cpp
    src/PointLight.cpp
    src/Material.cpp
    src/World.cpp
    src/Comps.cpp
    src/Camera.cpp
    src/Plane.cpp
    src/BasePattern.cpp
    src/StrippedPattern.cpp
    src/GradientPattern.cpp
    src/RingPattern.cpp
    src/CheckersPattern.cpp
    src/TestPattern.cpp
    src/Cube.cpp
    src/Cylinder.cpp
    src/Cones.cpp
)

add_library(RayTracer SHARED)
add_library(TJRayTracer::RayTracer ALIAS RayTracer)
target_sources(RayTracer PRIVATE ${SOURCES})


target_include_directories(RayTracer
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(RayTracer
    PUBLIC Eigen3::Eigen OpenMP::OpenMP_CXX
)

target_compile_definitions(RayTracer
    PRIVATE TJRAYTRACER_BUILD_DLL
)

set_target_properties(RayTracer PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    DEBUG_POSTFIX "_d"
)

install(TARGETS RayTracer
    EXPORT TJRayTracerTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
