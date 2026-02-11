cmake_minimum_required(VERSION 3.16)

project(
    CMakeRobNav
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(nav_core src/pose2d.cpp src/transform2d.cpp)
target_include_directories(nav_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(nav_core PRIVATE -Wall -Wextra -Wpedantic)


add_executable(dead_reckoning src/dead_reckoning.cpp)
target_link_libraries(dead_reckoning PRIVATE nav_core)
target_compile_options(dead_reckoning PRIVATE -Wall -Wextra -Wpedantic)

add_executable(test_pose2d tests/test_pose2d.cpp)
target_link_libraries(test_pose2d PRIVATE nav_core)
target_compile_options(test_pose2d PRIVATE -Wall -Wextra -Wpedantic)

add_executable(test_transform2d tests/test_transform2d.cpp)
target_link_libraries(test_transform2d PRIVATE nav_core)
target_compile_options(test_transform2d PRIVATE -Wall -Wextra -Wpedantic)


add_executable(frame_transform_demo src/frame_transform_demo.cpp)
target_link_libraries(frame_transform_demo PRIVATE nav_core)
target_compile_options(frame_transform_demo PRIVATE -Wall -Wextra -Wpedantic)


enable_testing()
add_test(NAME pose2d_tests COMMAND test_pose2d)
add_test(NAME transform2d_t COMMAND test_transform2d)

