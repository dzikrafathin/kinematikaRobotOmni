cmake_minimum_required (VERSION 3.0)

project(KinematikaRobot)
 
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_library(KinematikaBalik src/KinematikaBalik.cpp)
add_library(KinematikaMaju src/KinematikaMaju.cpp)

target_include_directories(
    KinematikaBalik 
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_include_directories(
    KinematikaMaju 
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(KinematikaBalik Eigen3::Eigen)
target_link_libraries(KinematikaMaju Eigen3::Eigen)

add_executable(contoh contoh.cpp)

target_include_directories(
    contoh
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(contoh KinematikaBalik)
target_link_libraries(contoh KinematikaMaju)