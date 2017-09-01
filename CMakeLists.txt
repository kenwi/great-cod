cmake_minimum_required(VERSION 3.8)
project(great_cod)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Application.cpp Application.h Widget.cpp Widget.h RenderContext.cpp RenderContext.h StateBase.cpp StateBase.h)
add_executable(great_cod ${SOURCE_FILES})
target_link_libraries(great_cod sfml-graphics sfml-window sfml-system)