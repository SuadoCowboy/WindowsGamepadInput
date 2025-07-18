cmake_minimum_required(VERSION 3.16)

project(WindowsGamepadInput)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(WindowsGamepadInput ${SOURCES})