cmake_minimum_required(VERSION 3.16)
project(TJRayTracer VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(TJRAYTRACER_BUILD_EXAMPLES "TJRayTracer: Build example applications" ON)
option(TJRAYTRACER_ENABLE_TESTS "TJRayTracer: Enable tests" OFF)

if(TJRAYTRACER_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(TJRAYTRACER_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

find_package(OpenMP REQUIRED)
find_package(Eigen3 REQUIRED)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_subdirectory(RayTracer)

# ---------- Package Config ----------

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/TJRayTracerConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/TJRayTracerConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TJRayTracer
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/TJRayTracerConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(EXPORT TJRayTracerTargets
    FILE TJRayTracerTargets.cmake
    NAMESPACE TJRayTracer::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TJRayTracer
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/TJRayTracerConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/TJRayTracerConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TJRayTracer
)
