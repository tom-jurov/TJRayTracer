# GTest include code would
# go somewhere in here
find_package(GTest REQUIRED)
add_executable(vec4_test Vec4_test.cpp)

target_link_libraries(vec4_test
 PRIVATE
  GTest::GTest
  vec4)

add_test(vec4_gtests vec4_test)
