cmake_minimum_required(VERSION 3.15)
project(GLFW-Wrapper)

option(BUILD_EXAMPLE "Build example project" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_compile_options(-std=c++14)
endif()

set(LIB_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)

add_subdirectory(${LIB_ROOT_DIR}/glfw)

set(SRC src/inputevent.cpp
		src/window.cpp
	)

add_library(glfw-wrapper STATIC ${SRC})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${LIB_ROOT_DIR}/glfw/include
)

find_package(OpenGL)

target_compile_definitions(glfw-wrapper PRIVATE GLFW_INCLUDE_NONE)

target_link_libraries(glfw-wrapper ${OPENGL_gl_LIBRARY})
target_link_libraries(glfw-wrapper glfw)

if(BUILD_EXAMPLE)
add_executable(example example/main.cpp)
target_link_libraries(example glfw-wrapper)
endif()
