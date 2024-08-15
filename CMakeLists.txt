cmake_minimum_required(VERSION 3.30)

project(MyTest)


add_subdirectory(_deps/wxwidgets)
add_executable(MyTest main.cpp)

target_include_directories(Engine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
