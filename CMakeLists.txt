cmake_minimum_required(VERSION 3.5)
project(great_cod)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Application.cpp src/Application.h src/Widget.cpp src/Widget.h src/RenderContext.cpp src/RenderContext.h src/StateBase.cpp src/StateBase.h)
add_executable(great_cod ${SOURCE_FILES})
target_link_libraries(great_cod sfml-graphics sfml-window sfml-system)
